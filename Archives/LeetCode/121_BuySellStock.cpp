//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int min = prices[0];
        int diff = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-min>diff) diff = prices[i]-min;
            if(prices[i]<min) min = prices[i];
        }
        return diff;
    }
};

//Not recommended :-

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        set<int> prev;
        prev.insert(prices[0]);
        int diff = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-*prev.begin() > diff) diff = prices[i] - *prev.begin();
            prev.insert(prices[i]);
        }
        return diff;
    }
};
