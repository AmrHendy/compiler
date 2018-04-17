#include "../../../header/LexcialAnalyzer/MachineStructure/Partition.h"

Partition::Partition(int identifier)
{
    this->identifier = identifier ;
    this-> start = 0 ;
}

Partition::Partition(int identifier, vector<CompositeState*>states)
{
    this->identifier = identifier ;
    this -> states = states ;
    for(CompositeState* s : this -> states)
    {
        if(s->is_start())
            start = 1 ;
        states_belong.insert(s->get_id());
    }

}

Partition::~Partition(void)
{
    this -> states.clear() ;
    this -> states_id.clear() ;
}

CompositeState*
Partition::get_state(int index)
{
    if(index<0)
        return NULL ;
    return this -> states[index] ;
}

CompositeState*
Partition::get_essential()
{
    if(start)
        states[0]->set_start();
    return states[0] ;
}

void
Partition::add_state(CompositeState* s)
{
    if(s->is_start())
        start = 1 ;
    states_belong.insert(s->get_id());
    this -> states.push_back(s) ;
}

bool
Partition::belong(CompositeState s)
{
    return states_belong.count(s.get_id());
}

int
Partition::size()
{
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
    vector<int> vis(states.size(),0) ;
    int left = states.size() ;

    while(left > 0)
    {
        Partition* p = new Partition(0) ;
        for(int i=0 ; i<(int)states.size() ; i++)
        {
            if(!vis[i])
            {
                p->add_state(states[i]) ;
                p->add_state_id(states_id[i]) ;
                res.push_back(*p) ;
                vis[i] = 1 ;
                left-- ;
                break;
            }
        }
        for(int j=0 ; j<(int)states.size() ; j++)
        {
            if(!vis[j] && res.back().can_add(states_id[j]))
            {
                res.back().add_state(states[j]);
                res.back().add_state_id(states_id[j]);
                vis[j] = 1 ;
                left-- ;
            }
        }
    }

    return  res;
}


bool
Partition::can_add(vector<int> to_add_id)
{
    for(vector<int> v : states_id)
    {
        if(!is_equal_id(v,to_add_id))
            return false ;
    }
    return true ;
}

bool
Partition::is_equal_id (vector<int> v1, vector<int> v2)
{
    if(v1.size() != v2.size())
        return false ;
    for(int i=0 ; i< (int)v1.size() ; i++)
    {
        if(v1[i] != v2[i])
            return false;
    }
    return true ;
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
Partition::add_state_id(vector<int> id)
{
    states_id.push_back(id) ;
}

void Partition::print()
{
    Logger::logger.print_string("\tPartition { \n", Files::log_file) ;
    for(CompositeState* c : states)
    {
        c->print();
    }
    Logger::logger.print_string("\n\t}", Files::log_file);
}


