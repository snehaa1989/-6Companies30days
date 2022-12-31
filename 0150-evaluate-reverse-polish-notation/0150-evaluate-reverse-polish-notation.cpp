class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;
        
        for(auto t : tokens)
        {
            if(t == "+" || t == "-" || t == "/" || t == "*")
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                
                if(t == "+")
                {
                    s.push(y + x);
                }
                else if(t == "*")
                {
                    s.push(y * x);
                }
                else if(t == "-")
                {
                    s.push(y - x);
                }
                else
                {
                    s.push(y / x);
                }
            }
                else
                {
                    int n = stoi(t);
                    s.push(n);
                }
        }
        
        return s.top();

    }
};