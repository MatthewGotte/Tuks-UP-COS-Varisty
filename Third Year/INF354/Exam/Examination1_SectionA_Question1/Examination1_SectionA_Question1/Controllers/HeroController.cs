using Examination1_SectionA_Question1.Models;
using Examination1_SectionA_Question1.ViewModels;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Threading.Tasks;

namespace Examination1_SectionA_Question1.Controllers
{

    [ApiController]
    [Route("api/[controller]")]
    public class HeroController : Controller
    {

        private readonly IRepository _repository;

        public HeroController(IRepository repo)
        {
            this._repository = repo;
        }

        [HttpPost]
        [Route("AddHeroWithQuotes")]
        public async Task<IActionResult> AddHeroWithQuotes(HeroViewModel hero)
        {
            try
            {

                this._repository.Add(new Hero
                {
                    Firstname = hero.Firstname,
                    Lastname = hero.Lastname,
                    Character = hero.Character,
                    Age = hero.Age,
                    Birthday = hero.Birthday,
                    Quote = hero.Quotes
                });

                var res = await this._repository.SaveChangesAsync();

                if (res)
                {
                    return Ok("Hero saved to the database");
                }
                else
                {
                    return BadRequest("Invalid Transaction");
                }
            }
            catch (Exception e)
            {
                return BadRequest("Invalid Transaction");
            }
        }

    }
}
