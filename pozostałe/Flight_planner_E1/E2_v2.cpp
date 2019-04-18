#include <iostream>
#include <algorithm>
using namespace std;

main()
{
    int how_many_cases, distance_to_fly;
    cin>>how_many_cases;

    while(how_many_cases>0)
    {
        //wczytanie danych (odwrocona tabela)
        cin>>distance_to_fly;
        int wind[10][distance_to_fly/100];

        for(int i=9; i>=0; i--)
        {
            for(int j=0; j<distance_to_fly/100; j++)
            {
                cin>>wind[i][j];
            }
        }
//        wypisanie
        cout<<endl;
        /*
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<(distance_to_fly/100); j++)
            {
                cout<<wind[i][j]<<" ";
            }
            cout<<endl;
        }*/
        //stworzenie tabeli dynamicznej z wynikiami
        int results[11][distance_to_fly/100 + 1];
        for(int i=0; i<=distance_to_fly/100; i++)
        {
            results[0][i]=100000;
        }
        for(int i=0; i<11; i++)
        {
            results[i][0]=100000;
        }
        for(int j=1; j<=(distance_to_fly/100); j++)
        {
            for(int i=1; i<=10; i++)
            {
                results[i][j]=100000;
            }
        }
        results[1][1]= (30 - wind[0][0]);
        for(int j=1; j<=(distance_to_fly/100); j++)
        {
            for(int i=1; i<10; i++)
            {
                int tmp;
                tmp = min(100000, results[i][j]);
                tmp = min(60 + results[i-1][j-1] - wind[i-1][j-1], tmp);
                tmp = min(30 + results[i][j-1] - wind[i-1][j-1], tmp);
                tmp = min(20 + results[i+1][j-1] - wind[i-1][j-1], tmp);
                results[i][j]=tmp;
                //results[i][j] = min(60 + results[i-1][j-1] - wind[i-1][j-1], 30 + results[i][j-1] - wind[i-1][j-1]);
               // results[i][j] = min(20 + results[i+1][j-1] - wind[i-1][j-1], results[i][j]);
            }
        }
        cout<<endl;

        for(int i=0; i<=10; i++)
        {
            for(int j=0; j<=(distance_to_fly/100); j++)
            {  cout.width(2);
                //cout<<"| r["<<i<<"]["<<j<<"]="<<results[i][j]<<" |";

                cout<<results[i][j]<<" ";
            }
            cout<<endl;
        }
        //cout<<"wynik: "<<min(30+results[1][distance_to_fly/100-1],20+results[2][distance_to_fly/100-1])<<endl;
        cout<<results[1][distance_to_fly/100];


    how_many_cases--;
    }




return 0;
}
