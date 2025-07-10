#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());

        int attend = 1;
        int att_en = events[0][1];
        cout << "Attending: [" << events[0][0] << "," << events[0][1] << "]" << endl;
        for (vector<int> pair : events)
        {
            // cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
            if (pair[0] >= att_en)
            {
                cout << "Attending: [" << pair[0] << "," << pair[1] << "]" << endl;
                attend += 1;
                att_en = pair[1];
            }
        }
        cout << "Attended a total of " << attend << " events!!" << endl;
        return attend;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> events = {{4, 5}, {1, 3}, {3, 4}, {2, 3}, {1, 2}, {4, 6}};
    obj.maxEvents(events);

    return 0;
}