#pragma once 
typedef struct Employee {
    char firstName[20];
    char lastName[20];
    int age;
    int salary;
    char gender; 
} Employee;
void enterEmployee();
void displayEmployee();