//6% score xD
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	long long int liczbaGablot;
	cin >> liczbaGablot;
	long long int gabloty[liczbaGablot + 5][3];


	for (long long int i = 0; i < liczbaGablot; i++)
	{
		for (long long int j = 0; j < 3; j++)
		{

			cin >> gabloty[i][j];
		}

	}



	char tab[liczbaGablot];

	for (long long int i = 0; i < liczbaGablot; i++)
	{

		if (gabloty[i][1] + gabloty[i][2] <= gabloty[i][0] + gabloty[i][1] && gabloty[i][1] + gabloty[i][2] <= gabloty[i][0] + gabloty[i][2])
		{
			tab[i] = 'D';
		}
		else if (gabloty[i][0] + gabloty[i][2] <= gabloty[i][0] + gabloty[i][1] && gabloty[i][0] + gabloty[i][2] <= gabloty[i][1] + gabloty[i][2])
		{

			tab[i] = 'P';

		}
		else
		{

			tab[i] = 'R';

		}


	}



	long long int iloscD = 0;
	long long int iloscP = 0;
	long long int iloscR = 0;

	for (long long int i = 0; i < liczbaGablot; i++)
	{

		iloscD += gabloty[i][0];
		iloscP += gabloty[i][1];
		iloscR += gabloty[i][2];

	}

	long long int D = 0;
	long long int P = 0;
	long long int R = 0;

	for (long long int i = 0; i < liczbaGablot; i++)
	{

		if (tab[i] == 'D')
		{
			D += 1;
		}
		if (tab[i] == 'P')
		{
			P += 1;
		}
		if (tab[i] == 'R')
		{
			R += 1;
		}
		if (D >= 2 && P >= 2 && R >= 2)
		{
			break;
		}

	}


	long long int BEST_D = 0;
	long long int BEST_P = 0;
	long long int BEST_R = 0;
	long long int sD = 0;
	long long int sP = 0;
	long long int sR = 0;

	if (D == 0 && iloscD > 0)
	{

		for (long long int i = 0; i < liczbaGablot; i++)
		{

			sD = gabloty[i][1] + gabloty[i][2];
			sP = gabloty[BEST_D][0] + gabloty[BEST_D][1];
			sR = gabloty[BEST_D][0] + gabloty[BEST_D][2];


			if ((sD <= sP) && (sD <= sR))
			{
				BEST_D = i;
			}

		}

		tab[BEST_D] = 'D';



	}

	if (P == 0 && iloscP > 0)
	{

		for (int i = 0; i < liczbaGablot; i++)
		{

			sP = gabloty[i][0] + gabloty[i][2];
			sR = gabloty[BEST_P][0] + gabloty[BEST_P][1];
			sD = gabloty[BEST_P][1] + gabloty[BEST_P][2];


			if ((sP <= sD) && (sP <= sR))
			{
				BEST_P = i;
			}

		}

		tab[BEST_P] = 'P';



	}

	if (R == 0 && iloscR > 0)
	{

		for (long long int i = 0; i < liczbaGablot; i++)
		{

			sR = gabloty[i][0] + gabloty[i][1];
			sP = gabloty[BEST_R][0] + gabloty[BEST_R][2];
			sD = gabloty[BEST_R][1] + gabloty[BEST_R][2];

			if (tab[i] == 'P' && P == 0)
			{
				BEST_R = i + 1;
				continue;
			}
			else if ((sR <= sD) && (sR <= sP))
			{
				BEST_R = i;
			}

		}

		tab[BEST_R] = 'R';


	}



	int o = 0;

	for (long long int i = 0; i < liczbaGablot; i++)
	{

		if (tab[i] == 'D')
		{
			o += gabloty[i][1] + gabloty[i][2];
		}
		else if (tab[i] == 'P')
		{
			o += gabloty[i][0] + gabloty[i][2];
		}
		else
		{
			o += gabloty[i][0] + gabloty[i][1];
		}

	}





	cout << o << endl;

	return 0;
}
