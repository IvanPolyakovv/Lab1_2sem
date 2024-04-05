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
    /*string surname;
    string name;
    string patronymic;
    cout << "Enter the full name of student you want to rewrite: ";
    cin >> surname >> name >> patronymic;
    int count = countStudents();
    Student* student = new Student[count];
    ifstream file("students.txt");
    for (int i = 0; i < count; i++)
    {
        file >> student[i].surname >> student[i].name >> student[i].patronymic >> student[i].group >> student[i].id;
        for (int j = 0; j < 3; j++)
        {
            file >> student[i].examsMarks[j];
        }
        for (int j = 0; j < 5; j++)
        {
            file >> student[i].testsMarks[j];
        }
        file.close();
        ofstream file;
        file.open("newFile.txt");
        if (student[i].surname == surname && student[i].name == name && student[i].patronymic == patronymic)
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
            cout << "Enter the new group: ";
            cin >> newStudent.group;
            cout << "Enter the new number in group: ";
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
                if (newStudent.testsMarks[j] == 2)
                {
                    temp++;
                }
            }
            newStudent.average = (float)sumMarks / 8;
            if (!file.is_open())
            {
                cout << "Error! File is not opened!\n";
            }
            else
            {
                if (temp == 0)
                {
                    file << newStudent.surname << ' ' << newStudent.name << ' ' << newStudent.patronymic << ' ' << newStudent.isMale << ' ' << newStudent.group << ' ' << newStudent.id << ' ';
                    for (int j = 0; j < 3; j++)
                    {
                        file << newStudent.examsMarks[j] << ' ';
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        file << newStudent.testsMarks[j] << ' ';
                    }
                    file << newStudent.average;
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
        else
        {
            file << student[i].surname << ' ' << student[i].name << ' ' << student[i].patronymic << ' ' << student[i].isMale << ' ' << student[i].group << ' ' << student[i].id << ' ';
            for (int j = 0; j < 3; j++)
            {
                file << student[i].examsMarks[j] << ' ';
            }
            for (int j = 0; j < 5; j++)
            {
                file << student[i].testsMarks[j] << ' ';
            }
            file << student[i].average;
            file << "\n";
        }
    }*/
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
            cout << "There are " << temp << " students";
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

int main()
{
    setlocale(0, "");
    char choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
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
    } while (choice != 'e');

}
