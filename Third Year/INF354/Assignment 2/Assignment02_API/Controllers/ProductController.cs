using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Assignment02_API.Models;

namespace Assignment02_API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class ProductController : ControllerBase
    {
        private readonly AppDbContext db = new AppDbContext();

        // Creating a product list. The list will contain all products.
        [HttpGet]
        [Route("getProductList")]
        public object GetProductList()
        {
            var productList = db.Product.ToList();

            return productList;
        }

        
    }
}
