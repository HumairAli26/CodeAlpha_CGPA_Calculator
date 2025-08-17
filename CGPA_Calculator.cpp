#include <iostream>
#include <vector>

using namespace std;

float calculateGPA(char grade) 
{
    if (grade == 'A') 
        return 4.0;
    else if (grade == 'B+') 
        return 3.7;
    else if (grade == 'B') 
        return 3.5;
    else if (grade == 'B-') 
        return 3.2;
    else if (grade == 'C+') 
        return 3.0;
    else if (grade == 'C') 
        return 2.8;
    else if (grade == 'C-') 
        return 2.5;
    else if (grade == 'D+') 
        return 2.3;
    else if (grade == 'D') 
        return 2.0;
    else if (grade == 'D-') 
        return 1.8;
    else if (grade == 'F') 
        return 0.0;
    else 
        return 0.0;
}

int main() 
{
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    float totalCGPA = 0;
    int totalCreditHours = 0;

    for (int i = 0; i < numSemesters; i++) 
    {
        int numCourses;
        cout << "Enter the number of courses in Semester " << i + 1 << ": ";
        cin >> numCourses;
        vector<int> creditHours(numCourses);
        vector<char> grades(numCourses);
        vector<float> gradePoints(numCourses);
        float semesterGPA = 0;
        int semesterCreditHours = 0;

        for (int j = 0; j < numCourses; j++) 
        {
            cout << "Enter credit hours for course " << j + 1 << " in Semester " << i + 1 << ": ";
            cin >> creditHours[j];
            cout << "Enter grade for course " << j + 1 << " in Semester " << i + 1 << ": ";
            cin >> grades[j];
            gradePoints[j] = creditHours[j] * calculateGPA(grades[j]);
            semesterGPA += gradePoints[j];
            semesterCreditHours += creditHours[j];
        }
        float gpa = semesterGPA / semesterCreditHours;

        totalCGPA += semesterGPA;
        totalCreditHours += semesterCreditHours;
        cout << "Your GPA for Semester " << i + 1 << " is: " << gpa << endl;
        cout << "Your CGPA after Semester " << i + 1 << " is: " << totalCGPA / totalCreditHours << endl;
        cout << endl;
    }
    return 0;
}