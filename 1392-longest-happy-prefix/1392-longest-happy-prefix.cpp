class Solution {
public:
    string longestPrefix(string s) 
    {
        int n = s.size();
        int i=1,j=0;
        vector<int> lps(n,0);
        while(i<n){
            if(s[i] == s[j]){
                 lps[i] = j + 1;
                 i++;
                 j++;
            }
            else{
                if(j > 0){
                    j = lps[j-1];
                }
                else{
                    lps[i] == 0;
                    i++;
                }
            }
        }

        int lenOfPrefixSuffix = lps[n-1];
        string ans = s.substr(0,lenOfPrefixSuffix);
        return ans;
    }
};