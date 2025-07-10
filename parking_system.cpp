#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
    int big_count;
    int medium_count;
    int small_count;

    ParkingSystem(int big, int medium, int small)
    {
        big_count = big;
        medium_count = medium;
        small_count = small;
    }

    bool addCar(int carType)
    {
        // 1 big
        // 2 medium
        // 3 small

        if (carType == 1 && big_count > 0)
        {
            big_count -= 1;
            return true;
        }
        if (carType == 2 && medium_count > 0)
        {
            medium_count -= 1;
            return true;
        }
        if (carType == 3 && small_count > 0)
        {
            small_count -= 1;
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}