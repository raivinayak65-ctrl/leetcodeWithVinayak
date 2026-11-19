class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i =nums[0], j=nums[nums[0]];
        
        while(i != j)
        {
            i = nums[i];
            j = nums[nums[j]]; // as nums[j] lies in the range of indices
        }

        i=0;
        while(i != j)
        {
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
};