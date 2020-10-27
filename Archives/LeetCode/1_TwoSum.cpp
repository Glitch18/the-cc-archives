#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> store;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            auto itr = store.find(target-nums[i]);
            if(itr!=store.end() && itr->second!=i){
                ans = {i,itr->second};
                break;
            }
            store[nums[i]]=i;
        }
        return ans;
    }
};
