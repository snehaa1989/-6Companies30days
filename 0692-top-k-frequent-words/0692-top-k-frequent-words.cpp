class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> umap;
        vector<string> ans;
        vector<string> ele;
        vector<int> scr;
        set<int> u;
        for(int i=0;i<words.size();i++){
            umap[words[i]]++;
        }
        
        for(auto x: umap){
            ele.push_back(x.first);
            u.insert(x.second);
        }
        for(auto x: u){
            scr.push_back(x);
        }
        sort(scr.begin(),scr.end());
        
        int count=0;
        int h =scr.size()-1;
        for(int i=0;i<k;i++){
            for(int j=0;j<ele.size();j++){
                if(umap[ele[j]]==scr[h-i]){
                    ans.push_back(ele[j]);
                       count++;
                }
                if(count==k){
                    return ans;
                }
            }   
        }
        return ans;
    }
};