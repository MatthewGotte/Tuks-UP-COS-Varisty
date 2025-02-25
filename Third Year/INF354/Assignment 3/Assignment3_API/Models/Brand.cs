﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assignment3_API.Models
{
    public class Brand : BaseEntity
    {
        public int BrandId { get; set; }
        public virtual ICollection<Product> Products { get; set; }
    }
}
