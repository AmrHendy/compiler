#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include <set>
#include "CompositeState.h"


using namespace std ;

class Partition
{
    /* attributes */
    private:

        vector<CompositeState*> states ;
        /* IDENTIFIERS TO SPLIT STATES AFTER RE_PARTITION*/
        vector<string> states_id ;
        char identifier ;

    public:

        /* constructor and destructor */
        Partition(void);
        Partition(char identifier);
        Partition(char identifier , vector<CompositeState*> states);
        virtual ~Partition(void);

        /* interface functions */
        void add_state(CompositeState*);
        bool belong(CompositeState*);
        vector<Partition> split();

        /* getters and setters */
        char get_identifier() ;
        vector<CompositeState*> get_states() ;
        void set_identifier(char identifier) ;
        void set_state_id(vector<string>) ;

};

#endif // PARTITION_H
