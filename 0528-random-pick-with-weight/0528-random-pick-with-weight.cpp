class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for(int i = 1; i < w.size(); i++) w[i] += w[i - 1];
        v = w;
    }

    int pickIndex() {
        return upper_bound(begin(v), end(v), rand() % v.back()) - begin(v);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */