class Solution {
public:
    int getLastMoment(int n, vector<int>& L, vector<int>& R) {
        
        sort(L.begin(), L.end());
        sort(R.begin(), R.end());
        
        if(L.size() == 0 && R.size() != 0){ 
            return n-R[0];
        }
        
        if(L.size() != 0 && R.size() == 0){
            return L[L.size()-1];
        }

        return max(L[L.size()-1] , n-R[0]);

    }
};