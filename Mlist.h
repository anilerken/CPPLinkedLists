#include <iostream>
#include "Musician.h"

typedef Musician Musician;
using namespace std;


class Mlist
{
public:
    Mlist();
    ~Mlist();
    void addMusician( string musicianFirstName, string musicianLastName, string musicianRole );
    void display();
    void removeMusician(string musicianFirstName, string musicianLastName);
    bool showMusician( string musicianFirstName, string musicianLastName);

private:
    struct MNode
    {
        Musician item;
        MNode *next;
    }  ;
    MNode *head;
    int size;
};
