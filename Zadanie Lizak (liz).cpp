//24% score
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int arr[1000005] = {};
	char a;
	int cnt = 0, W = 0, T = 0;
	int n, m, k; // n-> dlugosc lizaka, m->rozpatrywanie wartosci
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a == 'W')
		{
			arr[i] = 1; // W=1
			cnt++;
			W++;
		}
		else
		{
			arr[i] = 2; // T=2;
			cnt += 2;
			T++;
		}
	}
	int suma = arr[1];
	pair < int, int > ans;
	int x = 1, y = 1;
	bool ok = false;
	while (m--)
	{

		cin >> k;
		while (y <= n)
		{
			if (suma < k)
			{
				y++;
				suma += arr[y];
			}
			else if (suma > k)
			{
				suma -= arr[x];
				x++;
			}
			else
			{
				ok = true;
				ans.first = x;
				ans.second = y;
				break;
			}
		}
		if (k <= cnt)
		{
			if (ok == false)
				cout << "NIE\n";
			else
			{
				if (k == cnt)
					cout << 1 << ' ' << n << '\n';
				else if (W == n)
					cout << 1 << ' ' << k << '\n';
				else if (T == n && k % 2 == 0)
					cout << 1 << ' ' << k / 2 << '\n';
				else cout << ans.first << ' ' << ans.second << '\n';
			}



		}
		else cout << "NIE\n";


		x = y = 1;
		ok = false;
		suma = arr[1];





	}

	return 0;
}
