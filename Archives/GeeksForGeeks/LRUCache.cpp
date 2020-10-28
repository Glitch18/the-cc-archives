//https://practice.geeksforgeeks.org/problems/lru-cache/1
class LRUCache
{
private:
    int size;
    unordered_map<int,int> hash;
    int used;
    vector<int> recent;

public:
    LRUCache(int cap)
    {
        size = cap;
        used=0;
        hash.clear();
        recent.clear();
    }

    int get(int key)
    {
        auto itr = find(recent.begin(),recent.end(),key);
        if(itr==recent.end()) return -1;
        else{
            recent.erase(itr);
            recent.push_back(key);
            return hash[key];
       }
    }

    void set(int key, int value)
    {
        bool present = (hash.find(key)!=hash.end());
        if(present){
            hash[key]=value;
            auto itr = find(recent.begin(),recent.end(),key);
            recent.erase(itr);
            recent.push_back(key);
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
