class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int res = 0;
        for(char ch : s)
        {
            if (ch == '(')
            {
                st.push('(');
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();            
                }
                else 
                {
                    res++;
                }
            }
        }
        if(st.empty())
        {
            return res;
        }
        else{
            while(!st.empty())
            {
                st.pop();
                res++;
            }
            return res;
        }

               
    }
};