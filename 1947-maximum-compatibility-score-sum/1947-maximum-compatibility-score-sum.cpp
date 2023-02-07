class Solution {
public:
     int rec(int st,vector<vector<int>>& students, vector<vector<int>>& mentors,vector<bool> &visit)
     {
         int ans=0;
        int n=mentors.size();
        int m=mentors[0].size();
        if(st>=n)return 0;
         for(int i=0;i<mentors.size();i++)
         {
             if(visit[i])continue;
            int curr=0;
             for(int j=0;j<m;j++)
             {
                 if(students[st][j]==mentors[i][j])
                 curr++;
             }
             visit[i]=true;
             ans=max(ans,curr+rec(st+1,students,mentors,visit));
             visit[i]=false;
         }
         return ans;
     }
        int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
            int n=mentors.size();
           vector<bool>visit(n,false);
            return rec(0,students,mentors,visit);

        }
};