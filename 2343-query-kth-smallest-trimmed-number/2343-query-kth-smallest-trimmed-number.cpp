class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int>ans;
        for(auto x:queries)
        {
            int k=x[0];
            int change=x[1];
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<nums.size();i++)
            {
                string str=nums[i].substr(nums[i].size()-change);
                pq.push({str,i});
                if(pq.size()>k)pq.pop();                
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};