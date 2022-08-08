using Assignment3_API.Models;
using Assignment3_API.ViewModels;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using Microsoft.IdentityModel.Tokens;
using System;
using System.IdentityModel.Tokens.Jwt;
using System.Linq;
using System.Net;
using System.Net.Mail;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Assignment3_API.Controllers
{
    [ApiController]
    [Route("api/[controller]")]
    public class AuthenticationController : ControllerBase
    {
        private readonly AppDbContext db = new AppDbContext();


        private readonly UserManager<User> userManager;
        private readonly IUserClaimsPrincipalFactory<User> claimsPrincipalFactory;
        private readonly IConfiguration configuration;

        public AuthenticationController(UserManager<User> userManager, IUserClaimsPrincipalFactory<User> claimsPrincipalFactory, IConfiguration configuration)
        {
            this.userManager = userManager;
            this.claimsPrincipalFactory = claimsPrincipalFactory;
            this.configuration = configuration;
        }

        [HttpPost]
        [Route("verify")]
        public async Task<IActionResult> Verify(OTP otp)
        {
            var user = await userManager.FindByNameAsync(otp.uvm.email);
            /*get the expected otp from the otp table*/
            IQueryable<otp> expected = db.Otp.Where(otp => otp.UserId == user.Id);
            if (user != null)
            {
                if (expected.Count() != 0)
                {
                    if (sha256(otp.value) == expected.First().otpCode)
                    {
                        db.Otp.Remove(expected.First());
                        db.SaveChanges();
                        return GenerateJWTToken(user);
                    }
                    else
                    {
                        return StatusCode(StatusCodes.Status422UnprocessableEntity, new { message = "Invalid OTP." });
                    }
                } else
                {
                    return StatusCode(StatusCodes.Status422UnprocessableEntity, new { message = "Login is a prerequisite." });
                }
            } else
            {
                return StatusCode(StatusCodes.Status422UnprocessableEntity, new { message = "User not found." });
            }
        }

        [HttpPost]
        [Route("login")]
        public async Task<IActionResult> Login(UserViewModel uvm)
        {
            var user = await userManager.FindByNameAsync(uvm.email);
            if (user != null && await userManager.CheckPasswordAsync(user, uvm.password))
            {
                try
                {
                    var principal = await claimsPrincipalFactory.CreateAsync(user);
                    await HttpContext.SignInAsync(IdentityConstants.ApplicationScheme, principal);
                    /*return GenerateJWTToken(user);*/
                    try
                    {
                        string otp = generateOTP();
                        var otpTupple = new otp();
                        otpTupple.UserId = user.Id;
                        otpTupple.otpCode = sha256(otp);

                        var staleOtp = db.Otp.Where(otp => otp.UserId == user.Id).FirstOrDefault();
                        if (staleOtp != null)
                        {
                            db.Otp.Remove(db.Otp.Where(otp => otp.UserId == user.Id).First());
                            db.SaveChanges();
                        }

                        var store_otp = db.Otp.Add(otpTupple);
                        db.SaveChanges();
                        try
                        {
                            sendEmail(user.Email, otp.ToString());
                        } catch (Exception ex)
                        {
                            return StatusCode(StatusCodes.Status500InternalServerError, "Internal error occured. Email failed to send");
                        }
                        return StatusCode(StatusCodes.Status200OK, new { message = "The OTP has been sent to your email address." });
                    }
                    catch (Exception ex)
                    {
                        return StatusCode(StatusCodes.Status500InternalServerError, "Internal error occured. Please contact support");
                    }
                }
                catch (Exception)
                {
                    return StatusCode(StatusCodes.Status500InternalServerError, "Internal error occured. Please contact support");
                }
            }
            else
            {
                return StatusCode(StatusCodes.Status401Unauthorized, new { message = "Invalid user credentials." });
            }
        }

        [HttpGet]
        private ActionResult GenerateJWTToken(User user)
        {
            var claims = new[]
            {
                new Claim(JwtRegisteredClaimNames.Sub, user.Email),
                new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString()),
                new Claim(JwtRegisteredClaimNames.UniqueName, user.UserName)
            };

            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(configuration["Tokens:Key"]));
            var credentials = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

            var token = new JwtSecurityToken(
                configuration["Tokens:Issuer"],
                configuration["Tokens:Audience"],
                claims,
                signingCredentials: credentials,
                expires: DateTime.UtcNow.AddHours(3)
            );

            return Created("", new
            {
                token = new JwtSecurityTokenHandler().WriteToken(token),
                expiration = token.ValidTo
            });
        }

        static void sendEmail(string rcpt, string otp)
        {
            MailMessage mail = new MailMessage();
            mail.From = new System.Net.Mail.MailAddress("topsales.inf@zohomail.com");
            SmtpClient smtp = new SmtpClient();
            smtp.Port = 587;
            smtp.EnableSsl = true;
            smtp.DeliveryMethod = SmtpDeliveryMethod.Network;
            smtp.UseDefaultCredentials = false;
            smtp.Credentials = new NetworkCredential(mail.From.ToString(), "TopSales123*");
            smtp.Host = "smtp.zoho.com";
            mail.To.Add(new MailAddress(rcpt));
            mail.IsBodyHtml = true;
            mail.Subject = "Top Sales OTP";
            mail.Body = "<div style='background-color: #3f51b5'><h2 style='color: white; text-align: center; padding: 5px'>TopSales</h2></div><p>Your OTP pin: <strong>" + otp + "</strong></p>";
            smtp.Send(mail);
        }

        static string generateOTP()
        {
            Random random = new Random();
            string output = "";
            for (int i = 0; i < 4; i ++)
            {
                output += random.Next(0, 10).ToString();
            }
            return output;
        }

        [HttpPost]
        [Route("register")]
        public async Task<IActionResult> Register(UserViewModel uvm)
        {
            var user = await userManager.FindByNameAsync(uvm.email);
            if (user == null)
            {
                user = new User
                {
                    Id = Guid.NewGuid().ToString(),
                    Email = uvm.email,
                    UserName = uvm.email,
                };

                var result = await userManager.CreateAsync(user, uvm.password);

                if (result.Errors.Count() > 0)
                {
                    return StatusCode(StatusCodes.Status500InternalServerError, new { message = "Internal Error, Account not registered." });
                }
            } 
            else
            {
                return StatusCode(StatusCodes.Status403Forbidden, new { message = "User account already exists." });

            }

            return StatusCode(StatusCodes.Status200OK, new { message = "Registered successfully."});
        }

        static String sha256(String value)
        {
            StringBuilder Sb = new StringBuilder();
            using (SHA256 hash = SHA256Managed.Create())
            {
                Encoding enc = Encoding.UTF8;
                Byte[] result = hash.ComputeHash(enc.GetBytes(value));
                foreach (Byte b in result)
                    Sb.Append(b.ToString("x2"));
            }
            return Sb.ToString();
        }

    }
}
