class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for(int i=0;i<asteroids.size();i++){
            if(mass < asteroids[i]){
                return false;
            }
            mass += asteroids[i];
            if(mass >= 100000){
                return true;
            }
        }
        return true;
    }
};