import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { basketObjectVM } from '../products/basketObjectVM.module';
import { ToastController } from '@ionic/angular';


@Component({
  selector: 'app-basket',
  templateUrl: './basket.page.html',
  styleUrls: ['./basket.page.scss'],
})
export class BasketPage implements OnInit {

  cart: basketObjectVM[] = [];
  empty : boolean = false;

  constructor(private http: HttpClient, private toastController: ToastController) { 
  }

  ngOnInit() {
  }

  ionViewDidEnter() {
    const storage = localStorage.getItem('cart');
    if (storage) {
      //something is in the cart
      this.cart = JSON.parse(storage);
      this.empty = false;
    } else {
      this.empty = true;
    }
  }

  async showToast(message : string) {
    const toast = await this.toastController.create({
      message: message,
      duration: 2000
    });
    toast.present();
  }

  calcPrice(item : basketObjectVM) : string {
    // return (item.ProductPrice * item.Quantity).toFixed(2);
    const total = item.ProductPrice * item.Quantity;
    return total.toFixed(2);
  }

  removeFromBasket(id : number) {
    for (var i = 0; i < this.cart.length; i++) {
      if (this.cart[i].ProductId == id) {
        this.cart.splice(i, 1);
      }
    }
    //write back to localStorage:
    if (this.cart.length == 0) {
      localStorage.removeItem('cart');
      this.empty = true;
    } else {
      localStorage.setItem('cart', JSON.stringify(this.cart));
    }
  }

  checkout() {
    this.http.post<any>('https://localhost:63119/api/order/createOrder', {basketProducts: this.cart} ).subscribe(res => {
      if (res != null) {
        this.showToast("Failed to checkout");
      } else {
        localStorage.removeItem('cart');
        this.cart = [];
        this.empty = true;
      }
    })
  }

}
