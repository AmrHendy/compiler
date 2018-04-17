/*
 * Dfatablemin.h
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#ifndef DFA_DFATABLEMIN_H_
#define DFA_DFATABLEMIN_H_

#include "../MachineStructure/PartitionRapper.h"
#include "../MachineStructure/TransitionTable.h"

class Dfa_table_min
{
public:
    Dfa_table_min(TransitionTable, Partition_Rapper);
    TransitionTable* get_min_table();
private:
    TransitionTable dfa_table ;
    Partition_Rapper p_rapper ;
};

#endif /* DFA_DFATABLEMIN_H_ */
