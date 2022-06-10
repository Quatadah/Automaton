#ifndef GENERICAUTOMATONCLASS
#define GENERICAUTOMATONCLASS

#include <string>

template <class Symbol>
class Automaton{
private:
    int nbstates;
    int init_state;
    std::set<int> final_states;
    std::map<std::pair<int, Symbol>, int> transition_map;    
public:
    Automaton(const std::string &);
    friend bool is_accepted(int b, char e);
    int transition_from(int n, Symbol s) const;
    int initial_state() const;
    bool is_final() const;
    int nb_of_states() const;
    int get_state() const;
    void firstletter(char);
};

#endif