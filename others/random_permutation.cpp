#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

namespace others
{
    namespace random_permutation
    {
        template <typename T>
        void RandomPermutation(std::vector<T> &v)
        {
            int n = v.size();

            for (int i = 0; i < n; ++i)
                std::swap(v[i], v[rand() % n]);
        }

        void Test()
        {
            srand(time(NULL));

            for (int i = 0; i < 10; ++i)
            {
                std::vector<int> v = {1, 2, 3, 4, 5};
                RandomPermutation(v);

                for (auto &x : v)
                    std::cout << x << " ";
                std::cout << std::endl;
            }
        }
    }
}
