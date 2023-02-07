class Solution {
public:
    bool f(vector<int>&nums,vector<bool>&visited,int i,int target,int curr_sum,int k)
    {
        if(k==1) return true;
        if(i>=nums.size()) return false; 
        if(curr_sum==target)
        return f(nums,visited,0,target,0,k-1);
        for(int j=i;j<nums.size();j++)
        {
            if(visited[j]==false && curr_sum+nums[j]<=target)
            {
                visited[j] = true;
                if(f(nums,visited,j+1,target,curr_sum+nums[j],k)) return true;
                visited[j] = false;
            }
        }
     return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         int sum = 0;
         for(int i=0;i<nums.size();i++) sum+=nums[i];
         if(nums.size()<k || sum%k!=0) return false;
         vector<bool>visited(nums.size(),false);
         return f(nums,visited,0,sum/k,0,k);
    }
};