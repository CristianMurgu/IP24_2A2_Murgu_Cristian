// laborator1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// la1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#define NM 101

using namespace std;

class Person
{
public:
    Person() {}
    virtual ~Person() {}
    virtual string getStatus() const = 0;
};

class Student : public Person
{
private:
    int Age;
    string Name;
    int Nr_matricol;
public:
    Student(string name, int age, int nr_mat)
    {
        this->Name = name;
        this->Age = age;
        this->Nr_matricol = nr_mat;
    }
    string getStatus() const override
    {
        return "student";
    }
};

class Teacher : public Person
{
private:
    int Age;
    string Name;
    string Experience;
public:
    Teacher(){}
    Teacher(string name, int age, string experience)
    {
        this->Name = name;
        this->Age = age;
        this->Experience = experience;
    }
    string getStatus() const override
    {
        return "teacher";
    }
};
class Course
{
private:
    vector <Teacher> Prof;
    double Avg_grade=1;
public:
    Course() {}
    Course(double avg)
    {
        Avg_grade = avg;
    }
    double getAvg()
    {
        return this->Avg_grade;
    }
    void Add_teacher(Teacher New_t)
    {
        Prof.push_back(New_t);
    }
    Course& operator=(const Teacher& New_t)
    {
        Prof.push_back(New_t);
        return *this;
    }
    int countTeachers()
    {
        return Prof.size();
    }
    ~Course() {}
};

class University
{
protected:
    string University_name;
    string Department_name;
    string Location;
public:
    University() {}
    virtual ~University() {}
    virtual string getDepartment_name() const = 0;
    virtual string getUniversity() const = 0;
    virtual string getLocation() const = 0;
};

class Decan
{
protected:
    string Id_decan;
public:
    Decan() {}
    virtual ~Decan() {}
    virtual void Assign_decan(string New_d) = 0;
};

class Department : public University , public Decan
{
private:
    vector <Course> Courses;
    string Id_decan;
    string Department_name;
    string University_name;
    string Location;
public:
    Department(){}
    Department(string Uni_name, string Dep_name, string Loc)
    {
        this->Department_name = Dep_name;
        this->University_name = Uni_name;
        this->Location = Loc;
    }
    string getUniversity() const override
    {
        return University_name;
    }
    void Assign_decan(string New_d) override
    {
        this->Id_decan = New_d;
    }
    void Add_course(Course New_c)
    {
        this->Courses.push_back(New_c);
    }
    Department& operator=(const Course& New_c)
    {
        this->Courses.push_back(New_c);
        return *this;
    }
    int countTeachers()
    {
        int value=0;
        for (auto i : Courses)
        {
            value += i.countTeachers();
        }
    }
    string getLocation() const override
    {
        return this->Location;
    }
    string getDepartment_name() const override
    {
        return this->Department_name;
    }
};


int main()
{
    Student a("Dan",1,1);
    cout << a.getStatus()<<'\n';
    Course c;
    cout << c.getAvg()<<'\n';
    Teacher b("Ana", 40, "drd");
    c = b;
    cout << c.countTeachers();
    Department d("a","b","c");
    d.Assign_decan("Man");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
