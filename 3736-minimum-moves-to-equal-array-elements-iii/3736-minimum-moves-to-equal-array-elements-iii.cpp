class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for(int n: nums)
        {
            moves += abs(n-max);
        }
        
        return moves;
    }
};