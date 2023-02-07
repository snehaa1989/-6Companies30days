class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> leftLimit(n), rightLimit(n);
        vector<long long>prefixSum(n+1, 0);
        
        stack<int> stk;
        for(int i=0; i<n; i++){
            while(!stk.empty() && nums[stk.top()] >= nums[i]){
                stk.pop();
            }
            leftLimit[i] = stk.empty() ? 0 : stk.top() + 1;
            stk.push(i);
            
            prefixSum[i+1] = prefixSum[i] + (long long)nums[i];
        }
        
        while(!stk.empty()) stk.pop();
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && nums[stk.top()] >= nums[i]){
                stk.pop();
            }
            rightLimit[i] = stk.empty() ? n-1 : stk.top() - 1;
            stk.push(i);
        }
        
        long long maxMinProduct = 0;
        for(int i=0; i<n; i++){
            long long rangeSum = prefixSum[rightLimit[i]+1] - prefixSum[leftLimit[i]];
            long long curMinProduct = (long long)nums[i]*rangeSum;
            maxMinProduct = max(maxMinProduct, curMinProduct);
        }
        return maxMinProduct % 1000000007;
    }
};