import { Injectable, Output, EventEmitter } from '@angular/core';
import { Message } from '../models/message.model';

@Injectable({
  providedIn: 'root'
})
export class ChatMessageManagerServiceService {

  constructor() { }

  @Output() messageEmit = new EventEmitter<Message>();

  sendMsg(message : Message) {
    this.messageEmit.emit(message);
  }
}
