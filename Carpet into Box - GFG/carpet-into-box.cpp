//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{

    public:

    

    int find(int a,int b)

    {

        int ans=0;

        

        while(a>b)

        {

            ans++;

            a=(a/2);

        }

        

        return ans;

    }

    int carpetBox(int A, int B, int C, int D)

    {

        return min(find(A,C)+find(B,D),find(A,D)+find(B,C));    

    }

};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends