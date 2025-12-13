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

	// if the list is empty the make the new node the very first node
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
	
	// create newNode that will go before head
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

//Add a task within the list
void addAtPoint(struct Node** head, char* title, char* task, int data, int position) {


	// create newNode that will go before head
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;

	if (position == 1) {

		// insert all inputed info into newNode
		newNode->title = title;
		newNode->task = task;
		newNode->data = data;

		// make the newNode go before head
		newNode->next = *head;

		// set head back to the start by making it equal to new node
		*head = newNode;
		return;
	}

	//transverses through linked list until reaching user's desired position
	struct Node* temp = *head;
	for (int x = 0; temp != NULL && x < position - 1; x++)
		temp = temp->next;

	//If memory does not exist it returns 
	if (temp == NULL) {
		printf("Position out of bounds\n");
		free(newNode);
		return;

	//Gives data to node
	newNode->title = title;
	newNode->task = task;
	newNode->data = data;

	//Creates 
	newNode->next = temp->next;
	temp.next = newNode;

	}

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
void deleteAtPoint(struct Node** head, int position) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	//If head = NULL, then there is no elements in list
	if (*head == NULL) return;

	//Using "temp" to free memory
	struct Node* temp = *head;
	if (position == 1) {
		*head = temp->next;
		free(temp);
	}

	// Loop to transverse throught linked list 
	for (int x = 0; temp->next != NULL && x < position - 1; x++) {
		temp = temp->next;
	}

	//returns if temp is NULL
	if (temp == NULL || temp->next == NULL) return;

	//Creates pointer after desired deleted Node
	struct Node* next = temp->next->next;

	//deletes node
	free(temp->next);

	//temp now points to next node
	temp->next = next;
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

			addAtPoint(&head, &title, &task, &data, &position);

			break;
		case 6:

			deleteAtBeginning();

			break;
		case 7:

			deleteAtEnd();

			break;
		case 8:

			deleteAtPoint(&head, &position);

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