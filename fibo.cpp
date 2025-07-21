#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int fibo_arr[25];

    for (int i = 0; i < 25; i++)
    {
        fibo_arr[i] = fibo(i);
        cout << fibo_arr[i] << endl;
    }

    return 0;
}