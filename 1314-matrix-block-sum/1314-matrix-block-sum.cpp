class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=mat[i][j];
                mat[i][j]=sum;
            }
        }
        int minRow,minCol,maxRow,maxCol,currSum;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                minRow=max(0,i-k);
                maxRow=min(m-1,i+k);
                minCol=max(0,j-k);
                maxCol=min(n-1,j+k);
                currSum=0;
                for(int k=minRow;k<=maxRow;k++)
                {
                    currSum+=mat[k][maxCol];
                    if(minCol>0)
                        currSum-=mat[k][minCol-1];
                }
                ans[i][j]=currSum;
            }
        }
        return ans;
    }
};