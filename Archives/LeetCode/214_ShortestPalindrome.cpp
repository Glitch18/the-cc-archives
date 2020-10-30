//https://leetcode.com/problems/shortest-palindrome/submissions/
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i=0;
        for(int j=n-1;j>=0;j--) if(s[i]==s[j]) i++;

        if(i==n) return s;
        string rem = s.substr(i);
        reverse(rem.begin(),rem.end());
        return rem + shortestPalindrome(s.substr(0,i)) + s.substr(i);
    }
};

//Using KMP
