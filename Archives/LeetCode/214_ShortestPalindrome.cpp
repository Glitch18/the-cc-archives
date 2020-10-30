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
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        string new_s = s + "#" + rev;
        int j=0;

        vector<int> lookup = {0};

        for(int i=1;i<new_s.size();i++){
            while(j>0 && new_s[j]!=new_s[i]) j = lookup[j-1];
            if(new_s[j]==new_s[i]) j++;
            lookup.push_back(j);
        }

        return (rev.substr(0,n-lookup[new_s.size()-1])+s);
    }
};
