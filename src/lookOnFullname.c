#include "../include/headerA3.h"


int lookOnFullName(struct employee *headLL, char whichName[100]) {
    struct employee *current = headLL; //create a temporary pointer to the head of the list
    int position = 0;
    char fullName[100];

    while (current != NULL) {  //while the temporary pointer is not null increment the count and move the pointer to the next employee
        position++;
        strcpy(fullName,""); //clear the fullName string
        strcat(fullName,current->fname); //concatenate the first name and last name to the fullName string
        strcat(fullName," ");
        strcat(fullName,current->lname);
        
    if((strcmp(fullName, whichName)==0)){ //if the fullName string is equal to the whichName string return the position
        return position;
    }
        current = current->nextEmployee; //move the pointer to the next employee
    }

    printf("\nError: Employee not found"); //if the employee is not found print an error message and return -1
    return -1;
}
