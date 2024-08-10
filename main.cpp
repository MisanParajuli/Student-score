#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Record { // Creating a common variable to store student's name and their respective score
public:
    string name;
    int marks;

    //constructor
    Record (string& studentname, int& studentmarks){ // & was used so constructor doesn't create the copy of the variable
        name = studentname;
        marks = studentmarks;
    };
};

int main() {


    vector<Record> Student; // As student is going to be a dynamic array, vector is used to initialize

    ifstream takescore ("Results.txt"); // to find the file
    if (takescore.is_open()){
        string line; // to provide a variable to the content of the file
        while (getline(takescore, line)){ // takescore is used as cin when working with file and line is the variable that takes out content from that particular line only
           string studentname = line.substr(0, line.length()-3);  // Extracting name
           int studentmarks = stoi ( line.substr(line.length()-2, 2) ); // Extracting number and converting it to integer
            Student.emplace_back(studentname, studentmarks); // putting the extracted value to Parinam class
        };
    }
    else cerr << "File not found"; // In case if the file doesnot exist

    //Just finding the average and high score from the data

    double sum =0;
    int highest = 0;
    string highscorer;
    for (size_t i =0; i< Student.size(); i++ ){
        sum = sum + Student.at(i).marks;

        if (Student.at(i).marks > highest){
            highest = Student.at(i).marks;
            highscorer = Student.at(i).name;
        }
    }


    cout << "The average of all the scores is " << double (sum/Student.size()) << endl;
    cout << "The highest score is by " << highscorer << " with " << highest << " points" << endl;


    return 0;
}
