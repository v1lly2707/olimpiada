#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector < int > vec[30001];
    int tab[30001] = {};
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec[b].push_back(a);
    }
    for (int i = 1; i <= 30000; i++)
    {
        tab[i] = tab[i - 1];
        for (int a : vec[i])
            tab[i] = max(tab[i], tab[a] + i - a);
    }

    cout << tab[30000];
    return 0;
}
