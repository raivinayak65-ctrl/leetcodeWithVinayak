class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char ch : s)
        {
            if(ch=='(')
            {
                st.push(0);
            }
            else
            {
                int top = st.top();
                st.pop();
                
                int val = (top == 0) ? 1 : 2 *top;

                st.top() += val;
            }
        }
        return st.top();
    }
};