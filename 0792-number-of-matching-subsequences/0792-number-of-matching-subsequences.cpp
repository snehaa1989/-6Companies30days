class Solution {
public:
map<char,vector<int>> count;
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i=0;i<s.size();i++){
            count[s[i]].push_back(i);
        }
        int z=0;
        for(auto& x:words){
            int p=-1;
            int r=0;
            for(int j=0;j<x.size();j++){
                if(count.find(x[j])==count.end()){r=1;break;}
                if(upper_bound(count[x[j]].begin(),count[x[j]].end(),p)==count[x[j]].end()){r=1;break;}
                p=count[x[j]][upper_bound(count[x[j]].begin(),count[x[j]].end(),p)-count[x[j]].begin()];
                }
            if(r==0)z+=1;
        }
        return z;
    }
};