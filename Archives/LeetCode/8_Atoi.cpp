//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s){
        int ans = 0;
        bool isNegative=false;
        string valid = "0123456789";
        int i=0;

        while(s[i]==' ') i++;
        if(s[i]=='-') isNegative=true;
        if(s[i]=='+' || s[i]=='-') i++;
        if(valid.find(s[i])==string::npos) return 0;

        while(valid.find(s[i])!=string::npos){
            ans = ans*10 + (s[(i++)]-48);
            if(ans>INT_MAX/10)
                if(valid.find(s[i])!=string::npos)
                    return (isNegative) ? INT_MIN : INT_MAX;
            if(ans==INT_MAX/10 && (s[i]=='8'||s[i]=='9'))
                    return (isNegative) ? INT_MIN : INT_MAX;
        }

        if(valid.find(s[i])!=string::npos)
          return (isNegative) ? INT_MIN : INT_MAX;

        if(isNegative) ans *= -1;
        return ans;
    }
};
