#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void outputVector(vector<int>);

int main(){
    ifstream inputFile("grades.txt");
    vector<int> grades;
    int temp, i = 0; 

    if(inputFile.is_open()){
        while(inputFile >> temp){
            grades.at(i) = temp;
            ++i;
        }
    }
    else{
        cout << "Error, file is not opening" << endl;
        
        return 1;
    }
    outputVector(grades);

    return 0;
}

void outputVector(vector<int> list){
    
}