#pragma once
void printAllTasks(struct Node** head);
void searchTask(struct Node** head, int dataID);
void addToEnd(struct Node** head, char* title, char* task, int data);
void addToBeginning(struct Node** head, char* title, char* task, int data);
void addAtPoint();
void deleteAtBeginning(struct Node** head);
void deleteAtEnd();
void deleteAtPoint();
void fileSave(struct Node** head);
void fileLoad(struct Node** head);
char* getString();