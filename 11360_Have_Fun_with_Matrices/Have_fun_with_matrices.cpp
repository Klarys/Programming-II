#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

template <typename T> class Matrix
{
    private:
        vector <vector <T> > values;
    public:
        //konstruktory
        Matrix(int matrix_size);

        //do zadania
        void row(int row_a, int row_b);
        void col(int col_a, int col_b);
        void inc();
        void dec();
        void transpose();
        //operatory
        friend istream & operator>>(istream & input, Matrix <T> &m)
        {
            string row;
            for(int i=0; i<m.values.size(); i++)
            {
                cin>>row;
                for(int j=0; j<m.values[i].size(); j++)
                {
                    m.values[i][j] = row[j] - '0';
                }
            }
        return input;
        }
        friend ostream & operator<<(ostream & output, Matrix <T> &m)
        {
            for(int i=0; i<m.values.size(); i++)
            {
                for(int j=0; j<m.values[i].size(); j++)
                {
                    cout<<m.values[i][j]<<" ";
                }
                cout<<endl;
            }
        return output;
        }
};

template <typename T> Matrix<T>::Matrix(int matrix_size)
{
    this->values = vector <vector <T> > (matrix_size, vector <T>(matrix_size));
}

template <typename T> void Matrix<T>::row(int row_a, int row_b)
{
    this->values[row_a-1].swap(this->values[row_b-1]);
}

template <typename T> void Matrix<T>::col(int col_a, int col_b)
{
    for(int i=0; i<this->values.size(); i++)
    {
        swap(this->values[i][col_a-1], this->values[i][col_b-1]);
    }
}

template <typename T> void Matrix<T>::inc()
{
    for(int i=0; i<this->values.size(); i++)
    {
        for(int j=0; j<this->values[i].size(); j++)
        {
            this->values[i][j] = (this->values[i][j] +1)%10;
        }
    }
}

template <typename T> void Matrix<T>::dec()
{
    for(int i=0; i<this->values.size(); i++)
    {
        for(int j=0; j<this->values[i].size(); j++)
        {
            this->values[i][j] = (this->values[i][j] -1)%10;
            if(this->values[i][j]<0)
            {
                this->values[i][j]+=10;
            }
        }
    }
}

template <typename T> void Matrix<T>::transpose()
{
    //Matrix result(this->values.size());
    for(int i=0; i<this->values.size(); i++)
    {
        for(int j=i; j<this->values[i].size(); j++)
        {
            swap(this->values[i][j],this->values[j][i]);
        }
    }
}
/*
template <typename T> istream & operator>>(istream & input, Matrix <T> m)
{
    return input;
}*/

main()
{
    int how_many_cases, current_case=1;
    int how_many_operations, x, y;
    string operation;
    cin>>how_many_cases;
    while(how_many_cases--)
    {
        int matrix_size;
        cin>>matrix_size;
        Matrix <int> m(matrix_size);
        cin>>m;
        cin>>how_many_operations;
        while(how_many_operations--)
        {
            cin>>operation;
            if(operation[0]=='r')
            {
                cin>>x>>y;
                m.row(x,y);
            }
            else if(operation[0]=='c')
            {
                cin>>x>>y;
                m.col(x,y);
            }
            else if(operation[0]=='i')
            {
                m.inc();
            }
            else if(operation[0]=='d')
            {
                m.dec();
            }
            else if(operation[0]=='t')
            {
                m.transpose();
            }
        }
        cout<<"Case #"<<current_case<<endl;
        cout<<m;
        cout<<endl;
        current_case++;
    }
return 0;
}