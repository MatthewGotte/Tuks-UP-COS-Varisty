import { Component, EventEmitter, Injectable, OnInit, Output } from '@angular/core';

@Component({
  selector: 'app-nav-bar',
  templateUrl: './nav-bar.component.html'
})
@Injectable()
export class NavBarComponent implements OnInit {

  @Output() Reset: EventEmitter<any> = new EventEmitter()

  constructor() { }

  ngOnInit(): void {
  }

  onResetButtonClicked() {
    //TODO: notify app component to call its resetPomodoroSessions() method.
    this.Reset.emit();
  }

}
