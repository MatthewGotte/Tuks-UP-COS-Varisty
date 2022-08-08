import { Injectable } from '@angular/core';
import { BehaviorSubject, Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class MainService {

  private bs = new BehaviorSubject<boolean>(false);

  constructor() { }

  get obs(): Observable<boolean> {
    return this.bs.asObservable()
  }

  ngOnInit(): void {
  
  }

  LogIn(){
    this.bs.next(true)
  }

  LogOut(){
    this.bs.next(false)
  }
}
