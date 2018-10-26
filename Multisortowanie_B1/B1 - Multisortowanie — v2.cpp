#include <iostream>
#include <vector>
using namespace std;

struct czworka
{
    int wartosci[4];
    int id;
};

main()
{
    int ile_czworek;
    int j,i,p;
    vector <czworka> czworki;
    cin>>ile_czworek;

    //wczytywanie
    for(i=0;i<ile_czworek;i++)
    {
        czworka wpisywanie;
        cin>>wpisywanie.wartosci[0]>>wpisywanie.wartosci[1]>>wpisywanie.wartosci[2]>>wpisywanie.wartosci[3];
        wpisywanie.id=(i+1);
        czworki.push_back(wpisywanie);
    }
    //sortowanie
    for(p=0;p<4;p++)
    {
        //swieza kopia
        vector <czworka> temp;
        temp=czworki;
        //sortowanie
        for(i=0;i<ile_czworek;i++)
        {
            for(j=i+1; j<ile_czworek;j++)
            if(temp[i].wartosci[p]>temp[j].wartosci[p])
            {
                swap(temp[i],temp[j]);
            }
           /* if(temp[i].wartosci[p]==temp[j].wartosci[p] && j<i)
            {
                swap(temp[i],temp[j]);
            }*/
        }
        //wypisanie w sortowaniu po p
        for(i=0;i<ile_czworek;i++)
        {
            cout<<temp[i].id<<" ";
        }
        cout<<endl;
    }
return 0;
}
