#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        sort(fruits.begin(), fruits.end());   // Sort fruits
        sort(baskets.begin(), baskets.end()); // Sort baskets

        int i = 0, j = 0; // Two pointers
        int count = fruits.size();

        while (i < fruits.size() && j < baskets.size())
        {
            if (fruits[i] <= baskets[j]) // If the fruit fits in the basket
            {
                cout << fruits[i] << " placed in " << baskets[j] << endl;
                i++; // Move to the next fruit
                count--; // Decrease unplaced count
            }
            j++; // Move to the next basket regardless
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> fruits = {3, 5, 2, 8};
    vector<int> baskets = {4, 1, 6, 10};
    cout << "Unplaced fruits: " << sol.numOfUnplacedFruits(fruits, baskets) << endl;

    return 0;
}
