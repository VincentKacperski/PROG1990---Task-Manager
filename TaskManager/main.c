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
void printAllTasks(struct Node** head) {
	
	//Calculations
	struct Node* temp = *head;

	while (temp != NULL) {

		//Print all task information
		printf("Title: %s", temp->title);
		printf("Task ID: %s", temp->task);
		printf("Task Data: %d", temp->data);

		//Go to the next task
		temp = temp->next;

	}

}

//Print all tasks in the manager
void searchTask(struct Node** head, int dataID) {

	//Calculations
	struct Node* temp = *head;

	while (temp != NULL) {

		//Verifiy the correct ID
		if (dataID = temp->task) {
			printf("Title: %s", temp->title);
			printf("Task ID: %s", temp->task);
			printf("Task Data: %d", temp->data);
			break; //Exit the loop
		}

		//Go to the next task
		temp = temp->next;

	}
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
	printf("2: Search for a task.\n");
	printf("3: Add a task to the beginning.\n");
	printf("4: Add a task to the end.\n");
	printf("5: Add a task at a point.\n");
	printf("6: Delete a task at the beginning.\n");
	printf("7: Delete a task at the end.\n");
	printf("8: Delete a task at a point.\n");
	printf("9: Exit.\n");
	printf("=--------------------------------=\n");
	printf("\n");

}

//Main function
int main() {

	//Decleration
	int choice = 1;
	int dataID = 0;
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));

	if (head == NULL) {

		//Error Message
		printf("\n");
		printf("Warning: \n");
		printf("\n");

	}

	//User input
	while (choice >= 1 && choice <= 7) {

		//Display menu
		displayMenu();

		//User input
		printf("Choose an option from 1-7: ");
		scanf_s("%d", &choice);

		//Menu and function calls
		switch (choice) {

		case 1:

			//Search for the desired task
			printAllTasks(&head);

			break;
		case 2:

			//Search for the desired task
			searchTask(&head, dataID);

			//Error Message
			printf("\n");
			printf("Error: Invalid input!\n");
			printf("\n");

			break;
		case 3:

			addToBeginning();

			break;
		case 4:

			addToEnd();

			break;
		case 5:

			addAtPoint();

			break;
		case 6:

			deleteAtBeginning();

			break;
		case 7:

			deleteAtEnd();

			break;
		case 8:

			deleteAtPoint();

			break;
		case 9:

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