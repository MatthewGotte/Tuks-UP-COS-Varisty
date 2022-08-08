import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient, JsonpClientBackend } from '@angular/common/http';
import { ToastController } from '@ionic/angular';
import { ValueAccessor } from '@ionic/angular/directives/control-value-accessors/value-accessor';

@Component({
  selector: 'app-trending-page',
  templateUrl: './trending-page.component.html',
  styleUrls: ['./trending-page.component.scss'],
})

export class TrendingPageComponent implements OnInit {
  link = 'http://localhost:80/COS216/PA4/api.php';
  output: any;
  nocontent: string;
  genres = ['action', 'adventure', 'MMPORPG', 'narrative', 'testfornone'];

  constructor(private router: Router, private toast: ToastController, private http: HttpClient) { }

  ngOnInit() {
    //console.log('RUNNING');
    this.nocontent = '';
    const data = localStorage.getItem('res');
    console.log(data);
    if (data === null) {
      this.router.navigateByUrl('/login');
      return;
    }
    var ores = JSON.parse(data);
    const body = { "type" : "info", "return" : '*', "title" : '*', "key" : ores.API_key};
    this.http.post(this.link, body, {})
    .subscribe(res =>{
      this.printer(res);
    }, err => {
      this.toaster('Handshake with API failed.');
    });
  }

  printer(data) {
    //console.log(data['data']);
    var success = data['status'];
    console.log('=========' + success);
    if (success == 'unsuccessful') {
      this.nocontent = "Not Found";
      return;
    }
    this.output = data['data'];
    console.log(this.output);
  }

  logout() {
    localStorage.removeItem('res');
    this.router.navigateByUrl('/login');
  }

  performSearch(term) {
    //this.toaster(term);
    this.nocontent = '';
    this.output = null;
    const data = localStorage.getItem('res');
    console.log(data);
    if (data === null) {
      this.router.navigateByUrl('/login');
      return;
    }
    var ores = JSON.parse(data);
    const body = { "type" : "info", "return" : '*', "title" : term, "key" : ores.API_key};
    this.http.post(this.link, body, {})
    .subscribe(res =>{
      this.printer(res);
    }, err => {
      this.toaster('Handshake with API failed.');
    });
  }

  async toaster(message) {
    const toast = await this.toast.create( {
      message: message,
      duration: 3000,
      cssClass: 'yourClass'
    });
    toast.present();
  }

  doRefresh(event) {
    // setTimeout(() => {
    //   event.target.complete();
    //   this.toaster('Content refreshed.')
    //   this.genres = [];
    //   this.genres = ['action', 'adventure', 'MMPORPG', 'narrative'];

    // }, 2000);
    window.location.reload();
  }

  temp = [];
  onChange(event){
    console.log('filter - ' + event);
    var copy = JSON.stringify(this.output);
    //console.log(copy);
    for (var i = 0; i < copy.length; i++) {
      if (this.output[i] == null) continue;
      console.log(this.output[i].genres[0].slug)
      if (this.output[i].genres[0].slug == event) {
        this.temp.push(this.output[i]);
      }
    }
    console.log('------------FILTERED ARRAY------------');
    console.log(this.temp);
    this.output = this.temp;
    if (this.output.length == 0) this.nocontent = 'Not Found';
  }
  
}
