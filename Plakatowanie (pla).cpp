#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    int x, a, b;
    cin >> x;

    stack < int > stos;
    for (int i = 1; i <= x; i++)
    {
        cin >> a >> b;

        while (stos.empty() == false && stos.top() > b)
        {
            stos.pop();

        }
        if (stos.empty() == true || stos.top() < b)
        {
            stos.push(b);
            cnt++;
        }



    }




    cout << cnt;



    return 0;
}
