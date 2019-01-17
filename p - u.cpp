#include <iostream>
#include <vector>
using namespace std;

class Door
{
private:
    bool wing; //0 - closed, 1 - open

    friend void open_door(Door &d);
    friend void close_door(Door &d);
};

class Button_Panel //contains buttons allowing passengers to choose a destination floor
{
public: //metody i zmienne sa publiczne aby mogl ich uzywac pasazer oraz winda
    vector <bool> floor_buttons;
    bool alarm_button; //0 - not pressed, 1 - pressed
    bool stop_button; //0 - not pressed, 1 - pressed
    void push_alarm_button();
    void push_stop_button();
};

class Person
{
private:
    int weight;
    int current_floor;
    int destination_floor;

public:

};


class Elevator
{
private:
    int max_weight; //500 kg max - small elevator, 1100 kg max - big elevator
    int max_passengers;
    int lowest_floor;
    int highest_floor;
    int current_floor;
    Door doors;
    Button_Panel buttons;
    bool alarm; //0 - off, 1 - on
    vector <int> destination_floors;
    vector <Person> passengers;
    void stop_elevator();
};





//DOOR
void open_door(Door &d)
{
    if(d.wing == 0)
    {
       d.wing = 1;
    }
}
void close_door(Door &d)
{
    if(d.wing == 1)
    {
       d.wing = 0;
    }
   
}
//BUTTON_PANEL
void Button_Panel::push_alarm_button()
{
    if(this->alarm_button == 0)
    {
        this->alarm_button = 1;
    }
    else if(this->alarm_button == 1)
    {
        this->alarm_button = 0;
    }
    
}

void Button_Panel::push_stop_button()
{
    if(this->stop_button == 0)
    {
        this->stop_button = 1;
    }
    else if(this->stop_button == 1)
    {
        this->stop_button = 0;
    }
}

//PERSON

//ELEVATOR
void Elevator::stop_elevator() //usuwa elementy z destination_floors, zmienia stan przyciskow pieter na 0, zmienia stan przycisku stop na 0
{
    this->destination_floors.erase(destination_floors.begin(), destination_floors.end());
    for(int i=0; i<this->buttons.floor_buttons.size(); i++)
    {
        this->buttons.floor_buttons[i] = 0;
    }
    this->buttons.unpush_stop_button();
}


main()
{
    return 0;
}
