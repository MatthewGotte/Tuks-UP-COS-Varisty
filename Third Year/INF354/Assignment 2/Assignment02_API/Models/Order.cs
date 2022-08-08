using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

// Code scaffolded by EF Core assumes nullable reference types (NRTs) are not used or disabled.
// If you have enabled NRTs for your project, then un-comment the following line:
// #nullable disable

namespace Assignment02_API.Models
{
    [Table("order")]
    public partial class Order
    {
        public Order()
        {
            OrderLine = new HashSet<OrderLine>();
        }

        [Key]
        [Column("orderId")]
        public int OrderId { get; set; }
        [Column("date", TypeName = "date")]
        public DateTime Date { get; set; }

        [InverseProperty("Order")]
        public virtual ICollection<OrderLine> OrderLine { get; set; }
    }
}
