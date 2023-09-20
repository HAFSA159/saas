#include<stdio.h>
#include<stdlib.h>

struct TODO
{
    int id , deadline;
    char titel[20] , desc[200] , status[50];
};

struct TODO liste[90];
int nbTask = 0;

// for task adding
void addTask(int n){
    struct TODO newTask[n] ;
    newTask->id = nbTask + 1;
for(int i=0;i<n;i++){

printf("\nEnter a titel : ");
scanf("%s",newTask[i].titel);
printf("\nEnter a description : ");
scanf("%s",newTask[i].desc);
printf("\nEnter a deadline for the task : ");
scanf("%d",&newTask[i].deadline);
printf("\nEnter the status of the task /(todo, doing, done)/: ");
scanf("%s",newTask[i].status);
printf("\nTask added successfully :D \n");
}
}

//for showing the status
void diplayTasks(int n){
    struct TODO liste[n];
    printf("Liste des taches :\n");
    printf("ID\tTitre\tDescription\tDeadline\tStatut\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t\t%d\t\t%s\n", liste[i].id, liste[i].titel, liste[i].desc, liste[i].deadline, liste[i].status);
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
  addTask(n);
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

