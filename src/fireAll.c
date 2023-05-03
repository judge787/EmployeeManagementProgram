#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL){

  a3Emp *temp = *headLL; //create a temporary pointer to the head of the list
  int count =0;
  
  if(*headLL == NULL){
    printf("Error: There are already no employees.\n");
    return;
  }
  else{

    
  while(*headLL != NULL){ //while the pointer is not null free the memory and move the pointer to the next employee
    count++;
    temp = *headLL; //create a temporary pointer to the head of the list
    for ( int i = 0; i < temp->numDependents; i++){ //free the memory for the dependents
    free (temp->dependents[i]);
    }
    free(temp->dependents); //free the memory for the dependents

                
    *headLL = (*headLL)->nextEmployee;
    free(temp);
  }
  }
  if(count != 0){
    printf("All fired. Linked list is now empty.\n"); //if the count is not 0 then print the message
  }
}

