class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        
        // Find the maximum possible difference to size our frequency bucket
        int maxDiff = 0;
        vector<int> diffs(n);
        for (int i = 0; i < n; ++i) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            if (diffs[i] > maxDiff) {
                maxDiff = diffs[i];
            }
        }
        
        // Frequency array to count occurrences of each difference
        vector<long long> count(maxDiff + 1, 0);
        for (int d : diffs) {
            count[d]++;
        }
        
        // Greedily reduce the largest differences
        for (int d = maxDiff; d > 0 && totalOps > 0; --d) {
            if (count[d] == 0) continue;
            
            // Number of elements we can reduce from difference d to d - 1
            long long take = min(totalOps, count[d]);
            count[d] -= take;
            count[d - 1] += take;
            totalOps -= take;
        }
        
        // Calculate the minimum sum of squared differences
        long long minSquaredSum = 0;
        for (int d = 0; d <= maxDiff; ++d) {
            if (count[d] > 0) {
                minSquaredSum += count[d] * (long long)d * d;
            }
        }
        
        return minSquaredSum;
    }
};