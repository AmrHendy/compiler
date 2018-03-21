#include "Partition.h"
#include <set>

Partition::Partition(void){}

Partition::Partition(char identifier)
{
    this -> identifier = identifier ;
}

Partition::Partition(char identifier, vector<Composite_State>states)
{
    this -> identifier = identifier ;
    this -> states = states ;
}

Partition::~Partition(void){}

void Partition::add_state(Composite_State s)
{
    this -> states.push_back(s) ;
}

bool Partition::belong(Composite_State s)
{
    for(Composite_State i : states)
        if(s == i)
            return true ;
    return false ;
}

vector<Partition>
Partition::split()
{
   /* GATHER DIFFERENT IDS */
   set<string> ids ;
   for(string s : states_id)
   {
       ids.insert(s) ;
   }

   /* MAKE NEW PARTITIONS ACCORDING IDENTIFERS */
   vector<Partition> res ;
   for(string s : ids){
        Partition n_partition ;
        for(int i=0 ; i< (int) states_id.size() ; i++)
        {
            if(states_id[i] == s)
                n_partition.add_state(states[i]) ;
        }
        res.push_back(n_partition) ;
   }

   return res ;
}



char Partition::get_identifier()
{
    return this -> identifier ;
}

vector<Composite_State> Partition::get_states()
{
    return this -> states ;
}

void Partition::set_identifier(char identifier)
{
    this -> identifier = identifier ;
}

void Partition::set_state_id(vector<string> states_id)
{
    this -> states_id = states_id ;
}


















