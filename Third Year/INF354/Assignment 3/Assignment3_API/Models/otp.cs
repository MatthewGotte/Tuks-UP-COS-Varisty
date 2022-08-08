using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Assignment3_API.Models
{
    public class otp
    {
        public int otpId { get; set; }
        public string UserId { get; set; }
        public string otpCode { get; set; }
    }
}
