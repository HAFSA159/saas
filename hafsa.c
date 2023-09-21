#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TODO {
    int id, deadline;
    char titel[20], desc[200], status[50];
};


struct TODO liste[30];
int nbTask = 0;
int globalId = 0;

// Function to add a task
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
        
        // nbTask++;
        globalId++;
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
        printf("5. EXIT\n");
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
                exitProgram();
                break;
            default:
                printf("Invalid choice, Try Again\n");
                break;
        }
    }

    return 0;
}
