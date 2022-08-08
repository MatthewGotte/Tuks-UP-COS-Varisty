import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
import { MatSnackBar } from '@angular/material/snack-bar';
import { Router } from '@angular/router';
import { User } from '../models/user';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {

  loginForm! : FormGroup;
  frmBuilder : FormBuilder;

  loader = false;

  constructor(private builder : FormBuilder, private snackBar : MatSnackBar, private http : HttpClient, private router : Router) { 
    this.frmBuilder = builder;
  }

  ngOnInit(): void {
    this.loginForm = this.frmBuilder.group({
        email: ['', [Validators.required, Validators.email]],
        password: ['', Validators.required] //password is requied, will be vaidated with API call
    });
  }

  login() {

     //check if form is valid for API call
     if (this.loginForm.invalid) return;

     //construct object to post
     var uvm = new User(this.loginForm.controls['email'].value, this.loginForm.controls['password'].value);
 
     this.loader = true;
     //API call for register
     this.http.post<any>('https://localhost:44329/api/Authentication/login', uvm).subscribe(
      {
        next: data => {
          //200OK from the API
          this.showSnackBar(data.message);
          localStorage.setItem('uvm', JSON.stringify(uvm));
          this.router.navigate(['otp']);
        },
        error: err => {
          //error reported from the API (not a 200OK):
          this.showSnackBar(err.error.message);
          this.loader = false;
        }
      }
     );
  }

  showSnackBar(message : string) {
    this.snackBar.open(message, 'X', {duration: 2500});
  }

}
