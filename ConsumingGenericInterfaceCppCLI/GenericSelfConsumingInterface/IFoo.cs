using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericSelfConsumingInterface
{
    public interface IFoo<in t>
    {
        void Bar(t foo);
    }
}
