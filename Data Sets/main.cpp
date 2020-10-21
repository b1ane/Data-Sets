//
//  main.cpp
//  Data Sets
//
//  Created by Blane Zewdie on 10/20/20.
//

#include <iostream>
#include <iomanip>
#include <cmath> //for POW function

using namespace std;

//prints average of valid grades
double printAverage(int vGrades[], int length) {
    double avg = 0;
    
    for (int i = 0; i < length; i++) {
        // adds every valid grade in array
        avg = avg + vGrades[i];
    }
    //divides sum of every valid grade by number of grades
    avg = avg / length;
    
    return avg;
}

double printDeviation (int vGrades[], int length) {
    double avg = 0;
    double stdDev = 0;
    double rvalue;
    
    avg = printAverage(vGrades, length);
    
    for (int i = 0; i < length; i++) {
        stdDev = stdDev + pow(vGrades[i] - avg, 2);
    }
    
    rvalue = sqrt(stdDev / length);
    
    return rvalue;
}

void Histogram (int vGrades[], int length) {
    for (int i = 0; i < length; i++) {
        //prints left side of histogram
        //multiplies count of valid grades by 1o
        cout << right << setw(3) << (10 * i) << "|";
        
        //prints asterik for each valid grade
        for (int j = 0; j < vGrades[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}



int main() {
    // takes grades values from input
    int userGrades;
    // max amount of students = 100
    const int maxSTUDENTS = 100;
    
    //stores valid grades in array
    int vGrades[maxSTUDENTS];
    
    //count number of valid grades = number of students
    int counterV = 0;
    
    // stores invalid grades in array
    int iGrades[maxSTUDENTS];
    
    //counts number of invalid grades
    int counterI = 0;
    
    //user inputs choice from menu
    int menuChoice;
    
    // for histogram
    int arr[11];
    
    //cout << "Enter all grades: ";
    // takes input from user
    do {
        //cout << "Enter all grades: ";
        cin >> userGrades;
        
        // loop is terminated when user enters -1
        if (userGrades == -1) {
            break;
        }
        
        // grades eneterd must be between 0 and 100
        if ( (userGrades >= 0) && (userGrades <= 100) ) {
            // stores valid grades in array
            vGrades[counterV] = userGrades;
            //counts number of vaild grades
            counterV++;
        }
        else {
            // stores invalid grades in array
            iGrades[counterI++] = userGrades;
        }
    } while (true);
    
    cout << endl;
    
    cout << "The following grades are invalid: " << endl;
    
    //prints all invalid grades except the last value
    for (int i = 0; i < counterI - 1; i++) {
        cout << iGrades[i] << ", ";
    }
    //prints last value of array
    cout << iGrades[counterI - 1];
    
    
    cout << endl;
    
    //print menu
    do {
        cout << endl;
        cout << "Select an option:" << endl;
        cout << "(1) - Number of Students" << endl;
        cout << "(2) - Grades" << endl;
        cout << "(3) - Average" << endl;
        cout << "(4) - Standard Deviation" << endl;
        cout << "(5) - Histogram" << endl;
        cout << "(0) - Exit" << endl;
        
        //user enters menu choice
        cin >> menuChoice;
        
        // check if menu choice is a valid option
        if ( (menuChoice < 0) || (menuChoice > 5) ) {
            cout << "Invalid choice. Try again.";
        }
        
        //prints number of students
        if (menuChoice == 1) {
            cout << "Number of Students: " << counterV << endl;
        }
        
        // prints valid grades
        if (menuChoice == 2) {
            cout << "Grades: ";
            for (int i = 0; i < counterV - 1; i++) {
                cout << vGrades[i] << ", ";
            }
            cout << vGrades[counterV - 1] << endl;
        }
        
        //prints average of valid grades
        if (menuChoice == 3) {
            cout << "Class Average: ";
            cout << fixed << setprecision(2) << printAverage(vGrades, counterV);
            cout << endl;
        }
        
        //prints standard deviation of valid grades
        if (menuChoice == 4) {
            cout << "Standard Deviation: ";
            cout << fixed << setprecision(2) << printDeviation(vGrades, counterV);
            cout << endl;
        }
        
        //prints Histogram of valid grades
        if (menuChoice == 5) {
            cout << "Histogram: " << endl;
            cout << endl;
            
            for (int i = 0; i < 11; i++) {
                arr[i] = 0;
            }
            for (int j = 0; j < counterV; j++) {
                arr[vGrades[j] / 10]++;
            }
            Histogram(arr,11);
        }
        
    } while (menuChoice != 0);
    
    
    
    return 0;
}
