#include "AlternanceAutomaton.hpp"

AlternanceAutomaton::AlternanceAutomaton(char letter1, char letter2){
    this->letter1 = letter1;
    this->letter2 = letter2;
}

int AlternanceAutomaton::get_state() const{
    return current_state;
}

int AlternanceAutomaton::initial_state() const{
    return 1;
}

bool AlternanceAutomaton::is_final() const{
    return current_state == 1 || current_state == 2;
}

int AlternanceAutomaton::nb_of_states() const{
    return 3;
}

int AlternanceAutomaton::transition_from(int x, char a) const{
    if (x == 1 && a == letter2)
        return -1;
    else if (x == 1 && a == letter1)
        return 2;
    else if (x == 1 && a != letter1 && a != letter2)
        return 1;
    else if (x == 2 && a == letter2)
        return 1;
    else if (x == 2 && a == letter1)
        return -1;
    else if (x == 2 && a != letter1 && a != letter2)
        return 2;
    else if (x == 3 && a != letter1 && a != letter2)
        return 3;
    return -1;
}

void AlternanceAutomaton::firstletter(char newletter){
    letter1 = newletter;
}

bool AlternanceAutomaton::is_accepted(const std::string &s){
    //cout << "state at the beginning : " << current_state << endl;
    //cout << "letter 1  = " << letter1 << endl;
    //cout << "letter 2  = " << letter2 << endl;    
    for (int i = 0; i < s.size(); i++) {
        //cout << "x = " << current_state << "," << "a = " << s.at(i) << endl;
        if ((current_state = transition_from(current_state, s.at(i))) == -1)
            return false;
        //cout << "state at step " << i << " : " << current_state << endl;
    }
    return is_final();
}