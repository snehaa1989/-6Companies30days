class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int temp=0;
        //case 1
        for(int i=0;i<n;i++){
            temp+=nums[i];
            ans=max(ans,temp);
            if(temp<0){temp=0;}
        }

        //case 2
        int total=nums[0];
        int mini=nums[0];
        for(int i=1;i<n;i++){
            total+=nums[i];
            nums[i]=nums[i]+min(0,nums[i-1]);
            mini=min(mini,nums[i]);
        }
        if(total!=mini){
            ans=max(ans,total-mini);
        }
        
        return ans;
        
    }
};