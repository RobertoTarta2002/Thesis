//
// Created by rober on 04/05/2023.
//

#ifndef THESIS_APP_TABULATION_H
#define THESIS_APP_TABULATION_H

#include <iostream>
#include "vector"
#include <list>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Tabulation {
private:
    struct Term {
        string value;
        vector<int> minterms;

        Term(string val, vector<int> mints) : value(val), minterms(mints) {}
    };

    vector<Term> primeImplicants;



public:

    bool differenceCheck( string term1,  string term2);
    string decimalToBinary(int minterm);
    Term combineTerms(const Term& term1, const Term& term2);
    string simplify(vector<vector<int>> Binary_Table);
    bool uniqueTerm(Term term,vector<Term> terms);
    vector<Term> createTerms(vector<vector<int>> Binary_Table);

};


#endif //THESIS_APP_TABULATION_H


/*vector<vector<int>> Binary_Table//4 variables
        {
             ///{A, B, C, D, F, Dec} //F being the solution/implicants
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0, 1},
                {0, 0, 1, 0, 0, 2},
                {0, 0, 1, 1, 0, 3},
                {0, 1, 0, 0, 0, 4},
                {0, 1, 0, 1, 0, 5},
                {0, 1, 1, 0, 0, 6},
                {0, 1, 1, 1, 0, 7},
                {1, 0, 0, 0, 0, 8},
                {1, 0, 0, 1, 0, 9},
                {1, 0, 1, 0, 0,10},
                {1, 0, 1, 1, 0,11},
                {1, 1, 0, 0, 0,12},
                {1, 1, 0, 1, 0,13},
                {1, 1, 1, 0, 0,14},
                {1, 1, 1, 1, 0,15},
        };

        vector<Tabulation::Term> Tabulation::removeTerms(vector<Tabulation::Term> Terms){///Needs more thinking
    vector<Tabulation::Term> Resulting_Terms;
for(int i;i<Terms.size();i++){
    for(int j;j<Terms.size();j++) {
        int counter=0;
        for (int k; k < Terms[i].minterms.size(); k++) {
            for (int r; r < Terms[j].minterms.size(); r++) {
                if(counter)
                if (Terms[i].minterms[k] == Terms[j].minterms[r])
                    counter++;
            }
        }
    }
}


}
        */