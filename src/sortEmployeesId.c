#include "../include/headerA3.h"

void sortEmployeesId(struct employee *headLL){ //use bubble sort to sort the linked list by employee id from smallest to largest and print them out

int numEmps = countEmployees(headLL); //get the number of employees in the list
int array[numEmps]; //create an array to store the employee ids

struct employee *current = headLL; //create a temporary pointer to the head of the list

if(current == NULL){ //if the list is empty print an error message and return
    printf("Error: There are no employees, list is unable to sort.\n");
    return;
}

while(current != NULL){ 
for (int i = 0; i < numEmps; i++){ //store the employee ids in the array
    array[i] = current->empId;
    current = current->nextEmployee; //move the pointer to the next employee
}
}

    for (int i = 0; i < numEmps; i++){ //bubble sort the array
        for (int j = 0; j < numEmps - i - 1; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < numEmps; i++){ //print the employees in order
        int empPos = lookOnId(headLL, array[i]);
        printOne(headLL, empPos);
    }


}



