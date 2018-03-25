#include "Partition.h"

Partition::Partition(int identifier)
{
	this->identifier = identifier ;
}

Partition::Partition(int identifier , vector<CompositeState>states)
{
	this->identifier = identifier ;
    this -> states = states ;
}

Partition::~Partition(void){
	this -> states.clear() ;
	this -> states_id.clear() ;
}

CompositeState
Partition::get_state(int index){
	return this -> states[index] ;
}

CompositeState
Partition::get_essential(){
	bool accept,start ;
	for(CompositeState s : states){
		if(s.is_acceptance())
			accept = true ;
		if(s.is_start())
			start = true ;
	}
	states[0].set_start() ;
	return states[0] ;
}

void
Partition::add_state(CompositeState s)
{
    this -> states.push_back(s) ;
}

bool
Partition::belong(CompositeState s)
{
    for(CompositeState i : states)
        if(s == i)
            return true ;
    return false ;
}

int
Partition::size(){
	return this -> states.size() ;
}

vector<Partition>
Partition::split()
{
   /* GATHER DIFFERENT IDS */
   set<vector<int>> ids ;
   for(vector<int> s : states_id)
   {
       ids.insert(s) ;
   }

   /* MAKE NEW PARTITIONS ACCORDING IDENTIFERS */
   vector<Partition> res ;
   set<int> taken ;
   for(vector<int> s : ids){
        Partition n_partition(0) ;
        for(int i=0 ; i< (int) states_id.size() ; i++)
        {
        	bool eq = true;
        	if(states_id[i].size() != s.size() || taken.count(i) != 0){
        		eq = false;
        		continue;
        	}
			for(int index = 0; index < (int) states_id[i].size(); index++){
				if(states_id[i][index] == 0 || s[index] == 0 )continue;
				if(states_id[i][index] != s[index]){
					eq = false;
					break;
				}
			}
            if(eq){
            	n_partition.add_state(states[i]) ;
            	taken.insert(i);
            }
        }
        if(n_partition.size() != 0)
        	res.push_back(n_partition) ;
   }

   return res ;
}

int
Partition::get_identifier()
{
    return this -> identifier ;
}

void
Partition::set_identifier(int identifier)
{
    this -> identifier = identifier ;
}

void
Partition::add_state_id(vector<int> id){
	states_id.push_back(id) ;
}

void Partition::print(){
	Logger::logger.print_string("\tPartition { \n") ;
	for(CompositeState c : states){
		c.print();
	}
	Logger::logger.print_string("\n\t}");
}


