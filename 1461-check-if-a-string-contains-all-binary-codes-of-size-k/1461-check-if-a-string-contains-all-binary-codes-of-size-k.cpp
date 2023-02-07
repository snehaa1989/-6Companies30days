class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k){return false;}
        set<string>s1;
        for(int i=0; i<s.size()-k+1; i++){
            s1.insert(s.substr(i, k));
        }
        return s1.size()==pow(2, k);
    }
};