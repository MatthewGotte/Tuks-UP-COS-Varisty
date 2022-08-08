using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Examination1_SectionA_Question1.Models
{
    public interface IRepository
    {
        void Add<T>(T entity) where T : class;
        Task<bool> SaveChangesAsync();
    }
}
