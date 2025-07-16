#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        int max_assigns = 0;
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());

        int p = 0;
        int t = 0;

        while (p != players.size() || t != trainers.size())
        {
            if (players[p] <= trainers[t])
            {
                max_assigns += 1;
                p += 1;
                t += 1;
            }
            else
            {
                p += 1;
            }
        }
        
        return max_assigns;
    }
};

int main()
{

    return 0;
}