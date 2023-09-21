#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

namespace others
{
    namespace merge_k_sorted_lists
    {
        struct ListNode
        {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
            ~ListNode()
            {
                if (next != nullptr)
                    delete next;
            }
        };

        ListNode *MergeKSortedLists(const std::vector<ListNode *> &lists)
        {
            std::vector<ListNode *> heap;
            // By default, it generates the max heap but we can use a custom comparator to change it to the min heap.
            bool (*comparator)(ListNode *, ListNode *) =
                [](ListNode *a, ListNode *b)
            { return a->val > b->val; };

            {
                // Initialize heap
                for (ListNode *list : lists)
                    if (list)
                        heap.push_back(list);
                std::make_heap(heap.begin(), heap.end(), comparator);
            }

            ListNode *head = nullptr;
            ListNode *cur = nullptr;
            while (!heap.empty())
            {
                std::pop_heap(heap.begin(), heap.end(), comparator);

                ListNode *min_node = heap.back();
                heap.pop_back();

                if (min_node->next)
                {
                    heap.push_back(min_node->next);
                    std::push_heap(heap.begin(), heap.end(), comparator);
                }
                if (!head)
                {
                    head = new ListNode(min_node->val);
                    cur = head;
                }
                else
                {
                    cur->next = new ListNode(min_node->val);
                    cur = cur->next;
                }
            }

            return head;
        }

        void Test()
        {
            ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
            ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
            ListNode *l3 = new ListNode(2, new ListNode(6));
            std::vector<ListNode *> lists{l1, l2, l3};
            ListNode *merged = MergeKSortedLists(lists);
            for (ListNode *cur = merged; cur->next; cur = cur->next)
                assert(cur->val <= cur->next->val);

            delete l1;
            delete l2;
            delete l3;
            delete merged;

            std::cout << "All tests passed" << std::endl;
        }
    }
}
