#include <bits/stdc++.h>
using namespace std;
int n, m, z, p, k, l;

const int a = 19;
int nax[1 << a];
int lazy[1 << a];
int M = 1 << (a - 1);
void apply(int s, int val)
{
	nax[s] += val;
	if (s < M)
		lazy[s] += val;
}

void build(int s)
{
	s /= 2;
	while (s)
	{
		nax[s] = max(nax[2 * s], nax[2 * s + 1]);
		s /= 2;
	}
}

void push(int s)
{
	for (int h = a - 1; h > 0; h--)
	{
		int i = s >> h;
		if (lazy[i])
		{
			apply(i * 2, lazy[i]);
			apply(i * 2 + 1, lazy[i]);
			lazy[i] = 0;
		}
	}
}
void insert(int a, int b, int val)
{
	int l = a += M;
	int r = b += M;
	push(l);
	push(r);

	apply(l, val);
	if (l != r)
		apply(r, val);

	while (a / 2 != b / 2)
	{
		if (a % 2 == 0)
			apply(a + 1, val);
		if (b % 2 == 1)
			apply(b - 1, val);

		a /= 2;
		b /= 2;
	}

	build(l);
	build(r);
}

int query(int l, int r)
{
	l += M;
	r += M;
	push(l);
	push(r);

	int ans = max(nax[l], nax[r]);
	while (l / 2 != r / 2)
	{
		if (l % 2 == 0)
			ans = max(ans, nax[l + 1]);
		if (r % 2 == 1)
			ans = max(ans, nax[r - 1]);

		l /= 2;
		r /= 2;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> z; // liczba miast na trasie,liczba miejsc w pociagu,liczba zgloszen
	while (z--)
	{
		cin >> p >> k >> l; // nr stacji poczatkowej,nr stacji docelowej,wymagana liczba miejsc
		k--;
		int ans = query(p, k);
		if (ans + l <= m)
		{
			cout << "T\n";
			insert(p, k, l);
		}
		else
			cout << "N\n";

	}




	return 0;
}
