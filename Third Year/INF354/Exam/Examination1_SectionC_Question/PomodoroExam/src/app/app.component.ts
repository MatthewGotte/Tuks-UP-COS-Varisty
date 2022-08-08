import { Component, Input, OnInit } from '@angular/core';
import { Timer } from "easytimer.js";
import { Observable, Subject } from 'rxjs';
import { PomodoroStatus } from './models/PomodoroStatus.enum';
import { NavBarComponent } from './nav-bar/nav-bar.component';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html'
})
export class AppComponent implements OnInit {

  currentTimeSlot : string = "00:00:00";
  currentStatus : PomodoroStatus = PomodoroStatus.OnBreak;
  timer : Timer = new Timer();

  @Input() Reset: Observable<void> = new Observable<void>();

  constructor() {
    this.resetPomodoroSessions();
  }

  ngOnInit(): void {
    this.Reset.subscribe(() => {
      console.log('here')
    })
  }

  isWorking () : boolean {
    
    return this.currentStatus == PomodoroStatus.Working;//TODO: change this line to check if current status is equal to working
  }

  StartWorkSession() {
    this.timer.stop();
    this.timer.start({countdown: true, startValues: {minutes: 25}});
    
    //TODO: set current status to working
    this.currentStatus = PomodoroStatus.Working;
  }

  StartBreak() {
    this.timer.stop();
    this.timer.start({countdown: true, startValues: {minutes: 10}});

    //TODO: set current status to on break
    this.currentStatus = PomodoroStatus.OnBreak;
  }

  resetPomodoroSessions() {
    this.timer = new Timer();
    this.timer.addEventListener('secondsUpdated',  (e) => {
      this.currentTimeSlot = this.timer.getTimeValues().toString();
    })
    this.timer.addEventListener('targetAchieved', e=> { this.playNotification();})
    
    
    //TODO: set current status to on break
    this.currentStatus = PomodoroStatus.OnBreak;
  }

  playNotification() {
    var snd = new Audio("assets/beep.wav");  
    snd.play();
  }
}
