//
// Created by rober on 04/05/2023.
//

#ifndef THESIS_APP_KARNAUGH_H
#define THESIS_APP_KARNAUGH_H
#include <iostream>
#include "vector"
#include <list>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Karnaugh {

    int variable_size;
    vector<vector <int>> Matrix;
    vector<vector <int>> Groups;


public:

    bool static checkRight(vector<vector<int>> matrix,int i,int j);
    bool static checkBottom(vector<vector<int>> matrix,int i,int j);
    bool static checkCorners1(vector<vector<int>> matrix);
    bool static checkCorners2(vector<vector<int>> matrix);
    bool static checkCorners3(vector<vector<int>> matrix);
    bool static checkHLine(vector<vector<int>> matrix, int row);
    bool static checkVLine(vector<vector<int>> matrix, int column);
    bool static checkSquare(vector<vector<int>> matrix, int row,int column);
    bool static checkAll(vector<vector<int>> matrix);
    bool static checkVector(const vector<pair<int, int>>& new_group, const vector<vector<pair<int, int>>>& groups);
    string Simplify(vector<vector<int>> matrix);

    Karnaugh(vector<vector<int>> Matrix){
        this->Matrix=Matrix;
        size_t numRows = Matrix.size(); // Get the number of rows
        size_t totalSize = 0;
        for (const auto& row : Matrix) {
            totalSize += row.size(); // Add the number of columns in each row
        }
        variable_size = log2(totalSize);
    }


    Karnaugh();
};


#endif //THESIS_APP_KARNAUGH_H

/*
vector<vector<int>> Matrix3//4 variable matrix
        {
                {0, 0, 0, 0},
                {0, 0, 0, 0}

        };

 vector<vector<int>> Matrix4//5 variable matrix
        {
                {0, 0, 0, 0},//j
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
                //i
        };

vector<vector<int>> Matrix5//5 variable matrix
        {
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}
        };

vector<vector<int>> Matrix6//6 variable matrix
        {
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}
        };
*/