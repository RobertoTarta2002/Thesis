#include <iostream>
#include "vector"
#include "Boolean.h"
#include "Karnaugh.h"
#include "Tabulation.h"


using namespace std;

int main() {
    int choice=3;
    /// 1 is for Boolean
    /// 2 is for Karnaugh
    /// 3 is for Quine-McCluskey / Tabulation


    if(choice==1) {///Boolean Algebra
        string expression = "AB!CD+!ABCD+!A!BCD+!AB!C!D+A!BC!D+!A!B!CD+ABC!D+!A!B!C!D  " ;//"ABC+!AA+AB+!(AB)+!(A+B)+!A!B+!A+A!A+A+D(E+F)+E(F+G) "; /// Enter your expression here
        Boolean A;
        cout << A.Simplify(expression);
    }

    if(choice==2){///Karnaugh map
        vector<vector<int>> Matrix4//4 variable matrix
                {
                        {0, 0, 0, 1},//j
                        {1, 1, 0, 1},
                        {1, 1, 0, 1},
                        {0, 1, 0, 1}
                        //i
                };
        Karnaugh A;
        cout<< A.Simplify(Matrix4);

    }

    if(choice==3){///QM Method
        vector<vector<int>> Binary_Table//4 variables
                {
                     ///{A, B, C, D, F, Dec} //F being the solution/minterms
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 1, 1},
                        {0, 0, 1, 0, 0, 2},
                        {0, 0, 1, 1, 1, 3},
                        {0, 1, 0, 0, 0, 4},
                        {0, 1, 0, 1, 1, 5},
                        {0, 1, 1, 0, 0, 6},
                        {0, 1, 1, 1, 1, 7},
                        {1, 0, 0, 0, 0, 8},
                        {1, 0, 0, 1, 0, 9},
                        {1, 0, 1, 0, 1,10},
                        {1, 0, 1, 1, 0,11},
                        {1, 1, 0, 0, 1,12},
                        {1, 1, 0, 1, 0,13},
                        {1, 1, 1, 0, 1,14},
                        {1, 1, 1, 1, 1,15},
                };
        Tabulation A;
        cout << A.simplify(Binary_Table);


    }


    return 0;
}
