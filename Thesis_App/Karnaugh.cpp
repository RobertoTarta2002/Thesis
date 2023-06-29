//
// Created by rober on 04/05/2023.
//

#include "Karnaugh.h"




bool Karnaugh::checkRight(vector<vector<int>> matrix,int i,int j){
    if(matrix[i][j+1]==1)
        return true;
    else
        return false;
}

bool Karnaugh::checkBottom(vector<vector<int>> matrix,int i,int j){
    if(matrix[i+1][j]==1)
        return true;
    else
        return false;
}

bool Karnaugh::checkCorners1(vector<vector<int>> matrix){
    if(matrix[0][0]==1)
        if(matrix[0][matrix[0].size()]==1)
            if(matrix[matrix.size()][0]==1)
                if(matrix[matrix.size()][matrix[0].size()]==1)
                    return true;
    return false;
}

bool Karnaugh::checkCorners2(vector<vector<int>> matrix){///descendent diagonal \ ///
    if(matrix[0][0]==1)
        if(matrix[matrix.size()][matrix[0].size()]==1)
            return true;
    return false;
}

bool Karnaugh::checkCorners3(vector<vector<int>> matrix){///crescent diagonal / ///
    if(matrix[0][matrix[0].size()]==1)
        if(matrix[matrix.size()][0]==1)
            return true;
    return false;
}

bool Karnaugh::checkVLine(vector<vector<int>> matrix, int column){
    for(auto & i : matrix)
        if(i[column]==0)
            return false;
return true;
}

bool Karnaugh::checkHLine(vector<vector<int>> matrix, int row){
for(int i : matrix[row])
    if(i==0)
        return false;
return true;
}

bool Karnaugh::checkSquare(vector<vector<int>> matrix, int row,int column){
    if(matrix[row+1][column+1]==1)
        return true;
    return false;
}

bool Karnaugh::checkAll(vector<vector<int>> matrix){
    for(auto & i : matrix) {
        for (int j : i) {
            if(j==0)
                return false;
        }
    }
    return true;
}

string Karnaugh::Simplify(vector<vector<int>> matrix) {
    string result;
    vector<vector<pair<int,int>>> groups; // Updated to vector<vector<int>>
    vector<pair<int,int>> new_group;

    // Check if any new pairs are present
    if (checkAll(matrix)) {
        result = "The whole matrix is composed of 1's so the resulting output is 1";
        return result;
    }
    cout<< "After checkALL"<<endl;
    // Check for specific patterns and conditions
    if (checkCorners1(matrix)) {
        cout << "Group found out of the 4 corners of the matrix"<<endl;
        new_group.emplace_back(0, 0);
        new_group.emplace_back(0, matrix[0].size());
        new_group.emplace_back(matrix.size(), 0);
        new_group.emplace_back(matrix.size(), matrix[0].size());
        if(checkVector(new_group,groups))
            groups.push_back(new_group);
    }
    cout<< "After 4 corners"<<endl;
    if (checkCorners2(matrix)) {
        new_group.clear();
        cout << "Group found in top left corner and bottom right corner"<< endl;
        new_group.emplace_back(0, 0);
        new_group.emplace_back(matrix.size(), matrix[0].size());
        if(checkVector(new_group,groups))
            groups.push_back(new_group);
    }
    cout<< "After 2 corners1"<<endl;
    if (checkCorners3(matrix)) {
        new_group.clear();
        cout << "Group found in top right corner and bottom left corner"<< endl;
        new_group.emplace_back(0, matrix[0].size());
        new_group.emplace_back(matrix.size(), 0);
        if(checkVector(new_group,groups))
            groups.push_back(new_group);
    }
    cout<< "After 2 corners2"<<endl;
    // Iterate over the matrix and perform additional checks
    for (int j = 0; j < matrix.size(); j++) {
        for (int i = 0; i < matrix[j].size(); i++) {
            cout<< i<< "," << j<< "," <<matrix[j][i]<<  endl;
            if (matrix[i][j] == 1) {
                if (checkRight(matrix, i, j+1)) {
                    if(checkHLine(matrix, i)){
                        cout << "Group found in line " << j << endl;
                        new_group.clear();
                        for (int k = 0; k < matrix.size(); k++) {
                            new_group.emplace_back(k, j);
                        }
                        if(checkVector(new_group,groups))
                            groups.push_back(new_group);
                    }
                    if (checkBottom(matrix, i, j + 1)) {
                            //patternCoordinates.push_back({i + 1, j});
                            //patternCoordinates.push_back({i + 1, j + 1});
                        if (checkSquare(matrix, i + 1, j)) {
                            cout<< "Square found" << endl;
                            new_group.clear();
                            new_group.emplace_back(i, j);
                            new_group.emplace_back(i + 1, j);
                            new_group.emplace_back(i, j + 1);
                            new_group.emplace_back(i + 1, j + 1);
                            if(checkVector(new_group,groups))
                                groups.push_back(new_group);
                        }

                    }
                    else{
                        cout<< "HPair found"<< "x1:" << i << ","<< j << " x2:" << i << ","<< j+1 <<endl;
                        new_group.clear();
                        new_group.emplace_back(i, j);
                        new_group.emplace_back(i, j + 1);
                        if(checkVector(new_group,groups))
                            groups.push_back(new_group);
                    }
                }
                if (checkBottom(matrix, i, j + 1)) {
                    if (checkVLine(matrix, j)) {
                        cout << "Found column in" << endl;
                        new_group.clear();
                        for (int k = 0; k < matrix.size(); k++) {
                            new_group.emplace_back(k, j);
                        }
                        if(checkVector(new_group,groups))
                            groups.push_back(new_group);
                    } else {
                        cout << "Vpair found"<< endl;
                        new_group.clear();
                        new_group.emplace_back(i , j);
                        new_group.emplace_back(i + 1, j);
                        if (checkVector(new_group, groups))
                            groups.push_back(new_group);
                    }
                }
            }
        }
    }

    cout<< "Reached the end"<< endl;
    for(const auto& group:groups) {
        cout<< "New group:"<<endl;
        for (auto point: group) {
            cout << "X: " << point.first << " Y: " << point.second<< endl;
        }
    }

}



bool Karnaugh::checkVector(const vector<pair<int, int>>& new_group, const vector<vector<pair<int, int>>>& groups) {
    if(groups.empty())
        return true;
    for (const auto& group : groups) {
        bool isNewGroup = true;
        for (const auto& sub_group : group) {
            if (find(new_group.begin(), new_group.end(), sub_group) != new_group.end()) {
                isNewGroup = false;
                break;
            }
        }
        if (isNewGroup) {
            return true;  // Found a new group, return true
        }
    }
    return false;  // No new groups found
}

Karnaugh::Karnaugh() {

}











