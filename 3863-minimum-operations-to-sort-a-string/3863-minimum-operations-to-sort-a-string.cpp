class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // Case 0: If the string is already sorted
        string temp = s;
        sort(temp.begin(), temp.end());
        if (s == temp) return 0;
        
        // Case -1: Length 2 and not sorted cannot be fixed with proper substrings
        if (n == 2) return -1;
        
        char mn = s[0], mx = s[0];
        for (char c : s) {
            mn = min(mn, c);
            mx = max(mx, c);
        }
        
        // Case 1: Minimum is at index 0 (and not whole string) or maximum is at last index
        if (s[0] == mn || s.back() == mx) return 1;
        
        // Case 3: Maximum is uniquely at index 0 and minimum is uniquely at the last index
        if (s[0] == mx && s.back() == mn && count(s.begin(), s.end(), mx) == 1 && count(s.begin(), s.end(), mn) == 1) {
            return 3;
        }
        
        // Case 2: All other cases can be resolved in 2 operations
        return 2;
    }
};