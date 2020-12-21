//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
    unordered_set<int> prev;
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        for(int i=0;i<s.size();i++){
            int count = 0;
            for(int j=i;j<s.size();j++){
                if(prev.find(s[j])!=prev.end()) break;
                else count++;
                prev.insert(s[j]);
            }
            if(count > length) length = count;
            prev.clear();
        }
        return length;
    }
};
