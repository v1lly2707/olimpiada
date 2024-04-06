#include <bits/stdc++.h>
using namespace std;

double a[10005], b[10005];
struct s
{
	int i, j;
	double a, b;
	bool operator < (const s& x)const
	{
		if (x.a * b == a * x.b)
		{
			return j < x.j;
		}
		return x.a * b < a * x.b;
	}

};
s tab[10005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		tab[i].a = a[i];
		tab[i].b = b[i];
		tab[i].j = i;

	}


	sort(tab + 1, tab + n + 1);
	for (int i = 1; i <= n; i++)
		cout << tab[i].j << "\n";


	return 0;
}
