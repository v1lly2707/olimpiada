#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, arr[30005] = {};
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> arr[i];

	arr[m + 1] = pow(10, 9);
	int cnt = 0;
	sort(arr + 1, arr + m + 1);
	int j = 1;
	for (int i = m; i >= j; i--)
	{
		if (arr[i] + arr[j] <= n)
			j++;

		cnt++;
	}
	cout << cnt;
	return 0;
}
