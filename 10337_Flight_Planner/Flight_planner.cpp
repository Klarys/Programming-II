#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fuel(vector < vector < int > > values, int distance_to_fly)
{
    vector < vector < int > > results(values.size(), vector < int > (distance_to_fly, 1000));
    results[0][0] = 30 - values[0][0];
    results[1][0] = 60 - values[0][0];

    for(int i = 1; i < distance_to_fly; i++)
    {
        for(int j = 0; j < values.size(); j++)
        {
            int lift, hold, dive;

            if(j + 1 < values.size())
            {
                lift = results[j+1][i-1] - values[j+1][i] + 20;
            }
            else
            {
                lift = 1000;
            }
            hold = results[j][i-1] - values[j][i] + 30;

            if(j-1 >= 0)
            {
                dive = results[j-1][i-1] - values[j-1][i] + 60;
            }
            else
            {
                dive = 1000;
            }
            results[j][i] = min(lift, min(hold, dive));
        }
    }
    return results[0][distance_to_fly-1];
}

int main() {

    int how_many_cases;
    cin >> how_many_cases;
    for(int i = 0; i < how_many_cases; i++)
    {
        vector < vector < int > > values;
        int distance_to_fly;
        cin >> distance_to_fly;
        distance_to_fly /= 100;

        for(int i = 0; i < 10; i++)
        {
            vector < int > row;
            for(int j = 0; j < distance_to_fly; j++)
            {
                int wind;
                cin >> wind;
                row.push_back(wind);
            }
            values.push_back(row);
        }
        reverse(values.begin(), values.end());
        int result = fuel(values, distance_to_fly);

        cout << result << endl << endl;
    }
return 0;
}