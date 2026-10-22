class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int pos = -1;
        bool is_inc = true;
        bool is_dec = true;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos = i;
            }
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
                is_inc = false;
            }
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
                is_dec = false;
            }
        }

        int ans = INT_MAX;

        // Case 1: Cyclically increasing
        if (is_inc) {
            int rotate_only = pos;
            int rev_rot_rev = (n - pos) % n + 2;
            ans = std::min({ans, rotate_only, rev_rot_rev});
        }

        // Case 2: Cyclically decreasing
        if (is_dec) {
            int rot_then_rev = (pos + 1) % n + 1;
            int rev_then_rot = n - pos;
            ans = std::min({ans, rot_then_rev, rev_then_rot});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};