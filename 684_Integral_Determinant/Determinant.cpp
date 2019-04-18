#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

template <typename T> class Matrix
{
    public:
        int R,C;
        vector <vector <T> > values;

        //konstruktory
        Matrix() {};
        Matrix(int R, int C);

        //do zadania
        void row(int row_a, int row_b);
        void col(int col_a, int col_b);
        void inc();
        void dec();
        void transpose();
        //operatory
        friend istream & operator>>(istream & input, Matrix <T> &m)
        {
            for(int i=0; i<m.values.size(); i++)
            {
                for(int j=0; j<m.values[i].size(); j++)
                {
                    cin>>m.values[i][j];
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

template <typename T> Matrix<T>::Matrix(int R, int C)
{
    this->values = vector <vector <T> > (R, vector <T>(C));
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

/////////////////////////////////////////////////////////////////////////////////
//klasa dziedziczaca
template <typename T> class SquareMatrix : public Matrix<T>
{
    public:
    SquareMatrix(int x);

    SquareMatrix(int x, vector < vector < T > > table)
    {
        this->R = x;
        this->C = x;
        this->values = vector <vector <T> > (this->R, vector <T>(this->C));
    }

    T determinant()
    {
        T result = 1;

        for(int i=0; i<this->values.size()-1; i++)
        {
            this->abs_value(i, result);
            int max1, max2;
            this->max_values(max1, max2, i);

            if(this->values[max1][i] == 0 && this->values[max2][i] == 0)
            {
                return 0;
            }
            while(this->values[max2][i] != 0)
            {
                this->subRows(max2+1, max1+1);
                this->max_values(max1, max2, i);
            }
            if(max1 != i)
            {
                this->row(i+1, max1+1);
                result *= -1;
            }
        }
        for(int i=0; i<this->values.size(); i++)
        {
            result *= this->values[i][i];
        }

    return result;
    }

    void subRows(int row_a, int row_b)
    {
        for(int i=0; i<this->values.size(); i++)
        {
            this->values[row_b-1][i] -= this->values[row_a-1][i];
        }
    }

    void multiplyRow(int row_a, T y)
    {
        for(int i=0; i<this->values.size(); i++)
        {
            this->values[row_a-1][i] *= y;
        }
    }


    void max_values(int &max1, int &max2, int col)
    {
        max1 = col;
        for(int i=col; i<this->values.size(); i++)
        {
            if(this->values[i][col] > this->values[max1][col])
            {
                max1 = i;
            }
        }

        if(max1 != col) max2 = col;
        else max2 = col+1;

        for(int i=col; i<this->values.size(); i++)
        {
            if(max1 != i)
            {
                if(this->values[i][col] > this->values[max2][col])
                {
                    max2 = i;
                }
            }
        }
    }

    void abs_value(int col, T &det)
    {
        for(int i=0; i<this->values.size(); i++)
        {
            if(this->values[i][col]<0)
            {
                this->multiplyRow(i+1, -1);
                det *= -1;
            }
        }
    }

    friend istream & operator>>(istream & input, SquareMatrix <T> &m)
    {
        for(int i=0; i<m.values.size(); i++)
        {
            for(int j=0; j<m.values[i].size(); j++)
            {
                cin>>m.values[i][j];
            }
        }
    return input;
    }
};

template <typename T> SquareMatrix<T>::SquareMatrix(int matrix_size)
{
    this->values = vector <vector <T> > (matrix_size, vector <T>(matrix_size));
}

main()
{
    int matrix_size;
    do
    {
        cin>>matrix_size;
        if(matrix_size==0)
        {
            cout<<"*"<<endl;
            break;
        }

        SquareMatrix <int> m(matrix_size);
        cin>>m;
        cout<<m.determinant()<<endl;
    }while(matrix_size!=0);
return 0;
}