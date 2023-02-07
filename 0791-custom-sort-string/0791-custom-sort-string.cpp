class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        unordered_map<char, int>m, m1;
        for(int i=0; i<s.size(); i++){m[s[i]]++;}
        for(int i=0; i<order.size(); i++){
            if(m.find(order[i])!=m.end()){
                while(m[order[i]]){
                    ans+=order[i];
                    m[order[i]]--;
                    m1[order[i]]++;
                }
            }
        }
        for(int i=0; i<s.size(); i++){
            if(m1.find(s[i])==m1.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};