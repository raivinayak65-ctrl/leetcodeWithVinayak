#include <unordered_set>
#include <vector>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        
        // Outer loop for the starting index of the subarray
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinct_elements;
            // Inner loop for the ending index of the subarray
            for (int j = i; j < n; ++j) {
                distinct_elements.insert(nums[j]);
                int count = distinct_elements.size();
                total_sum += count * count;
            }
        }
        
        return total_sum;
    }
};