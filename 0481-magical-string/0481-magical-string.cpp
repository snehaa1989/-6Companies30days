class Solution {
public:
    int magicalString(int n) {
        if(n <= 2) return 1;

        string s = "122";
        int i = 2,end=2;
        while(s.size() < n){
            if(s[i] == '1'){
                if(s[end]=='2'){
                    s.push_back('1');
                }
                else{
                    s.push_back('2');
                }
            }
            else{
                if(s[end]=='2'){
                   s += "11";
                }
                else{
                    s += "22";
                }
            }

            i++;
            end = s.size() - 1;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans++;
        }

        return ans;
    }
};