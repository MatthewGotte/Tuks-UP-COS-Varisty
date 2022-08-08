import { Injectable } from '@angular/core';
import { FormGroup } from '@angular/forms';

@Injectable({
  providedIn: 'root'
})

export class MainService {

constructor() { }

/**
*
* SECTION C - Question 1 (Complete the service)
*/
  createEmail(signupFrm : any) {
    const firstName = signupFrm.controls['firstName'].value;
    const lastName = signupFrm.controls['lastName'].value;
    const email = `${firstName.substring(0,1).toUpperCase()}${lastName.substring(0, 1).toUpperCase()}${lastName.substring(1, 3)}@company.com`;
    const obj = {
      firstName: firstName,
      lastName: lastName,
      email: email
    }
    //add to localstorage
    localStorage.setItem('userDetails', JSON.stringify(obj));
  } 

}
