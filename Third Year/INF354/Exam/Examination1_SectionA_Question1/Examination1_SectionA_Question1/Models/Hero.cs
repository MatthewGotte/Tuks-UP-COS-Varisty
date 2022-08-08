using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Examination1_SectionA_Question1.Models
{
    public class Hero
    {
        public int HeroId {get;set;}
        public string Firstname { get; set; }
        public string Lastname { get; set; }
        public string Character { get; set; }
        public int? Age { get; set; }

        [DataType(DataType.Date)]
        public DateTime? Birthday { get; set; } 
        public virtual ICollection<Quote> Quote { get; set; }
    }
}
