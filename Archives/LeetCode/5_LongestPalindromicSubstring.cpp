//https://leetcode.com/problems/longest-palindromic-substring/submissions/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int mem[n][n];

        for(int i=0;i<n;i++) mem[i][i]=1;

        string ans = s.substr(0,1);

        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(s[i]!=s[j]){
                    mem[i][j]=0;
                    continue;
                }
                //check (i+1,j-1);
                if(j==i+1){
                    mem[i][j]=1;
                    if(j-i+1 > ans.size()) ans = s.substr(i,j-i+1);
                    continue;
                }
                if(mem[i+1][j-1]){
                    mem[i][j]=1;
                    if(j-i+1 > ans.size()) ans = s.substr(i,j-i+1);
                }
                else mem[i][j]=0;
            }
        }
        return ans;
    }
};
