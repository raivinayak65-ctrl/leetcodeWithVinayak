#include <string>

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // A number with 'num' digits can have at most a sum of 9 * num
        if (sum > 9LL * num || sum < 1) {
            return "";
        }

        int count9 = sum / 9;
        int rem = sum % 9;

        string result = "";
        result.reserve(num);

        // 1. Add all the 9s
        result.append(count9, '9');

        // 2. Add the remainder digit if it exists
        if (rem > 0) {
            result.push_back('0' + rem);
        }

        // 3. Fill the remaining positions with '0'
        int zeros = num - result.length();
        if (zeros > 0) {
            result.append(zeros, '0');
        }

        return result;
    }
};