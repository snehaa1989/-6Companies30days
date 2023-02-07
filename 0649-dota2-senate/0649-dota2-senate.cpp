class Solution {
public:
    string predictPartyVictory(string senate) {
    
         queue<int> Rq, Dq;
    
    for(int i=0; i<senate.size(); i++)
        senate[i] == 'R' ? Rq.push(i): Dq.push(i);
    
    int senator_a, senator_b;
    
    while(!Rq.empty() && !Dq.empty()){
        
        senator_a = Rq.front();
        senator_b = Dq.front();
        
        Rq.pop();
        Dq.pop();
        
        if (senator_a < senator_b)
            Rq.push(senator_a+senate.size());
        
        else
            Dq.push(senator_b+senate.size());
        
    }
    
	if (Rq.size() > Dq.size())
		return "Radiant";
    
	
    return "Dire";
}
};