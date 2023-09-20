#include <iostream>

namespace divide_and_conquer
{
    namespace tower_of_hanoi
    {
        void MoveTower(int n, char start_peg, char intermediate_peg, char dest_peg)
        {
            if (n == 1)
            {
                std::cout << "Move disk 1 from peg " << start_peg << " to peg " << dest_peg << std::endl;
                return;
            }

            MoveTower(n - 1, start_peg, dest_peg, intermediate_peg);
            std::cout << "Move disk " << n << " from peg " << start_peg << " to peg " << dest_peg << std::endl;
            MoveTower(n - 1, intermediate_peg, start_peg, dest_peg);
        }

        void Test()
        {
            MoveTower(3, 'A', 'B', 'C');
        }
    }
}
