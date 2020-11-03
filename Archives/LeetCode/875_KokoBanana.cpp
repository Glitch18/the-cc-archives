//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int answer;
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int K = low + (high-low)/2;
            long long st = 0;
            for(auto ai:piles){
                st += (ai+K-1)/K;
            }
            if(st <= H){
                answer=K;
                high = K-1;
            }
            else low = K+1;
        }
        return answer;
    }
};
