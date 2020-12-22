//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> prev;
        int ans = 0;
        int i=0,j=0;
        
        while(j<s.size()){
            if(prev.find(s[j]) != prev.end()) i = max(prev[s[j]]+1,i);
            prev[s[j]] = j;
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};
