#include <iostream>
#include <vector>
using namespace std;

int religion_index(int index, vector <int> &religions)
{
    if(index!=religions[index])
    {
        religions[index] = religion_index(religions[index], religions);
        return religions[index];
    }
    else
    {
        return index;
    }
}

main()
{
    int students;
    int pairs;
    int cases=1;

    while(cin>>students>>pairs && students!=0 && pairs!=0)
    {
        vector <int> religions;
        for(int i=0; i<=students; i++)
        {
            religions.push_back(i);
        }

        int result = students;
        int i,j;
        for(int k=0; k<pairs; k++)
        {
            cin>>i>>j;
            int religion_i = religion_index(i, religions);
            int religion_j = religion_index(j, religions);

            if(religion_i != religion_j)
            {
                religions[religion_i] = religion_j;
                result--;
            }

        }

    cout<<"Case "<<cases<<": "<<result<<endl;
    cases++;
    }
return 0;
}