#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_HPP
#define DATA_STRUCTURES_PRIORITY_QUEUE_HPP

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
            virtual ~PriorityQueue() = default;
        };
    }
}

#endif // DATA_STRUCTURES_PRIORITY_QUEUE_HPP
