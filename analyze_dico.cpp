// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "AlternanceAutomaton.hpp"

int main () {
    string line;
    ofstream outputFile("extraction_alternance.dat");
    ifstream myfile("dictionnaire.dat");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            cout << line << endl;
            AlternanceAutomaton automaton('a', 'r');
            if (automaton.is_accepted(line)){
                cout << line << endl;
                if (outputFile.is_open()) {
                    outputFile << line << endl;
                }
            }            
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    outputFile.close();

    return 0;
}