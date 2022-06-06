class TimeMap {
public:
    unordered_map<string,map<int,string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key][timestamp]=value;
     }
     string get(string key, int timestamp) {
        
         auto ub= mp[key].upper_bound(timestamp);
         if(ub==mp[key].begin()) return "";
         ub--;
         return ub->second;
        
         
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */