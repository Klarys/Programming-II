#include <iostream>
using namespace std;


main()
{
    int tea_type;
    int answer;
    int correct_answers = 0;
    while(cin>>tea_type)
    {
        correct_answers = 0;
        for(int i=0;i<5;i++)
        {
            cin>>answer;
            if(answer == tea_type) correct_answers++;
        }
        cout<<correct_answers<<endl;
    }
return 0;
}
