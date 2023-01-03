class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        string res = "";
        int a = 0, b = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < n; i++)
        {
            

            if(secret[i] == guess[i])
            {
                a++;
                
                
            }
            else
            {
                m[secret[i]]++;
            }
    
        }
        
     
        for(int i =0;i<secret.size();i++){
            if(secret[i]!= guess[i]){
                if(m[guess[i]]>0){
                    b++;
                    m[guess[i]]--;
                }
            }
        }
    
          
        res += to_string(a);
        res += 'A';
        res += to_string(b);
        res += 'B';
        return res;
    }
};