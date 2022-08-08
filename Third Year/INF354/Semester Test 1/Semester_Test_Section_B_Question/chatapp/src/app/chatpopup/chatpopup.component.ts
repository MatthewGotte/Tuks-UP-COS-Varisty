import { Component, Input, OnInit } from '@angular/core';
import { FormControl } from '@angular/forms';
import { Message } from '../models/message.model';
import { ChatMessageManagerServiceService } from '../services/chat-message-manager-service.service';

declare var require: any;

@Component({
  selector: 'semtest-chatpopup',
  templateUrl: './chatpopup.component.html',
  styleUrls: ['./chatpopup.component.css']
})
export class ChatPopupComponent {

  typedUserMsg : FormControl = new FormControl();
  msgs : Message[] = [];

  elizabot : any;

  constructor(private chatService : ChatMessageManagerServiceService) {

    this.elizabot = require('../elizabot.js'); //This implementation of eliza is sourced from https://github.com/oren/eliza-bot

    let welcome = this.elizabot.start()
    this.onAddNewMessage(new Message(true, welcome));
  }

  sendUserMessage() {
    let userMsg = this.typedUserMsg.value;
    this.onAddNewMessage(new Message(false, userMsg));
    this.typedUserMsg.reset();

    let resp = this.elizabot.reply(userMsg);
    this.onAddNewMessage(new Message(true, resp));
  }

  onAddNewMessage(msg : Message) {
    this.msgs.push(msg);
    
    //TODO: Send 'msg' to chatstats component
    this.chatService.sendMsg(msg);
  }
  
}
