#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n, m, w, b;
	cin >> n >> m;
	int tab[n + 5] = {};
	int pom[m + 5] = {};
	int a[n + 5] = {};

	for (int i = 1; i <= n; i++)
		cin >> tab[i];

	for (int i = 1; i <= m; i++)
		cin >> pom[i];

	a[1] = tab[1];

	for (int i = 2; i <= n; i++)
	{
		tab[i] = min(tab[i], tab[i - 1]);
	}
	int o = n;

	for (int i = 1; i <= m; i++, o--)
	{
		while (o > 0 && tab[o] < pom[i])
			o--;

		if (o == 0)
		{
			puts("0");
			return 0;
		}


	}
	cout << o + 1;



	return 0;
}
