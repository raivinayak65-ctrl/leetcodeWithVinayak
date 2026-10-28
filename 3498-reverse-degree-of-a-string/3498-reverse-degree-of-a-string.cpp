class Solution {
public:
    int reverseDegree(string s) {
        int x = 0;
        int i = 1; 
        for(char ch: s)
        {
            x += ('z' - ch +1) * i;
            i++;
        }
        return x;
    }
};