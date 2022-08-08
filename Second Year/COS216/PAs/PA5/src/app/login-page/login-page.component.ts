import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';
import { Storage } from '@ionic/storage-angular';
import { ToastController } from '@ionic/angular';

@Component({
  selector: 'app-login-page',
  templateUrl: './login-page.component.html',
  styleUrls: ['./login-page.component.scss'],
})
export class LoginPageComponent implements OnInit {
  link = 'http://localhost:80/COS216/PA4/api.php';
  failmessage : string = '';

  constructor(private toast: ToastController, private http: HttpClient, private router: Router, private storage: Storage) { }

  ngOnInit() {
    //await this.storage.create();
    
  }

  loginEvent(val) {
    const sto = localStorage.getItem('res');
    if (sto != null) {
      this.router.navigateByUrl('/trending')
      return;
    }
    //console.warn(val);
    if (val.email == '' || val.password == '') {
      this.toaster('No credentials provided.');
      return;
    }
    const body = { "type" : "login", "email" : val.email, "password" : val.password };
    this.http.post(this.link, body, {})
    .subscribe(async res =>{
      if (res['code'] === '200') {
        console.log(res);
        localStorage.setItem('res', JSON.stringify(res));
        this.router.navigateByUrl('/trending')
      }
      else {
        this.toaster('Invalid credentials provided');
      }
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

}
