class StockSpanner {
public:
    vector<int> v;
    unordered_map<int,int> prev;

    StockSpanner() {
        prev[0]=1;
    }

    int next(int price) {
        v.push_back(price);
        int span=1;
        int index = v.size()-2;

        if(index>=0) while(v[index]<=v.back()){
            span += prev[index];
            index -= prev[index];
            if(index<0) break;
        }
        prev[v.size()-1] = span;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
