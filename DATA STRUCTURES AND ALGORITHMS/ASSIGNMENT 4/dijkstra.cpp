#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
#define FIO ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl "\n"
#define pb push_back
#define MP make_pair
#define loop(i, a, n) for (int i = a; i < n; i++)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define newline cout << "\n"

#define INF 100000

typedef vector<ll> vl;
typedef vector<int> vi;

int smallest(vi distances, vector<bool> checked, int n)
{
    int idx = -1;
    loop(i, 0, n) 
    {
        if (checked[i] == false && idx == -1) 
            idx = i;
        else if (checked[i] == false && distances[i] <= distances[idx])
            idx = i;
    }
    return idx;
}

void solve(int tc)
{
    int size, startNode;
    cin >> size >> startNode;
    vector<vector<int>> mtx(size, vector<int>(size));
    vi distances(size);
    vector<bool> checked(size);
    loop(i, 0, size)
    {
        loop(j, 0, size)
        {
            cin >> mtx[i][j];
            if (mtx[i][j] && i == startNode)
                distances[j] = mtx[i][j];
            else if (i == startNode)  
                distances[j] = INF;
        }
        checked[i] = false;
    }
    distances[startNode] = 0;
    // check for smallest distance 
    loop(i, 0, size)
    {
        int idx = smallest(distances, checked, size);
        checked[idx] = true;
        // update distances of connected nodes to the selected node
        loop(i, 0, size)
        {
            if (mtx[idx][i]) 
                distances[i] = min(distances[i], distances[idx] + mtx[idx][i]);
        }
    }

    loop(i, 0, size)
    {
        cout << distances[i] << " ";
    }
    newline;
}

int main(void)
{
    FIO;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}