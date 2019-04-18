#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point
{
public:
    double x;
    double y;

    Point()
    {
        x=0;
        y=0;
    }
    Point(double a, double b)
    {
        this->x=a;
        this->y=b;
    }
    friend istream& operator>>(istream& input, Point &p)
    {
        cin>>p.x>>p.y;
        return input;
    }
};

class Figure
{
    public:
    virtual bool containing_check(Point p){};
};

class Rectangle:public Figure
{
public:
    Point upper_left_corner;
    Point upper_right_corner;
    Point lower_left_corner;
    Point lower_right_corner;


    Rectangle(){};
    Rectangle (Point ulc, Point lrc)
    {
        this->upper_left_corner = ulc;
        this->upper_right_corner = Point(lrc.x, ulc.y);
        this->lower_left_corner = Point(ulc.x, lrc.y);
        this->lower_right_corner = lrc;
    }
    virtual bool containing_check(Point p);
};

class Circle:public Figure
{
public:
    Point center;
    double radius;


    Circle(){};
    Circle(Point center_input, double radius_input)
    {
        this->center = center_input;
        this->radius = radius_input;
    }
    virtual bool containing_check(Point p);
    //friend istream& operator>>(istream& input, Circle &c);
};

class Triangle:public Figure
{
public:
    Point vertex1;
    Point vertex2;
    Point vertex3;

    Triangle(){};
    Triangle(Point a, Point b, Point c)
    {
        vertex1 = a;
        vertex2 = b;
        vertex3 = c;
    }
    virtual bool containing_check(Point p);
    double sign(Point p1, Point p2, Point p3)
    {
        return (((p1.x - p3.x) * (p2.y - p3.y)) - ((p2.x - p3.x) * (p1.y - p3.y)));
    }
    //friend istream& operator>>(istream& input, Triangle &t);
};



bool Rectangle::containing_check(Point p)
{
    return ((p.x > this->upper_left_corner.x) && (p.x < this->lower_right_corner.x) && (p.y < this->upper_left_corner.y) && (p.y > this->lower_right_corner.y));
}

bool Circle::containing_check(Point p)
{
    return (sqrt((this->center.x-p.x)*(this->center.x-p.x) + (this->center.y-p.y)*(this->center.y-p.y))<this->radius);
}

bool Triangle::containing_check(Point p)
{
        double d1, d2, d3;
        bool negative, positive;

        d1 = sign(p, this->vertex1, this->vertex2);
        d2 = sign(p, this->vertex2, this->vertex3);
        d3 = sign(p, this->vertex3, this->vertex1);

        negative = ((d1 <= 0) || (d2 <= 0) || (d3 <= 0));
        positive = ((d1 >= 0) || (d2 >= 0) || (d3 >= 0));

        return !(positive && negative);
    /*
    double A_line1 = this->vertex2.y - this->vertex1.y/this->vertex2.x - this->vertex1.x;
    double B_line1 = this->vertex1.y - A_line1 * this->vertex1.x;

    double A_line2 = this->vertex1.y - this->vertex3.y/this->vertex1.x - this->vertex3.x;
    double B_line2 = this->vertex3.y - A_line2 * this->vertex3.x;

    double A_line3 = this->vertex2.y - this->vertex3.y/this->vertex2.x - this->vertex3.x;
    double B_line3 = this->vertex3.y - A_line3 * this->vertex3.x;

    return ((p.y > (A_line1 * p.x + B_line1)) || (p.y < (A_line2 * p.x + B_line2)) || (p.y > (A_line3 * p.x + B_line3)));
    */
}

main()
{
    char figure_type;

    //pobieranie figur
    vector <Figure*> figures;
    while(cin>>figure_type && figure_type!='*')
    {
        Point a,b,c;
        double r;
        if(figure_type == 'r')
        {
            cin>>a>>b;
            Figure *new_figure = new Rectangle(a,b);
            figures.push_back(new_figure);
        }
        else if(figure_type == 'c')
        {
            cin>>a>>r;
            Figure *new_figure = new Circle(a,r);
            figures.push_back(new_figure);
        }
        else if(figure_type == 't')
        {
            cin>>a>>b>>c;
            Figure *new_figure = new Triangle(a,b,c);
            figures.push_back(new_figure);
        }
    }

    //pobieranie punktow
    Point input_point;
    int point_counter=0;
    while(cin>>input_point)
    {
         if(input_point.x == 9999.9 && input_point.y == 9999.9)
         {
             break;
         }
         else
         {
            point_counter++;
            int contained = 0;
            for(int j=1; j<=figures.size(); j++)
            {

                if(figures[j-1]->containing_check(input_point))
                {
                    contained++;
                    cout<<"Point "<<point_counter<<" is contained in figure "<<j<<endl;
                }
            }
            if(contained == 0)
            {
                cout<<"Point "<<point_counter<<" is not contained in any figure "<<endl;
            }
         }
    }

return 0;
}