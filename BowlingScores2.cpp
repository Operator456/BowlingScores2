#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// struct Bowler
struct Bowler {
    string name;
    int scores[5]{};
    int averageScore{};
};

// function prototypes
bool getBowlingData(const string& fileName, Bowler bowlers[], int& count);
void GetAverageScore(Bowler bowlers[], int count);
void PrettyPrintResults(Bowler bowlers[], int count);

int main() {

    // declaring variables
    int count = 0;

    // define filename BowlingScores.txt
    string fileName = "BowlingScores.txt";
    Bowler bowlers[100];

    // setting the precision
    cout << setprecision(2) << fixed << showpoint;

    // calling functions in main()
    if (getBowlingData(fileName, bowlers, count)) {
        GetAverageScore(bowlers, count);

        PrettyPrintResults(bowlers, count);
    }

    // if file not opened
    else {
        cout << "\nSomething went wrong, file not found!!" << endl;
    }
    return 0;
}

// getBowlingData() to read into BowlingScores.txt file 
bool getBowlingData(const string& fileName, Bowler bowlers[], int& count) {

    // defines an input stream for the data file
    ifstream dataInput;

    // Opening the input file
    dataInput.open(fileName.c_str());

    // checking whether the file name is valid or not
    if (dataInput.fail()) {
        return false;
    }
    else {
        // counting no of records in the file
        while (dataInput >> bowlers[count].name) {
            for (int& score : bowlers[count].scores) {
                dataInput >> score;
            }
            count++;
        }

        // close the input file
        dataInput.close();
    }
    return true;

}

// GetAverageScore() method to calculate average 
void GetAverageScore(Bowler bowlers[], int count) {
    double total;

    // for loop to read all scores of every bowler
    for (int i = 0; i < count; i++) {
        total = 0;
        for (int score : bowlers[i].scores) {
            total += score;
        }

        // calculate average
        bowlers[i].averageScore = (int)(total / 4);
    }
}

// PrettyPrintResults() method to display the Output
void PrettyPrintResults(Bowler bowlers[], int count) {

    // display header
    cout << setw(10) << left << "Name" << setw(6) << left << "S1" << setw(8) << left << "S2";
    cout << setw(8) << left << "S3" << setw(6) << left << "S4" << setw(6) << left << "S5" << setw(6) << left << "Average" << endl;
    cout << setw(10) << left << "----" << setw(6) << left << "----" << setw(8) << left << "----";
    cout << setw(8) << left << "----" << setw(6) << left << "----" << setw(6) << left << "----" << endl;

    // for loop to print all names and scores
    for (int i = 0; i < count; i++) {
        cout << setw(10) << left << bowlers[i].name;
        for (int score : bowlers[i].scores) {
            cout << score << "\t";
        }

        // display average of every bowler
        cout << setw(5) << bowlers[i].averageScore << endl;
    }
}