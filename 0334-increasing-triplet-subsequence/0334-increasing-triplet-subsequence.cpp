class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long a = 1e10, b = 1e10;
        for (int i : nums) {
            if (i > b) return true;
            if (i > a) b = min((long long) i, b);
            a = min((long long) i, a);
        }
        return false;
    }
};