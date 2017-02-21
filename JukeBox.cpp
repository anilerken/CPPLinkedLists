#include "JukeBox.h"

JukeBox::JukeBox()
{
    head = NULL;
    size = 0;
}

JukeBox::~JukeBox()
{
    while ( head != NULL )
    {
        removeTrack(head->item.title);
    }
}

bool equals(const string& a, const string& b)
{
    int sz = a.size();
    if ( b.size() != sz)
        return false;
    for ( int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

void JukeBox::removeMusician( string trackTitle, string musicianFirstName, string musicianLastName )
{
    bool found = false;
    TNode* cur = head;
    while ( found != true && cur != NULL )
    {
        //if ( cur ->item.title == trackTitle )
        if ( equals( cur->item.title, trackTitle))
            found = true;
        if ( !found )
            cur = cur -> next;
    }
    if ( !found )
        cout << "This track doesn't exist" <<endl;
    if ( found )
    {
        cur->item.L.removeMusician( musicianFirstName, musicianLastName);
    }

}


void JukeBox::addMusician( string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole )
{
    bool found = false;
    TNode* cur = head;
    while ( found != true && cur != NULL )
    {
        if ( equals( cur ->item.title, trackTitle ))
            //if ( cur ->item.title == trackTitle )
            found = true;
        if ( !found )
            cur = cur -> next;
    }

    if ( found )
        cur->item.L.addMusician(musicianFirstName, musicianLastName, musicianRole);
    if ( !found )
        cout << "Such track doesn't exist. Musician can not be added" << endl;
}

void JukeBox::showTrack(string trackTitle)
{
    bool found = false;
    TNode* cur = head;

    while ( found != true && cur != NULL )
    {
        //if ( cur->item.title == trackTitle )
        if ( equals( cur->item.title, trackTitle ))
        {
            found = true;
        }
        if ( !found )
            cur = cur ->next;
    }


    if ( found )
    {
        cout << "Title: " << cur->item.title << endl;
        cout << "Release year: " << cur ->item.releaseYear << endl;

        cur->item.L.display();
    }
    else
    {
        cout << "--None--" << endl;
    }
}

void JukeBox::addTrack( string trackTitle, int releaseYear)
{
    bool exists = false;
    TNode* cur = head;
    while ( cur != NULL && exists == false )
    {
        //if( (cur->item).title == trackTitle )
        if ( equals( cur->item.title, trackTitle ))
        {
            exists = true;
        }
        cur = cur->next;
    }

    if ( !exists)
    {
        Track newTrack( trackTitle, releaseYear);
        TNode* newNode = new TNode;
        newNode->item = newTrack;

        if ( head == NULL)
        {
            head = newNode;
            head->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    if ( exists )
        cout << "Track already exists."<<endl;
    //delete cur;
}

void JukeBox::removeTrack(string trackTitle)
{
    bool exists = false;
    int index = 0;
    TNode *cur = head;
    while ( cur != NULL && exists == false)
    {
        //if ( cur->item.title == trackTitle )
        if ( equals( cur->item.title, trackTitle ))
            exists = true;
        else
        {
            cur = cur->next;
            index++;
        }
    }
    TNode* prev = head;
    cur = head;
    if ( exists == false)
    {
        cout << "No such track."<<endl;
    }

    else
    {
        if ( index == 0 )
        {
            cur = head;
            head = head->next;
        }
        if ( index != 0 )
        {

            for ( int i = 0; i < index - 1; i++ )
            {
                prev = prev->next;
            }
            cur = prev->next;
            prev->next = cur->next;
        }
        cur->next = NULL;
        delete cur;
        cur = NULL;

    }
}

void JukeBox::showAllTracks()
{
    TNode *cur = head;
    if ( cur == NULL )
        cout << "---None---" << endl;
    else
    {
        while ( cur != NULL )
        {
            cout << cur->item.title;
            cout << ", ";
            cout << cur ->item.releaseYear<<endl;
            cur = cur ->next;
        }
    }
}

void JukeBox::showMusicianRoles( string musicianFirstName, string musicianLastName )
{
    bool notfound = true;
    cout << musicianFirstName << " " << musicianLastName << endl;
    TNode* cur = head;
    while ( cur != NULL )
    {
        if ( cur->item.L.showMusician( musicianFirstName, musicianLastName ))
        {
            notfound = false;
            cout << ", " << cur->item.title << ", " << cur->item.releaseYear << endl;
        }
        cur = cur ->next;
    }
    if ( notfound)
        cout << "---None---"<< endl;
}
