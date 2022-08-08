using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Examination1_SectionA_Question2.ViewModels
{
    public class UserViewModel
    {
        public string Username { get; set; }

        [DataType(DataType.EmailAddress)]
        public string EmailAddress { get; set; }
        public string Password { get; set; }
    }
}
