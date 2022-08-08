import { Component, Input, OnInit } from '@angular/core';

@Component({
  selector: 'app-child',
  templateUrl: './child.component.html',
  styleUrls: ['./child.component.scss']
})
export class ChildComponent implements OnInit {

  test = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  display! : any;
  name = "test name";

  @Input() childName = {
    name: "",
    surname: ""
  };

  constructor() {


    setTimeout(() => {
      //filter:
      this.name = "new name here";
    },2000);
  }

  ngOnInit(): void {
    console.log(this.childName.name + " " + this.childName.surname);
  }

}
