//https://leetcode.com/problems/lru-cache/
class LRUCache {
    unordered_map<int,int> hash;
    vector<int> recent;
    int size;
    int used;
public:
    LRUCache(int capacity) {
        size = capacity;
        used = 0;
        hash.clear();
        recent.clear();
    }

    int get(int key) {
        auto itr = find(recent.begin(),recent.end(),key);
        if(itr==recent.end()) return -1;
        recent.erase(itr);
        recent.push_back(key);
        return hash[key];
    }

    void put(int key, int value) {
        bool present = (hash.find(key)!=hash.end());
        if(present){
            auto itr = find(recent.begin(),recent.end(),key);
            recent.erase(itr);
            recent.push_back(key);
            hash[key]=value;
        }
        else{
            if(used==size){
                hash.erase(recent[0]);
                recent.erase(recent.begin());
                used--;
            }
            hash[key]=value;
            recent.push_back(key);
            used++;
        }
    }
};
