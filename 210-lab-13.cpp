#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int MISSED_EXAM = 0;

void outputVector(vector<int>);

int main(){
    ifstream inputFile("grades.txt");
    vector<int> grades;
    int temp, i = 0; 

    if(inputFile.is_open()){
        while(inputFile >> temp){
            grades.push_back(temp);
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
    vector<int>::iterator found = find(list.begin(), list.end(), MISSED_EXAM);

    cout << "CLASS 1241B" << "\n" << endl;

    cout << "Number of students in the class: " << list.size() << endl;

    cout << "List of all grades for the exam 1: " << endl;
    for(int gr: list) cout << gr << " "; cout << endl;

    cout << "Grade of the very first student in the list" << list.front() << endl;
    cout << "Grafe of the very last student in the list" << list.back() << endl;

    cout << "Did the entire class miss the exam?" << endl;
    cout << (list.empty() == 0? "No" : "Yes") << endl;

    cout << "Did any of the students miss the exam?(someone recoeved grade of 0)" << endl;



}