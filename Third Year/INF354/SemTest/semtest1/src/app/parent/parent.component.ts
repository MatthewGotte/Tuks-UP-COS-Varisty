import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-parent',
  templateUrl: './parent.component.html',
  styleUrls: ['./parent.component.scss']
})
export class ParentComponent implements OnInit {

  n : any;

  constructor() {
    this.n = {
      name : "Joe",
      surname : "Soap"
    }
  }

  ngOnInit(): void {
  }

}
