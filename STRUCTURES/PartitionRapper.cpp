/*
 * PartitionRapper.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: abdelrhman
 */

#include "PartitionRapper.h"
#include "../GENERATORS/NumberGenerator.h"

Partition_Rapper::Partition_Rapper() {
}


Partition_Rapper::Partition_Rapper(TransitionTable dfa_table) {
	finished = false ;
	this -> dfa_table = dfa_table ;
}

Partition_Rapper::~Partition_Rapper() {
	this -> partitions.clear() ;
}

vector<CompositeState>
Partition_Rapper::get_essentials(){
	vector<CompositeState> ess ;
	for(Partition p : partitions){
		ess.push_back(p.get_essential()) ;
	}
	return ess ;
}


void
Partition_Rapper::add_partition(Partition p){
	partitions.push_back(p);
}

void
Partition_Rapper::re_partition(){

	NumberGenerator::setCurrentInt(1);

	/* NEW PARTIONS GENERATED */
	vector<Partition> n_partitions ;
	/* GENERATE IDS FOR PARTIONS */
	for (int i = 0 ; i < (int)partitions.size() ; i++){
		partitions[i].set_identifier(NumberGenerator::getNextUniqueInt()) ;
	}

	for (int i = 0 ; i < (int)partitions.size() ; i++){
		/* GENERATE IDENTIFIERS FOR PARTITION STATES */
		generate_partion_ids(i) ;
		/* SPLIT PARTITION TO NEW PARTITIONS ACCORDING TO NEW IDENTIFIERS */
		vector<Partition> to_add = partitions[i].split() ;
		/* ADD NEW PARTITIONS */
		for(Partition n_p : to_add)
			n_partitions.push_back(n_p) ;
	}

	finished = (n_partitions.size() == partitions.size()) ;
	partitions = n_partitions ;


	NumberGenerator::setCurrentInt(1);
	/* GENERATE IDS FOR PARTIONS */
	for (int i = 0 ; i < (int)partitions.size() ; i++){
		partitions[i].set_identifier(NumberGenerator::getNextUniqueInt()) ;
	}
}

bool
Partition_Rapper::is_finished(){
	return this->finished ;
}

void
Partition_Rapper::generate_partion_ids(int index){
	vector<string> ids ;

//	int n1 = partitions[index].size() ;
//	int n2 = Alpha::getAlphabet().size() ;

//	Logger::print_string("size of partition "
//			+ patch::to_string(index)
//			+ "is "
//			+ patch::to_string(n1)
//			+ " alpabet size is "
//			+ patch::to_string(n2)
//			+ "\n" ) ;

	Logger::print_string(" genrating ids for partition " + patch::to_string(index) +  ": \n");
	for(int i=0 ; i < partitions[index].size() ; i++ ){
		/* NEW IDENTIFIER FOR STATE i IN PARTITION */
		vector<int> id ;
		/* ALPHABET */
		set<char> alpha = Alpha::getAlphabet();
		/* APPEND TO STATE ID PARTITION ID */
		for (char c : alpha ){
			CompositeState* to = partitions[index].get_state(i).get_transition(c) ;
			if(to == nullptr)
				id.push_back(get_state_partition_id(*to)) ;
			else
				id.push_back(0);
		}

		Logger::print_string(" id for state " + patch::to_string(i) +" : ");
		for(int i : id){
			Logger::print_string(patch::to_string(i)+" ");
		}
		Logger::print_string("\n");

		partitions[index].add_state_id(id) ;
	}
}

int
Partition_Rapper::get_state_partition_id(CompositeState c){
	for(Partition p : partitions)
		if(p.belong(c))
			return p.get_identifier();
	return 0 ;
}

void
Partition_Rapper::set_partition_id(int index , int id){
	partitions[index].set_identifier(id) ;
}


void
Partition_Rapper::print(){
	Logger::logger.print_string("Partition_rapper { \n") ;
	for(Partition p : partitions){
		int id = p.get_identifier() ;
		Logger::print_string(patch::to_string(id));
	}
	Logger::logger.print_string("\n}");
}

