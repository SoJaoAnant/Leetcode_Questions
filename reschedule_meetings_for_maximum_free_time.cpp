#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int window_with_greatest_gap(vector<int> &gaps, int k)
    {
        if (gaps.size() < k)
            return -1;

        int sum = 0;
        int win_sum = 0;

        for (int i = 0; i < k; ++i)
        {
            win_sum += gaps[i];
        }

        sum = win_sum;

        for (int i = k; i < gaps.size(); ++i)
        {
            win_sum += gaps[i] - gaps[i - k];
            sum = max(sum, win_sum);
        }

        return sum;
    }

    void
    fill_gaps(vector<int> &gaps, int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        int diffj = 0;
        int diffi = startTime[0];
        int i = 1;
        int j = 0;

        gaps.push_back(diffi - diffj);

        while (j < endTime.size())
        {
            if (i == endTime.size())
            {
                diffj = endTime[j];
                diffi = eventTime;
            }
            else
            {
                diffj = endTime[j];
                diffi = startTime[i];
            }

            gaps.push_back(diffi - diffj);

            // cout << "i: " << i << ": " << diffi << endl;
            // cout << "j: " << j << ": " << diffj << endl;
            i += 1;
            j += 1;
        }

        // cout << gaps.size() << endl;
        // for (int gap : gaps)
        // {
        // cout << gap << " ";
        // }
    }

    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        vector<int> gaps;

        fill_gaps(gaps, eventTime, startTime, endTime);

        return window_with_greatest_gap(gaps, k + 1);
    }
};

int main()
{
    vector<int> start_time = {1, 4, 9};
    // vector<int> end_time = {2, 6, 13};
    vector<int> end_time = {8, 2, 5, 9, 1, 10, 6, 3, 4, 7, 10, 2, 8};
    int event_time = 16;
    int k = 1;

    Solution obj;
    // cout << endl << "Max Free Time: " << obj.maxFreeTime(event_time, k, start_time, end_time);

    cout << obj.window_with_greatest_gap(end_time, 3);

    return 0;
}