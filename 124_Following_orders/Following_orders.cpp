#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_permutation(vector <char> variables, vector < pair <char, char> > orderings) //funkcja sprawdzajaca czy dana permutacja spelnia podane w inpucie warunki
{
    for(int i=0;i<orderings.size();i++)
    {
        vector<char>::iterator first_occurrence = search(variables.begin(), variables.end(), &orderings[i].first, (&orderings[i].first)+1);
        vector<char>::iterator second_occurrence = search(variables.begin(), variables.end(), &orderings[i].second, (&orderings[i].second)+1);
        int indeks_of_first_in_pair=first_occurrence-variables.begin();
        int indeks_of_second_in_pair=second_occurrence-variables.begin();

        if(indeks_of_second_in_pair < indeks_of_first_in_pair)
        {
            return false;
        }
    }
return true;
}

main()
{
    string orderings_input, input, variables;
    int i;
    while(getline(cin, input))
    {
        vector <char> variables;
        vector < pair <char, char> > orderings;
        //przetwarzania inputu
        for(i=0;i<input.size();i=i+2)
        {
            variables.push_back(input[i]);
        }
        sort(variables.begin(),variables.end()); //sortowanie (konieczne bo specyfikacja działania next_permutation())
        getline(cin,orderings_input); //pobranie linii z warunkami
        for(i=0;i<orderings_input.size();i=i+4)
        {
            orderings.push_back(make_pair(orderings_input[i],orderings_input[i+2]));
        }
        //wypisywanie odpowiednich permutacji
        do
            {
                if(check_permutation(variables, orderings))
                {
                    //wypisanie
                    for(i=0;i<variables.size();i++)
                    {
                        cout<<variables[i];
                    }
                    cout<<endl;
                }
              }while(next_permutation(variables.begin(),variables.end()));
    cout<<endl;
    }
return 0;
}