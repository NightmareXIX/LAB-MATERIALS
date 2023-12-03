#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0 && arr[i][k] == 1 && arr[k][j] == 1)
                    arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}