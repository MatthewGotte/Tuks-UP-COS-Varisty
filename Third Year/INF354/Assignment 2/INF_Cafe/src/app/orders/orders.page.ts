import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { Observable } from 'rxjs';


@Component({
  selector: 'app-orders',
  templateUrl: './orders.page.html',
  styleUrls: ['./orders.page.scss'],
})
export class OrdersPage implements OnInit {

  orders : any;
  empty : boolean = true;

  constructor(private http: HttpClient) { }

  ngOnInit() {
  }

  ionViewDidEnter() {
    this.queryAllOrders().subscribe(res => {
      this.orders = res;
      if (res.length) {
        this.empty = false;
      }
    });
  }

  queryAllOrders() : Observable<any> {
    return this.http.get('https://localhost:63119/api/order/getOrders')
  }

  getDate(date : string) : string {
    return date.substring(0, date.indexOf('T'));
  }

}
