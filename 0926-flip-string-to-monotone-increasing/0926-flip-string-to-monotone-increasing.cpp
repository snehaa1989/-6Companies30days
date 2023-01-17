class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int flip = 0, one = 0;
        for (auto i : S)
        { 
            if (i == '1')
                one++;
            else
            {
                flip++;
                flip = min(flip, one);
            }
        }
        return flip;
    }
};