#include <bits/stdc++.h>

using namespace std;

vector < int > pol[50005]; // vector polaczen

int lca[17][50005];
int odl[50005];

void dfs(int v, int p) // obliczanie wartosci poczatkowej czyli lca[0][v]
{
    lca[0][v] = p;
    for (auto u : pol[v])
        if (u != p)
        {
            odl[u] = odl[v] + 1;
            dfs(u, v);
        }
}

int query(int p, int q) // obliczanie lca WAZNE!!!
{
    int tmp, log;

    if (odl[p] < odl[q])
        swap(p, q);


    for (log = 1; 1 << log <= odl[p]; log++);
    log--;

    for (int i = log; i >= 0; i--)
        if (odl[p] - (1 << i) >= odl[q])
            p = lca[i][p];

    if (p == q)
        return p;

    for (int i = log; i >= 0; i--)
        if (lca[i][q] != -1 && lca[i][p] != lca[i][q])
        {
            p = lca[i][p];
            q = lca[i][q];
        }


    return lca[0][p];
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, u, v;
    long long int sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) // tworzenie polaczen
    {
        cin >> a >> b;
        pol[a].push_back(b);
        pol[b].push_back(a);
    }
    dfs(1, -1);
    for (int i = 1; i <= 17; i++) // obliczanie tablicy lca
        for (int j = 1; j <= n; j++)
            lca[i][j] = lca[i - 1][lca[i - 1][j]];




    cin >> m;
    cin >> v;

    for (int i = 0; i < m - 1; i++)
    {
        cin >> u;
        long long int zap = query(v, u);

        sum += odl[v] + odl[u] - 2 * odl[zap];

        v = u;
    }

    cout << sum;



    return 0;
}
