#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include <set>
#include "CompositeState.h"
#include "../LOGGER/Logger.h"


using namespace std ;

class Partition
{

    public:

        /* constructor and destructor */
        Partition(int);
        Partition(int,vector<CompositeState> states);
        virtual ~Partition(void);

        /* interface functions */
        CompositeState get_state(int index) ;
        CompositeState get_essential() ;
        void add_state (CompositeState) ;
        bool belong (CompositeState) ;
        int size() ;

        vector<Partition> split();

        /* getters and setters */
        int get_identifier() ;
        void set_identifier(int identifier) ;
        void add_state_id(vector<int>) ;

        void print() ;

    /* attributes */
    private:
        vector<CompositeState> states ;
        /* IDENTIFIERS TO SPLIT STATES AFTER RE_PARTITION*/
        vector<vector<int>> states_id ;

        int identifier ;


};

#endif // PARTITION_H
