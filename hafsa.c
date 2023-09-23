#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct TODO {
    int id, deadline;
    char titel[20], desc[200], status[50];
};

struct TODO liste[30];

int nbTask = 0; //nbTask keeps track of the number of tasks in the list.
int globalId = 1; // and globalId is used to assign unique IDs to tasks

char listOfStatus[3][10] = {"todo", "doing", "done"};
// Function to add a task

int isValidStatus(char status[]) { //function check if the status id valid
    for (int i = 0; i < 3; i++) {
        if (strcmp(status, listOfStatus[i]) == 0) {
            return 1; // Valid status found
        }
    }
    return 0; // Status is not valid
}
void sortTitle() {
    int i, j;
    struct TODO temp; //ach hadaaaaaaaaaaaaaaaa

    for (i = 0; i < nbTask ; i++) { //outer
        for (j = i + 1; j < nbTask; j++) {//inner
            if (strcmp(liste[i].titel, liste[j].titel) > 0) {
                
                temp = liste[i];
                liste[i] = liste[j];
                liste[j] = temp;
            }
        }
    }
    printf("Sorted List of Tasks:\n");
    printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\n");
    for (int i = 0; i < nbTask; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status);
    }
}
void addTask() {

    printf("How many tasks do you want to enter? ");
    scanf("%d", &nbTask);

    for (int k = 0; k < nbTask; k++) {
        liste[k].id = globalId; //indix at3tah id
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
            globalId++; // to get each time a unique id
        }
    }

    printf("\nTask added successfully 😄\n");
}

// Function to modify a task by ID
void modifyTask() {
    int modificationID ,choix;
    printf("\nEnter the ID of the task you want to modify: ");
    scanf("%d", &modificationID);
    
    int check = 0;
    // check katkhed zero flwl Mn b3d kdore boucle bch tqlb ala task Li khsk dire aliha l update
    // dik condition If Ila lqity task K’t updateha
    
    for (int i = 0; i < nbTask; i++) {
     if (liste[i].id == modificationID) {

    printf("TAP 1 if you wanna change the titel \n");
    printf("TAP 2 if you wanna change the description \n");
    printf("TAP 3 if you wanna change the deadline \n");
    printf("Enter your choice");
    scanf("%d",&choix);
    
    switch(choix){
    case 1 :
            printf("\nEnter a new titel: ");
            scanf("%s", liste[i].titel); 
            break;
    case 2 :        
            printf("Enter a new description: ");
            scanf("%s", liste[i].desc);
            break;
    case 3 :        
            printf("Enter a new deadline for the task: ");
            scanf("%d", &liste[i].deadline);
            break;
        }
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
void deleteTask() {
    int findId;
printf("Enter the ID");
scanf(" %d",&findId);
    
    int found =-1 ;//makaynach

for(int i = 0; i < nbTask; i++){
    if(liste[i].id == findId){
         found = i;// rah hiya lfound id   
         break;     
    }   
}
 if(found!=-1){//ila kan $$$$$$$$$$$$$$$$$$$$$$$$$$$$ 😒
    for (int i = found; i < nbTask-1; i++){ //mni i9lb in9s lina indix lkhrani 
      liste[i].id = liste[i+1];//bach i compare lina i m3a li 7daha
    }
    nbTask--;
    printf("Task with id %d has been deleted",findId);
 }else{
    printf("Task with id %d not found",findId);
 }

}*/

void deleteTask() {
    int findId;
    printf("Enter the ID of the task you want to delete: ");
    scanf("%d", &findId);

    int foundIndex = -1; // Initialize to -1 to indicate not found

    for (int i = 0; i < nbTask; i++) {
        if (liste[i].id == findId) {
            foundIndex = i; // Store the index of the found task
            break;
        }
    }

    if (foundIndex != -1) {
        // Shift tasks to fill the gap left by the deleted task
        for (int i = foundIndex; i < nbTask - 1; i++) {
            liste[i] = liste[i + 1];
        }

        nbTask--;
        printf("Task with ID %d has been deleted.\n", findId);
    } else {
        printf("Task with ID %d not found.\n", findId);
    }
}



void statistics() {

    int choice = 0;
    char isCompleted[50] = "";//$$$$$$$$$$$

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
        printf("3. Sort Titels of Tasks\n");
        printf("4. Display the tasks\n");
        printf("5. Tasks statistics\n");
        printf("6. To Delete a Task\n");
        printf("7. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            // Removed while() replaced with for loop in the addTask() function
                addTask();
                break;
            case 2:
                modifyTask();
                break;
            case 3:
                sortTitle();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                statistics();
                break;
            case 6:
                deleteTask();
                break;
            case 7:
                exitProgram();
                break;
            default:
                printf("Invalid choice, Try Again\n");
                break;
        }
    }

    return 0;
}
