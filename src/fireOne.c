#include "../include/headerA3.h"

void fireOne(a3Emp **headLL, int whichOne) { //function to fire one employee
    a3Emp *temp = *headLL; //create a temporary pointer to the head of the list
    a3Emp *prev = NULL; //create a previous pointer
    int count = 1;
    int numEmps = 0;

    if (*headLL == NULL) {
        printf("Error: list is empty.\n"); //if the list is empty print an error message and return
        return;
        
    }
    if (whichOne ==0){ //if whichOne is 0 print an error message and return
        return;
    }
    if (whichOne == 1) {
        *headLL = (*headLL)->nextEmployee; //if whichOne is 1 then move the head of the list to the next employee
        printf("Employee [Id: %d] fired", temp->empId);
        free(temp);
    } else {
        // Use temp to iterate through the list, preserving the original head of the list
        while (temp != NULL && count < whichOne) { //while the temporary pointer is not null and the count is less than whichOne set temp to the employee that needs to be fired
            prev = temp;
            temp = temp->nextEmployee;
            count++;
        }
        
        // Check if the desired position was found, update the 'nextEmployee' pointer of the previous node, and free the memory
        if (temp != NULL) {
            prev->nextEmployee = temp->nextEmployee;
            printf("Employee [Id: %d] fired", temp->empId);
            free(temp);
        } else {
            printf("\nPosition not found");
        }
    }
    numEmps = countEmployees(*headLL); //call the countEmployees function to get the number of employees
    
    printf("\nThere are now %d employees\n", numEmps); //print the number of remaining employees
}