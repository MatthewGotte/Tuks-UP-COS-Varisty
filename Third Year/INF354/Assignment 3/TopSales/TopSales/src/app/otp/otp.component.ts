import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { MatSnackBar } from '@angular/material/snack-bar';
import { Router } from '@angular/router';
import { OTP } from '../models/otp';

@Component({
  selector: 'app-otp',
  templateUrl: './otp.component.html',
  styleUrls: ['./otp.component.scss']
})
export class OtpComponent implements OnInit {

  otpForm! : FormGroup;
  frmBuilder : FormBuilder;

  loader = false;

  constructor(private builder : FormBuilder, private snackBar : MatSnackBar, private http : HttpClient, private router : Router) {
    this.frmBuilder = builder;
  }

  ngOnInit(): void {
    this.otpForm = this.frmBuilder.group({
      otp: ['', Validators.pattern(new RegExp('^[0-9]{4}$'))]
    });
  }

  send() {

    //check if the form is valid for API call
    if (this.otpForm.invalid) return;

    if (!localStorage.getItem('uvm')) {
      this.showSnackBar('Invalid Request');
      this.router.navigate(['login']);
      return;
    }

    this.loader = true;
    //build payload
    var otp = new OTP(JSON.parse(localStorage.getItem('uvm')!), this.otpForm.controls['otp'].value);
    this.http.post<any>('https://localhost:44329/api/Authentication/verify', otp).subscribe(
      {
        next: data => {
          //Redirect to the dashboard:
          console.log(data); //store the JWT as a cookie or?...
          //store token as cookie:
          document.cookie=`token=${data.token};expires=${data.expiration}`;
          this.router.navigate(['dashboard']);
        },
        error: err => {
          //error reported from the API (not a 200OK):
          this.showSnackBar(err.error.message);
          this.loader = false;
        }
      }
    )

  }

  showSnackBar(message : string) {
    this.snackBar.open(message, 'X', {duration: 2500});
  }

}
