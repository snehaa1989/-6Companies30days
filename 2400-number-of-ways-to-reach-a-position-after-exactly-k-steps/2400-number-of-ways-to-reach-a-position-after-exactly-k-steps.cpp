class Solution {
public:
    int dp(int currPos,int &endPos, int remainingSteps,vector <vector <int>> &cache){
        if(currPos==endPos && remainingSteps==0)
            return 1;
        
        if(remainingSteps<=0)
            return 0;
        
        int &ans=cache[currPos][remainingSteps];
        
        if(ans!=-1)
            return ans;
        
        return ans=(dp(currPos+1,endPos,remainingSteps-1,cache)+dp(currPos-1,endPos,remainingSteps-1,cache))%1000000007;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1200;
        endPos+=1200;
        
        vector <vector <int>> cache(4000,vector <int> (k+1,-1));
        return dp(startPos,endPos,k,cache);
    }
};