import { Component, OnInit } from '@angular/core';
import { Observable } from 'rxjs';
import { HttpClient } from '@angular/common/http';
import { ToastController } from '@ionic/angular';
import { FormBuilder, FormGroup } from '@angular/forms';
import { basketObjectVM } from './basketObjectVM.module';

@Component({
  selector: 'app-products',
  templateUrl: './products.page.html',
  styleUrls: ['./products.page.scss'],
})
export class ProductsPage implements OnInit {

  products : Observable<any>;
  addToBasketfrm : FormGroup;

  constructor(private http: HttpClient, private toastController: ToastController, private builder : FormBuilder) { 
    this.addToBasketfrm = this.builder.group({
      quantity: ['1']
    });

    if (this.products == null) {
      this.queryAllProducts().subscribe(res => {
        this.products = res;
        // console.log(res);
      });
    }

  }

  ngOnInit() {
  }

  async showToast(message : string) {
    const toast = await this.toastController.create({
      message: message,
      duration: 2000
    });
    toast.present();
  }

  queryAllProducts() : Observable<any> {
    return this.http.get('https://localhost:63119/api/product/getProductlist');
  }

  addToBasket(product : any) {

    const quantity = Number(this.addToBasketfrm.controls['quantity'].value);

    //check quantity:
    if (quantity < 1) {
      this.showToast("Quantity must be at least one.");
    } else {
        
      //assume cart empty
      let cart : basketObjectVM[] = [];
      // console.log(cart);

      //check if anything already in cart
      if (localStorage.getItem('cart')) {
        JSON.parse(localStorage.getItem('cart')).forEach(element => {
          cart.push(element);
        });
      }
      
      var flag = true;
      //check if basketObjectVM already exisit:
      for (var i = 0; i < cart.length; i++) {
        if (cart[i].ProductId == product.productId) {
          cart[i].Quantity += quantity;
          flag = false;
        }
      }

      if (flag) {
        cart.push(new basketObjectVM(product.productId, product.productName, product.productDescription, product.productPrice, quantity));
        console.log('here...');
      }

      console.log(cart);
      localStorage.setItem('cart', JSON.stringify(cart));
      this.addToBasketfrm.reset({ quantity: ['1'] });
      
    }

  }

}
