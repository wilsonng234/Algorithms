#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>

namespace divide_and_conquer
{
    namespace longest_substring_with_at_least_k_repeating_characters
    {
        /*
            Leetcode 395. Longest Substring with At Least K Repeating Characters
            Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

            if no such substring exists, return 0.
        */

        int LongestSubstringWithAtLeastKRepeatingCharacters(const std::string &s, int k, int start, int end);

        int LongestSubstringWithAtLeastKRepeatingCharacters(const std::string &s, int k)
        {
            return LongestSubstringWithAtLeastKRepeatingCharacters(s, k, 0, s.size() - 1);
        }

        int LongestSubstringWithAtLeastKRepeatingCharacters(const std::string &s, int k, int start, int end)
        {
            if (start > end)
                return 0;
            if (start == end)
                return k == 1;

            std::unordered_map<char, int> frequency_map;

            for (int i = start; i <= end; i++)
            {
                char c = s[i];

                if (!frequency_map.count(c))
                    frequency_map.insert({c, 1});
                else
                    frequency_map[c]++;
            }

            for (int i = start; i <= end; i++)
            {
                if (frequency_map[s[i]] < k)
                {
                    int left = LongestSubstringWithAtLeastKRepeatingCharacters(s, k, start, i - 1);
                    int right = LongestSubstringWithAtLeastKRepeatingCharacters(s, k, i + 1, end);

                    return std::max(left, right);
                }
            }

            return end - start + 1;
        }

        void Test()
        {
            assert(LongestSubstringWithAtLeastKRepeatingCharacters("aaabb", 3) == 3);
            assert(LongestSubstringWithAtLeastKRepeatingCharacters("ababbc", 2) == 5);
            assert(LongestSubstringWithAtLeastKRepeatingCharacters("ababacb", 3) == 0);
            assert(LongestSubstringWithAtLeastKRepeatingCharacters("bbaaacbd", 3) == 3);

            std::cout << "All tests passed!\n";
        }
    }
}
