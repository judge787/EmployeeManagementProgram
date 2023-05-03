#include "../include/headerA3.h"

int main(int argc,char **argv){

    struct employee *headLL = NULL; //create a pointer to the head of the linked list

    loadEmpData(&headLL, "proFile.txt");  //load the employee data from the file

    int whileLoopTerminator = 0; //for while loop
    int userChoice = 0; //for menu options
    int position = 0;//for printOne fucntion
    int employeeId = 0;//for lookOnId function
    int lookOnIdPosition =0; //fprom lookOnId function
    char whichName[100]; //for lookOnFullName function
    int lookOnFullNamePosition = 0; //from lookOnFullName function
    int numberOfEmployees = 0; //for countEmployees function
    char yesOrNo[1]; //for choice 


while (whileLoopTerminator == 0){ //while loop for menu options
      
    printf("\nMenu options:\n");
    printf("1. Add a new employee\n");
    printf("2. Print data of all employees\n");
    printf("3. Print data of the nth employee\n");
    printf("4. Search for employee based on empId\n");
    printf("5. Search for employee based on full name\n");
    printf("6. Count the total number of employees\n");
    printf("7. Sort the employees based on their empId\n");
    printf("8. Remove the nth employee in the current LL\n");
    printf("9. Remove all employees in the current LL\n");
    printf("10. Exit\n");
    printf("Choose your menu option: ");
    scanf("%d", &userChoice);
    
    switch(userChoice){ //switch statement for menu options
    
        case 1:
            recruitEmployee(&headLL); //add a new employee
            break;
    
        case 2:
            printAll(headLL);  //print all employees
            break;  
        
        case 3:
            printf("\nEnter a position: "); 
            scanf("%d", &position);
            printOne(headLL, position); //print one employee
            break;
        
        case 4:
            printf("\nEnter a Employee ID: ");
            scanf("%d", &employeeId);
            lookOnIdPosition = lookOnId(headLL, employeeId); //look for employee based on id
            printf("Position: %d", lookOnIdPosition);
            break;
        
        case 5:
            printf("\nEnter the full name of the employee: ");
            getchar();
            fgets(whichName, 100, stdin); 
            whichName[strlen(whichName)-1] = '\0'; //remove the new line character
            lookOnFullNamePosition = lookOnFullName(headLL, whichName); //look for employee based on full name
            printf("\nReturn Value: position: %d\n", lookOnFullNamePosition); 
            printOne(headLL, lookOnFullNamePosition); //print the employee from the position returned from lookOnFullName
            break;
        
        case 6:
            numberOfEmployees = countEmployees(headLL); //count the number of employees
            printf("\n\nTotal number of employees = %d", numberOfEmployees); 
            break;
        
        case 7:
            sortEmployeesId(headLL); //sort the employees based on their id
            break;
        
        case 8:
            numberOfEmployees = countEmployees(headLL); //count the number of employees
            printf("Currently there are %d employees\n", numberOfEmployees); 
            printf("Which employee do you wish to fire – enter a value between %d and %d: ", (headLL->numDependents) -1, numberOfEmployees); //print the number of employees
            scanf(" %d", &position);
            fireOne(&headLL, position); //fire one employee
            break;
        
        case 9:
            getchar(); //clear the buffer
            printf("\nAre you sure you want to fire everyone: "); 
            scanf(" %c", &yesOrNo[0]); //get the user input
            if(yesOrNo[0] == 'y' || yesOrNo[0] == 'Y'){ //if the user input is y or Y then fire everyone
            fireAll(&headLL); //fire all employees
            }
            break;

        case 10: 
            fireAll(&headLL); //fire all employees
            whileLoopTerminator =1; //terminate the while loop
            break;

        default: //if the user enters an invalid input print an error message
            printf("Invalid input");
            break;
    }

}


    return 0;
 }