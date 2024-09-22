class RandomizedSet {
    set<int> s;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()){
            s.insert(val);
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
            s.erase(val);
            return true;
        }    
        else
            return false;
    }
    
    int getRandom() {
        int n = s.size();
        int curr = rand() % n;
        int i = 0;
        for(set<int>::iterator it = s.begin(); it != s.end(); it++){
            if(i == curr)
                return *it;
            i++;
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */