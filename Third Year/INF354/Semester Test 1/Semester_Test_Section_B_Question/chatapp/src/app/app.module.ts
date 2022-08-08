import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { ReactiveFormsModule } from '@angular/forms';
import { AppComponent } from './app.component';
import { ChatPopupComponent } from './chatpopup/chatpopup.component';
import { ChatMessageComponent } from './chatmessage/chatmessage.component';
import { ChatstatsComponent } from './chatstats/chatstats.component';

@NgModule({
  declarations: [
    AppComponent,
    ChatPopupComponent,
    ChatMessageComponent,
    ChatstatsComponent
  ],
  imports: [
    BrowserModule,
    ReactiveFormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
