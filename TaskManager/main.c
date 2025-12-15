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
		printf("Title: %s\n", temp->title);
		printf("Task ID: %s\n", temp->task);
		printf("Task Data: %d\n", temp->data);

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
		if (dataID == temp->task) {
			printf("Title: %s\n", temp->title);
			printf("Task ID: %s\n", temp->task);
			printf("Task Data: %d\n", temp->data);
		}
	}
}

//Updates information about a task
void updateTask(struct Node** head, int dataID) {

	//Delaration
	struct Node* temp = *head;
	int choice;
	char* newtask;
	char* newtitle;
	int newdata;

	while (temp != NULL) {

		//Verifiy the correct ID
		if (dataID == temp->data) {

			//Ask the user for a new title
			printf("Would you like to change the task name?\n");
			printf("Enter 1 for yes 0 for no: ");
			scanf_s("%d", &choice);
			if (choice == 1) {
				printf("Enter a new title: ");
				scanf_s("%s", &newtask);
				temp->task = newtask;
			}

			//Ask the user for a new name
			printf("Would you like to change the task tile?\n");
			printf("Enter 1 for yes 0 for no: ");
			scanf_s("%d", &choice);
			if (choice == 1) {
				printf("Enter a new name: ");
				scanf_s("%s", &newtitle);
				temp->title = newtitle;
			}

			//Ask the user for a new title
			printf("Would you like to change any data?\n");
			printf("Enter 1 for yes 0 for no: ");
			scanf_s("%d", &choice);
			if (choice == 1) {
				printf("Enter new data: ");
				scanf_s("%d", &newdata);
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
	if (*head == NULL) {
		*head = newNode;
		return;
	}

	// loop until the next value is the end of the list
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

void deleteAtBeginning(struct Node** head) {
	// check if list is already empty
	if (*head == NULL) {
		return;
	}
	// make a temp variable, then move the head down one
	struct Node* temp = *head;
	*head = temp->next;
	// free the temp variable
	free(temp);
}
//Add a task within the list
void addAtPoint(struct Node** head, char* title, char* task, int data, int position) {


	// create newNode that will go before head
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	// insert all inputed info into newNode
	newNode->title = title;
	newNode->task = task;
	newNode->data = data;

	if (position == 1) {

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
	}

	//Creates 
	newNode->next = temp->next;
	temp->next = newNode;

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
void deleteAtPoint(struct Node** head, int position) {

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

	//Checks if there is another node after deleted one
	if (temp == NULL || temp->next == NULL) return;

	//Creates pointer after desired deleted Node
	struct Node* next = temp->next->next;

	//deletes node
	free(temp->next);
	//temp now points to next node
	temp->next = next;
}

//Saves list to file
void fileSave(struct Node** head) {
	
	// create the file pointer 
	FILE* fp = NULL;
	// make the error check variable
	errno_t error;
	// open the file in write mode well catching any errors
	error = fopen_s(&fp, "save.txt", "w");
	// check if any errors got catched or the pointer is NULL
	if (error != 0 || fp == NULL) {
		printf("File does not exist");
		return;
	}
	// loop through the list and add the information to the file
	struct Node* temp = *head;
	while (temp != NULL) {
		fprintf(fp, "%s\n", temp->title);
		fprintf(fp, "%s\n", temp->task);
		fprintf(fp, "%d\n", temp->data);
		temp = temp->next;
	}
	// close the file
	fclose(fp);
}


//ONLY FOR START OF PROGRAM
//Loads list from file
void fileLoad(struct Node** head) {

	// create the file pointer
	FILE* fp = NULL;
	// make the error check variable
	errno_t error;
	// variables for retreving info from file
	int c;
	int i = 0;
	int size = 0;
	int maxSize = 10;
	char* string;

	// open the file in read mode well catching any errors
	error = fopen_s(&fp, "save.txt", "r");
	// check if any erros got catched or the pointer is NULL
	if (error != 0 || fp == NULL) {
		printf("There is an error in opening file");
	}
	// create a new node to get the info from the file
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	// loop through file to collect all information and put into list
	while (1 == 1) {
		i++;
		string = NULL;
		size = 0;
		maxSize = 10;
		string = (char*)malloc(maxSize * sizeof(char));
		while ((c = getc(fp)) != '\n' && c != EOF) {
			
			string[size++] = (char)c;

			if (size >= maxSize - 1) {
				maxSize += 4;
				char* temp = (char*)realloc(string, maxSize * sizeof(char));
				string = temp;
			}

		}
		char* temp = realloc(string, sizeof(char) * (size + 1));
		string = temp;
		string[size] = '\0';
		switch (i) {
		case 1:
			newNode->title = string;
			break;
		case 2:
			newNode->task = string;
			break;
		case 3:
			newNode->data = atoi(string);
			break;
		default:
			i = 0;
			addToEnd(head, newNode->title, newNode->task, newNode->data);
			if (c == EOF) {
				free(newNode);
				fclose(fp);
				return;
			}
		}
		
	}
	// free the node and close the file
	free(newNode);
	fclose(fp);
}

void getString(char** finalString) {

	// defining variables
	int size = 0;
	int maxSize = 10;
	char* string = NULL;
	int c;

	// allocate string some memory
	string = (char*)malloc(maxSize * sizeof(char));

	// bug fix
	if ((c = getchar()) != '\n') {
		string[size++] = (char)c;
	}
	
	// as characters get inputed, allocate memory untill the user does next line (enter)
	while ((c = getchar()) != '\n' && c != EOF) {

		string[size++] = (char)c;

		if (size >= maxSize - 1) {
			maxSize += 4;
			char* temp = (char*)realloc(string, maxSize * sizeof(char));
			string = temp;
		}

	}
	//fix memory amount
	char* temp = realloc(string, sizeof(char) * (size + 1));
	string = temp;
	string[size] = '\0';

	// set final string to the string that was gotten from the function so it can be sent out of the function
	*finalString = string;

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
	printf("9: Save all data\n");
	printf("10: Exit.\n");
	printf("=--------------------------------=\n");
	printf("\n");

}

//Main function
int main() {

	//Decleration
	int choice = 1;
	int dataID = 0;
	int loadData, position;
	struct Node* head = NULL;
	
	char* title = NULL;
	char* task = NULL;
	int data;

	if (head == NULL) {

		//Error Message
		printf("\n");
		printf("Warning: \n");
		printf("\n");

	}

	printf("Would you like to load your previous data?: ");
	printf("Enter 1 (yes) or 2 (no): ");
	scanf_s("%d", &loadData);
	
	switch (loadData) {

	case 1:
		printf("Loading all Data from file.\n");
		fileLoad(&head);
		break;

	default:
		break;
	}

	
	
	//User input
	while (choice >= 1 && choice <= 10) {

		//Display menu
		displayMenu();

		//User input
		printf("Choose an option from 1-10: ");
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
			
			printf("Input the title to your task: ");
			getString(&title);
			printf("Input your task: ");
			getString(&task);
			printf("Input extra data (number): ");
			scanf_s("%d", &data);
			addToBeginning(&head, title, task, data);

			break;
		case 4:

			printf("Input the title to your task: ");
			getString(&title);
			printf("Input your task: ");
			getString(&task);
			printf("Input extra data (number): ");
			scanf_s("%d", &data);
			addToEnd(&head, title, task, data);

			break;
		case 5:

			//Add a task within the manager
			addAtPoint(&head, "title", "task", 1, position);

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
			deleteAtPoint(&head, &position);

			break;

		case 9:
			fileSave(&head);

			break;
		case 10:

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