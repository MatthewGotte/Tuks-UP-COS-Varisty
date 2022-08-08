import { Component, OnInit } from '@angular/core';
import { Message } from '../models/message.model';
import { ChatMessageManagerServiceService } from '../services/chat-message-manager-service.service';

@Component({
  selector: 'semtest-chatstats',
  templateUrl: './chatstats.component.html',
  styleUrls: ['./chatstats.component.css']
})
export class ChatstatsComponent implements OnInit {

  //TODO: create your stats variables here
  isBotAuthored : number;
  Message : number;
  ExceedingTen : number;

  constructor(private chatService : ChatMessageManagerServiceService) {
    this.isBotAuthored = 1;
    this.Message = 0;
    this.ExceedingTen = 0;
  }

  ngOnInit(): void {
    //recieveEmit
    this.chatService.messageEmit.subscribe((res : Message) => {
      this.recieveMessage(res);
    })
  }

  //TODO: create your method for receiving each message here
  recieveMessage(message : Message) {
    console.log("here");
    //increase stats
    if (message.isBotAuthored) {
      this.isBotAuthored++;
    } else {
      this.Message++;
    }
    //count for ExceedingTen
    //ten words means there should be 9 spaces, thus >= 10 spaces means words are EXCEEDING 10
    var wordCount = (message.content.match(/ /g) || []).length; //regex global for ' ' and count it or [] array
    if (wordCount >= 10) {
      this.ExceedingTen++;
    }

  }

}
