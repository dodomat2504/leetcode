#include <iostream>
#include <cmath>


int myAtoi(const std::string& s) {
    int index = 0;
    const int maxLen = s.length();

    // ignore leading whitespaces
    while (s[index] == ' ')
        if (index+1 < maxLen)
            index++;
        else
            return 0;

    std::string numString = "";

    // get or assume sign
    bool positive = true;
    if (s[index] == '+' || s[index] == '-')
        positive = s[index++] == '+';
    
    // remove leading zeros
    while (s[index] == '0')
        if (index+1 < maxLen)
            index++;
        else
            return 0;

    // get rest of digits
    while (index < maxLen) {
        const char c = s[index++];
        if (c < '0' || c > '9')
            break;

        numString += c;
        if (numString.length() > 10)
            return positive ? INT32_MAX : INT32_MIN;
    }

    if (numString.length() == 0)
        return 0;

    long long result = 0;
    for (int i = 0; i < numString.length(); i++) {
        result += (pow(10, i) * (numString[numString.length() - 1 - i] - '0'));
    }

    if (positive)
        return result < INT32_MAX ? (int) result : INT32_MAX;
    else
        return (-1 * result) > INT32_MIN ? (int) (-1 * result) : INT32_MIN;
}

int main() {
    int nums[3];
    const std::string s1 = "42";
    const std::string s2 = "   -42";
    const std::string s3 = "4193 with words";
    
    nums[0] = myAtoi(s1);
    nums[1] = myAtoi(s2);
    nums[2] = myAtoi(s3);

    for (const int i : nums)
        std::cout << "output: " << std::to_string(i) << std::endl;

    return 0;
}
