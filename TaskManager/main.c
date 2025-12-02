#include <stdio.h>
#include <stdlib.h>
#include "main.h"

struct Node {
	char* title;
	char* task;
	int data;
	struct Node* next;
};

//Print all tasks in the manager
void printAllTasks() {
	//Calculations

}

//Add a task to the end of the list
void addToEnd() {
	//Calculations

}

//Add a task to the beginning of the list
void addToBeginning() {
	//Calculations

}

//Add a task within the list
void addAtPoint() {
	//Calculations

}

//Add a task at the beginning
void deleteAtBeginning() {
	//Calculations

}

//Delete a task at the end
void deleteAtEnd() {
	//Calculations

}

//Delete a task within the list
void deleteAtPoint() {
	//Calculations

}

void displayMenu() {

	//Display menu
	printf("\n");
	printf("=--------------------------------=\n");
	printf("1: Print all tasks.\n");
	printf("3: Add a task to the beginning.\n");
	printf("2: Add a task to the end.\n");
	printf("4: Add a task at a point.\n");
	printf("5: Delete a task at the beginning.\n");
	printf("6: Delete a task at the end.\n");
	printf("7: Delete a task at a point.\n");
	printf("8: Exit.\n");
	printf("=--------------------------------=\n");
	printf("\n");

}

//Main function
int main() {

	//Decleration
	struct Node* head = NULL;
	int choice = 1;

	//User input
	while (choice >= 1 && choice <= 7) {

		//Display menu
		displayMenu();

		printf("Choose an option from 1-7: ");
		scanf_s("%d", &choice);

		//Menu and function calls
		switch (choice) {

		case 1:
			printAllTasks();
			break;
		case 2:
			addToBeginning();
			break;
		case 3:
			addToEnd();
			break;
		case 4:
			addAtPoint();
			break;
		case 5:
			deleteAtBeginning();
			break;
		case 6:
			deleteAtEnd();
			break;
		case 7:
			deleteAtPoint();
			break;
		case 8:
			exit(0); //exit the program
			break;

		default:
			//Display error message
			printf("\n");
			printf("Error: Invalid input!\n");
			printf("\n");
			choice = 1; //Reset choice
			break;

		}
	}

	return 0;
}