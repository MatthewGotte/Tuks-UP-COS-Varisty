using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Assignment02_API.ViewModels;

namespace Assignment02_API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DummyController : ControllerBase
    {
        [HttpPost]
        [Route("generatePassword")]
        public object GeneratePassword(dummyVM dummyVM)
        {
            Random ran = new Random();
            string password = dummyVM.LastName.Trim().ToUpper().Replace(" ", "_");
            password += "_";
            password += dummyVM.FirstName.Substring(0, 1).ToUpper();
            password += "_";
            password += ran.Next(1, 1000);

            dummyVM.Password = password;

            return dummyVM;
        } 
    }
}
