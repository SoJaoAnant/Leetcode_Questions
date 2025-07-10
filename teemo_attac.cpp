#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int poisoned = 0;
        int time = timeSeries[timeSeries.size() - 1];
        int okay = timeSeries[timeSeries.size() - 1];

        for (int i = 0; i < timeSeries.size(); i++)
        {

        }
        
        return okay;
    }
};

int main()
{
    Solution obj;
    vector<int> time_series = {1, 4};

    cout << obj.findPoisonedDuration(time_series, 2);
    return 0;
}