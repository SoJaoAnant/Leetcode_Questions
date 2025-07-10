#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
    }
};

int main()
{
    vector<int> deck = {1, 9, 2, 7, 3, 11, 4, 8, 5, 10, 6};
    
    //1 2 3 4 5 6
    //9 10 7 8 11

    queue<int> deck_print;
    for (auto &it : deck)
    {
        deck_print.push(it);
    }

    for (; deck_print.empty() == false;)
    {
        cout << deck_print.front() << " ";
        deck_print.pop();
        deck_print.push(deck_print.front());
        deck_print.pop();
    }

    return 0;
}