#include <iostream>
#include <vector>
using namespace std;

int maximum(int a, int b)
{
    return (a > b)? a : b;
}

main()
{
    //input
    int i, j, x, temp;
    int number_of_events;
    cin>>number_of_events;
    int c_order[number_of_events]; //correct order
    for(i=1;i<=number_of_events;i++)
    {
        cin>>x;
        c_order[x-1]=i;
    }

    while(cin>>x)
    {
        vector <int> s_order(number_of_events); //students orders
        s_order[x-1]=1;
        for(i=2;i<=number_of_events;i++)
        {
            cin>>x;
            s_order[x-1]=i;
            //cout<<"s_o["<<x-1<<"]= "<<i<<".";
        }
        /*for(i=0;i<s_order.size();i++)
        {
            cout<<s_order[i]<<"x";
        }
        cout<<endl;*/
     //  cout<<lcs(c_order,s_order,number_of_events,number_of_events)<<endl;
        int arr[number_of_events+1][number_of_events+1]; //+1 for the columns of 0's
        for(i=0;i<=number_of_events;i++)
        {
            arr[i][0]=0;
            arr[0][i]=0;
        }
        for(i=1;i<=number_of_events;i++)
        {
            for(j=1;j<=number_of_events;j++)
            {
                if(c_order[i-1]==s_order[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                }
                else
                {
                    arr[i][j]=maximum(arr[i][j-1],arr[i-1][j]);
                }
            }
        }
        cout<<arr[number_of_events][number_of_events];
            /*
        for(i=0;i<=number_of_events;i++)
        {
            for(j=0;j<=number_of_events;j++)
            {
                   cout<<"arr["<<i<<"]["<<j<<"]="<<arr[i][j]<<".";
            }
            cout<<endl;
        }

    }

    for(i=0;i<number_of_events;i++)
    {
        cout<<"c_or: "<<c_order[i]<<" ";
    }*/
}
return 0;
}


