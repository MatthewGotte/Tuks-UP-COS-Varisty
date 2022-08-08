using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

// Code scaffolded by EF Core assumes nullable reference types (NRTs) are not used or disabled.
// If you have enabled NRTs for your project, then un-comment the following line:
// #nullable disable

namespace Assignment02_API.Models
{
    [Table("orderLine")]
    public partial class OrderLine
    {
        [Key]
        [Column("orderLineId")]
        public int OrderLineId { get; set; }
        [Column("orderId")]
        public int OrderId { get; set; }
        [Column("productId")]
        public int ProductId { get; set; }
        [Column("quantity")]
        public int Quantity { get; set; }

        [ForeignKey(nameof(OrderId))]
        [InverseProperty("OrderLine")]
        public virtual Order Order { get; set; }
        [ForeignKey(nameof(ProductId))]
        [InverseProperty("OrderLine")]
        public virtual Product Product { get; set; }
    }
}
