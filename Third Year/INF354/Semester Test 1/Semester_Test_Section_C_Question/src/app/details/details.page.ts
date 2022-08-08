import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-details',
  templateUrl: './details.page.html',
  styleUrls: ['./details.page.scss'],
})
export class DetailsPage implements OnInit {
  userObj: any;
  constructor() { }

/**
*
* SECTION C - Question 1 (Complete the ngOnInit Function)
*/
  ngOnInit() {
    this.userObj = JSON.parse(localStorage.getItem('userDetails'));
  }



}
