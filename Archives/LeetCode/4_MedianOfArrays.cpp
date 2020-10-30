//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i=0,j=0;
        while(i<nums1.size() || j<nums2.size()){
            if(i==nums1.size()) merged.push_back(nums2[j++]);
            else if(j==nums2.size()) merged.push_back(nums1[i++]);
            else if(nums1[i]<=nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        double ans;
        if(merged.size()%2==0) ans =\
                    (double)(merged[merged.size()/2]+merged[merged.size()/2-1])/2;
        else ans = merged[merged.size()/2];
        return ans;
    }
};
