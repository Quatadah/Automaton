#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib>
#include "Automaton.hpp"

int main(int argc, char *argv[]) {
    vector<char> v; // where we gonna stock our vector
    ifstream indata;  // indata is like cin
    char num; // variable for input value
        indata.open("motbizarre.dat"); // opens the file
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

    Automaton<int> automaton("automate.dat");
    vector<char>::iterator begin = v.begin();
    vector<char>::iterator end = v.end();
    bool is_valid = is_accepted(begin, end);
    string answer = is_valid ? "Oui" : "Non";
    cout << "Le mot est accepté ? " << answer << endl;
}