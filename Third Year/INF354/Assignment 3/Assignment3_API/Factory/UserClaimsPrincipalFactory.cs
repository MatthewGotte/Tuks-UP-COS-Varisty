using Assignment3_API.Models;
using Microsoft.AspNetCore.Identity;
using Microsoft.Extensions.Options;

namespace Assignment3_API.Factory
{
    public class UserClaimsPrincipalFactory : UserClaimsPrincipalFactory<User, IdentityRole>
    {
        public UserClaimsPrincipalFactory(UserManager<User> userManager, RoleManager<IdentityRole> roleManager, IOptions<IdentityOptions> optionsAccessor) : base(userManager, roleManager, optionsAccessor)
        {

        }
    }
}
