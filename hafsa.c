#include<stdio.h>
#include<stdlib.h>

struct TODO
{
    int id
    char titel[20] , desc[200] , deadline[10], status[50]; 
};
struct TODO task[];
int nbTask = 0;
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



struct TODO todo;
printf("***WELCOME TO THE MENU***");
printf("1.");
printf("2.");
printf("3.");
printf("4.");



