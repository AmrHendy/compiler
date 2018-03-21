#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include "../data_structures/transition_table/Composite_State.h"

using namespace std ;

class Partition
{
    /* attributes */
    private:

        vector<Composite_State> states ;
        /* IDENTIFIERS TO SPLIT STATES AFTER RE_PARTITION*/
        vector<string> states_id ;
        char identifier ;

    public:

        /* constructor and destructor */
        Partition(void);
        Partition(char identifier);
        Partition(char identifier , vector<Composite_State> states);
        virtual ~Partition(void);

        /* interface functions */
        void add_state(Composite_State);
        bool belong(Composite_State);
        vector<Partition> split();

        /* getters and setters */
        char get_identifier() ;
        vector<Composite_State> get_states() ;
        void set_identifier(char identifier) ;
        void set_state_id(vector<string>) ;


};

#endif // PARTITION_H
