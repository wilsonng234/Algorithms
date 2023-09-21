#include <vector>

namespace data_structures
{
    namespace priority_queue
    {
        template <typename Comparable>
        class PriorityQueue
        {
        public:
            virtual void Insert(Comparable element) = 0;
            virtual Comparable ExtractMin() = 0;
        };
    }
}
