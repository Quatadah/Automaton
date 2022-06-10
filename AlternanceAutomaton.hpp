#include <string>
#include <iostream>
using namespace std;

class AlternanceAutomaton {
   private:
    char letter1;
    char letter2;
    int current_state = 1;
public:
    AlternanceAutomaton(char letter1, char letter2);
    bool is_accepted(const std::string &s);
    int transition_from(int, char) const;
    int initial_state() const;
    bool is_final() const;
    int nb_of_states() const;
    int get_state() const;
    void firstletter(char);
};