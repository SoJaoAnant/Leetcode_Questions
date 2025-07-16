#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int max_gap(vector<int> &gaps, vector<int> &times)
    {
        if (gaps.size() == 1)
        {
            return gaps[0];
        }
        if (gaps.size() == 2)
        {
            return gaps[0] + gaps[1];
        }

        int wi = 1;
        int sum = 0;
        int win_sum = 0;

        for (int i = 0; i < 2; ++i)
        {
            win_sum += gaps[i];
        }

        sum = win_sum;

        for (int i = 2; i < gaps.size(); ++i)
        {
            win_sum += gaps[i] - gaps[i - 2];
            if (win_sum > sum)
            {
                wi = i;
                sum = win_sum;
            }
        }

        int max_adj = gaps[wi+1];
        int sum3;
        if (find(times.begin(), times.end(), max_adj) != times.end())
        {
            sum3 = max_adj;
        }
        max_adj = gaps[wi - 2];
        if (find(times.begin(), times.end(), max_adj) != times.end())
        {
            if(sum3 < max_adj)
            {
                sum3 = max_adj;
            }
        }

        return sum3 + gaps[wi] + gaps[wi - 1];
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

            i += 1;
            j += 1;
        }
    }

    void fill_time(vector<int> &times, vector<int> &startTime, vector<int> &endTime)
    {
        for (int i = 0; i < startTime.size(); i++)
        {
            times.push_back(endTime[i] - startTime[i]);
        }
    }

    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
    {
        vector<int> gaps;
        vector<int> times;
        fill_gaps(gaps, eventTime, startTime, endTime);
        fill_time(times, startTime, endTime);
        return max_gap(gaps, times);
    }
};

int main()
{
    vector<int> start_time = {0, 3, 7, 9};
    vector<int> end_time = {1, 4, 8, 10};
    // vector<int> end_time = {8, 2, 5, 9, 1, 10, 6, 3, 4, 7, 10, 2, 8};
    int event_time = 10;
    int k = 1;

    Solution obj;
    cout << endl
         << "Max Free Time: " << obj.maxFreeTime(event_time, start_time, end_time);

    return 0;
}

/*
5
[1,3]
[2,5]
10
[0,7,9]
[1,8,10]
10
[0,3,7,9]
[1,4,8,10]
5
[0,1,2,3,4]
[1,2,3,4,5]
41
[17,24]
[19,25]
86
[22,82]
[66,85]
*/