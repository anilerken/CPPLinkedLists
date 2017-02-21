#include <iostream>
#include "Mlist.h"
using namespace std;


class Track
{
public:
    Track();
    Track( string title, int releaseYear);
    string title;
    int releaseYear;
    Mlist L;
};

