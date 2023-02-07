class TweetCounts {
public:
    unordered_map<string,set<pair<int,int>>>data;
    int iter;
    
    TweetCounts() {
        iter = 0;    
    }
    void recordTweet(string tweetName, int time) {
        data[tweetName].insert({time,iter++});
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int chunk = freq[0]=='m' ? 60 : (freq[0]=='h' ? 3600 : 24*3600);
        set<pair<int,int>>::iterator start = data[tweetName].lower_bound({startTime,0});
        set<pair<int,int>>::iterator end = data[tweetName].end();
        vector<int>res;
        for(int i=0;i<=(endTime - startTime)/chunk;i++)res.push_back(0);

        while(start!=end && (*start).first<=endTime)
        {
            res[((*start).first - startTime)/chunk]++;
            start++;
        }
        
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */