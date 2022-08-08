using System.ComponentModel.DataAnnotations;

namespace Assignment3_API.ViewModels
{
    public class UserViewModel
    {
        [DataType(DataType.EmailAddress)]
        public string email { get; set; }
        public string password { get; set; }
    }
}
