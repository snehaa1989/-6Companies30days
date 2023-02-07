class Solution {
public:
     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector <pair <int,int>> arr;
        for(int i = 0; i<profits.size(); i++) arr.push_back({capital[i],profits[i]});
        sort(arr.begin(),arr.end());
        
        priority_queue <int> q;
        int ans = 0, i=0;
        while(i<arr.size() and k){
            if(w>=arr[i].first) q.push(arr[i++].second);
            else{
                if(q.empty()) return w;
                
                w += q.top();
                q.pop();
                k--;
            }
        }
        while(k-- and !q.empty()){
            w += q.top();
            q.pop();
        }
        return w;
    }
};