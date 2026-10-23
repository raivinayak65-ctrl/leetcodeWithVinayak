class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // Initialize with all bits set (-1 in two's complement is all 1s)
        int k = -1; 
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                k &= nums[i];
            }
        }
        
        // If k is still -1, no elements were misplaced (already sorted)
        return k == -1 ? 0 : k;
    }
};