/*
 * PartitionRapper.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: abdelrhman
 */

#include "../../../header/LexcialAnalyzer/MachineStructure/PartitionRapper.h"
#include "../../../header/LexcialAnalyzer/Helper/NumberGenerator.h"

Partition_Rapper::Partition_Rapper()
{
}


Partition_Rapper::Partition_Rapper(TransitionTable dfa_table)
{
    finished = false ;
    this -> dfa_table = dfa_table ;
}

Partition_Rapper::~Partition_Rapper()
{
    this -> partitions.clear() ;
}

CompositeState*
Partition_Rapper::get_essential(CompositeState* c)
{
    if(partitions[state_partition_index[c->get_id()]].belong(*c))
        return partitions[state_partition_index[c->get_id()]].get_essential() ;
    return new CompositeState()  ;
}


void
Partition_Rapper::add_partition(Partition p)
{
    for(int i=0 ; i<p.size() ; i++)
    {
        state_partition_index[p.get_state(i)->get_id()] = partitions.size() ;
    }
    partitions.push_back(p);
}

void
Partition_Rapper::re_partition()
{

    NumberGenerator::setCurrentInt(1);

    /* NEW PARTIONS GENERATED */
    vector<Partition> n_partitions ;
    /* GENERATE IDS FOR PARTIONS */
    for (int i = 0 ; i < (int)partitions.size() ; i++)
    {
        partitions[i].set_identifier(NumberGenerator::getNextUniqueInt()) ;
    }

    for (int i = 0 ; i < (int)partitions.size() ; i++)
    {
        /* GENERATE IDENTIFIERS FOR PARTITION STATES */
        generate_partion_ids(i) ;
        /* SPLIT PARTITION TO NEW PARTITIONS ACCORDING TO NEW IDENTIFIERS */
        vector<Partition> to_add = partitions[i].split() ;
        /* ADD NEW PARTITIONS */
        for(Partition n_p : to_add)
            n_partitions.push_back(n_p) ;
    }

    finished = (n_partitions.size() == partitions.size()) ;
    partitions.clear();

    for(Partition p : n_partitions)
        add_partition(p);
}

bool
Partition_Rapper::is_finished()
{
    return this->finished ;
}

void
Partition_Rapper::generate_partion_ids(int index)
{
    vector<string> ids ;
    for(int i=0 ; i < partitions[index].size() ; i++ )
    {
        /* NEW IDENTIFIER FOR STATE i IN PARTITION */
        vector<int> id ;
        /* ALPHABET */
        set<char> alpha = Alpha::getAlphabet();
        /* APPEND TO STATE ID PARTITION ID */
        for (char c : alpha )
        {
            CompositeState* to = dfa_table.get_transition(partitions[index].get_state(i),c) ;

            if(to->get_size() != 0)
                id.push_back(get_state_partition_id(*to)) ;
            else
                id.push_back(-1);
        }
        partitions[index].add_state_id(id) ;
    }
}

int
Partition_Rapper::get_state_partition_id(CompositeState c)
{

    if(partitions[state_partition_index[c.get_id()]].belong(c))
        return partitions[state_partition_index[c.get_id()]].get_identifier() ;
    return -1 ;
}

void
Partition_Rapper::set_partition_id(int index, int id)
{
    partitions[index].set_identifier(id) ;
}


void
Partition_Rapper::print()
{
    Logger::logger.print_string("Partition_rapper { \n", Files::log_file) ;
    for(Partition p : partitions)
    {
        int id = p.get_identifier() ;
        Logger::print_string(patch::to_string(id), Files::log_file);
    }
    Logger::logger.print_string("\n}", Files::log_file);
}

