class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans= INT_MAX;
        unordered_map<int,int> mp;
        for (int i=0; i<cards.size(); i++){
            if (mp.find(cards[i]) != mp.end()){
                ans= min(ans,i-mp[cards[i]]+1);
            }
            mp[cards[i]]= i;
        }
        if (ans==INT_MAX)return -1;
        return ans;
    }
};