class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = 0, n = nums.size();
        for(int i : numsDivide) g = __gcd(g, i);
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(g % nums[i] == 0) return i;
        }
        return -1;
    }
};