#include <iostream>
#include <vector>
using namespace std;

main()
{
    int height;
    int test=1;
    while(cin>>height)
    {
        //end of input
        if(height==(-1))
        {
            return 0;
        }
        //input
        vector <int> heights;
        heights.push_back(height);
        while(cin>>height)
        {

            if(height==(-1))
            {
                break;
            }
            else
            {
                heights.push_back(height);
            }
        }
        //fidning longest decreasing subsequence
            int missiles_hit[heights.size()];
            int i, j, max_missiles_hit = 0;
            for (i = 0; i < heights.size(); i++)
            {
                missiles_hit[i] = 1;
            }
            for (i = 1; i < heights.size(); i++)
            {
                for (j = 0; j < i; j++)
                {
                    if (heights[i] <= heights[j] && missiles_hit[i] < missiles_hit[j] + 1)
                    missiles_hit[i] = missiles_hit[j] + 1;
                }
            }
            for (i = 0; i < heights.size(); i++)
            {
                if (max_missiles_hit < missiles_hit[i])
                {
                    max_missiles_hit = missiles_hit[i];
                }
            }
            //output
            cout<<"Test #"<<test<<":"<<endl;
            cout<<"  maximum possible interceptions: "<<max_missiles_hit<<endl;
            test++;
    }
return 0;
}
