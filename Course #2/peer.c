#include <stdio.h>
#include<stdlib.h>
#include<time.h>

//ENUMS with the 5 departaments
typedef enum{
  RRHH, Sales, Investigation, Software, Ejecutive
}Departaments;

//STRUCT with employee data 
typedef struct{
    Departaments departaments;
    int annual_salary;
    int social_security_number;
}EmployeeData;

//Prototype of function that generate the salary of each departament
int generateSalary(Departaments departaments);

//Protoype of function that print the name of departaments 
char* printDepartaments(Departaments departaments);

//Main function  
int main(void) {

  srand(time(NULL)); 
  EmployeeData employeeData[10];

  for(int i = 0; i < 10; i++) {
        employeeData[i].departaments = rand() % 5;
        employeeData[i].social_security_number = rand() % 1000000 +1; 
        employeeData[i].annual_salary = generateSalary(employeeData[i].departaments);
  }

  for(int i = 0; i < 10; i++) {
      printf("\nEmployee %d:\n", i+1);
      printf("  Departament: %s\n", printDepartaments(employeeData[i].departaments));
      printf("  Annual Salary: $%d\n", employeeData[i].annual_salary);
      printf("  Social Security Number: %i\n", employeeData[i].social_security_number);
  }

  return 0;
}

//Body of function that generate the salary of each departament
int generateSalary(Departaments departaments){
  int base_salary;
  switch(departaments) {
      case RRHH:
            base_salary = 30000;
          break;
      case Sales:
            base_salary = 40000;
          break;
      case Investigation:
            base_salary = 50000;
          break;
      case Software:
            base_salary = 65000;
          break;
      case Ejecutive:
            base_salary = 90000;
          break;
      default:
            base_salary = 0;
          break;
  }
  int displacement = rand() % 10000;
  return base_salary + displacement;
}

//Body of function that print the name of departaments

char* printDepartaments(Departaments departaments){
  switch(departaments){
    case RRHH:
      return "RRHH";
      break;
    case Sales:
      return "Sales";
      break;
    case Investigation:
      return "Investigation";
      break;
    case Software:
      return "Software";
      break;
    case Ejecutive:
      return "Ejecutive";
      break;
    default:
      return "Department not found";
  }
}