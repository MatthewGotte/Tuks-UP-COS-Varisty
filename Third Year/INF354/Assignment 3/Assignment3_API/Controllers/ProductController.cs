using Assignment3_API.Models;
using Assignment3_API.ViewModels;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assignment3_API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class ProductController : Controller
    {

        private static readonly AppDbContext db = new AppDbContext();

        [HttpGet]
        [Route("getproducts")]
        [Authorize(AuthenticationSchemes = JwtBearerDefaults.AuthenticationScheme)]
        public async Task<IActionResult> GetProductsAsync()
        {
            try
            {
                
                var productList = await db
                    .Products
                    .Select(p => new
                    {
                        p.Name,
                        p.Description,
                        p.DateCreated,
                        p.DateModified,
                        p.IsActive,
                        p.IsDeleted,
                        p.Price,
                        p.ProductType,
                        p.Brand
                    }).ToListAsync();

                return Ok(new { products = productList });

            }
            catch (Exception ex)
            {

            }
            return Ok();
        }

        private static string output;

        [HttpGet]
        [Route("test")]
        public async Task<IActionResult> test()
        {
            try
            {
                var productList = new List<object>();
                var t  = db
                    .Products
                    .Select(p => new
                    {
                        p.Name,
                        p.Description,
                        p.DateCreated,
                        p.DateModified,
                        p.IsActive,
                        p.IsDeleted,
                        p.Price,
                        p.ProductType,
                        p.Brand
                    }).ToListAsync();

                return Ok(new { products = productList.First() });

            }
            catch (Exception ex)
            {

            }
            return Forbid();
        }


    }
}
