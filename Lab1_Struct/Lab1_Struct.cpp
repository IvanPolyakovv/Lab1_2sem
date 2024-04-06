#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

struct Student
{
    string surname;
    string name;
    string patronymic;
    bool isMale;
    int group;
    short id;
    short examsMarks[3];
    short testsMarks[5];
    float average;
};

struct Abiturient
{
    string surname;
    string name;
    string patronymic;
    bool isMale;
    short age;
    string city;
    short examMarks[3];
    int averageOfExams;
    bool originalTrue;
    float averageOfCertificate;
};

int countStudents()
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        int k = 0;
        string str;
        while (getline(file, str))
        {
            k++;
        }
        return k;
    }
    file.close();
}

void newStudent()
{
    Student student;
    cout << "Enter the surname: ";
    cin >> student.surname;
    cout << "Enter the name: ";
    cin >> student.name;
    cout << "Enter the patronymic: ";
    cin >> student.patronymic;
    cout << "If student is male - 1, is female - 0: ";
    cin >> student.isMale;
    cout << "Enter the group: ";
    cin >> student.group;
    cout << "Enter the number in group: ";
    cin >> student.id;
    int temp = 0;
    int sumMarks = 0;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            cout << "Enter the Programming mark: ";
            break;
        case 1:
            cout << "Enter the Mathematical analysis mark: ";
            break;
        case 2:
            cout << "Enter the Algebra and geometry mark: ";
            break;
        }
        cin >> student.examsMarks[i];
        sumMarks += student.examsMarks[i];
        if (student.examsMarks[i] == 2)
        {
            temp++;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
        case 0:
            cout << "Enter the Physics mark: ";
            break;
        case 1:
            cout << "Enter the Philosophy mark: ";
            break;
        case 2:
            cout << "Enter the English mark: ";
            break;
        case 3:
            cout << "Enter the Informatics mark: ";
            break;
        case 4:
            cout << "Enter the Foundations of Russian statehood mark: ";
            break;
        }
        cin >> student.testsMarks[i];
        sumMarks += student.testsMarks[i];
        if (student.testsMarks[i] == 2)
        {
            temp++;
        }
    }
    student.average = (float)sumMarks / 8;
    ofstream file;
    file.open("students.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error! File is not opened!\n";
    }
    else
    {
        if (temp == 0)
        {
            file << student.surname << ' ' << student.name << ' ' << student.patronymic << ' ' << student.isMale << ' ' << student.group << ' ' << student.id << ' ';
            for (int i = 0; i < 3; i++)
            {
                file << student.examsMarks[i] << ' ';
            }
            for (int i = 0; i < 5; i++)
            {
                file << student.testsMarks[i] << ' ';
            }
            file << student.average;
            file << "\n";
            file.close();
            cout << "Done!\n";
        }
        else
        {
            cout << "Error! Student cannot be written in file because of 2 marks!\n";
        }
    }
}

void rewriteStudent()
{
    string surname, name, patronymic;
    cout << "Enter the full name (Surname, Name, Patronymic) of the student you want to rewrite: ";
    cin >> surname >> name >> patronymic;
    ifstream oldFile;
    oldFile.open("students.txt");
    int count = countStudents();
    Student* student = new Student[count];
    for (int i = 0; i < count; i++)
    {
        oldFile >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >> student[i].group >> student[i].id;
        for (int j = 0; j < 3; j++)
        {
            oldFile >> student[i].examsMarks[j];
        }
        for (int j = 0; j < 5; j++)
        {
            oldFile >> student[i].testsMarks[j];
        }
        oldFile >> student[i].average;
    }
    oldFile.close();
    ofstream newFile;
    newFile.open("newFile.txt");
    for (int i = 0; i < count; i++)
    {
        if ((surname == student[i].surname) && (name == student[i].name) && (patronymic == student[i].patronymic))
        {
            Student newStudent;
            cout << "Enter the new surname: ";
            cin >> newStudent.surname;
            cout << "Enter the new name: ";
            cin >> newStudent.name;
            cout << "Enter the new patronymic: ";
            cin >> newStudent.patronymic;
            cout << "If student is male - 1, is female - 0: ";
            cin >> newStudent.isMale;
            cout << "Enter the group: ";
            cin >> newStudent.group;
            cout << "Enter the number in group: ";
            cin >> newStudent.id;
            int temp = 0;
            int sumMarks = 0;
            for (int j = 0; j < 3; j++)
            {
                switch (j)
                {
                case 0:
                    cout << "Enter the Programming mark: ";
                    break;
                case 1:
                    cout << "Enter the Mathematical analysis mark: ";
                    break;
                case 2:
                    cout << "Enter the Algebra and geometry mark: ";
                    break;
                }
                cin >> newStudent.examsMarks[j];
                sumMarks += newStudent.examsMarks[j];
                if (newStudent.examsMarks[j] == 2)
                {
                    temp++;
                }
            }
            for (int j = 0; j < 5; j++)
            {
                switch (j)
                {
                case 0:
                    cout << "Enter the Physics mark: ";
                    break;
                case 1:
                    cout << "Enter the Philosophy mark: ";
                    break;
                case 2:
                    cout << "Enter the English mark: ";
                    break;
                case 3:
                    cout << "Enter the Informatics mark: ";
                    break;
                case 4:
                    cout << "Enter the Foundations of Russian statehood mark: ";
                    break;
                }
                cin >> newStudent.testsMarks[j];
                sumMarks += newStudent.testsMarks[j];
                if (newStudent.testsMarks[i] == 2)
                {
                    temp++;
                }
            }
            newStudent.average = (float)sumMarks / 8;
            if (!newFile.is_open())
            {
                cout << "Error! File is not opened!\n";
            }
            else
            {
                if (temp == 0)
                {
                    newFile << newStudent.surname << ' ' << newStudent.name << ' ' << newStudent.patronymic << ' ' << newStudent.isMale << ' ' << newStudent.group << ' ' << newStudent.id << ' ';
                    for (int j = 0; j < 3; j++)
                    {
                        newFile << newStudent.examsMarks[j] << ' ';
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        newFile << newStudent.testsMarks[j] << ' ';
                    }
                    newFile << newStudent.average;
                    newFile << "\n";
                    cout << "Done!\n";
                }
                else
                {
                    cout << "Error! Student cannot be written in file because of 2 marks!\n";
                }
            }
        }
        else
        {
            newFile << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << ' ' << student[i].isMale << ' ' <<
                student[i].group << ' ' << student[i].id << ' ';
            for (int j = 0; j < 3; j++)
            {
                newFile << student[i].examsMarks[j] << ' ';
            }
            for (int j = 0; j < 5; j++)
            {
                newFile << student[i].testsMarks[j] << ' ';
            }
            newFile << student[i].average << endl;
        }
    }
    newFile.close();
    remove("students.txt");
    rename("newFile.txt", "students.txt");
    delete[] student;
}

void menu()
{
    cout << "\n1.Create a new student record.\n2. Making changes to an existing record.\n3. Output of all student data.\n" <<
        "4. The output of information about all students of group N.\n5. The conclusion of the top of the most successful students with the highest rated average score for the last session." <<
        "\n6. Output the number of male and female students.\n7. Output data on students who do not receive a scholarship; study only at 4 and 5; study only at 5\n" <<
        "8. Output data on students who have a number in the list – k.\nm. Go to menu\ne. Exit\n\n";
}

void allStudents()
{
    ifstream file;
    file.open("students.txt");
    if (!file.is_open())
    {
        cout << "Error! File is not opened!\n";
    }
    else
    {
        int count = countStudents();
        Student* student = new Student[count];
        ifstream file("students.txt");
        for (int i = 0; i < count; i++)
        {
            file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >> student[i].group >> student[i].id;
            for (int j = 0; j < 3; j++)
            {
                file >> student[i].examsMarks[j];
            }
            for (int j = 0; j < 5; j++)
            {
                file >> student[i].testsMarks[j];
            }
            file >> student[i].average;
            cout << "_____________________________________________\n";
            cout << "Full name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
            cout << "Sex: ";
            if (student[i].isMale)
            {
                cout << "Male\n";
            }
            else
            {
                cout << "Female\n";
            }
            cout << "Group and id in group: " << student[i].group << ' ' << student[i].id << '\n';
            cout << "Exams marks: \n";
            for (int j = 0; j < 3; j++)
            {
                switch (j)
                {
                case 0:
                    cout << "Programming: ";
                    break;
                case 1:
                    cout << "Mathematical analysis: ";
                    break;
                case 2:
                    cout << "Algebra and geometry: ";
                    break;
                }
                cout << student[i].examsMarks[j] << '\n';
            }
            for (int j = 0; j < 5; j++)
            {
                switch (j)
                {
                case 0:
                    cout << "Physics: ";
                    break;
                case 1:
                    cout << "Philosophy: ";
                    break;
                case 2:
                    cout << "English: ";
                    break;
                case 3:
                    cout << "Informatics: ";
                    break;
                case 4:
                    cout << "The Foundations of Russian statehood: ";
                    break;
                }
                cout << student[i].testsMarks[j] << '\n';
            }
            cout << "_____________________________________________\n";
        }
        delete[] student;
    }

}

void writeStudentsGroup()
{
    int groupNumber;
    cout << "Enter the group number: ";
    cin >> groupNumber;
    ifstream file;
    file.open("students.txt");
    if (!file.is_open())
    {
        cout << "Error! File is not opened!";
    }
    else
    {
        int count = countStudents();
        if (count == 0)
        {
            cout << "There are no students in group!";
        }
        else
        {
            Student* student = new Student[count];
            for (int i = 0; i < count; i++)
            {
                file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >>
                    student[i].group >> student[i].id;
                    for (int j = 0; j < 3; j++)
                    {
                        file >> student[i].examsMarks[j];
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        file >> student[i].testsMarks[j];
                    }
                    file >> student[i].average;
            }
            file.close();
            int temp = 0;
            for (int i = 0; i < count; i++)
            {
                if (student[i].group == groupNumber)
                {
                    cout << "_________________________________________________________\n";
                    cout << "Name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
                    cout << "Sex: ";
                    if (student[i].isMale)
                    {
                        cout << "Male\n";
                    }
                    else
                    {
                        cout << "Female\n";
                    }
                    cout << "Group: " << student[i].group << "\nNumber in group: " << student[i].id << '\n';
                    cout << "Exams: \n";
                    for (int j = 0; j < 3; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            cout << "Programming: ";
                            break;
                        case 1:
                            cout << "Mathematical analysis: ";
                            break;
                        case 2:
                            cout << "Algebra and geometry: ";
                            break;
                        }
                        cout << student[i].examsMarks[j] << '\n';
                    }
                    cout << "Tests: \n";
                    for (int j = 0; j < 5; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            cout << "Physics: ";
                            break;
                        case 1:
                            cout << "Philosophy: ";
                            break;
                        case 2:
                            cout << "English: ";
                            break;
                        case 3:
                            cout << "Informatics: ";
                            break;
                        case 4:
                            cout << "Foundations of Russian statehood: ";
                            break;
                        }
                        cout << student[i].testsMarks[j] << '\n';
                    }
                    cout << "_________________________________________________________\n";
                    temp++;
                }
            }
            delete[] student;
        }
    }
}

void printTop()
{
    ifstream file;
    file.open("students.txt");
    if (!file.is_open())
    {
        cout << "Error! File is not opened!";
    }
    else
    {
        int count = countStudents();
        if (count == 0)
        {
            cout << "There are no students in group!";
        }
        else
        {
            Student* student = new Student[count];
            for (int i = 0; i < count; i++)
            {
                file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >>
                    student[i].group >> student[i].id;
                for (int j = 0; j < 3; j++)
                {
                    file >> student[i].examsMarks[j];
                }
                for (int j = 0; j < 5; j++)
                {
                    file >> student[i].testsMarks[j];
                }
                file >> student[i].average;
            }
            file.close();
            for (int i = 0; i < count; i++)
            {
                for (int j = 0; j < count - 1 - i; j++)
                {
                    if (student[j].average < student[j + 1].average)
                    {
                        swap(student[j], student[j + 1]);
                    }
                }
            }
            cout << "The top of students by average: \n";
            for (int i = 0; i < count; i++)
            {
                cout << "_________________________________________________________\n";
                cout << "Name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
                cout << "Sex: ";
                if (student[i].isMale)
                {
                    cout << "Male\n";
                }
                else
                {
                    cout << "Female\n";
                }
                cout << "Group: " << student[i].group << "\nNumber in group: " << student[i].id << '\n';
                cout << "Exams: \n";
                for (int j = 0; j < 3; j++)
                {
                    switch (j)
                    {
                    case 0:
                        cout << "Programming: ";
                        break;
                    case 1:
                        cout << "Mathematical analysis: ";
                        break;
                    case 2:
                        cout << "Algebra and geometry: ";
                        break;
                    }
                    cout << student[i].examsMarks[j] << '\n';
                }
                cout << "Tests: \n";
                for (int j = 0; j < 5; j++)
                {
                    switch (j)
                    {
                    case 0:
                        cout << "Physics: ";
                        break;
                    case 1:
                        cout << "Philosophy: ";
                        break;
                    case 2:
                        cout << "English: ";
                        break;
                    case 3:
                        cout << "Informatics: ";
                        break;
                    case 4:
                        cout << "Foundations of Russian statehood: ";
                        break;
                    }
                    cout << student[i].testsMarks[j] << '\n';
                }
                cout << "Average: " << student[i].average << '\n';
                cout << "_________________________________________________________\n";
            }
            delete[] student;
        }
    }
}

void countStudentsSex()
{
    bool isMale;
    cout << "Enter the sex (1 - Male, 0 - Female): ";
    cin >> isMale;
    ifstream file;
    file.open("students.txt");
    if (!file.is_open())
    {
        cout << "Error! File is not opened!";
    }
    else
    {
        int count = countStudents();
        if (count == 0)
        {
            cout << "There are no students!";
        }
        else
        {
            Student* student = new Student[count];
            for (int i = 0; i < count; i++)
            {
                file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >>
                    student[i].group >> student[i].id;
                for (int j = 0; j < 3; j++)
                {
                    file >> student[i].examsMarks[j];
                }
                for (int j = 0; j < 5; j++)
                {
                    file >> student[i].testsMarks[j];
                }
                file >> student[i].average;
            }
            file.close();
            int temp = 0;
            for (int i = 0; i < count; i++)
            {
                if (student[i].isMale == isMale)
                {
                    temp++;
                }
            }
            cout << "There are " << temp << " students\n";
            delete[] student;
        }
    }
}

void printScolarship()
{
    ifstream file;
    file.open("students.txt");
    if (!file.is_open())
    {
        cout << "Error! File is not opened!";
    }
    else
    {
        int count = countStudents();
        if (count == 0)
        {
            cout << "There are no students in group!";
        }
        else
        {
            Student* student = new Student[count];
            for (int i = 0; i < count; i++)
            {
                file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >>
                    student[i].group >> student[i].id;
                for (int j = 0; j < 3; j++)
                {
                    file >> student[i].examsMarks[j];
                }
                for (int j = 0; j < 5; j++)
                {
                    file >> student[i].testsMarks[j];
                }
                file >> student[i].average;
            }
            file.close();
            int choice;
            cout << "1 - Students without scolarship (with 3,4,5)\n2 - Students with scolarship (with 4,5)\n3 - Students with scolarship (with only 5)\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                for (int i = 0; i < count; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].examsMarks[j] == 3)
                        {
                            temp++;
                        }
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        if (student[i].testsMarks[j] == 3)
                        {
                            temp++;
                        }
                    }
                    if (temp)
                    {
                        cout << "_________________________________________________________\n";
                        cout << "Name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
                        cout << "Sex: ";
                        if (student[i].isMale)
                        {
                            cout << "Male\n";
                        }
                        else
                        {
                            cout << "Female\n";
                        }
                        cout << "Group: " << student[i].group << "\nNumber in group: " << student[i].id << '\n';
                        cout << "Exams: \n";
                        for (int j = 0; j < 3; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                cout << "Programming: ";
                                break;
                            case 1:
                                cout << "Mathematical analysis: ";
                                break;
                            case 2:
                                cout << "Algebra and geometry: ";
                                break;
                            }
                            cout << student[i].examsMarks[j] << '\n';
                        }
                        cout << "Tests: \n";
                        for (int j = 0; j < 5; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                cout << "Physics: ";
                                break;
                            case 1:
                                cout << "Philosophy: ";
                                break;
                            case 2:
                                cout << "English: ";
                                break;
                            case 3:
                                cout << "Informatics: ";
                                break;
                            case 4:
                                cout << "Foundations of Russian statehood: ";
                                break;
                            }
                            cout << student[i].testsMarks[j] << '\n';
                        }
                        cout << "_________________________________________________________\n";
                    }
                }
                break;
            case 2:
                for (int i = 0; i < count; i++)
                {
                    int temp1 = 0;
                    int temp2 = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].examsMarks[j] == 3)
                        {
                            temp1++;
                        }
                        if (student[i].examsMarks[j] == 5)
                        {
                            temp2++;
                        }
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        if (student[i].testsMarks[j] == 3)
                        {
                            temp1++;
                        }
                        if(student[i].testsMarks[j] == 5)
                        {
                            temp2++;
                        }
                    }
                    if ((temp1 == 0) && (temp2 != 8))
                    {
                        cout << "_________________________________________________________\n";
                        cout << "Name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
                        cout << "Sex: ";
                        if (student[i].isMale)
                        {
                            cout << "Male\n";
                        }
                        else
                        {
                            cout << "Female\n";
                        }
                        cout << "Group: " << student[i].group << "\nNumber in group: " << student[i].id << '\n';
                        cout << "Exams: \n";
                        for (int j = 0; j < 3; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                cout << "Programming: ";
                                break;
                            case 1:
                                cout << "Mathematical analysis: ";
                                break;
                            case 2:
                                cout << "Algebra and geometry: ";
                                break;
                            }
                            cout << student[i].examsMarks[j] << '\n';
                        }
                        cout << "Tests: \n";
                        for (int j = 0; j < 5; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                cout << "Physics: ";
                                break;
                            case 1:
                                cout << "Philosophy: ";
                                break;
                            case 2:
                                cout << "English: ";
                                break;
                            case 3:
                                cout << "Informatics: ";
                                break;
                            case 4:
                                cout << "Foundations of Russian statehood: ";
                                break;
                            }
                            cout << student[i].testsMarks[j] << '\n';
                        }
                        cout << "_________________________________________________________\n";
                    }
                }
                break;
            case 3:
                for (int i = 0; i < count; i++)
                {
                    int temp1 = 0;
                    int temp2 = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].examsMarks[j] == 3)
                        {
                            temp1++;
                        }
                        if (student[i].examsMarks[j] == 4)
                        {
                            temp2++;
                        }
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        if (student[i].testsMarks[j] == 3)
                        {
                            temp1++;
                        }
                        if (student[i].testsMarks[j] == 4)
                        {
                            temp2++;
                        }
                    }
                    if (!temp1 && !temp2)
                    {
                        cout << "_________________________________________________________\n";
                        cout << "Name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
                        cout << "Sex: ";
                        if (student[i].isMale)
                        {
                            cout << "Male\n";
                        }
                        else
                        {
                            cout << "Female\n";
                        }
                        cout << "Group: " << student[i].group << "\nNumber in group: " << student[i].id << '\n';
                        cout << "Exams: \n";
                        for (int j = 0; j < 3; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                cout << "Programming: ";
                                break;
                            case 1:
                                cout << "Mathematical analysis: ";
                                break;
                            case 2:
                                cout << "Algebra and geometry: ";
                                break;
                            }
                            cout << student[i].examsMarks[j] << '\n';
                        }
                        cout << "Tests: \n";
                        for (int j = 0; j < 5; j++)
                        {
                            switch (j)
                            {
                            case 0:
                                cout << "Physics: ";
                                break;
                            case 1:
                                cout << "Philosophy: ";
                                break;
                            case 2:
                                cout << "English: ";
                                break;
                            case 3:
                                cout << "Informatics: ";
                                break;
                            case 4:
                                cout << "Foundations of Russian statehood: ";
                                break;
                            }
                            cout << student[i].testsMarks[j] << '\n';
                        }
                        cout << "_________________________________________________________\n";
                    }
                }
            }
            delete[] student;
        }
    }
}

void writeStudentsIdGroup()
{
    int id;
    cout << "Enter the id in group: ";
    cin >> id;
    ifstream file;
    file.open("students.txt");
    if (!file.is_open())
    {
        cout << "Error! File is not opened!";
    }
    else
    {
        int count = countStudents();
        if (count == 0)
        {
            cout << "There are no students in group!";
        }
        else
        {
            Student* student = new Student[count];
            for (int i = 0; i < count; i++)
            {
                file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].isMale >>
                    student[i].group >> student[i].id;
                for (int j = 0; j < 3; j++)
                {
                    file >> student[i].examsMarks[j];
                }
                for (int j = 0; j < 5; j++)
                {
                    file >> student[i].testsMarks[j];
                }
                file >> student[i].average;
            }
            file.close();
            int temp = 0;
            for (int i = 0; i < count; i++)
            {
                if (student[i].id == id)
                {
                    cout << "_________________________________________________________\n";
                    cout << "Name: " << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << '\n';
                    cout << "Sex: ";
                    if (student[i].isMale)
                    {
                        cout << "Male\n";
                    }
                    else
                    {
                        cout << "Female\n";
                    }
                    cout << "Group: " << student[i].group << "\nNumber in group: " << student[i].id << '\n';
                    cout << "Exams: \n";
                    for (int j = 0; j < 3; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            cout << "Programming: ";
                            break;
                        case 1:
                            cout << "Mathematical analysis: ";
                            break;
                        case 2:
                            cout << "Algebra and geometry: ";
                            break;
                        }
                        cout << student[i].examsMarks[j] << '\n';
                    }
                    cout << "Tests: \n";
                    for (int j = 0; j < 5; j++)
                    {
                        switch (j)
                        {
                        case 0:
                            cout << "Physics: ";
                            break;
                        case 1:
                            cout << "Philosophy: ";
                            break;
                        case 2:
                            cout << "English: ";
                            break;
                        case 3:
                            cout << "Informatics: ";
                            break;
                        case 4:
                            cout << "Foundations of Russian statehood: ";
                            break;
                        }
                        cout << student[i].testsMarks[j] << '\n';
                    }
                    cout << "_________________________________________________________\n";
                    temp++;
                }
            }
            delete[] student;
        }
    }
}

void abitMenu()
{
    cout << "1. Create new record\n" << "2. Print abiturients under 18 yo\n" << "3. Print abiturients with average of exams from 85\n" << "4. Print abiturients who not from StP\n" <<
        "5. Print abiturients with 5 average of certificate\n" << "e. Exit\n";
}

void newAbit()
{
    Abiturient abiturient;
    cout << "Enter the surname: ";
    cin >> abiturient.surname;
    cout << "Enter the name: ";
    cin >> abiturient.name;
    cout << "Enter the patronymic: ";
    cin >> abiturient.patronymic;
    cout << "If student is male - 1, is female - 0: ";
    cin >> abiturient.isMale;
    cout << "Enter the age: ";
    cin >> abiturient.age;
    cout << "Enter the city: ";
    cin >> abiturient.city;
    int sumMarks = 0;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            cout << "Exam 1: ";
            break;
        case 1:
            cout << "Exam 2: ";
            break;
        case 2:
            cout << "Exam 3: ";
            break;
        }
        cin >> abiturient.examMarks[i];
        sumMarks += abiturient.examMarks[i];
    }
    abiturient.averageOfExams = sumMarks / 3;
    cout << "If abiturient gave the original of certificate - 1, else - 0: ";
    cin >> abiturient.originalTrue;
    cout << "Enter the average of certificate: ";
    cin >> abiturient.averageOfCertificate;
    ofstream file;
    file.open("abiturients.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error! File is not opened!\n";
    }
    else
    {
        file << abiturient.surname << ' ' << abiturient.name << ' ' << abiturient.patronymic << ' ' << abiturient.isMale << ' ' <<
            abiturient.age << ' ' << abiturient.city << ' ' << abiturient.averageOfExams << ' ' << abiturient.originalTrue << ' ' <<
            abiturient.averageOfCertificate << endl;
    }
}

int countAbit()
{
    ifstream file("abiturients.txt");
    if (file.is_open())
    {
        int k = 0;
        string str;
        while (getline(file, str))
        {
            k++;
        }
        return k;
    }
    file.close();
}

void abitUnder18()
{
    ifstream file;
    file.open("abiturients.txt");
    int count = countAbit();
    Abiturient* abit = new Abiturient[count];
    for (int i = 0; i < count; i++)
    {
        file >> abit[i].surname >> abit[i].name >> abit[i].patronymic >> abit[i].isMale >> abit[i].age >> abit[i].city >>
            abit[i].averageOfExams >> abit[i].originalTrue >> abit[i].averageOfCertificate;
    }
    file.close();
    for (int i = 0; i < count; i++)
    {
        if (abit[i].age < 18)
        {
            cout << "______________________________________________________\n";
            cout << "Full name: " << abit[i].surname << ' ' << abit[i].name << ' ' << abit[i].patronymic << endl;
            if (abit[i].isMale)
            {
                cout << "Sex: Male\n";
            }
            else
            {
                cout << "Sex: Female\n";
            }
            cout << "Age: " << abit[i].age << endl;
            cout << "City: " << abit[i].city << endl;
            cout << "Average of exams: " << abit[i].averageOfExams << endl;
            if (abit[i].originalTrue)
            {
                cout << "Original: yes\n";
            }
            else
            {
                cout << "Original: no\n";
            }
            cout << "Average of certificate: " << abit[i].averageOfCertificate << endl;
            cout << "______________________________________________________\n";
        }
    }
    delete[] abit;
}

void abitEgeFrom85()
{
    ifstream file;
    file.open("abiturients.txt");
    int count = countAbit();
    Abiturient* abit = new Abiturient[count];
    for (int i = 0; i < count; i++)
    {
        file >> abit[i].surname >> abit[i].name >> abit[i].patronymic >> abit[i].isMale >> abit[i].age >> abit[i].city >>
            abit[i].averageOfExams >> abit[i].originalTrue >> abit[i].averageOfCertificate;
    }
    file.close();
    for (int i = 0; i < count; i++)
    {
        if (abit[i].averageOfExams >= 85)
        {
            cout << "______________________________________________________\n";
            cout << "Full name: " << abit[i].surname << ' ' << abit[i].name << ' ' << abit[i].patronymic << endl;
            if (abit[i].isMale)
            {
                cout << "Sex: Male\n";
            }
            else
            {
                cout << "Sex: Female\n";
            }
            cout << "Age: " << abit[i].age << endl;
            cout << "City: " << abit[i].city << endl;
            cout << "Average of exams: " << abit[i].averageOfExams << endl;
            if (abit[i].originalTrue)
            {
                cout << "Original: yes\n";
            }
            else
            {
                cout << "Original: no\n";
            }
            cout << "Average of certificate: " << abit[i].averageOfCertificate << endl;
            cout << "______________________________________________________\n";
        }
    }
    delete[] abit;
}

void abitNotSpb()
{
    ifstream file;
    file.open("abiturients.txt");
    int count = countAbit();
    Abiturient* abit = new Abiturient[count];
    for (int i = 0; i < count; i++)
    {
        file >> abit[i].surname >> abit[i].name >> abit[i].patronymic >> abit[i].isMale >> abit[i].age >> abit[i].city >>
            abit[i].averageOfExams >> abit[i].originalTrue >> abit[i].averageOfCertificate;
    }
    file.close();
    for (int i = 0; i < count; i++)
    {
        if (abit[i].city != "Saint-Petersburg")
        {
            cout << "______________________________________________________\n";
            cout << "Full name: " << abit[i].surname << ' ' << abit[i].name << ' ' << abit[i].patronymic << endl;
            if (abit[i].isMale)
            {
                cout << "Sex: Male\n";
            }
            else
            {
                cout << "Sex: Female\n";
            }
            cout << "Age: " << abit[i].age << endl;
            cout << "City: " << abit[i].city << endl;
            cout << "Average of exams: " << abit[i].averageOfExams << endl;
            if (abit[i].originalTrue)
            {
                cout << "Original: yes\n";
            }
            else
            {
                cout << "Original: no\n";
            }
            cout << "Average of certificate: " << abit[i].averageOfCertificate << endl;
            cout << "______________________________________________________\n";
        }
    }
    delete[] abit;
}

void abitCert5()
{
    ifstream file;
    file.open("abiturients.txt");
    int count = countAbit();
    Abiturient* abit = new Abiturient[count];
    for (int i = 0; i < count; i++)
    {
        file >> abit[i].surname >> abit[i].name >> abit[i].patronymic >> abit[i].isMale >> abit[i].age >> abit[i].city >>
            abit[i].averageOfExams >> abit[i].originalTrue >> abit[i].averageOfCertificate;
        if (abit[i].averageOfCertificate == 5)
        {
            cout << "______________________________________________________\n";
            cout << "Full name: " << abit[i].surname << ' ' << abit[i].name << ' ' << abit[i].patronymic << endl;
            if (abit[i].isMale)
            {
                cout << "Sex: Male\n";
            }
            else
            {
                cout << "Sex: Female\n";
            }
            cout << "Age: " << abit[i].age << endl;
            cout << "City: " << abit[i].city << endl;
            cout << "Average of exams: " << abit[i].averageOfExams << endl;
            if (abit[i].originalTrue)
            {
                cout << "Original: yes\n";
            }
            else
            {
                cout << "Original: no\n";
            }
            cout << "Average of certificate: " << abit[i].averageOfCertificate << endl;
            cout << "______________________________________________________\n";
        }
    }
    file.close();
    delete[] abit;
}

int main()
{
    setlocale(0, "");
    char choiceStud = '0';
    char choiceAbit = '0';
    do {
        bool mainChoice;
        cout << "1 - Students, 0 - Abiturients: ";
        cin >> mainChoice;
        if (mainChoice)
        {
            menu();
            cout << "Enter your choice: ";
            cin >> choiceStud;
            switch (choiceStud)
            {
            case '1':
                newStudent();//новая запись в файл
                break;
            case '2':
                rewriteStudent();//изменение в запись
                break;
            case '3':
                allStudents();//вывод всех
                break;
            case '4':
                writeStudentsGroup();//по группе
                break;
            case '5':
                printTop();//топ
                break;
            case '6':
                countStudentsSex();//по полу
                break;
            case '7':
                printScolarship();//по успеваемости
                break;
            case '8':
                writeStudentsIdGroup();//по номеру в списке
                break;
            case 'm':
                menu();//вывод меню
                break;
            case 'e':
                return 0;//выход
            }
        }
        else
        {
            abitMenu();
            cout << "Enter your choice: ";
            cin >> choiceAbit;
            switch (choiceAbit)
            {
            case '1':
                newAbit();
                break;
            case '2':
                abitUnder18();
                break;
            case '3':
                abitEgeFrom85();
                break;
            case '4':
                abitNotSpb();
                break;
            case '5':
                abitCert5();
                break;
            case 'e':
                return 0;
            }
        }
    } while (choiceStud != 'e' || choiceAbit != 'e');
}
