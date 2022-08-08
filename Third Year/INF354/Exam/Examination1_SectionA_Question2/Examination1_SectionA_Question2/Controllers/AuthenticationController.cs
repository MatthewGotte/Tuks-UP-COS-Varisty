using Examination1_SectionA_Question2.Models;
using Examination1_SectionA_Question2.ViewModels;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Examination1_SectionA_Question2.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AuthenticationController : ControllerBase
    {
        private readonly UserManager<AppUser> _userManager;

        public AuthenticationController(UserManager<AppUser> userManager)
        {
            _userManager = userManager; 
        }

        ///////////////////////////////////////////////////
        // Create the RegisterUser endpoint/method below //

        [HttpPost]
        [Route("RegisterUser")]
        public async Task<IActionResult> RegisterUser(UserViewModel uvm)
        {
            //Find user in DB:
            
            try
            {
                var user = await _userManager.FindByNameAsync(uvm.Username);

                if (user != null)
                {
                    return Forbid("Account Already Exists."); //user exisits here
                }

                //user does not exist here
                var res = await _userManager.CreateAsync(new AppUser
                {
                    Id = Guid.NewGuid().ToString(),
                    Email = uvm.EmailAddress,
                    UserName = uvm.Username
                }, uvm.Password);

                if (res.Succeeded)
                {
                    return Ok("Account created successfully");
                } 
                else
                {
                    return StatusCode(StatusCodes.Status500InternalServerError, "Internal Server Error. Please contact support.");
                }

            } 
            catch (Exception ex)
            {
                return StatusCode(StatusCodes.Status500InternalServerError, "Internal Server Error. Please contact support.");
            }
        }

        ///////////////////////////////////////////////////
    }
}
