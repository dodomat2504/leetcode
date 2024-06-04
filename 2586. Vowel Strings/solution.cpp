#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    /// @brief 
    /// @param words array of strings
    /// @param left index left
    /// @param right index right
    /// @return Num of vowel strings in range
    int vowelStrings(vector<string>& words, int left, int right) {
        const std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int sum = 0;
        for (int i = left; i <= right; i++) {
            const char l = words[i][0];
            const char r = words[i][words[i].length()-1];

            if (vowels.find(l) != vowels.end() && vowels.find(r) != vowels.end()) {
                sum++;
            }
        }

        return sum;
    }
};