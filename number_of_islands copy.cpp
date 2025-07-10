#include <bits/stdc++.h>
using namespace std;

int do_bfs_please(int island[4][4], int i, int j, int row, int col)
{
    queue<pair<int, int>> land_q;
    land_q.push({i, j});
    island[i][j] = -1;

    while (!land_q.empty())
    {
        pair<int, int> cell = land_q.front();
        int x = cell.first;
        int y = cell.second;

        land_q.pop();
        // printf("Exploring (%d,%d)\n", x, y);

        if (x + 1 >= 0 && x + 1 < 4 && island[x + 1][y] == 1)
        {
            land_q.push({x + 1, y});
            island[x + 1][y] = 2;
        }
        if (x - 1 >= 0 && x - 1 < 4 && island[x - 1][y] == 1)
        {
            land_q.push({x - 1, y});
            island[x - 1][y] = 2;
        }
        if (y + 1 >= 0 && y + 1 < 4 && island[x][y + 1] == 1)
        {
            land_q.push({x, y + 1});
            island[x][y + 1] = 2;
        }
        if (y - 1 >= 0 && y - 1 < 4 && island[x][y - 1] == 1)
        {
            land_q.push({x, y - 1});
            island[x][y - 1] = 2;
        }
    }
}

int main()
{
    int island[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    int row = 4, col = 4;
    int nisland;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (island[i][j] == 1)
            {
                nisland += 1;
                do_bfs_please(island, i, j, row, col);
            }
        }
    }

    cout << nisland << endl;

    return 0;
}