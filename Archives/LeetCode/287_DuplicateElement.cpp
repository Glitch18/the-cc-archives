//https://leetcode.com/problems/find-the-duplicate-number/

//Other solutions to this are-

//n2 two loop
//sort and traverse
//hashmap
//slow and fast
//this one below
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])]<0) return abs(nums[i]);
            else nums[abs(nums[i])] = -1 * nums[abs(nums[i])];
        }
        return -1;
    }
};

//slow fast approach:-

int findDuplicate(vector<int>& nums) {
    int slow,fast;
    slow = nums[0];
    fast = nums[0];

    slow = nums[slow];
    fast = nums[nums[fast]];

    while(slow!=fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}
