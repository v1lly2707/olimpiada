//54% score
#include <bits/stdc++.h>
using namespace std;
int prefix_sum[100005] = {};
int arr[100005] = {};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, a, d, l;

	cin >> n >> k;
	int pom;
	while (k--)
	{
		cin >> a >> l >> d;
		if (d == 1)
		{
			prefix_sum[a]++;
			prefix_sum[l + a]--;

		}
		else
		{
			pom = 0;
			for (int i = a; l > pom; i += d)
			{
				arr[i]++;
				pom++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		prefix_sum[i] = prefix_sum[i] + prefix_sum[i - 1];
	for (int i = 1; i <= n; i++)
		cout << arr[i] + prefix_sum[i] << ' ';
	return 0;
}
