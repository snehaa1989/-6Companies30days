class Solution {
public:
    int help(int delay,int forget,int n,vector<int> &dp){
        int mod=1e9+7;
        int a = forget;
        a -= delay;
        if(dp[n] != -1) return dp[n];
        int j=0;
        int sum=0;
        while(a>0 && n-delay-j>0){
            a--;
            sum += ((long)help(delay,forget,n-delay-j,dp)%mod);
            sum = sum%mod;
            j++;
        }
        if(n-forget>0){
            dp[n] = (sum%mod);
        }
        else{
            dp[n] = ((sum+1)%mod);
        }
        return dp[n];
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,-1);
        return help(delay,forget,n,dp); 
    }
};