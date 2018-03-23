#include "Partition.h"

Partition::Partition(void){}

Partition::Partition(char identifier)
{
    this -> identifier = identifier ;
}

Partition::Partition(char identifier, vector<CompositeState>states)
{
    this -> identifier = identifier ;
    this -> states = states ;
}

Partition::~Partition(void){}

void Partition::add_state(CompositeState s)
{
    this -> states.push_back(s) ;
}

bool Partition::belong(CompositeState s)
{
    for(CompositeState i : states)
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
        	bool eq = true;
        	if(states_id[i].size() != s.size()){
        		eq = false;
        		continue;
        	}
			for(int index = 0; index < states_id[i].size(); index++){
				if(states_id[i][index] == '#' || s[index] == '#')continue;
				if(states_id[i][index] != s[index]){
					eq = false;
					break;
				}
			}
            if(eq) n_partition.add_state(states[i]) ;
        }
        res.push_back(n_partition) ;
   }

   return res ;
}



char Partition::get_identifier()
{
    return this -> identifier ;
}

vector<CompositeState> Partition::get_states()
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
