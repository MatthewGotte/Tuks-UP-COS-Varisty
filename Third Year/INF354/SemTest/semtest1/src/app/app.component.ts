import { Component, Output } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  // name = "Shannon";
  @Output() name: string;
  title = 'semtest1';
  constructor() {
    console.log('root reached') 
    this.name="Shannon"
  }
}
