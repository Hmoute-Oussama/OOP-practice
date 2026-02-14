// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
#include <vector>
#include <string>
class Course {
protected:
    string CourseName;
    double Grade;
public:
    Course(string name, double grade) {
        CourseName = name;
        Grade = grade;
    }
    void setCourseName(string name) {
        CourseName = name;
    }
    string getCourseName() const{
        return CourseName;
    }
    void setGrade(double grade) {
        Grade = grade;
    }
    double getGrade() const{
        return Grade;
    }
    void displayCourse() const{
        cout << "Course : " << CourseName << "- Grade : " << Grade << endl;
    }

};
class Person {
protected:
    string FirstName;
    string LastName;
    int Age;
public:
    void setFirstName(string first_name) {
        FirstName = first_name;
    }
    string getFirstName() const{
        return FirstName;
    }
    void setLastName(string last_name){
        LastName = last_name;
    }
    string getLastName() const{
        return LastName;
    }
    void setAge(int age) {
        Age = age;
    }
    int getAge() const{
        return Age;
    }
    Person(string firstname, string lastname, int age) {
        FirstName = firstname;
        LastName = lastname;
        Age = age;
    }
    void introduceYourSelf() const{
        cout <<"Introduce : " <<FirstName << " " << LastName << " is " << Age << " years old." << endl;
    }

};
class Student :public Person {
protected:
    int id;
    vector<Course> courses;
public:
    void addCourse(Course course) {
        courses.push_back(course);
     }
    double calculateGPA() const{
        if (courses.empty()) return 0.0;
        double sum = 0.0;
        for (auto x : courses) {
            sum += x.getGrade();
        }
        return sum / courses.size();
    }
    void setId(int id) {
        this->id = id;
    }
    int getId() const{
        return id;
    }
    Student(string firstname, string lastname, int age, int id) :Person(firstname, lastname, age) {
        this->id = id;
    }
    void whoIsYou() const{
        cout <<"who am i : "<< "My name is " << getFirstName() << " " << getLastName() << " and i am " << getAge() << " years old ." << endl;
    }
    void displayAllCourses() const{
        if (courses.empty()) {
            cout << "No course available !" << endl;
        }
        else {
            for (auto c : courses) {
                c.displayCourse();
            }
        }
        cout << "==============================================================" << endl;
    }
    bool passedAllCourses() const{
        for (auto c : courses) {
            if (c.getGrade() < 10.0) {
                return false;
            }
        }
        return true;
    }
    Course TheBestCourse() const{
        if (courses.empty()) {
            return Course("None", 0.0);
        }
        Course best = courses.at(0);
        for (auto c : courses) {
            if (c.getGrade() > best.getGrade()) {
                best = c;
            }
        }
        return best;
    }
     
};
 
class Teacher: public Person {
protected:
    string Subject;
    int YearsOfExperience;
public:
    Teacher( string firstname, string lastname, int age,string subject, int experience):Person( firstname,  lastname,  age) {
        Subject = subject;
        YearsOfExperience = experience;
    }
    string getSubject() const{
        return Subject;
    }
    void setSubject(string subject) {
        Subject = subject;
    }
    int getYearsofExperience() const{
        return YearsOfExperience;
    }
    void setYearsOfExperience(int years){
        YearsOfExperience = years;
    }
    void teach() const{
        cout << "The teacher " << getLastName() << " is teaching the subject " << Subject << endl;
    }
};
class School {
protected:
    string School_Name;
    vector<Student> students;
    vector<Teacher> teachers;
public :
    School(string name) {
        School_Name = name;
    }
    void setSchoolName(string name) {
        School_Name = name;
    }
    string getSchoolName() const{
        return School_Name;
    }
    void addStudent(Student s) {
        students.push_back(s);
    }
    void addTeacher(Teacher t) {
        teachers.push_back(t);
    }
    void displayAllStudent() const{
        if (students.empty()) {
            cout << "No students available ." << endl;
        }
        else {
            for (auto s : students) {
                s.introduceYourSelf();
            }
        }
        cout << "========================================" << endl;
    }
    void displayAllTeachers() const{
        if (teachers.empty()) {
            cout << "No teacher available ." << endl;
        }
        else {
            for (auto t : teachers) {
                t.introduceYourSelf();
            }
        }
        cout << "========================================" << endl;
    }
    double averageGPA() const{
        if (students.empty()) {
            return 0.0;
        }else {
            double sum = 0;
            for (auto s : students) {
                sum += s.calculateGPA();
            }
            return sum / students.size();
        }
        
    }
    
};
int main()
{
     
    School school("ENSA School");

    while (true) {
        cout << "\n===== SCHOOL MANAGEMENT MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Display All Students\n";
        cout << "4. Display All Teachers\n";
        cout << "5. Average GPA of Students\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string fname, lname;
            int age, id;
            cout << "First name: "; cin >> fname;
            cout << "Last name: "; cin >> lname;
            cout << "Age: "; cin >> age;
            cout << "ID: "; cin >> id;
            Student s(fname, lname, age, id);

             
            s.addCourse(Course("Math", 14.5));
            s.addCourse(Course("Physics", 12.0));

            school.addStudent(s);
            cout << "Student added!\n";
        }
        else if (choice == 2) {
            string fname, lname, subject;
            int age, exp;
            cout << "First name: "; cin >> fname;
            cout << "Last name: "; cin >> lname;
            cout << "Age: "; cin >> age;
            cout << "Subject: "; cin >> subject;
            cout << "Years of experience: "; cin >> exp;
            Teacher t(fname, lname, age, subject, exp);
            school.addTeacher(t);
            cout << "Teacher added!\n";
        }
        else if (choice == 3) {
            school.displayAllStudent();
        }
        else if (choice == 4) {
            school.displayAllTeachers();
        }
        else if (choice == 5) {
            cout << "Average GPA of all students: " << school.averageGPA() << endl;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    cout << "Exiting program.\n";
    return 0;
}

 
