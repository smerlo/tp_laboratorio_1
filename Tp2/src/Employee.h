#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct{
	int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;
}Employee;

int emp_initEmployees(Employee* list, int len);
int emp_getEmptyIndex(Employee* list,int length);
int emp_addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int emp_hasData(Employee* list,int length);
int emp_modificarArray(Employee* list,int length, int employeeId);
int emp_removeEmployee(Employee* list, int len, int id);
int emp_sortEmployees(Employee* list, int len, int order);
int emp_printEmployees(Employee* list, int length);
int emp_Sueldos(Employee list[], int len);
int emp_EliminarPorEmpleadoId(Employee* list,int limite, int indice);
int emp_imprimir(Employee* pElemento);
#endif /* EMPLOYEE_H_ */
