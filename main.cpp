#include "triplezero.hpp"
#include <iostream>


int main(int argc, char *argv[]){
    TripleZeroAutomaton automaton;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    bool b = automaton.is_accepted(v);
    cout << "accepted ? " << b << endl;
    return 0;
}