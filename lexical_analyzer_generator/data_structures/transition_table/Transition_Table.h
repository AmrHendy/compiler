#ifndef TRANSITION_TABLE_H_  /* Include guard */
#define TRANSITION_TABLE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <set>
#include "Transition_Table.h"
#include "../dfa_generation/Partition.h"
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


    /* getters and setters */
    vector<Composite_State> get_start_states();
    vector<Composite_State> get_end_states();
    Row get_row(Composite_State id);
    Composite_State get_transition(Composite_State id, char trans);

    /* interface functions */
    set<char> get_alphabet () ;

    void add_row(Row r);
    void add_row(Composite_State id);
    bool row_found(Composite_State id);

    void add_transition (Composite_State id, char trans, State to );
    void add_transition (Composite_State id, char trans, Composite_State to );

    Transition_Table get_equavilent_table(vector<Partition> partitions) ;

private:
    /* PRIVATE FUNCTIONS */
    Partition get_partition_belong(vector<Partition> partitions , Composite_State c);

};


#endif // COMMANDS_H_
