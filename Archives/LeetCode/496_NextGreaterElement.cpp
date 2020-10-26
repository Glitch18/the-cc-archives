class Solution {
public:
    stack<int> greater;

    vector<int> NGEarray(const vector<int> &nums2){
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--){
            if(!greater.empty()) while(greater.top()<nums2[i]){
                greater.pop();
                if(greater.empty()) break;
            }

            if(greater.empty()){
                ans.push_back(-1);
                greater.push(nums2[i]);
                continue;
            }

            ans.push_back(greater.top());
            greater.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge = NGEarray(nums2);
        vector<int> ans;

        for(auto i:nums1){
            ans.push_back(nge[find(nums2.begin(),nums2.end(),i)-nums2.begin()]);
        }

        return ans;
    }
};
