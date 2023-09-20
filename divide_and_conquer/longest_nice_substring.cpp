#include <iostream>
#include <string>
#include <cassert>
#include <unordered_set>

namespace divide_and_conquer
{
    namespace longest_nice_substring
    {
        /*
            Leetcode 1763. Longest Nice Substring
            A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

            Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
        */

        std::string LongestNiceSubstring(std::string s, int start, int end);

        std::string LongestNiceSubstring(std::string s)
        {
            return LongestNiceSubstring(s, 0, s.size() - 1);
        }

        std::string LongestNiceSubstring(std::string s, int start, int end)
        {
            if (start >= end)
                return "";

            std::unordered_set<char> all_characters;
            for (int i = start; i <= end; i++)
                all_characters.insert(s[i]);

            for (int i = start; i <= end; i++)
            {
                if (!all_characters.count(toupper(s[i])) || !all_characters.count(tolower(s[i])))
                {
                    std::string left = LongestNiceSubstring(s, start, i - 1);
                    std::string right = LongestNiceSubstring(s, i + 1, end);

                    return left.size() >= right.size() ? left : right;
                }
            }

            return s.substr(start, end - start + 1);
        }

        void Test()
        {
            assert(LongestNiceSubstring("YazaAay") == "aAa");
            assert(LongestNiceSubstring("Bb") == "Bb");
            assert(LongestNiceSubstring("c") == "");
            assert(LongestNiceSubstring("dDzeE") == "dD");
            assert(LongestNiceSubstring("aAbBcC") == "aAbBcC");

            std::cout << "All tests passed!\n";
        }
    }
}
