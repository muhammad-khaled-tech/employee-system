#include <iostream>
#include <iomanip>
#include "ansi_terminal.hpp"
#include "terminal.hpp"
#include "employee.hpp"
#include "input.hpp" 

using namespace std;
using namespace Ansi;

const int maxNumberOfEmployees = 100;
static Employee employees[maxNumberOfEmployees];
static int currentEmployeeCount = 0;


void waitForInput()
{
    while (readKey() == KEY_UNKNOWN);
}

void enterEmployee()
{
    
    if (currentEmployeeCount >= maxNumberOfEmployees)
    {
        cout << CLEAR_SCREEN << CURSOR_HOME << flush;
        cout << move(10, 20) << FG_BRIGHT_RED << "Error: Employee list is full!" << RESET;
        waitForInput();
        return;
    }


    cout << CLEAR_SCREEN << CURSOR_HOME << flush;
    cout << move(2, 10) << BOLD << FG_BRIGHT_CYAN << BG_YELLOW << "  ENTER EMPLOYEE DETAILS  " << RESET;

  
    disableRawMode(); 
    cout << SHOW_CURSOR;

    Employee newEmp;


    cout << move(4, 10) << FG_BRIGHT_CYAN << "First Name : " << RESET;
    cin >> setw(19) >> newEmp.firstName;

    cout << move(5, 10) << FG_BRIGHT_CYAN << "Last Name  : " << RESET;
    cin >> setw(19) >> newEmp.lastName;

    cout << move(6, 10) << FG_BRIGHT_CYAN << "Age        : " << RESET;
    cin >> newEmp.age;

    cout << move(7, 10) << FG_BRIGHT_CYAN << "Salary     : " << RESET;
    cin >> newEmp.salary;

    cout << move(8, 10) << FG_BRIGHT_CYAN << "Gender(M/F): " << RESET;
    cin >> setw(1) >> newEmp.gender; 

    enableRawMode();
    cout << HIDE_CURSOR;


    employees[currentEmployeeCount] = newEmp;
    currentEmployeeCount++;

    cout << move(12, 10) << FG_BRIGHT_GREEN << "Saved Successfully!" << RESET;
    cout << move(14, 10) << FG_CYAN << "(Press any key to return...)" << flush;
    
    waitForInput(); 
        cout << CLEAR_SCREEN << CURSOR_HOME << flush;

}


void displayEmployee()
{
    cout << CLEAR_SCREEN << CURSOR_HOME << flush;
    
   
    if (currentEmployeeCount == 0)
    {
        cout << move(10, 20) << FG_BRIGHT_RED << "Error: Employee list is empty!" << RESET;
        cout << move(12, 20) << FG_CYAN << "(Press any key to return...)" << flush;
        waitForInput();
        return;
    }

    cout << move(2, 25) << BOLD << FG_BRIGHT_CYAN << BG_WHITE << "  EMPLOYEE LIST  " << RESET;
    
    cout << move(4, 5) << BOLD << FG_BRIGHT_CYAN 
         << left << setw(20) << "First Name" 
         << setw(20) << "Last Name" 
         << setw(10) << "Age" 
         << setw(15) << "Salary" 
         << setw(10) << "Gender" << RESET;


    for (int i = 0; i < currentEmployeeCount; i++)
    {
        cout << move(5 + i, 5) << FG_WHITE 
             << left << setw(20) << employees[i].firstName 
             << setw(20) << employees[i].lastName 
             << setw(10) << employees[i].age 
             << fixed << setw(15)<< employees[i].salary 
             << setw(10) << employees[i].gender;
    }
    
    cout << move(7 + currentEmployeeCount, 10) << FG_BRIGHT_CYAN << "(Press any key to return...)" << flush;
    
    waitForInput(); 
        cout << CLEAR_SCREEN << CURSOR_HOME << flush;

    
}