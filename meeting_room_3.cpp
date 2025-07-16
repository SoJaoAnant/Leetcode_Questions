#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<int, vector<int>, greater<int>> room_heap;
        unordered_map<int, int> bookings;
        unordered_map<int, int> filled;

        sort(meetings.begin(), meetings.end());

        int i = 0;
        while (i < n)
        {
            if (filled[i] == 0)
            {
                room_heap.push(i);
            }
            i++;
        }

        
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    obj.mostBooked(3, meetings);
    return 0;
}