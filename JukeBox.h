#include <iostream>
#include "Track.h"

typedef Track Track;

using namespace std;

class JukeBox
{
public:
    JukeBox();
    ~JukeBox();
    void addTrack( string trackTitle, int releaseYear );
    void removeTrack( string trackTitle );
    void addMusician( string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole );
    void removeMusician( string trackTitle, string musicianFirstName, string musicianLastName );
    void showAllTracks();
    void showTrack( string trackTitle );
    void showMusicianRoles( string musicianFirstName, string musicianLastName );

private:
    struct TNode
    {
        Track item;
        TNode *next;
    };
    TNode* head;
    int size;
};
