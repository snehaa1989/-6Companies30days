class Solution {
public:
    int dx[4] = {1,1,-1,-1};
    int dy[4] = {1,-1,-1,1};

    int getRhombusSum(int row,int col,vector<vector<int>>& grid,int side){
        int sum=0;
        int k=0;
        if((grid.size()-row-1)<side*2) return -1;
        while(k<side*4){
            sum+=grid[row][col];
            row+=dx[k/side];
            col+=dy[k/side];
            k++;
        }
        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<int> result;
        set<int> sums;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                sums.insert(grid[i][j]);
                if(j==0 || j==cols-1) continue;
                int maxLength = min(j,cols-j-1);
                for(int side=1;side<=maxLength;++side){
                    int rhombusSum = getRhombusSum(i,j,grid,side);
                    if(rhombusSum!=-1) sums.insert(rhombusSum);
                }
            }
        }
        for(auto it=sums.rbegin();it!=sums.rend();++it){
            if(result.size()==3) break;
            result.push_back(*it);
        }
        return result;    
    }
};