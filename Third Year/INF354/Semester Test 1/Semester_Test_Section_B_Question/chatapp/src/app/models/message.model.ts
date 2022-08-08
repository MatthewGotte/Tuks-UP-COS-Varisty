
export class Message {
    content : string = "";
    msgTime : Date;
    isBotAuthored : boolean = false;

    constructor(createdByABot : boolean, body : string) {
        this.content = body;
        this.msgTime = new Date(Date.now());
        this.isBotAuthored = createdByABot;
    }
}