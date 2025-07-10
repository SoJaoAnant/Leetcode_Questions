#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int check_attack(int kx, int ky, vector<vector<int>> &queens)
    {
        for (vector<int> sub : queens)
        {
            if (sub[0] == kx && sub[1] == ky)
            {
                return 1;
            }
        }
        return 0;
    }

    void king_move(int x, int y, int kx, int ky, vector<vector<int>> &attack, vector<vector<int>> &queens)
    {
        // cout << kx << " " << ky << endl;
        if (x == 0 && y == 0)
        {
            return;
        }

        while (kx >= 0 && kx < 8 && ky >= 0 && ky < 8)
        {
            kx += x;
            ky += y;
            if (check_attack(kx, ky, queens) == 1)
            {
                cout << kx << " " << ky << endl;
                attack.push_back({kx, ky});
                break;
            }
        }
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<int>> attack;
        vector<int> dir = {-1, 0, 1};

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // cout << dir[i] << " " << dir[j] << endl;
                king_move(dir[i], dir[j], king[0], king[1], attack, queens);
            }
        }
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> queens = {{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
    vector<int> king = {2, 2};
    obj.queensAttacktheKing(queens, king);

    return 0;
}