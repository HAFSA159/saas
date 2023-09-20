#include<stdio.h>
#include<stdlib.h>

struct TODO
{
    int id , deadline;
    char titel[20] , desc[200] , status[50];
};

struct TODO liste[90];
int nbTask = 0;
int globalId = 0;

// for task adding
void addTask(int n){
    liste[nbTask].id = globalId;

printf("\nEnter a titel : ");
scanf("%s",liste[nbTask].titel);
printf("\nEnter a description : ");
scanf("%s",liste[nbTask].desc);
printf("\nEnter a deadline for the task : ");
scanf("%d",&liste[nbTask].deadline);
printf("\nEnter the status of the task /(todo, doing, done)/: ");
scanf("%s",liste[nbTask].status);
printf("\nTask added successfully :D \n");

    nbTask++;
    globalId++;
}

//for showing the status
void diplayTasks(int n){
    printf("Liste des taches :\n");
    printf("ID\tTITRE\tDESCRIPTION\tDEADLINE\tSTATUT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\n",liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status);
    }
}

//to exit
void exitProgram() {
    printf("BYE BYE!\n");
    exit(0);
}

//for diplaying the menu
int main(){
int choice , n;

while(1){
printf("^^^^^^^^^^^^^ WELCOME 'TODO LIST' ^^^^^^^^^^^^^\n");
printf("*** THE MENU ***\n");
printf("1. Add a New Task \n");
printf("2. Modify a Task\n");
printf("3. Delete a Task \n");
printf("4. Display the tasks\n");
printf("5. EXIT\n");
scanf("%d", &choice);

switch (choice)
{
case 1:
printf("How many tasks you want to enter ?");
scanf("%d",&n);
int i=0;
while(i<n) {
  addTask(n);
  i++;
}
    break;
case 4:
  diplayTasks(n);
    break;
case 5:
   exitProgram();
    break;
default:
 printf("Invalid choice, Try Again\n");
    break;
}
}
}

