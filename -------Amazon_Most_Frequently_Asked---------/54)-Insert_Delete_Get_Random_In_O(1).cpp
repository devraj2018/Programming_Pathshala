class RandomizedSet {
public:
    vector<int>arr;
    unordered_map<int,int>mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
     }
    
    bool remove(int val) {
         if(mp.find(val)==mp.end()) return false;
         
         int to_remove=val;
         int to_swap=arr[arr.size()-1];
         swap(arr[mp[val]],arr[arr.size()-1]);
         mp[to_swap]=mp[to_remove];
         mp.erase(to_remove);
         arr.pop_back();
         return true;
     }
    
    int getRandom() {
         return arr[rand()%arr.size()];
     }
};