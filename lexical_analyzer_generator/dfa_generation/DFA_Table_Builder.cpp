/* IMPORT LIBRARIES */
/*********************************************/
#include "DFA_Table_Builder.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"
#include "Partition.h"

/* CONSTRUCTOR */
/*********************************************/
DFA_Table_Builder::DFA_Table_Builder(Transition_Table nfa_table)
{
    this->nfa_table = nfa_table;
}

DFA_Table_Builder::~DFA_Table_Builder(void)
{
    /* NOTHING */
}

/* INTERFACE METHODS */
/*********************************************/
Transition_Table
DFA_Table_Builder::generate_dfa_table(void)
{
    Transition_Table* dfa_table = new Transition_Table() ;
    // TODO use NFA table to get dfa table
}

Transition_Table
DFA_Table_Builder::minimize_dfa_table(Transition_Table dfa_table)
{
    /* SPLIT START STATES FROM END STATES */
    Partition start_states('0', dfa_table.get_start_states()) ;
    Partition end_states('1', dfa_table.get_end_states()) ;

    /* BUILD ALL PARTITIONS */
    vector<Partition> partitions ;
    partitions.push_back(start_states) ;
    partitions.push_back(end_states) ;

    while(re_partition(&partitions, dfa_table));

    /* REMOVE EQUAVILENT STATES AND MODIFY TABLE  */
    return dfa_table.get_equavilent_table(partitions) ;
}


/* PRIVATE FUNCTIONS */
bool DFA_Table_Builder::re_partition(vector<Partition>* partitions , Transition_Table dfa_table )
{
    /* NEW PARTIONS GENERATED */
    vector<Partition> n_partitions ;
    int siz = (*partitions).size() ;
    /* GENERATE IDS FOR PARTIONS */
    for (int i = 0 ; i < siz ; i++){
        (*partitions)[i].set_identifier('0' + i) ;
    }


    for(Partition p : *partitions){
        /* GENERATE IDENTIFIERS FOR PARTITION STATES */
        generate_partition_ids(*partitions , &p , dfa_table ) ;
        /* SPLIT PARTITION TO NEW PARTITIONS ACCORDING TO NEW IDENTIFIERS */
        vector<Partition> to_add = p.split() ;
        /* ADD NEW PARTITIONS */
        for(Partition n_p : to_add)
            n_partitions.push_back(n_p) ;
    }

    if(partitions->size() == n_partitions.size()){
        return false ;
    }

    partitions = &n_partitions ;

    return true ;
}


void DFA_Table_Builder::generate_partition_ids(vector<Partition> all_partitions , Partition* partition , Transition_Table dfa_table ){
    /* GET STATES OF THE PARTITION */
    vector<Composite_State> states = partition -> get_states() ;
    /* NEW IDENTIFIERS FOR PARTITION STATES */
    vector<string> ids ;

    for(Composite_State c : states){
        /* NEW IDENTIFIER FOR STATE i IN PARTITION */
        string id = "" ;
        /* ALPHABET */
        set<char> alpha = dfa_table.get_alphabet() ;
        /* APPEND TO STATE ID PARTITION ID */
        for (char i : alpha ){
            /* GET STATE WILL GO TO IF STATE C TOOK I */
            Composite_State to = dfa_table.get_transition(c , i) ;
            /* STATE TO IS NOT FOUND */
            if(to.get_states().empty())
                continue ;
            /* GET PARTITION STATE TO BELONG TO */
            char partition_id = get_partition_belong(all_partitions,to).get_identifier() ;
            /* APPEND PARTITION ID TO STATE ID */
            id.push_back(partition_id) ;
        }
        ids.push_back(id);
    }

    /* SET IDS OF STATES */
    partition->set_state_id(ids) ;
}


Partition
DFA_Table_Builder::get_partition_belong(vector<Partition> partitions , Composite_State c){
    /* LOOK FOR PARTITION STATE C BELONG TO */
    for (Partition p : partitions){
        if(p.belong(c))
            return p ;
    }
}
