using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Examination1_SectionA_Question1.Models
{
    public class Repository : IRepository
    {
        private readonly AppDbContext _appDbContext;
        public Repository(AppDbContext appDbContext)
        {
            _appDbContext = appDbContext;
        }
        public void Add<T>(T entity) where T : class
        {
            _appDbContext.Add(entity);
        }

        public async Task<bool> SaveChangesAsync()
        {
            return await _appDbContext.SaveChangesAsync() > 0;
        }
    }
}
