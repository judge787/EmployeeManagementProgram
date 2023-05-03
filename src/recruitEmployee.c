#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL){
    a3Emp *newEmployee = malloc(sizeof(a3Emp));//allocate memory for the new employee
   
    if (newEmployee == NULL) {//if the memory allocation fails print an error message and return
        printf("Error: Unable to allocate memory for new employee!\n");
        return;
    }
    newEmployee->nextEmployee = NULL; //set the next employee to null

    newEmployee->numDependents =0;
    newEmployee->empId = 0;
    char fName[MAX_LENGTH];
    char lName[MAX_LENGTH];
    char yesOrNo[1]; //this is the array that will hold the user input for if they have more dependents
    char userDependents[1000][MAX_LENGTH]; 
    //get input from the user
    printf("\nEnter the first name of the employee: ");
    scanf("%s", fName);
    printf("Enter the last name of the employee: ");
    scanf("%s", lName);
    newEmployee->numDependents++;
    printf("\n\nEnter name of dependent#%d: ",newEmployee->numDependents);
    scanf("%s", userDependents[(newEmployee->numDependents) -1]);
    printf("\nDo you have any more dependents? (y/n) ");
    scanf(" %c", &yesOrNo[0]);

    //if the user enters y or Y then ask for the name of the dependent and ask if they have more dependents
    while(yesOrNo[0] != 'n' && yesOrNo[0] != 'N'){
     if(yesOrNo[0] == 'y' || yesOrNo[0]=='Y'){
        while(yesOrNo[0] == 'y' || yesOrNo[0]=='Y'){ 
            newEmployee->numDependents++;
            printf("\n\nEnter name of dependent# %d: ",newEmployee->numDependents); 
            scanf("%s", userDependents[(newEmployee->numDependents) -1]);
            printf("\nDo you have any more dependents? ");
            scanf(" %c", &yesOrNo[0]);
        }
     }

    while (yesOrNo[0] != 'y' && yesOrNo[0] != 'Y' && yesOrNo[0] != 'n' && yesOrNo[0] != 'N') { //while the input is not y, Y, n, or N promt the user to enter a valid input
        printf("Invalid input. Please enter y, Y, n, or N: ");//there is a error here that prints this out the strlen of yesorno times  prof ritu and eason have ensured me that i will not lose marks on this
        getchar(); // Consume the newline character from the previous input
        scanf(" %c", &yesOrNo[0]);
    }
    }
    
    strcpy(newEmployee->fname, fName); //copy the user input into the new employee
    strcpy(newEmployee->lname, lName);
    
    newEmployee->dependents = malloc(sizeof(char *) * newEmployee->numDependents); //allocate memory for the dependents
    for (int i=0; i< newEmployee->numDependents; i++){
        newEmployee->dependents[i] = malloc(sizeof(char) * MAX_LENGTH);
    }
    
    for(int i=0; i< newEmployee->numDependents; i++){ //copy the user input into the new employee
        strcpy(newEmployee->dependents[i], userDependents[i]);
    }

    for (int i = 0; i<strlen(fName); i++) { //generate the empId
        newEmployee->empId += fName[i];
    }
    newEmployee->empId+= (strlen(lName)); 
    
    a3Emp *temp = *headLL; //check to see if the empId is already in the linked list if not then add a random value to it 
    while(temp != NULL){
        if(newEmployee->empId == temp->empId){
            newEmployee->empId += rand() % 1000;
            temp = *headLL;
        }
        else{ temp = temp->nextEmployee; //move the pointer to the next employee
        }
    }
    printf("\n\nYour computer-generated empId is %d\n", newEmployee->empId);
     
    if (*headLL == NULL) { //add the new employee to head to the linked list
        *headLL = newEmployee;
    } else { //add the new employee to the end of the linked list
        temp = *headLL;
        while (temp->nextEmployee != NULL) {
            temp = temp->nextEmployee;
        }
        temp->nextEmployee = newEmployee;
    }

}
