#include "mainQuestion3.hpp"

void mainQuestion3()
{
    // Creating a student to store all students.
    vector<Student*> students;
    
    // Creating some students.
    StudentMaster firstStudent = StudentMaster(1, "Marc", "IA", 17.5);
    StudentEngineer secondStudent = StudentEngineer(2, "Erwan", "IS", 599);
    StudentDoubleCursus thirdStudent = StudentDoubleCursus(3, "Mary", "AV", 19.5, 800);
    StudentDoubleCursus fourthStudent = StudentDoubleCursus(4, "Julien", "EVE", 9.99, 800);
    StudentDoubleCursus fifthStudent = StudentDoubleCursus(5, "Louis", "ESE", 19.5, 599);
    StudentDoubleCursus sixthStudent = StudentDoubleCursus(6, "Philippe", "Mecanique", 9, 599);

    // Adding those students to the vector.
    students.push_back(&firstStudent);
    students.push_back(&secondStudent);
    students.push_back(&thirdStudent);
    students.push_back(&fourthStudent);
    students.push_back(&fifthStudent);
    students.push_back(&sixthStudent);

    cout << "Some students have been created and here are the information about them:" << endl;
    cout << "-----------" << endl;

    // Iterating among all students.
    for(Student* student: students)
    {
        // Display information concerning the current student.
        student->displayInformation();
        
        // Display a custom sentence if the student passed.
        if (student->hasPassed())
            cout << "This student passed successfully!" << endl;
        else
            cout << "This student failed..." << endl;
        cout << "-----------" << endl;
    }
}