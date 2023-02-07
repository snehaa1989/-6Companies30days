class Solution
{
public:
    typedef pair<string, int> pi;
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        unordered_map<string, long long> m1; //{creator,total views}
        unordered_map<string, pi> m2;  //{creator, id with max view}
        int n = creators.size();
        for (int i = 0; i < n; i++)
        {
            string s = creators[i];
                m1[s] += views[i];
            if (m2.find(s) != m2.end())
            {
                if (views[i] == m2[s].second)
                {
                    m2[s].first = min(m2[s].first, ids[i]);
                }
                else if (views[i] > m2[s].second)
                {
                    m2[s] = {ids[i], views[i]};
                } 
            }
            else
            {
                m2[s] = {ids[i], views[i]};
            }
        }
        long long m = 0;
        for (auto &x : m1)
            m = max(m, x.second);
        vector<vector<string>> v;
        for (auto &x : m1)
        {
            if (x.second == m)
            {
                string s = x.first;
                string id = m2[s].first;
                v.push_back({s, id});
            }
        }
        return v;
    }
};