#ifndef TRANSITION_TABLE_H_  /* Include guard */
#define TRANSITION_TABLE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <set>
#include "Transition_Table.h"
#include "Row.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Transition_Table
{
private:
    /* attributes */
    vector<Row> rows ;
    set<char> alphabet ;

public:
    /* constructor */
    Transition_Table(void);   // This is the constructor declaration
    ~Transition_Table(void);  // This is the destructor: declaration

    /* interface functions */
    void add_row(Composite_State id);
    void add_transition (Composite_State id, char trans, State to );
    void add_transition (Composite_State id, char trans, Composite_State to );
    bool row_found(Composite_State id);
    set<char> get_alphabet () ;


};


#endif // COMMANDS_H_
