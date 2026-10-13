class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i < n; i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        
        int mid = (n/2);
        long long int res =0;
        for(int i = 0; i < mid; i++)
        {
            res -= nums[i];
        }
        for(int i=mid; i < n; i++ )
        {
            res+= nums[i];
        }
        return res;
    }
};