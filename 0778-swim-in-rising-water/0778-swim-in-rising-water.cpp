class Solution {
public:
    
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int vis[51][51] = {};
    int n;
    
    bool ok(vector<vector<int>>& grid, int mid, int i, int j){
        
        if(i<0 or i == n or j<0 or j == n or vis[i][j] or grid[i][j] > mid)
            return 0;
        
        if(i == n-1 and j == n-1) return 1;
        
        vis[i][j] = 1;
        
        for(auto& k: dirs){
            int ni = i+k[0], nj = j+k[1];
            
            if(ok(grid, mid, ni, nj)) return 1;
        }
        
        return 0;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        
        n = grid.size();
        
        int lo = 0, hi = n*n-1, ans = -1;
        
        
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;
            
            if(ok(grid, mid, 0, 0)){
                
                ans = mid;
                hi = mid-1;
                
            }
            else lo = mid+1;
            
            memset(vis,false,sizeof(vis));
        }
        
        return ans;
    }
};