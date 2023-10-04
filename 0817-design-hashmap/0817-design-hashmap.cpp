class MyHashMap {
public:
    vector<pair<int,int>> m;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        for(auto& x:m){
            if(x.first==key){
                x.second=value;
                return;
            }
        }
        m.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        for(const auto& x:m){
            if(x.first==key){
                return x.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto x=m.begin(); x!=m.end(); x++){
            if(x->first==key){
                m.erase(x);
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */