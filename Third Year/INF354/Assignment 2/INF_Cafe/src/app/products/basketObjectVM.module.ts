export class basketObjectVM {

    constructor(id : number, name : string, desc : string, price : number, quantity : number) {
        this.ProductId = id;
        this.ProductName = name;
        this.ProductDescription = desc;
        this.ProductPrice = price;
        this.Quantity = quantity;
    }

    public ProductId : number
    public ProductName : string
    public ProductDescription : string
    public ProductPrice : number
    public Quantity : number

}