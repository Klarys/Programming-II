#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool deposit(int i, int j, vector <vector <char> > &grid)
{
    if(grid[i][j]=='*')
    {
        return false;
    }
    else
    {
        grid[i][j]='*';
        if(i-1>=0)
        {
            if(j-1>=0) deposit(i-1,j-1,grid);
            deposit(i-1,j,grid);
            if(j+1<grid[i].size()) deposit(i-1,j+1,grid);
        }
        if(j+1<grid[i].size()) deposit(i,j+1,grid);
        if(i+1<grid.size())
        {
            if(j-1>=0) deposit(i+1,j-1,grid);
            deposit(i+1,j,grid);
            if(j+1<grid[i].size()) deposit(i+1,j+1,grid);
        }
        if(j-1>=0) deposit(i,j-1,grid);

    return true;
    }
}

main()
{
    int m,n;
    while(cin>>m>>n && m!=0)
    {
        vector <vector <char> > grid;
        int deposits=0;
        char tmp;
        vector <char> tmpv;
        for(int i=0; i<m ;i++)
        {
            grid.push_back(tmpv);
        }

        for(int i=0; i<m ;i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>tmp;
                grid[i].push_back(tmp);
            }
        }

        for(int i=0; i<m ;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(deposit(i,j,grid)) deposits++;
            }
        }
        cout<<deposits<<endl;
        /*
        for(int i=0; i<m ;i++)
        {
            deposits[m][n]=0;
            grid[m][n]='*';
        }
        for(int i=0; i<n ;i++)
        {
            deposits[m][n]=0;
            grid[m][n]='*';
        }

        deposit=0;
        for(int i=1; i<m ;i++)
        {
            for(int j=1; i<n; j++)
            {
                if(grid[i][j]=='@')
                {
                    if(deposits[i][j]==0)
                    {

                    }
                }
            }
        }
        */
    }
return 0;
}