//60% score
#include <bits/stdc++.h>                                                        

using namespace std;

long long int bity[1005][10005];
long long int iloscOperacji[1005][1005];
int o = 0;
int pom1, pom2;
void przeszukiwanie(int iloscWierszy, int iloscKolumn)
{

    for (int i = iloscWierszy, j = iloscKolumn; i <= pom1 && j > 0; i++, j--)
    {
        bity[i][j] += (iloscOperacji[i][j + 1] + iloscOperacji[i + 1][j] + bity[i][j + 1] + bity[i + 1][j] - bity[i + 1][j + 1] - iloscOperacji[i + 1][j + 1]);
        if (iloscOperacji[i][j] % 2 != 0)
        {
            o++;
            bity[i][j]++;
        }


    }
    if (iloscWierszy == 1 && iloscKolumn == 1)
    {
        return;
    }

    if (iloscWierszy > 1)
    {
        przeszukiwanie(iloscWierszy - 1, iloscKolumn);
    }

    else
    {
        przeszukiwanie(1, iloscKolumn - 1);
    }





}

void cos()
{
    for (int k = 0; k < pom1 + 2; k++)
    {
        for (int l = 0; l < pom2 + 2; l++)
        {
            bity[k][l] = 0;
        }
    }
}
int main()
{

    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(0);
    int iloscWierszy, iloscKolumn, iloscZapytan;
    int i1, j1, i2, j2;

    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cin >> iloscWierszy >> iloscKolumn >> iloscZapytan;
    pom1 = iloscWierszy;
    pom2 = iloscKolumn;
    while (iloscZapytan--)
    {
        cin >> i1 >> j1 >> i2 >> j2;
        iloscOperacji[i2][j2]++;
        iloscOperacji[i1 - 1][j1 - 1]++;
        iloscOperacji[i2][j1 - 1]--;
        iloscOperacji[i1 - 1][j2]--;
        przeszukiwanie(iloscWierszy, iloscKolumn);
        cout << o << endl;
        cos();


        o = 0;
    }
    return 0;
}
