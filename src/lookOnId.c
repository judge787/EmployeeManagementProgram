#include "../include/headerA3.h"

int lookOnId (struct employee *headLL, int whichEmpId){

struct employee * current; //create a temporary pointer to the head of the list
current = headLL; //set the temporary pointer to the head of the list
int position =0; 

while(current != NULL){ //while the temporary pointer is not null increment the count and move the pointer to the next employee
    position++;

    if(whichEmpId == current->empId){ //if the whichEmpId is equal to the current employee id return the position
    return position;
    }

    current = current->nextEmployee;
}

printf("\nError: Emp Id not found\n"); //if the employee is not found print an error message and return -1
return -1;

}