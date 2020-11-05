//https://leetcode.com/problems/score-of-parentheses/
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for(int i=0;i<S.size();i++){
            if(S[i]=='(') st.push(0);
            else{
                if(st.top()==0){
                    st.pop();
                    int score = 1;
                    if(!st.empty()){
                        score += st.top();
                        st.pop();
                    }
                    st.push(score);
                }
                else{
                    int score = st.top(); st.pop();
                    score *= 2;
                    if(!st.empty()) {score += st.top(); st.pop();}
                    st.push(score);
                }
            }
        }
        return st.top();
    }
};
