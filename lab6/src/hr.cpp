#include <lab6/main.hpp>

bool sortByVal(const pair<string, double> &a, const pair<string, double> &b)
{ 
    return (a.second > b.second); 
} 

Employee::Employee(string newid,string newname,string newsurname,string newposition)
{
    id=newid;
    name=newname;
    surname=newsurname;
    departmentId="";
    position=newposition;
}

Employee::Employee()
{

}

void Employee::printemployee()
{
    cout << "ID: " << id << endl << "Name: " << name << endl << "Surname: " << surname << endl << "Department ID: " << departmentId << endl << "Position: " << position << endl;
}

string Employee::getId()
{
    return id;
}

void Employee::setdepartment(string depid)
{
    departmentId = depid;
}

void HRMS::add(Employee employee, string departmentId, double salary )
{
    employee.setdepartment(departmentId);
    employees[employee.getId()] = employee;
    departments[departmentId].push_back(employee.getId());
    salaries[employee.getId()]=salary;
}

void HRMS::printDepartment(string departmentId)
{
    for (size_t it;it<departments[departmentId].size();it++)
    {
        cout << "Print Department: " << endl;
        employees[departments[departmentId][it]].printemployee();
    }
}

void HRMS::changeSalary(string employeeId, double salary)
{
    salaries[employeeId]=salary;
}

void HRMS::printSalaries()
{
    auto it = salaries.begin();
    for(it;it!=salaries.end();it++)
    {
        employees[it->first].printemployee();
        cout << "Salary: " << it->second << endl;
    }
}

void HRMS::printSalariesSorted()
{
    auto it = salaries.begin();
    
    vector <pair <string, double>> vec;
    for(it;it!=salaries.end();it++)
    {
        vec.push_back(make_pair(it->first,it->second));
    }
    sort(vec.begin(),vec.end(),sortByVal);
    auto it2 = vec.begin();
    for(it2;it2!=vec.end();it2++)
    {
        employees[it2->first].printemployee();
        cout << "Salary: " << it2->second << endl;
    }
}

void HRMS::main()
{
    Employee pracownik1("1","Julian","Makowski","ksiegowy");
    Employee pracownik2("2","Oliwer","Szulc","wozny");
    Employee pracownik3("3","Dawid","Baranowski","informatyk");
    Employee pracownik4("4","Gizela","Szymczak","ceo");
    Employee pracownik5("5","Kornelia","Zajac","wozny");
    Employee pracownik6("6","Ferdynand","Olejnik","vice ceo");
    Employee pracownik7("7","Mateusz","Wolski","informatyk");
    Employee pracownik8("8","Albina","Kasprzak","elektryk");
    Employee pracownik9("9","Wieslaw","Krawczyk","wozny");
    Employee pracownik10("10","Ewelina","Baranowska","ksiegowy");
    HRMS firma;
    firma.add(pracownik1,"01",4500.00);
    firma.add(pracownik2,"02",3000.00);
    firma.add(pracownik3,"01",5000.00);
    firma.add(pracownik4,"03",10000.00);
    firma.add(pracownik5,"03",3000.00);
    firma.add(pracownik6,"04",8000.00);
    firma.add(pracownik7,"01",5000.00);
    firma.add(pracownik8,"02",4800.00);
    firma.add(pracownik9,"04",3000.00);
    firma.add(pracownik10,"02",4500.00);
    firma.printDepartment("01");
    firma.printDepartment("02");
    firma.printDepartment("03");
    firma.printDepartment("04");
    firma.changeSalary("1",5000.00);
    firma.printSalaries();
    firma.changeSalary("5",3500.00);
    firma.printSalariesSorted();
}