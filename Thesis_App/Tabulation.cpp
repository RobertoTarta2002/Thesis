    //
    // Created by rober on 04/05/2023.
    //

    #include "Tabulation.h"

    bool Tabulation::differenceCheck( string term1,  string term2) {
        int differences = 0;
        for (int i = 0; i < term1.length(); i++) {
            if (term1[i] != term2[i])
                differences++;
            if (differences > 1)
                return false;
        }
        return (differences == 1);
    }

    string Tabulation::decimalToBinary(int minterm) {
        if (minterm == 0)
            return "0";

        string binaryString;
        int numBits = log2(minterm) + 1;

        for (int i = numBits - 1; i >= 0; i--) {
            int bit = (minterm >> i) & 1;
            binaryString += to_string(bit);
        }

        return binaryString;
    }

    Tabulation::Term Tabulation::combineTerms(const Term& term1, const Term& term2) {
        string combinedValue;
        vector<int> combinedMinterms;

        for (int i = 0; i < term1.value.length(); i++) {
            if (term1.value[i] == term2.value[i]) {
                combinedValue += term1.value[i];
            } else {
                combinedValue += "-";
            }
        }

        combinedMinterms.insert(combinedMinterms.end(), term1.minterms.begin(), term1.minterms.end());
        combinedMinterms.insert(combinedMinterms.end(), term2.minterms.begin(), term2.minterms.end());

        return Term(combinedValue, combinedMinterms);
    }



    string Tabulation::simplify(vector<vector<int>> Binary_Table){
        vector<Tabulation::Term> terms;
        vector<Tabulation::Term> new_terms;
        vector<Tabulation::Term> final_terms;
        Tabulation A;
        terms = A.createTerms(Binary_Table);
        if(terms.empty())
            return "No solutions in Binary Table";

        for(int k=0;k<4;k++) {
            for (int i = 0; i < terms.size(); i++) {
                for (int j = 0; j < terms.size(); j++)
                    if (differenceCheck(terms[i].value, terms[j].value) && i != j) {
                        new_terms.push_back(A.combineTerms(terms[i], terms[j]));
                        cout<< "Terms combined" << endl;
                    }


            }
            terms=new_terms;
            new_terms.clear();
        }
        for(int i=0;i<terms.size();i++){
            if(uniqueTerm(terms[i],terms))
                final_terms.push_back(terms[i]);
        }

        for(int i=0;i<final_terms.size();i++){
            cout << "Binary value of term:" << final_terms[i].value << "Minterms:";
            for(int j=0;j<final_terms[i].minterms.size();j++)
                cout <<  final_terms[i].minterms[j] << "," << endl;
        }
        return "Done";
    }

    bool Tabulation::uniqueTerm(Tabulation::Term term,vector<Tabulation::Term> terms){
        unordered_set<int> uniqueMinterms;

        for (int minterm : term.minterms) {
            uniqueMinterms.insert(minterm);
        }

        for (const Term& otherTerm : terms) {
            if (&otherTerm != &term) {  // Exclude self-comparison
                for (int minterm : otherTerm.minterms) {
                    if (uniqueMinterms.find(minterm) != uniqueMinterms.end()) {
                        return true;  // Found a repeated minterm, return true
                    }
                }
            }
        }

        return false;  // No repeated minterms found, return false
    }

    vector<Tabulation::Term> Tabulation::createTerms(vector<vector<int>> Binary_Table){
        vector<Tabulation::Term> terms;

        for(int i=0; i<Binary_Table.size();i++){
            if(Binary_Table[i][5]==1){
            string Value = to_string(Binary_Table[i][0]) + to_string(Binary_Table[i][1]) + to_string(Binary_Table[i][2]) + to_string(Binary_Table[i][3]);
            vector<int> minterms;
            minterms.push_back(Binary_Table[i][6]);
            Term A(Value,minterms);
            terms.push_back(A);}
        }
        return terms;
    }
