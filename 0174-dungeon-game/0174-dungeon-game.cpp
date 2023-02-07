class Solution {
public:
 
int f(int i ,int j,vector<vector<int>>&d,vector<vector<int>>&dp){
    if(i==d.size()||j==d[0].size()){
        return 1e9;
    }
    if(i==d.size()-1&&j==d[0].size()-1){
        if(d[i][j]<0){
            return abs(d[i][j])+1;
        }
        else{
            return 1;
        }
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(d[i][j]<0){
        int r=abs(d[i][j])+f(i,j+1,d,dp);
        int l=abs(d[i][j])+f(i+1,j,d,dp);
        return dp[i][j]= min(l,r);
    }
    else{
        int r=d[i][j]-f(i,j+1,d,dp);
        int l=d[i][j]-f(i+1,j,d,dp);
        if(r>=0||l>=0) return dp[i][j]=1;
        else{
            return dp[i][j]=min(abs(l),abs(r));
        }
    }
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
     vector<vector<int>>dp(dungeon.size(),vector<int>(dungeon[0].size(),-1));
       return f(0,0,dungeon,dp); 
    }
};