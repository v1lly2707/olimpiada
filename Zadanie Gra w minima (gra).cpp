#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    int tab[1000005] = {};

    int pom = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> tab[i];

    sort(tab, tab + n);

    for (int i = 1; i <= n; i++)
        pom = max(pom, tab[i] - pom);


    cout << pom;


    return 0;
}
