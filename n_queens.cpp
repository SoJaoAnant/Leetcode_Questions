#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_safe(int row, int col, vector<string> &board, int n)
    {
        int back_row = row;
        int back_col = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row--;
        }

        row = back_row;
        col = back_col;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = back_row;
        col = back_col;

        while (col < 0 && row >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }

        return true;
    }

    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (is_safe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);
        solve(0, n, board, ans);
        return ans;
    }
};

int main()
{
    int n = 4; // we are taking 4*4 grid and 4 queens
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}