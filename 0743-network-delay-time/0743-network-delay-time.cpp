class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[src ] = 0;
        
        set<pair<int,int>> st;
        st.insert({0,src});
        
        while(st.size()){
            auto it = *(st.begin());
            int wt = it.first;
            int u = it.second;
            st.erase(it);
            
            for(auto it : adj[u]){
                int v = it.first;
                int edgeweight = it.second;
                
                if(dist[v] > wt + edgeweight){
                    if(dist[v] != INT_MAX) 
                        st.erase({dist[v],v});
                    dist[v] = wt + edgeweight;
                    st.insert({dist[v],v});
                }
            }     
        }
        int distance = INT_MIN;
            for(int i = 1;i<=n;i++){
                if(dist[i] == INT_MAX) return -1;
                distance = max(distance,dist[i]);
            }
            return distance;
    }
};