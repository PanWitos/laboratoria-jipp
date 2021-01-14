#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Employee
{
    private:
        string id;
        string name;
        string surname;
        string departmentId;
        string position;
    public:
        Employee(string,string,string,string);
        Employee();
        void printemployee();
        string getId();
        void setdepartment(string);
};

class HRMS
{
    private:
        map<string,Employee> employees;
        map<string,vector<string>> departments;
        map<string,double> salaries;
    public:
        void add(Employee employee, string departmentId, double salary);
        void printDepartment(string departmentId);
        void changeSalary(string employeeId, double salary);
        void printSalaries();
        void printSalariesSorted();
        void main();
};