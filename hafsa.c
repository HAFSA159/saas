#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

struct TODO { // stocker 
    int id, deadline, dayEnd;
    char titel[20], desc[200], status[50];
};

struct TODO liste[30]; 

int nbTask = 0;

struct Date {
    int day;
    int month;
    int year;
};

    struct Date calculateDeadline(int daysToAdd) { //calcule current time  
    struct Date currentDate;
    time_t currentTime;
    struct Date deadline;
    struct tm tm_info;

    // Get the current time
    time(&currentTime);

    if (localtime_r(&currentTime, &tm_info) == NULL) {  
        printf("Error: localtime_r");
    }

    // This part extracts the current day of the month 
    currentDate.day = tm_info.tm_mday;  

    currentDate.month = tm_info.tm_mon + 1; 

    currentDate.year = tm_info.tm_year + 1900; 

    currentDate.day += daysToAdd;

    mktime(&tm_info); //converts time to UTC
    
    deadline.day = tm_info.tm_mday;
    deadline.month = tm_info.tm_mon + 1;
    deadline.year = tm_info.tm_year + 1900;

    return deadline;
}

int globalId = 1; 

char listOfStatus[3][10] = {"todo", "doing", "done"};

int isValidStatus(char status[]) { 
    for (int i = 0; i < 3; i++) {
        if (strcmp(status, listOfStatus[i]) == 0) {
            return 1; // found
        }
    }
    return 0; 
}

void sortTitle() {
    int i, j;
    struct TODO temp; 

    for (i = 0; i < nbTask - 1; i++) {  
        for (j = 0; j < nbTask - i - 1; j++) { 
            if (strcmp(liste[j].titel, liste[j + 1].titel) > 0) {
                
                temp = liste[j];
                liste[j] = liste[j + 1];
                liste[j + 1] = temp;
            }
        }
    }
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

        struct Date deadlineDate = calculateDeadline(liste[k].deadline);
        
        liste[k].dayEnd = deadlineDate.day + liste[k].deadline;

        printf("Deadline Date: %d/%d/%d\n", deadlineDate.day + liste[k].deadline, deadlineDate.month, deadlineDate.year);

        if (!isValidStatus(liste[k].status)) {
            printf("Invalid status. Please enter a valid status (todo, doing, done).\n");
            k--; 
        } else {
            globalId++;
        }
    }
    printf("\nTask added successfully 😄\n");
}

void modifyTask() {
    int modificationID ,choix;
    printf("\nEnter the ID of the task you want to modify: ");
    scanf("%d", &modificationID);
    
    int check = 0; 
    
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
    printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\tDate\n");

    for (int i = 0; i < nbTask; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\t%d\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status, liste[i].dayEnd);
    }
}

// Function to delete a task by ID
void deleteTask() {
    int deleteID;
    printf("Enter the ID of the task you want to delete: ");
    scanf("%d", &deleteID);

    int foundIndex = 0; 

    for (int i = 0; i < nbTask; i++) {
        if (liste[i].id == deleteID) {
            foundIndex = i;
            break;
        }
    }

    // Tasks deletes from list 
    if (foundIndex != 0) {
        for (int i = foundIndex; i < nbTask - 1; i++) {
            liste[i] = liste[i + 1];
        }
        nbTask--; 
        printf("Task with ID %d deleted successfully 😄\n", deleteID);
    } else {
        printf("Task with ID %d not found\n", deleteID);
    }
}


// statistics :

void statistics() {

    int choice = 0;

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
    printf("ID\tDEADLINE\n");
        for (int i = 0; i < nbTask; i++) {
            printf("%d\t%d\n", liste[i].id, liste[i].deadline);
        }
        break;
    default:
        break;
    }
}

void SortingByDeadlineDsc() {
    int k, i;
    struct TODO temp; // to avoid data to distract 

    for (int k = 0; k < nbTask - 1; k++) {  
        for (int i = k+1; i < nbTask; i++) {
            if(liste[k].dayEnd < liste[i].dayEnd){ //en comparant la 1er vc la 2em than w swipe thm
                
                temp = liste[k];
                liste[k] = liste[i];
                liste[i] = temp;
            }
        }
    }

    printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\tDate\n");
    for (int i = 0; i < nbTask; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\t%d\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status, liste[i].dayEnd);
    }
}

void searchTaskByID() {
    int searchID;
    printf("Enter the ID of the task you want to search for: ");
    scanf("%d", &searchID);

    int found = 0; 

    for (int i = 0; i < nbTask; i++) {
        if (liste[i].id == searchID) {
            printf("Task found:\n");
            printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\tDate\n");
            printf("%d\t%s\t%s\t\t%d\t\t%s\t%d\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status, liste[i].dayEnd);
            found = 1;
            break;
        }
    }
        if(found == 0)
           printf("Task with ID %d not found\n", searchID);
        else 
           printf("Task with ID %d found\n", searchID);
}

void SearchTaskByID() {
    int searchID;
    printf("Enter the ID of the task you want to search for: ");
    scanf("%d", &searchID);

    int found = 0; 

    for (int i = 0; i < nbTask; i++) {
        if (liste[i].id == searchID) {
            printf("Task found:\n");
            printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\tDate\n");
            printf("%d\t%s\t%s\t\t%d\t\t%s\t%d\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status, liste[i].dayEnd);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Task with ID %d not found\n", searchID);
    }
}

void SearchTaskByTitle() {
    char searchTitle[20];
    printf("Enter the title of the task you want to search for: ");
    scanf("%s", searchTitle);

    int found = 0;

    printf("Tasks with title '%s':\n", searchTitle);
    printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\tDate\n");

    for (int i = 0; i < nbTask; i++) {
        if (strcmp(liste[i].titel, searchTitle) == 0) {
            printf("%d\t%s\t%s\t\t%d\t\t%s\t%d\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status, liste[i].dayEnd);
            found = 1;
        }
    }

    if (found==0) {
        printf("No tasks with title '%s' found\n", searchTitle);
    }
}

void SortingByDeadlineAsc() {
    int i, j;
    struct TODO temp;

    for (int k = 0; k < nbTask ; k++) {
        for (int i = k+1; i < nbTask; i++) {
            if(liste[k].dayEnd > liste[i].dayEnd){
                temp = liste[k];
                liste[k] = liste[i];
                liste[i] = temp;
            }
        }
    }

    printf("ID\tTITLE\tDESCRIPTION\tDEADLINE\tSTATUS\tDate\n");
    for (int i = 0; i < nbTask; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\t%d\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status, liste[i].dayEnd);
    }
}

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
        printf("7. Sorting By Deadline Dsc\n");
        printf("8. Sorting By Deadline Asc\n");
        printf("9. Search Task By Title\n");
        printf("10. Search Task By ID\n");
        printf("0. EXIT");
        printf("Enter ur choice : \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
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
                SortingByDeadlineDsc();
                break;
            case 8:
                SortingByDeadlineAsc();
                break;
            case 9:
                SearchTaskByTitle()
                break;           
            case 10:
                SearchTaskByID();
                break;
            case 0:
               Exit();
                break;
            default:
                printf("Invalid choice, Try Again\n");
                break;
        }
    }
    return 0;
}
