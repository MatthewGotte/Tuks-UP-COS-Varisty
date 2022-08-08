using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Assignment02_API.Models;
using Assignment02_API.ViewModels;

namespace Assignment02_API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class OrderController : ControllerBase
    {
        private readonly AppDbContext db = new AppDbContext();

        // Creating an order list. The list will contain all orders.
        [HttpGet]
        [Route("getOrders")]
        public object GetOrders(int id)
        {
            var orderList = db.Order.ToList();

            return orderList;
        }

        //Creating a new order. This will receive a list of the basket products containing their product information and ordered quantity
        [HttpPost]
        [Route("createOrder")]
        public object CreateOrder(orderVM orderVM)
        {
            Order orderCreate = new Order()
            {
                Date = DateTime.Now
            };
            try
            {
                foreach (var item in orderVM.basketProducts)
                {
                    Console.WriteLine("hello");
                    OrderLine orderline = new OrderLine
                    {
                        Order = orderCreate,
                        OrderId = orderCreate.OrderId,
                        ProductId = item.ProductId,
                        Product = db.Product.Find(item.ProductId),
                        Quantity = item.Quantity,
                    };
                    db.OrderLine.Add(orderline);
                }

                db.Order.Add(orderCreate);
                db.SaveChanges();

                return Ok();

            }
            catch (Exception e)
            {
                return BadRequest(e.Message);
            }

        }

        
    }
}
