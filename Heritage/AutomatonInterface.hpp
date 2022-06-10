template <class Symbol>
class AutomatonInterface{
public:
    virtual bool is_final() const = 0;
    virtual int initial_state() const = 0;
    virtual int nb_of_states() const = 0;
};