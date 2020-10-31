//https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string open = "{([";
        unordered_map<char,char> close;
        close[')'] = '(';
        close['}'] = '{';
        close[']'] = '[';
        for(auto i:s){
            if(open.find(i)!=string::npos) st.push(i);
            else{
                if(st.empty()) return false;
                if(st.top()!=close[i]) return false;
                st.pop();
            }
        }
        return (st.empty());
    }
};
