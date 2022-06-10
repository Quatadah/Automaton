#ifndef GENERICAUTOMATONCLASS
#define GENERICAUTOMATONCLASS

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

template <class Symbol>
class Automaton {
   private:    
    int nbstates;
    int init_state;
    std::set<int> final_states;
    std::map<std::pair<int, Symbol>, int> transition_map;    
public:
    Automaton(const std::string &);
    friend bool is_accepted(vector<int>::iterator begin, vector<int>::iterator end);
    int transition_from(int n, Symbol s) const;
    int initial_state() const;
    bool is_final(int n) const;
    int nb_of_states() const;    
    Automaton operator* (Automaton const &automaton2) const;
};

template <class Symbol>
int Automaton<Symbol>::initial_state() const{
    return init_state;
}

template <class Symbol>
bool Automaton<Symbol>::is_final(int n) const{
    set<int>:: iterator it;
    for( it = final_states.begin(); it!= final_states.end(); ++it){
        int state = *it;
        if (n == state)
            return true;
    }
    return false;
}

template <class Symbol>
int Automaton<Symbol>::nb_of_states() const{
    return nbstates;
}


template <class Symbol>
Automaton<Symbol>::Automaton(const std::string &name){
    string line;
    ifstream myfile (name);
    string delimiter = " ";
    int lineCounter = 0;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {            
            if (lineCounter == 0){                
                nbstates = (int)line.at(0) - '0';
                init_state = (int)line.at(6) - '0';;                
            } else if (lineCounter == 1) {                
                for(int i = 0; i < line.size(); i += 2) {
                    final_states.insert((int)line.at(i) - '0');
                }
            } else {                
                int src = (int)line.at(0) - '0';
                Symbol symbol = (Symbol) ((int)line.at(2) - '0');
                int dest = (int)line.at(4) - '0';                
                transition_map.insert(pair<pair<int, Symbol>, int> (pair<int, Symbol>(src, symbol), dest));                
            }
            lineCounter++;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
    
}

template <class Symbol>
bool is_accepted(vector<char>::iterator begin, vector<char>::iterator end){
    return true;
}

template <class Symbol>
int Automaton<Symbol>::transition_from(int n, Symbol s) const{
    auto tr = make_pair(n, s);
	if(transition_map.count(tr) > 0){
		auto it = transition_map.find(tr);
		return it->second;
	}	
	return -1;
}

std::set<Symbol> extract_alphabet() const{
    std::set<Symbol> alphabet;
    std::map<std::pair<int, Symbol>, int> ::iterator it;
    for (it = transition_map.begin(); it != transition_map.end(); it++){
        alphabet.insert(it->second);
    }
}

#endif