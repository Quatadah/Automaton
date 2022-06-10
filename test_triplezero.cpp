#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>

#include "triplezero.hpp"

int main(int argc, char *argv[]) {
    vector<int> v; // where we gonna stock our vector
    ifstream indata;  // indata is like cin
    int num; // variable for input value
        indata.open("zero_one.dat"); // opens the file
    if(!indata) { 
        cerr << "Erreur : Le fichier ne peut pas être ouvert" << endl;
        exit(1);
    }
    indata >> num;
    while ( !indata.eof() ) { // keep reading until end-of-file        
        v.push_back(num);
        indata >> num;  // sets EOF flag if no value found
    }
    indata.close();
    
    // In this step, v has the values, now we're gonna test it
    
    TripleZeroAutomaton automaton;
    bool is_valid = automaton.is_accepted(v);
    string answer = is_valid ? "Oui" : "Non";
    cout << "Le mot est accepté ? " << answer << endl;

    return 0;
}