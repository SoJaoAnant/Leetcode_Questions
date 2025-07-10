#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_max_value(vector<vector<int>> &events, int event_no, int curr_value, int rem_events)
    {
        if (rem_events == 0 || event_no == events.size())
        {
            return 0;
        }
        int attend = find_max_value(events, event_no + 1, curr_value + events[event_no][2], rem_events - 1);

        int nattend;
        for (int i = event_no; i < events.size(); i++)
        {
            if(events[i][0] > events[event_no][1])
            {
                nattend = find_max_value(events, event_no + 1, curr_value, rem_events);
                // cout << "chose the event "<< events[i][0] << " " << events[i][1] << endl;
                break;
            }
        }
        
        // cout << attend << " " << nattend << endl;
        return max(attend, nattend);
    }

    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end());
        int max_value = find_max_value(events, 0, 0, k);

        cout << max_value << endl;
        return max_value;
    }
};

int main()
{
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    int k = 2;
    Solution obj;
    obj.maxValue(events, k);
    return 0;
}