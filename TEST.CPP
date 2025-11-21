#include <iostream>
#include <iomanip> 
#include "ansi_terminal.hpp"
#include "terminal.hpp"

using namespace std ;
using namespace Ansi ;
typedef struct employee {
char firstname[20] ;
char lastName[20] ;
int age ;
float salary ;
char gender ;
} employee;


void enterEmployee (employee* emp){
cout<<CLEAR_SCREEN<<CURSOR_HOME<<flush ;
cout << move(2 , 10) << BOLD << FG_BRIGHT_CYAN<< BG_YELLOW << "====="<<"ENTER EMPLOYEE DETAILS"<< "=====" << RESET ;
disableRawMode() ;
cout << move (4 , 10) << FG_BRIGHT_CYAN << "Enter First Name : " << RESET ;
cin >> emp->firstname ;




}