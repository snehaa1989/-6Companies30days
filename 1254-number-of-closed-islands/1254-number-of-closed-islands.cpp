class Solution {
        private:
            void dfs(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& vis, bool &check){

                vis[row][col]=1;
               int delrow[]={-1,0,1,0};
              int delcol[]={0,1,0,-1};
               int n = grid.size();
              int m = grid[0].size();

            for(int i =0; i<4; i++){
               int nrow = row+delrow[i];
               int ncol = col+delcol[i];
               if(nrow<0 || ncol<0 || nrow>=n || ncol>=m){
                 check = false;
               }
               if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]!=1 
                 && grid[nrow][ncol]==0){
                 dfs(nrow,ncol,grid,vis,check);

               }

            }
            }
public:
    int closedIsland(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      int cnt =0;
      vector<vector<int>>vis(n,vector<int>(m,0));
      
      
      for(int i =0; i<n; i++){
          for(int j = 0; j<m; j++){
              if(grid[i][j]==0 && vis[i][j] != 1){
                bool check =true;
                  dfs(i, j, grid, vis,check);
                  if(check)cnt++;
             }
          }
      }
      return cnt;
    }
};