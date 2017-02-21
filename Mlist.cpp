#include "Mlist.h"

Mlist::Mlist()
{
    head = NULL;
    size = 0;
}
Mlist::~Mlist()
{
    while ( head != NULL )
        removeMusician( head->item.firstname, head->item.lastname );
}

bool equals2(const string& a, const string& b)
{
    int sz = a.size();
    if ( b.size() != sz)
        return false;
    for ( int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

void Mlist::removeMusician( string musicianFirstName, string musicianLastName )
{
    bool exists = false;
    MNode* cur = head;
    MNode* prev = head;
    int count = 0;
    while ( cur != NULL && exists == false )
    {
        //if ( cur->item.firstname == musicianFirstName && cur->item.lastname == musicianLastName)
        if ( equals2( cur->item.firstname, musicianFirstName ) && equals2( cur->item.lastname, musicianLastName ))
            exists = true;
        if ( !exists)
        {
            cur = cur->next;
            count++;
        }
    }
    if ( !exists )
        cout << "This musician doesn't exist in this track" << endl;
    else
    {
        while ( count > 1  )
        {
            prev = prev ->next;
            count--;
        }
        //if ( cur->item.firstname == head->item.firstname && cur->item.lastname == head->item.lastname )
        if ( equals2( cur->item.firstname, head->item.firstname ) && equals2( cur->item.lastname, head->item.lastname ))
            head = head ->next;
        else
        {
            prev ->next = cur ->next;
        }
        cur ->next = NULL;
        delete cur;
        cur = NULL;
    }
}

void Mlist::addMusician( string musicianFirstName, string musicianLastName, string musicianRole )
{
    bool exists = false;
    MNode* cur = head;
    while ( cur != NULL )
    {
        //if ( cur->item.firstname == musicianFirstName && cur->item.lastname == musicianLastName)
        if ( equals2( cur->item.firstname, musicianFirstName ) && equals2( cur->item.lastname, musicianLastName ))
            exists = true;
        cur = cur->next;
    }
    if ( exists )
        cout << "This musician already exists in this track." << endl;
    else
    {
        MNode* newnode = new MNode;
        Musician m( musicianFirstName, musicianLastName, musicianRole);
        newnode ->item = m;
        if ( head == NULL )
        {
            head = newnode;
            head->next = NULL;
        }

        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
}

void Mlist::display()
{
    MNode* cur = head;
    while ( cur != NULL)
    {
        cout << cur->item.firstname << " " << cur->item.lastname << " " << cur->item.role << endl;
        cur = cur ->next;
    }
}

bool Mlist::showMusician( string musicianFirstName, string musicianLastName)
{
    bool exists = false;
    MNode* cur = head;
    while ( cur != NULL )
    {
        if ( equals2( cur->item.firstname, musicianFirstName) && equals2( cur->item.lastname, musicianLastName))
        {
            cout << cur->item.role;
            exists = true;
        }
        cur = cur ->next;
    }
    return exists;
}
