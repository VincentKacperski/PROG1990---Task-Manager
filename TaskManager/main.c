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
		}
	}
}

//Updates information about a task
void updateTask(struct Node** head, int dataID) {

	//Delaration
	struct Node* temp = *head;
	int choice = 0;
	char* newtask = 0;
	char* newtitle = 0;
	int newdata = 0;

	while (temp != NULL) {

		//Verifiy the correct ID
		if (dataID = temp->task) {

			//Ask the user for a new title
			printf("Would you like to change the task name?\n");
			printf("Enter 1 for yes 0 for no: \n");
			scanf_s("%d", choice);
			if (choice == 1) {
				printf("Enter a new title: ");
				scanf_s("%s", newtask);
				temp->task = newtask;
			}

			//Ask the user for a new name
			printf("Would you like to change the task tile?\n");
			printf("Enter 1 for yes 0 for no: \n");
			scanf_s("%d", choice);
			if (choice == 1) {
				printf("Enter a new name: ");
				scanf_s("%s", newtitle);
				temp->title = newtitle;
			}

			//Ask the user for a new title
			printf("Would you like to change any data?\n");
			printf("Enter 1 for yes 0 for no: \n");
			scanf_s("%d", choice);
			if (choice == 1) {
				printf("Enter new data: ");
				scanf_s("%d", newdata);
				temp->data = newdata;
			}
			break;
		}

		//Traverse the list
		temp = temp->next;
	}
}

//Add a task to the end of the list
void addToEnd(struct Node** head, char* title, char* task, int data) {
	
	//create newNode that will go at the end of the list
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	// insert all inputed info into newNode
	newNode->title = title;
	newNode->task = task;
	newNode->data = data;
	// set the newNode to have nothing after it because it will be the last node in the list
	newNode->next = NULL;

	// if the list is empty then make the new node the very first node
	if (*head = NULL) {
		*head = newNode;
		return;
	}

	// loop untill the next value is the end of the list
	struct Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// make the end of the list the newNode
	temp->next = newNode;

}

//Add a task to the beginning of the list
void addToBeginning(struct Node** head, char* title, char* task, int data) {
	
	//Create newNode that will go before head
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	// insert all inputed info into newNode
	newNode->title = title;
	newNode->task = task;
	newNode->data = data;
	// make the newNode go before head
	newNode->next = *head;

	// set head back to the start by making it equal to new node
	*head = newNode;
}

//Add a task at the beginning
void deleteAtBeginning(struct Node* head) {

	//Declaration
	struct Node* searchNode = (struct Node*)malloc(sizeof(struct Node));
	searchNode = head; //Capture the head address
	head = head->next; //Assign the address of head to the next node
	free(searchNode); //Free the previous node that was the head
	searchNode = NULL; //Eliminate dangeling pointers

}

//Delete a task at the end
void deleteAtEnd(struct Node** head) {

	//Declaration
	struct Node* temp = *head;

	while (temp != NULL) {

		//Free the last node
		if (temp->next = NULL) {
			free(temp);
			temp = NULL;
		}

		//Traverse the list to the end
		temp = temp->next;

	}
}

//Delete a task within the list
void deleteAtPoint() {
	//Calculations

}

//Add a task within the list
void addAtPoint() {
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

			break;
		case 3:

			//Adds a task to the beginning of the mamanger
			addToBeginning();

			break;
		case 4:

			//Add a task to the end of the manager
			addToEnd();

			break;
		case 5:

			//Add a task within the manager
			addAtPoint();

			break;
		case 6:

			//Delete a task at the beginning of the manager
			deleteAtBeginning(&head);

			break;
		case 7:

			//Delete a task at the beginning of the manager
			deleteAtEnd(&head);

			break;
		case 8:

			//Delete a task within the manager
			deleteAtPoint();

			break;
		case 9:

			//Exit the program
			exit(0);

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