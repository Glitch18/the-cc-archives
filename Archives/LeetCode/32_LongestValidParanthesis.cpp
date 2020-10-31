//https://leetcode.com/problems/longest-valid-parentheses/submissions/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int max = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                if(i-st.top()>max) max = i-st.top();
            }
        }
        return max;
    }
};
