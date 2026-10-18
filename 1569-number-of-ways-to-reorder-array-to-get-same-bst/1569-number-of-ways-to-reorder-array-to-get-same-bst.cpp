class Solution {
private:
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    // Helper to compute binomial coefficients using Pascal's triangle
    long long combination(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (table[n][k] != -1) return table[n][k];
        return table[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % MOD;
    }

    long long solve(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        std::vector<int> left_sub, right_sub;
        int root = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left_sub.push_back(nums[i]);
            } else {
                right_sub.push_back(nums[i]);
            }
        }

        long long left_ways = solve(left_sub);
        long long right_ways = solve(right_sub);

        int L = left_sub.size();
        int R = right_sub.size();

        // Ways to merge left and right subtrees: C(L + R, L)
        long long ways = combination(L + R, L);
        
        // Multiply by the ways to form left and right subtrees
        ways = (ways * left_ways) % MOD;
        ways = (ways * right_ways) % MOD;

        return ways;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        // Initialize Pascal's triangle memoization table
        table = std::vector<std::vector<long long>>(n + 1, std::vector<long long>(n + 1, -1));
        
        // Subtract 1 because the problem asks for reorderings *other than* the original array
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
