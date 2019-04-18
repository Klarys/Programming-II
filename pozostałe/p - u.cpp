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

    bool alarm_button_status();
    bool stop_button_status();
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

bool Button_Panel::alarm_button_status()
{
    return alarm_button;
}

bool Button_Panel::stop_button_status()
{
    return stop_button;
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
    if(this->buttons.stop_button_status() == 1) //jesli stop_button ma wartosc 1 to wcisnij go jeszcze raz
    {
        this->buttons.push_stop_button();
    }
}

//pozostale
void print_menu()
{
    cout<<"Wybierz co chcesz zrobic:"<<endl;
    cout<<"1 - dodaj nowego pasazera"<<endl;
    cout<<"2 - uruchom symulacje"<<endl;
    cout<<"0 - zakoncz dzialanie programu"<<endl;
}

main()
{
    int mode=0;
    while(mode!=1 && mode!=2)
    {
        cout<<"Wybierz tryb w którym ma dzialac program:"<<endl;
        cout<<"1 - tryb uproszczony, wszyscy pasazerowie podawani sa na poczatku"<<endl;
        cout<<"2 - tryb normalny, kazdy \"krok\" na trasie windy wypisywany jest osobno, mozna dodac pasazerow w trakcie wykonywania programu"<<endl;
        cin>>mode;
    }

    int choice = -1;
    //MODE 1
    if(mode == 1)
    {
        while(true)
        {
            print_menu();
            cin>>choice;
            switch(choice)
            {
            case 1:
                break;
            case 2:
                break;
            case 0:
                cout<<"Konczenie dzialania programu...";
                return 0;

            }
        }
    }
    //MODE 2
    if(mode == 2)
    {

    }

    return 0;
}
