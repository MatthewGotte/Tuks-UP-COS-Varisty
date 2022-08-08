import { Component, Input, OnInit } from '@angular/core';
import { Message } from '../models/message.model';

@Component({
  selector: 'semtest-chatmessage',
  templateUrl: './chatmessage.component.html',
  styleUrls: ['./chatmessage.component.css']
})
export class ChatMessageComponent implements OnInit {

  @Input()
  msg! : Message;

  constructor() { }

  ngOnInit(): void {
  }

}
