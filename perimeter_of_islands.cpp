#include <bits/stdc++.h>
using namespace std;

int do_bfs_please(int island[4][4], int i, int j)
{
    queue<pair<int, int>> land_q;
    land_q.push({i, j});
    island[i][j] = 2;
    int perim = 0;

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
        // printf("Bottom (%d,%d) %d\n", x + 1, y, island[x + 1][y]);
        if ((x + 1 == 4) || island[x + 1][y] != 1 && island[x + 1][y] != 2)
        {
            // printf("water at (%d,%d) %d\n", x + 1, y, island[x + 1][y]);
            // printf("Bottom water\n");
            perim += 1;
        }
        if (x - 1 >= 0 && x - 1 < 4 && island[x - 1][y] == 1)
        {
            land_q.push({x - 1, y});
            island[x - 1][y] = 2;
        }
        if ((x - 1 == -1) || island[x - 1][y] != 1 && island[x - 1][y] != 2)
        {
            // printf("water at (%d,%d) %d\n", x - 1, y, island[x - 1][y]);
            // printf("Top water\n");
            perim += 1;
        }
        if (y + 1 >= 0 && y + 1 < 4 && island[x][y + 1] == 1)
        {
            land_q.push({x, y + 1});
            island[x][y + 1] = 2;
        }
        if ((y + 1 == 4) || island[x][y + 1] != 1 && island[x][y + 1] != 2)
        {
            // printf("water at (%d,%d) %d\n", x, y + 1, island[x][y + 1]);
            // printf("Left water\n");
            perim += 1;
        }
        if (y - 1 >= 0 && y - 1 < 4 && island[x][y - 1] == 1)
        {
            land_q.push({x, y - 1});
            island[x][y - 1] = 2;
        }
        if ((y - 1 == -1) || island[x][y - 1] != 1 && island[x][y - 1] != 2)
        {
            // printf("water at (%d,%d) %d\n", x, y - 1, island[x][y - 1]);
            // printf("Right water\n");
            perim += 1;
        }
    }

    return perim;
}

int main()
{
    int island[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    int found = 0;
    int perim;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (island[i][j] == 1)
            {
                found = 1;
                perim = do_bfs_please(island, i, j);
                break;
            }
        }
        if (found == 1)
        {
            break;
        }
    }

    cout << perim << endl;

    return 0;
}

/*
[[1,1,0,0,0],
[1,1,0,0,0],
[0,0,0,1,1],
[0,0,0,1,1]]
*/