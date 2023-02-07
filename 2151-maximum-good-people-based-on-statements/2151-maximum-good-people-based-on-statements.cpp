class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans=0;
        for(int i=1; i<(1<<statements.size()); i++){
            int chk=1;
            for(int j=0; j<statements.size(); j++){
                if(!(i&(1<<j))){
                    continue;
                }
                for(int k=0; k<statements.size(); k++){
                    if((i&(1<<k)) && statements[j][k]==0){
                        chk=-1; break;
                    }
                    else if(!(i&(1<<k)) && statements[j][k]==1){
                        chk=-1; break;
                    }
                }
                if(chk==-1){break;}
            }
            if(chk==1){
                int cnt=0;
                int n1=i;
                while(n1>0){
                    if(1&n1){cnt++;}
                    n1=n1>>1;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};