#include <iostream>
#include <fstream>// for file input
#include <vector> // for std::vector
#include <algorithm>// for sort(), find, max_element(), min_element
#include <numeric>// for accumulate()
using namespace std;

const int MISSED_EXAM = 0;

//Function prototype
void outputVector(vector<int>);

int main(){
    ifstream inputFile("grades.txt");
    vector<int> grades;
    int temp, i = 0; 

    //Check if file is open and read grades into the vector
    if(inputFile.is_open()){
        while(inputFile >> temp){
            grades.push_back(temp); //store grade in vector
            ++i;
        }
        inputFile.close(); // Closes file after reading all of the data
    }
    else{
        cout << "Error, file is not opening" << endl;
        
        return 1;
    }
    //Calls function to output all information stored in the vector
    outputVector(grades);

    return 0;
}

//This function outputs all information from the vector(grades in the class)
//Argument: vector of grades of data type int
//This is a void function(no return)
void outputVector(vector<int> list){
    //Iterator to check if any students missed the exam and received grade of 0
    vector<int>::iterator found = find(list.begin(), list.end(), MISSED_EXAM);

    cout << "CLASS 1241B" << "\n" << endl;
    //Output the number of students in the class using list.size()
    cout << "Number of students in the class: " << list.size() << endl;
    //Output all grades stored in the vector 
    cout << "List of all grades for the exam 1: " << endl;
    for(int gr: list) cout << gr << " "; cout << endl;
    //Output grades of the first and last student's grade
    cout << "Grade of the very first student in the list: " << list.front() << endl;
    cout << "Grade of the very last student in the list: " << list.back() << endl;
    //Check if vector is empty(if all students missed the exam)
    cout << "Did the entire class miss the exam?" << endl;
    cout << (list.empty() == 0? "No" : "Yes") << endl;
    //Check if at least one student missed the exam and received grade of 0
    cout << "Did any of the students miss the exam?(someone receшved grade of 0)" << endl;
    cout << (found != list.end()? "Yes, unfortunately at least one of the students missed the exam." : "No, none of the students missed the exam.") << endl;
    //Sort vector of grades from lowest to highest
    cout << "Sorted list of the grades from lowest to highest: " << endl;
    sort(list.begin(), list.end());
    for(int gr : list) cout << gr << " "; cout << endl;
    //Sort vector of grades from highest to lowest
    cout << "Sorted list of the grades from highest to lowest: " << endl;
    sort(list.rbegin(), list.rend());
    for(int gr : list) cout << gr << " "; cout << endl;
    //Output highest and lowest grade received on the exam
    cout << "Highest grade received on the exam: " << *max_element(list.begin(), list.end()) << endl;
    cout << "Lowest grade received on the exam: " << *min_element(list.begin(),list.end()) << endl;
    //Compute and output class average(nearest whole number)
    cout << "Class average on the exam(nearest whole number): " << ((accumulate(list.begin(), list.end(), 0))/ list.size());

}