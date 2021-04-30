#include <bits/stdc++.h>
#include <limits.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back

using namespace std;

vector<vector<vector<int>>> parent;

void solve(vector<vector<int>> &shortestpath, vector<vector<int>> &cost, int &H, int &V, int Hnow, int Vnow)
{

    if (shortestpath[Vnow][Hnow] + cost[Vnow][Hnow] <= shortestpath[Vnow][Hnow + 1])
    {
        shortestpath[Vnow][Hnow + 1] = shortestpath[Vnow][Hnow] + cost[Vnow][Hnow];
        parent[Vnow][Hnow + 1][0] = Vnow;
        parent[Vnow][Hnow + 1][1] = Hnow;
    }
    if (shortestpath[Vnow][Hnow] + cost[Vnow][Hnow] <= shortestpath[Vnow + 1][Hnow])
    {
        shortestpath[Vnow + 1][Hnow] = shortestpath[Vnow][Hnow] + cost[Vnow][Hnow];
        parent[Vnow + 1][Hnow][0] = Vnow;
        parent[Vnow + 1][Hnow][1] = Hnow;
    }
    if (shortestpath[Vnow][Hnow] + cost[Vnow][Hnow] <= shortestpath[Vnow + 1][Hnow + 1])
    {
        shortestpath[Vnow + 1][Hnow + 1] = shortestpath[Vnow][Hnow] + cost[Vnow][Hnow];
        parent[Vnow + 1][Hnow + 1][0] = Vnow;
        parent[Vnow + 1][Hnow + 1][1] = Hnow;
    }

    Hnow += 1;
    if (Hnow == H)
    {
        Vnow += 1;
        if (Vnow == V)
            return;
        else
            return solve(shortestpath, cost, H, V, 0, Vnow);
    }
    else
    {
        return solve(shortestpath, cost, H, V, Hnow, Vnow);
    }
}

int main(void)
{
    //H is horizontal grid
    //V is vertical grid

    int H, V;
    cin >> H >> V;
    vector<int> Hvec, Vvec;
    vector<vector<int>> cost;
    vector<vector<int>> shortestpath;
    //horizontal and vertical cost
    rep(i, H)
    {
        int temp;
        cin >> temp;
        Hvec.pb(temp);
    }
    rep(i, V)
    {
        int temp;
        cin >> temp;
        Vvec.pb(temp);
    }

    //cost init
    rep(i, V)
    {
        vector<int> temp;
        rep(j, H)
        {
            temp.pb(abs(Hvec[j] - Vvec[i]));
        }
        cost.pb(temp);
    }

    //shortestpath init
    rep(i, V + 1)
    {
        vector<int> temp;
        rep(j, H + 1)
        {
            temp.pb(INT_MAX);
        }
        shortestpath.pb(temp);
    }
    shortestpath[0][0] = cost[0][0];

    //parent init
    rep(i, V + 1)
    {
        vector<vector<int>> temp;
        rep(j, H + 1)
        {
            temp.pb(vector<int>(2, -1));
        }
        parent.pb(temp);
    }

    //solve recursion
    solve(shortestpath, cost, H, V, 0, 0);

    //print
    rep(i, cost.size())
    {
        rep(j, cost[i].size())
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    rep(i, V)
    {
        rep(j, H)
        {
            cout << shortestpath[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    rep(i, V)
    {
        rep(j, H)
        {
            cout << parent[i][j][0] << "," << parent[i][j][1] << " ";
        }
        cout << endl;
    }
    return 0;
}