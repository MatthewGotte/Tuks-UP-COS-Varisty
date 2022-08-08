import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { MatSnackBar } from '@angular/material/snack-bar';
import { Router } from '@angular/router';
import { User } from '../models/user';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})
export class RegisterComponent implements OnInit {

  registerForm! : FormGroup;
  frmBuilder : FormBuilder;
  loader = false;

  constructor(private builder : FormBuilder, private snackBar : MatSnackBar, private http : HttpClient, private router : Router) { 
    this.frmBuilder = builder;
  }

  ngOnInit(): void {
    this.registerForm = this.frmBuilder.group({
      email: ['', [Validators.required, Validators.email]],
      password: ['', Validators.pattern(new RegExp('.{8,}'))]
    });
  }

  register() {

    //check if form is valid for API call
    if (this.registerForm.invalid) return;

    //construct object to post
    var uvm = new User(this.registerForm.controls['email'].value, this.registerForm.controls['password'].value);

    this.loader = true;
    //API call for register
    this.http.post<any>('https://localhost:44329/api/Authentication/register', uvm).subscribe(
      {
        next: data => {
          //200OK from the API
          this.showSnackBar(data.message);
          this.router.navigate(['login']);
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
