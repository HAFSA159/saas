#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TODO {
    int id, deadline;
    char titel[20], desc[200], status[50];
};


struct TODO liste[30];

int nbTask = 0;
int globalId = 1;

char listOfStatus[10][10] = {"todo", "doing", "done"};
// Function to add a task

int isValidStatus(char status[]) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(status, listOfStatus[i]) == 0) {
            return 1; // Valid status found
        }
    }
    return 0; // Status is not valid
}
void addTask() {

    printf("How many tasks do you want to enter? ");
    scanf("%d", &nbTask);

    for (int k = 0; k < nbTask; k++) {
        liste[k].id = globalId;
        printf("\nEnter a title: ");
        scanf("%s", liste[k].titel);
        printf("Enter a description: ");
        scanf("%s", liste[k].desc);
        printf("Enter a deadline for the task: ");
        scanf("%d", &liste[k].deadline);
        printf("Enter the status of the task (todo, doing, done): ");
        scanf("%s", liste[k].status);

        if (!isValidStatus(liste[k].status)) {
            printf("Invalid status. Please enter a valid status (todo, doing, done).\n");
            k--; // Decrement k to re-enter the status
        } else {
            globalId++;
        }
    }

    printf("\nTask added successfully 😄\n");
}

// Function to modify a task by ID
void modifyTask() {
    int modificationID;
    printf("\nEnter the ID of the task you want to modify: ");
    scanf("%d", &modificationID);
    int check = 0;
    for (int i = 0; i < nbTask; i++) {
        if (liste[i].id == modificationID) {
            
            printf("\nEnter a new title: ");
            scanf("%s", liste[i].titel);
            printf("Enter a new description: ");
            scanf("%s", liste[i].desc);
            printf("Enter a new deadline for the task: ");
            scanf("%d", &liste[i].deadline);
            
            check = 1; // Task found and modified
            break;
        }
    }

    if (check == 0) {
        printf("Task with ID %d not found\n", modificationID);
    } else {
        printf("\nTask modified successfully 😄\n");
    }
}

// Function to display tasks
void displayTasks() {
    printf("List of tasks:\n");
    printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\n");

    for (int i = 0; i < nbTask; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status);
    }
}



void statistics() {

    int choice = 0;
    char isCompleted[50] = "";

    printf("1: Show total number of tasks\n");
    printf("2: Show total of tasks Completed\n");
    printf("3: Show total of tasks Incompleted\n");
    printf("4: Show total rest of days left for tasks\n");
    scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        printf("Total number of tasks: %d\n", nbTask);
        break;
    case 2:
        int completed = 0;
        for (int i = 0; i < nbTask; i++)
        {   
            if (strcmp(liste[i].status, "done") == 0) {
                completed++;
            } 
        }

        if(completed != 0) printf("Total number of tasks completed: %d\n", completed);
        
        break;

    case 3:
        int incompleted = 0;
        for (int i = 0; i < nbTask; i++)
        {   
            if (strcmp(liste[i].status, "doing") == 0 || strcmp(liste[i].status, "todo") == 0) {
                incompleted++;
            } 
        }
          if(incompleted != 0) printf("Total number of tasks Incompleted: %d\n", incompleted);
        
        break;
    case 4:
        int remaining = 0;
        for (int i = 0; i < nbTask; i++)
        {   
            if (strcmp(liste[i].status, "doing") == 0 || strcmp(liste[i].status, "todo") == 0) {
                incompleted++;
            } 
        }
          if(incompleted != 0) printf("Total number of tasks Incompleted: %d\n", incompleted);
        
        break;
    default:
        break;
    }

}


// Function to exit the program
void exitProgram() {
    printf("BYE BYE!\n");
    exit(0);
}

int main() {
    int choice;

    while (1) {
        printf("^^^^^^^^^^^^^ WELCOME 'TODO LIST' ^^^^^^^^^^^^^\n");
        printf("THE MENU\n");
        printf("1. Add a New Task\n");
        printf("2. Modify a Task\n");
        printf("3. Delete a Task\n");
        printf("4. Display the tasks\n");
        printf("5. Tasks statistics\n");
        printf("6. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            // Removed while() replaced with for loop in the addTask() function
                addTask();
                break;
            case 2:
                modifyTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                statistics();
            break;
            case 6:
                exitProgram();
                break;
            default:
                printf("Invalid choice, Try Again\n");
                break;
        }
    }

    return 0;
}
