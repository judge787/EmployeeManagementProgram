#include "../include/headerA3.h"

int countEmployees(a3Emp * headLL){

    a3Emp *temp = headLL; //create a temporary pointer to the head of the list
    int count =0;
    if (temp == NULL) { //if the list is empty print an error message and return 0
        printf("Error from count function: There are no employees in the list.\n");
        return 0;
        
    } else {
            
            while (temp != NULL) { //while the temporary pointer is not null increment the count and move the pointer to the next employee
                temp = temp->nextEmployee;
                count++;
            }
            return count; //return the count
     }


}

