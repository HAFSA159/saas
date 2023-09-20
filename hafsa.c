#include<stdio.h>
#include<stdlib.h>

struct TODO
{
    int id;
    char titel[20] , desc[200] , deadline[10], status[50]; 
};

struct TODO liste[90];
int nbTask = 0;

// for task adding
void addTask(){
    struct TODO newTask;
    newTask.id = nbTask + 1;
printf("Enter a titel : ");
scanf("%s",newTask.titel);
printf("Enter a description : ");
scanf("%s",newTask.desc);
printf("Enter a deadline for the task : ");
scanf("%s",newTask.deadline);
printf("Enter the status of the task /(todo, doing, done)/: ");
scanf("%s",newTask.status);
 task[nbTask]=newTask;
 newTask++
printf("Task added successfully :D");
}

//for showing the status
void diplayTasks(){
    printf("Liste des taches :\n");
    printf("ID\tTitre\tDescription\tDeadline\tStatut\n");
    for (int i = 0; i < nbTask; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n", liste[i].id, liste[i].title, liste[i].description, liste[i].deadline, liste[i].status);
    }
}

//for diplaying the menu 
int main(){
int choice;
printf("^^^^^^^^^^^^^ WELCOME 'TODO LIST' ^^^^^^^^^^^^^\n");
printf("*** THE MENU ***\n");
printf("1. Add a New Task \n");
printf("2. Modify a Task\n");
printf("3. Delete a Task ");
printf("4. Display the tasks");
printf("5. EXIT");
scanf("%d", &choice);

switch (choice)
{
case "1":
  addTask();
    break;
case"4":
  diplayTasks();
    break;
case "5":
   printf("BYE BYE!");
    break;
default:
 printf("Invalid choice, Try Again");
    break;
}
}



