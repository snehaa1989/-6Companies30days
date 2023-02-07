class Solution {
public:
    vector<string> ans;
    void recurse(string res,string curr,int index,string s){
        if(index==s.length()){
            if(curr.empty() and count(res.begin(),res.end(),'.')==3){
                ans.push_back(res);
            }
            return;
        }
        if(!curr.empty() and stoi(curr)==0){
            return;
        }
        curr.push_back(s[index]);
        if(stoi(curr)>255){
            return;
        }
        recurse(res,curr,index+1,s);
        if(!res.empty()){
            recurse(res+"."+curr,"",index+1,s);
        }
        else{
            recurse(curr,"",index+1,s);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        recurse("","",0,s);
        return ans;
    }
};