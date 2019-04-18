#include <iostream>
#include <vector>
#include <set>
using namespace std;


main()
{
    int cases;
    cin>>cases;
    while(cases>0)
    {
        int snowflakes_counter, tmp;
        int result;
        int current_max;

        cin>>snowflakes_counter;
        tmp=snowflakes_counter;
        vector <int> snowflakes;
        int new_snowflake;
        while(snowflakes_counter>0)
        {
            cin>>new_snowflake;
            snowflakes.push_back(new_snowflake);
            snowflakes_counter--;
        }

        set <int> unique_snowflakes;
        int first=0;
        int last=0;


        result=0;
        snowflakes_counter=tmp;
        while(last < snowflakes_counter)
        {
            while(unique_snowflakes.count(snowflakes[last]) == 0 && last < snowflakes_counter)
            {
                unique_snowflakes.insert(snowflakes[last]);
                last++;
            }

            if((last - first) > result)
            {
                result = last-first;
            }

            unique_snowflakes.erase(snowflakes[first]);
            first++;
        }
        /*
        for(k=snowflakes.size(); k>0; k--)
        {
            for(i=0; i<k; i++)
            {
                for(j=i; j<k; j++)
                {
                    if(snowflakes[i]==snowflakes[j])
                    {
                        if(current_max>result)
                        {result = current_max;}
                        current_max=0;
                    }
                    else
                    {
                        current_max++;
                    }
                }
            }
        }
        */
        cout<<result<<endl;
    cases--;
    }
return 0;
}