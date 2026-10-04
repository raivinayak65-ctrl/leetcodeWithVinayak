class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;

        for (int i = 0; i < word.size(); i++){
            if (word[i] >= 'A' && word[i] <= 'Z'){
                cnt++;
            }
        }
        // all are the small one
        if (cnt == 0 || cnt == word.size()){
            return true;
        }
        // if count is one the it should be the first letter
        if (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z'){
            return true;
        }
        return false;
        }
    
};