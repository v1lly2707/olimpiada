#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector < int > vec[500005];
vector < int > aux;
vector < int > ::iterator it1;
vector < int > ::iterator it2;
bool ok = false;
int ans;
int arr[500005] = {};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		arr[i] = a;
		vec[a].push_back(i);
	}






	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (a == b)
			cout << arr[a] << '\n';
		else
		{
			for (int j = 1; j <= 26; j++)
			{
				c = rand() % (b - a + 1) + a;
				it1 = lower_bound(vec[arr[c]].begin(), vec[arr[c]].end(), a);
				it2 = upper_bound(vec[arr[c]].begin(), vec[arr[c]].end(), b);

				int cnt = it2 - it1;
				int length = (b - a + 1) / 2;
				if (cnt > length)
				{
					ok = true;
					ans = arr[c];
					break;
				}
			}
			if (ok == false)
				cout << 0 << '\n';
			else cout << ans << '\n';
			ans = 0;
			ok = false;
		}


	}


	return 0;
}
