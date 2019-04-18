#include <iostream>
#include <string>
#include <vector>
using namespace std;


main()
{
    int cases;
    cin>>cases;
    vector <string> button;
    button.push_back(" ");
    button.push_back(".,?\"");
    button.push_back("abc");
    button.push_back("def");
    button.push_back("ghi");
    button.push_back("jkl");
    button.push_back("mno");
    button.push_back("pqrs");
    button.push_back("tuv");
    button.push_back("wxyz");

    while(cases>0)
    {
        int length;
        cin>>length;
        int tmp;
        int buttons[length];
        int pushes[length];
        for(int i=0; i<length; i++)
        {
            cin>>tmp;
            buttons[i]=tmp;
        }
        for(int i=0; i<length; i++)
        {
            cin>>tmp;
            pushes[i]=tmp;
        }
        for(int i=0; i<length; i++)
        {
            cout<<button[buttons[i]][pushes[i]-1];
        }
        cout<<endl;
    cases--;
    }

return 0;
}
