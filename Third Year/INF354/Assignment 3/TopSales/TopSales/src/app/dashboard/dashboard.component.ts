import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { ChartData, ChartOptions } from 'chart.js';


// export interface top10lement {
//   name : string;
//   price : number;
//   brand : string;
//   type : string;
//   description : string;
// }

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {

  //API response
  productResponse! : any;
  sortedProductResponse! : any;
  top10Products! : any;

  displayedColumns : string[] = ['name', 'price', 'brand', 'type', 'description'];

  //Product Count by Brands
  byBrands! : any;

  byBrandsOptions: ChartOptions = {
    responsive: false,
    plugins: {
      title: {
        display: true,
        text: 'Monthly Sales Data',
      },
    },
  };

  //Product Count by Product Type
  byProductType! : any;

  byProductTypeOptions: ChartOptions = {
    responsive: false,
    plugins: {
      title: {
        display: true,
        text: 'Monthly Sales Data',
      },
    },
  };

  loading : boolean;

  constructor(private http : HttpClient) {
    this.loading = false;
  }

  ngOnInit(): void {

    this.loading = true;

    var cookie = this.getCookie('token');

    this.http.get('https://localhost:44329/api/Product/getproducts', { 'headers' : new HttpHeaders().set('Authorization', 'Bearer ' + cookie) } ).subscribe(
      {
        next: (data : any) => {
          this.loading = false;
          this.productResponse = data.products;
          this.populateGraphs();
          this.sortProducts();
          this.takeTop10Sorted();
          console.log(this.top10Products);
        },
        error: err => {
          console.log(err);
        }
      }
    );

  }

  takeTop10Sorted() {
    var output = new Array();
    for (var i = 0; i < 10; i++) {
      //output.push(this.sortedProductResponse[i]);
      var item = this.sortedProductResponse[i];
      output.push(item)
    }
    this.top10Products = output;
  }

  sortProducts() {
    this.sortedProductResponse = this.productResponse.sort( function(a : any, b : any) {
        var y = a.price;
        var x = b.price;
        return ((x < y) ? -1 : ((x > y) ? 1 : 0));
    });
  }

  countBrand(brandName : string) : any {
    return this.productResponse.filter((el : any) => {
      return el.brand.name == brandName;
    }).length;
  }

  countProductType(productType : string) : number {
    return this.productResponse.filter((el : any) => {
      return el.productType.name == productType;
    }).length;
  }

  populateGraphs() {
   
    // loggin each product
    // this.productResponse.forEach((el : any) => {
    //   console.log(el);
    // });

    var countNike = this.countBrand('Nike');
    var countAdidas = this.countBrand('Adidas');
    var countLevi = this.countBrand('Levi Strauss & Co.');
    var countFootwear = this.countProductType('Footwear');
    var countClothing = this.countProductType('Clothing');
    var countAccessories = this.countProductType('Accessories');

    // console.log(countNike);
    // console.log(countAdidas);
    // console.log(countLevi);
    // console.log(countFootwear);
    // console.log(countClothing);
    // console.log(countAccessories);

    this.byBrands = {
      labels: [
        'Nike',
        'Adidas',
        'Levi Strauss & Co.'
      ],
      datasets: [{
        label: 'Product Count by Brands',
        data: [countNike, countAdidas, countLevi],
        backgroundColor: [
          'rgb(255, 99, 132)',
          'rgb(54, 162, 235)',
          'rgb(255, 205, 86)'
        ],
        hoverOffset: 4
      }]
    };

    this.byProductType = {
      labels: [
        'Footwear',
        'Clothing',
        'Accessories'
      ],
      datasets: [{
        label: 'My First Dataset',
        data: [countFootwear, countClothing, countAccessories],
        backgroundColor: [
          'rgb(255, 99, 132)',
          'rgb(54, 162, 235)',
          'rgb(255, 205, 86)'
        ],
        hoverOffset: 4
      }]
    };

  }

  getCookie(cname : string) {
    let name = cname + "=";
    let ca = document.cookie.split(';');
    for(let i = 0; i < ca.length; i++) {
      let c = ca[i];
      while (c.charAt(0) == ' ') {
        c = c.substring(1);
      }
      if (c.indexOf(name) == 0) {
        return c.substring(name.length, c.length);
      }
    }
    return "";
  }

}
