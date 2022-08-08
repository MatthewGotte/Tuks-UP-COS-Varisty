import { Component, OnInit } from '@angular/core';
import { MainService } from './main.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit{
  title = 'practice';
  flag = false;

  constructor(private main: MainService){

  }

  ngOnInit(){
    this.main.obs.subscribe((data:any) =>
      {
        this.flag = data;
      })
  }

  LogIn(){
    console.log("log in clicked")
    this.main.LogIn();
    
  }

  LogOut(){
    console.log("log out clicked")
    this.main.LogOut();

  }

}
