//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {

  public:

   long long dfs(int node, vector<int> adj[], vector<int> &A, vector<vector<long long>> &dp, bool f){

        if(dp[node][f] != -1e18)

            return dp[node][f];

        long long ans = -1e18;

        for(int child: adj[node]){

            ans = max(ans, dfs(child, adj, A, dp, !f));

        }

        long long nodeVal = A[node-1];

        if(f)

            nodeVal = -nodeVal;

        if(ans == -1e18)

            return dp[node][f] = nodeVal;

        else

            return dp[node][f] = nodeVal + ans;

    }

    long long bestNode(int N, vector<int> &A, vector<int> &P) {

        // code here

        vector<int> adj[N+1];

        for(int i=1; i<N; i++)

            adj[P[i]].push_back(i+1);

        

        vector<vector<long long>> dp(N+1, vector<long long>(2, -1e18));

        long long ans = -1e18;

        for(int i=1; i<=N; i++){

            ans=max(ans,dfs(i, adj, A, dp, 0));

        }

        

        return ans;

    }

 

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends