class Solution {
public:
int M= 1e9+7;
    int reverse(int n){
        int ans=0;
        while (n>0){
            ans*=10;
            ans+= (n%10);
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        map<int,long> mp;
        for (int i=0; i<nums.size(); i++){
            mp[nums[i]-reverse(nums[i])]++;
        }
        long long ans=0;
        for (auto val: mp){
            ans= (ans+((val.second)*(val.second-1))/2)%M;
            /* if (val.second&1){
                ans+= ((val.second%M)*((val.second-1)/2)%M)%M;
            }
            else{
                ans+= (((val.second-1)%M)*((val.second/2)%M))%M;
            } */
            ans= ans%M;
        }
        return ans;
    }
};