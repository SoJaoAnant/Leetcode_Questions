#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> index_map;
        for (int i = 0; i < numbers.size(); i++)
        {
            int complement = target - numbers[i];
            if (index_map.find(complement) != index_map.end())
            {
                return {index_map[complement] + 1, i + 1};
            }
            index_map[numbers[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(numbers, target);
    for (int index : result)
    {
        cout << index << " ";
    }
}
