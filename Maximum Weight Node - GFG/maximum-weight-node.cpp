//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      vector<int> adj[N];

     //creating a graph

     for(int i = 0 ;i < N ; i++)

     {

         if(Edge[i] != -1)

         adj[Edge[i]].push_back(i);

     }

     int val = 0;

     int ans = 0;

     // checking sum of incoming all nodes on a given node

     for(int i = 0 ; i < N ; i++)

     {

        int  sm  =0;

         for(auto x : adj[i])

         {

            sm = sm+x; 

         }

         if(sm >= val)

         {

             val = sm;

             ans = i;

         }

     }

     return ans;

     

  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends