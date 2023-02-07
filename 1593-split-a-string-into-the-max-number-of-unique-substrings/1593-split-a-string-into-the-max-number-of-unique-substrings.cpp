class Solution {
public:
   void helper(string s,int& ans,set<string>st,int ind,int n)
   {
     if (ind>=n)
     {
         int curr=st.size();
         if (curr>ans)
         {
         ans=max(ans,curr);
         for (auto it:st)
         {
             cout<<it<<" ";
         }
         }
     }
     for (int i=ind;i<n;i++)
     {
         if (st.find(s.substr(ind,ind-i+1))==st.end())
         {
             string temp=s.substr(ind,i-ind+1);
             st.insert(temp);
             helper(s,ans,st,i+1,n);

            st.erase(temp);
         }
     }
   }
    int maxUniqueSplit(string s) {
        set<string>st;
        int ans=INT_MIN;
        int n=s.size();
        helper(s,ans,st,0,n);
        return ans;
    }
};