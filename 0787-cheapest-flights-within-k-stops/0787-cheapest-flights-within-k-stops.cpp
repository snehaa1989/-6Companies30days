class Solution {
public:
    vector<pair<int,int>> ad[105];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(int i=0;i<flights.size();i++)
        {
            ad[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty())
        {
            auto p= q.front();
            q.pop();
            int stop=p.first;
            int u=p.second.first;
            int val=p.second.second;
            if(stop==k+1&&u==dst)
                break;
            if(stop>k+1)
                continue;
            for(auto i: ad[u])
            {
                int v=i.first;
                int d=i.second;
                if(d+val<dis[v] && stop<k+1)
                {
                    dis[v]=d+val;
                    q.push({stop+1,{v,dis[v]}});
                }
            }
        }
        if(dis[dst]==INT_MAX)
        return -1;
        return dis[dst];
    }
};