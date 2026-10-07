class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int levelSize = q.size();
            unordered_set<string> currentLevelVisited;

            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front();
                q.pop();

                // If the current string is valid, add it to results
                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                // If we found valid strings at this depth, don't generate deeper levels
                if (found) continue;

                // Generate all possible strings by removing one parenthesis
                for (int j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string next = curr.substr(0, j) + curr.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Stop exploring further levels once valid strings are found
            if (found) break;
        }

        return result;
    }

private:
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};