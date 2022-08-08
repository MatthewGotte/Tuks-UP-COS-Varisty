import { User } from "./user";
export class OTP {
    public uvm : User;
    public value : string;

    constructor(uvm : User, value : string) {
        this.uvm = uvm;
        this.value = value;
    }
}
