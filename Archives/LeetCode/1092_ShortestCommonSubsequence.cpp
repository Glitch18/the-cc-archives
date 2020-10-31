//https://leetcode.com/problems/shortest-common-supersequence/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        int mem[m+1][n+1];

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0) mem[i][j] = j;
                else if(j==0) mem[i][j] = i;

                else if(str1[i-1]==str2[j-1]) mem[i][j] = 1 + mem[i-1][j-1];

                else mem[i][j] = 1 + min(mem[i-1][j],mem[i][j-1]);
            }
        }

        int i=m,j=n;
        string ans = "";

        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                ans += str1[i-1];
                i--; j--;
            }

            else if(mem[i-1][j]<mem[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0) ans += str1[--i];
        while(j>0) ans += str2[--j];

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
