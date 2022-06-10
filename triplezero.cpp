#include "triplezero.hpp"


int TripleZeroAutomaton::get_state() const{
    return current_state;
}

int TripleZeroAutomaton::initial_state() const{
    return 1;
}

bool TripleZeroAutomaton::is_final() const{
    return current_state == 4;
}

int TripleZeroAutomaton::nb_of_states() const{
    return 4;
}

int TripleZeroAutomaton::transition_from(int x, int a) const{    
    if (x == 1 && a == 1)
        return 1;
    else if (x == 1 && a == 0)
        return 2;
    else if (x == 2 && a == 1)
        return 1;
    else if (x == 2 && a == 0)
        return 3;
    else if (x == 3 && a == 1)
        return 1;
    else if (x == 3 && a == 0)
        return 4;
    else if (x == 4 && (a == 0 || a == 1))
        return 4;
    else //Dans le cas où on demande de faire une transformation qui n'existe pas
        return -1;
}

bool TripleZeroAutomaton::is_accepted(vector<int> v){
    //cout << "state at the beginning : " << current_state << endl;
    for (int i = 0; i < v.size(); i++) {
        if ((current_state = transition_from(current_state, v.at(i))) == -1)
            return false;
        //cout << "state at step " << i << " : " << current_state << endl;
    }
    return is_final();
}