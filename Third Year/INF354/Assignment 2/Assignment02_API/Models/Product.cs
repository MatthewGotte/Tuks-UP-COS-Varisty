using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

// Code scaffolded by EF Core assumes nullable reference types (NRTs) are not used or disabled.
// If you have enabled NRTs for your project, then un-comment the following line:
// #nullable disable

namespace Assignment02_API.Models
{
    [Table("product")]
    public partial class Product
    {
        public Product()
        {
            OrderLine = new HashSet<OrderLine>();
        }

        [Key]
        [Column("productId")]
        public int ProductId { get; set; }
        [Required]
        [Column("productName")]
        [StringLength(150)]
        public string ProductName { get; set; }
        [Required]
        [Column("productDescription")]
        [StringLength(300)]
        public string ProductDescription { get; set; }
        [Column("productPrice")]
        public double ProductPrice { get; set; }

        [InverseProperty("Product")]
        public virtual ICollection<OrderLine> OrderLine { get; set; }
    }
}
