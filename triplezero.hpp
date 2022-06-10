#include <vector>
#include <iostream>
using namespace std;

class TripleZeroAutomaton{
private:
    int current_state = initial_state();

public:
    bool is_accepted(vector<int> v);
    int transition_from(int, int) const;
    int initial_state() const;
    bool is_final() const;
    int nb_of_states() const;
    int get_state() const;
};