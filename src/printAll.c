#include "../include/headerA3.h"

void printAll(struct employee *headLL){

struct employee *current; //create a temporary pointer to the head of the list
current = headLL; //set the temporary pointer to the head of the list
int count = 0; 
while(current != NULL){ //while the temporary pointer is not null increment the count and move the pointer to the next employee
    if(count==0){ //if the count is 0 print the header
        printf("\n\nEmployee #%d:", count +1);
        printf("\n    Employee id:%d", current->empId);
        printf("\n    First name:%s", current->fname);
        printf("\n    Last name:%s", current->lname);
        printf("\n    Dependents[%d]: ", current->numDependents);
    }
    else{
        printf("\nEmployee #%d:", count +1);
        printf("\n    Employee id:%d", current->empId);
        printf("\n    First name:%s", current->fname);
        printf("\n    Last name:%s", current->lname);
        printf("\n    Dependents[%d]: ", current->numDependents);
    }
    for(int i =0; i< current->numDependents; i++){ //print the dependents
        if (i!= (current->numDependents)-1){ //

        printf("%s, ", current->dependents[i]);
        }
        else printf("%s\n\n", current->dependents[i]); //print the dependents
    }
    
    count++; //increment the count
    current = current->nextEmployee; //move the pointer to the next employee
}
    if (count == 0) printf("Error: There are no employees.\n"); //if the count is 0 print an error message
    else printf("Currently, there are %d employees.\n", count); //print the number of employees
}