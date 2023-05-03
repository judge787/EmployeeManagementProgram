#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne){

struct employee *current; //create a temporary pointer to the head of the list
current = headLL;
int count =0;
int empFound = 0;
while (current != NULL){ //while the temporary pointer is not null increment the count and move the pointer to the next employee
   count++;
    if (count == whichOne){ //if the count is equal to the whichOne print the employee information
        empFound = 1; //set the empFound flag to 1
        printf("\n\nEmployee id: %d", current->empId);
        printf("\nFirst name: %s", current->fname);
        printf("\nLast name: %s", current->lname);
        printf("\nDependents: ");
        
        for(int i =0; i< current->numDependents; i++){ //print the dependents
            if (i!= (current->numDependents)-1){

            printf("%s, ", current->dependents[i]); //print the dependents so that there is a comma after each dependent
            }
            else printf("%s\n\n", current->dependents[i]); //print the dependents
        }
    }
    else {
        current = current->nextEmployee; // move the pointer to the next employee
    }
}
    if (empFound == 0) printf("Error: There is no employee with that id.\n");
}