#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compute_area(int i, int j, const vector<int> &height)
    {
        return (j - i) * min(height[j], height[i]);
    }

    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int temp;
        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            temp = compute_area(i,j,height);
            max_area = max(max_area,temp);

            if(height[i] < height[j]) i++;
            else j--;
        }

        return max_area;
    }
};

int main()
{

    return 0;
}