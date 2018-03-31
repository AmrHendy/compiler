/*
 * PartitionRapper.h
 *
 *  Created on: Mar 24, 2018
 *      Author: abdelrhman
 */

#ifndef STRUCTURES_PARTITIONRAPPER_H_
#define STRUCTURES_PARTITIONRAPPER_H_

#include "Partition.h"
#include "CompositeState.h"
#include "TransitionTable.h"

class Partition_Rapper
{
public:
    Partition_Rapper();

    Partition_Rapper(TransitionTable dfa_table);

    virtual ~Partition_Rapper();

    CompositeState * get_essential(CompositeState * c);

    void add_partition(Partition);

    void re_partition();

    bool is_finished();

private:
    void generate_partion_ids(int index);

    int get_state_partition_id(CompositeState);

    void set_partition_id(int index,
                          int id);

    void print();

private:
    TransitionTable   dfa_table;
    vector<Partition> partitions;
    map<int, int>     state_partition_index;
    bool              finished = false;
};
#endif /* STRUCTURES_PARTITIONRAPPER_H_ */

