class Solution {
public:
    int dp[1001][1001] = {0};
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }
        if(dp[i][j]>0)
            return dp[i][j];
        
        int ans = INT_MIN;
        if(nums1[i]==nums2[j])
            return dp[i][j] = 1 + helper(nums1, nums2, i+1, j+1);
        else{
            return 0;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = -1;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                m = max(m,helper(nums1, nums2, i, j));
            }
        }
        
        return m;
    }
};