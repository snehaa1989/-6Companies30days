class Solution {
public:
    int helper(vector<vector<int>> &adj,int start,int level,vector<int>&amount,vector<bool>&visited,vector<int>&nodelevel){
        int ans=0;
        int val=INT_MIN;
        for(int i=0;i<adj[start].size();i++){
            if(!visited[adj[start][i]]){
                visited[adj[start][i]]=true;
                val=max(val,helper(adj,adj[start][i],level+1,amount,visited,nodelevel));
            }
        }
        ans=val;
        if(val==INT_MIN){
            ans=0;
        }
        if(nodelevel[start]==-1){
           ans+=amount[start];
        }
        else if(nodelevel[start]<level){
           ans+=0;
        }
        else if(nodelevel[start]==level){
           ans+=(amount[start]/2);
        }
        else{
           ans+=amount[start];
        }
        return ans;
    }
    void bob_path(int start,int level,vector<int>& nodelevel,vector<vector<int>>& adj,bool &found){
          nodelevel[start]=level;
          if(start==0){
              found=true;
              return;
          }
          for(int i=0;i<adj[start].size();i++){
              if(nodelevel[adj[start][i]]==-1){
                  bob_path(adj[start][i],level+1,nodelevel,adj,found);
                  if(found){
                      return;
                  }
              }
          }
          nodelevel[start]=-1;
          return ;

    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<int> nodelevel(amount.size(),-1);
        vector<vector<int>> adj(amount.size());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool found=false;
        bob_path(bob,0,nodelevel,adj,found);
      
       vector<bool> visited(amount.size(),false);
       visited[0]=true;
        int ans=helper(adj,0,0,amount,visited,nodelevel);
        return ans;
    }
};