#include <bits/stdc++.h>
using namespace std;

vector < pair < int, int > > P;
long long n, i = 1, j = 1, x, y, a = 0, b = 0;
long long dst = 0;
bool IfVisited[200005] = {};
int f(pair < int, int > p)
{
	int x = p.first;
	int y = p.second;

	if (x > 0 && y == 0)
		return 1;
	if (x > 0 && y > 0)
		return 2;
	if (x == 0 && y > 0)
		return 3;
	if (x < 0 && y>0)
		return 4;
	if (x < 0 && y == 0)
		return 5;
	if (x < 0 && y < 0)
		return 6;
	if (x == 0 && y < 0)
		return 7;
	if (x > 0 && y < 0)
		return 8;
}

bool comp(pair < int, int > A, pair < int, int > B)
{


	if (f(A) < f(B))
		return true;
	else if (f(A) > f(B))
		return false;
	else
		if ((A.second) * (B.first) == (A.first) * (B.second))
		{
			if (A.first == 0 && B.first == 0)
				return A.second < B.second;

			return A.first < B.first;
		}




	return (A.second) * (B.first) < (A.first) * (B.second);
}
int main()
{
	ios_base::sync_with_stdio(0);



	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		P.push_back({ x,y });

	}

	sort(P.begin(), P.end(), comp);
	for (int i = 0; i < n; i++)
		P.push_back({ P[i].first,P[i].second });


	while (i < 2 * n)
	{
		if (IfVisited[j % n] == false && j < 2 * n && pow(a + P[j].first, 2) + pow(b + P[j].second, 2) >= pow(a - P[i].first, 2) + pow(b - P[i].second, 2))
		{
			a += P[j].first;
			b += P[j].second;
			IfVisited[j % n] = true;
			j++;
		}
		else if (i < j && i < 2 * n)
		{
			a -= P[i].first;
			b -= P[i].second;
			IfVisited[i % n] = false;
			i++;
		}

		dst = max(dst, a * a + b * b);
	}

	cout << dst;



	return 0;

}
