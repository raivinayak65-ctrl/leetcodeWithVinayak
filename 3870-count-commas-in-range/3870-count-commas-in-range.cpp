class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        long long current = 1000;
        while (n >= current) {
            count += (n - current + 1);
            current *= 1000;
        }
        return count;
    }
};