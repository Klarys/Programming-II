#include <iostream>
using namespace std;


class Elevator
{
    int max_weight; //500 kg max - small elevator, 1100 kg max - big elevator
    int max_passengers;
    int lowest_floor;
    int highest_floor;
    int current_floor;
    Button_Panel buttons;
    bool alarm; //0 - off, 1 - on
    vector <int> destination_floors;

    friend class Button_Panel;
    friend class Call_button;
};

class Small_Elevator: public Elevator
{
    Single_Door door;
};

class Big_Elevator: public Elevator
{
    Double_Door door;
    Emergency_Exit e_exit;
};

class Single_Door
{
    bool wing; //0 - closed, 1 - open
    friend class Small_Elevator;
    friend class Button_Panel;
};

class Double_Door
{
    bool left_wing; //0 - closed, 1 - open
    bool right_wing; //0 - closed, 1 - open
    friend class Big_Elevator;
    friend class Button_Panel;
};

class Emergency_Exit //placed on the ceiling of the big elevator
{
    bool hatch; //0 - closed, 1 - open
    friend class Big_Elevator;
};

class Button_Panel //placed inside every type of elevator, contains buttons allowing passengers to choose a destination floor
{
    vector <bool> floor_buttons;
    bool alarm_button;
    bool stop_button;
    friend class Person;
};

class Call_button //placed at every floor, allows people to call the elevator
{
    bool button; //0 - not pressed, 1 - pressed
    friend class Person;
};

class Person
{
    int weight;
    int current_floor;
    int destination_floor;
    int closest_elevator;

    void push_call_button();
    void get_in_elevator();
    void walk_out_elevator();
};

class Building
{
    vector <Small_Elevator> s_elevators;
    vector <Big_Elevator> b_elevators;
    vector <Call_button> c_buttons; //one for each floor
    vector <Person> people;
    int floors;
    int elevators;
};

