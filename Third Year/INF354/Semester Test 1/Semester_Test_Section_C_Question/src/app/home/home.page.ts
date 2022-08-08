import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { ToastController } from '@ionic/angular';
import { Router } from '@angular/router';
import { MainService } from '../services/main.service';
@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {
  registerForm: FormGroup;
  message: string = '';
  constructor(private formBuilder: FormBuilder, private toastController : ToastController, private mainService : MainService, private router : Router) {}



  ngOnInit(){
    this.registerForm = this.formBuilder.group({
      firstName: ['', [Validators.required, Validators.minLength(3)]],
      lastName:['', [Validators.required, Validators.minLength(5)]]
    });
  }

/**
*
* SECTION C - Question 1 (Complete the component)
*/

  async submitRegister() {
    if (this.registerForm.controls['firstName'].errors || this.registerForm.controls['lastName'].errors) {
      this.showToastMessage('Registration unsuccessful');
      return;
    }
    //email in MainService
    this.mainService.createEmail(this.registerForm);
    //show toast
    this.showToastMessage('Registration Successful');
    //re-route to details component
    this.router.navigate(['/details']);
  }

  async showToastMessage(message : string) {
    const toast = await this.toastController.create({
      message: message,
      duration: 2000,
      position: 'top'
    });
    toast.present();
  }


}
