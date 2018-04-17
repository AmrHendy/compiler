#include "../../../header/LexcialAnalyzer/MachineStructure/Machine.h"

Machine::Machine()
{
    end = new State(-1);
    start = new State(-1);
}

Machine::Machine(char basic_char)
{
    start = new State(NumberGenerator::getNextUniqueInt());
    end = new State(NumberGenerator::getNextUniqueInt());
    start->add_transition(basic_char, end);
}

Machine::~Machine()
{
    // TODO Auto-generated destructor stub
}

State* Machine::get_start()
{
    if(start == nullptr)
        return new State(-1) ;
    return start;
}

State* Machine::get_end()
{
    if(end == nullptr)
        return new State(-1) ;
    return end ;
}

void Machine::set_start(State* start)
{
    Machine::start = start ;
}

void Machine::set_end(State* end)
{
    Machine::end = end;
}

void
Machine::print()
{
    string str = "" ;
    set<State> vis ;
    vector<State> traverse ;

    Logger::logger.print_string("digraph Machine {\n", Files::graph_file);

    traverse.push_back(*this->get_start());
    vis.insert(*this->get_start());

    while(!traverse.empty())
    {
        State now = traverse.back();
        traverse.pop_back() ;
        for(char c : Alpha::getAlphabet())
        {
            vector<State*> tos = now.get_transitions(c);
            for(State* s : tos)
            {
                if(vis.count(*s) == 0)
                {
                    traverse.push_back(*s);
                    vis.insert(*s);
                }
                int to_id = s->get_id(), id = now.get_id();
                str+= "\t" +patch::to_string(id)
                      + " -> "
                      + patch::to_string(to_id)
                      + " [ label = \"" ;
                string tmp = patch::to_string(c) ;
                if( tmp[0] == '\0' )
                    str += "~" ;
                else
                    str += tmp ;
                str += "\" ];\n";
            }
        }
    }

    Logger::print_string(str, Files::graph_file);
    Logger::print_string("}\n", Files::graph_file);
}

