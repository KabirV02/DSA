#include<bits/stdc++.h>
using namespace std;

// T.C:

// Spreadsheet init: O(rows)

// setCell/resetCell: O(log(row))

// cellValue: O(log(row))

// getValue: O(L)

// S.C:

// O(26 × rows) = O(rows)

class Spreadsheet {
public:
    int cellValue(string formula){
        
        if(!isalpha(formula[0]))return stoi(formula);

        char column = formula[0];
        string row = formula.substr(1);
        int rowNumber = stoi(row);
        return mp[column][rowNumber-1];
    }

    unordered_map<char, vector<int>> mp;
    Spreadsheet(int rows) {

        for (char ch = 'A'; ch <= 'Z'; ch++) {
            for (int i = 1; i <= rows; i++) {
                mp[ch].push_back(0);
            }
        }
    }

    void setCell(string cell, int value) {

        char column = cell[0];
        string row = cell.substr(1);
        int rowNumber = stoi(row);
        mp[column][rowNumber - 1] = value;
    }

    void resetCell(string cell) {
        char column = cell[0];
        string row = cell.substr(1);
        int rowNumber = stoi(row);
        mp[column][rowNumber - 1] = 0;
    }

    int getValue(string formula) {
            int end = 1;
            while(end < formula.length() && formula[end] != '+'){
                end++;
            }
        return cellValue(formula.substr(1,end-1)) + cellValue(formula.substr(end+1));
    }
};

