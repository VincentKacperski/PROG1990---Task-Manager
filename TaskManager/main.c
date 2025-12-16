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

	//Errpr handleing
	if (temp == NULL) {

		printf("\n");
		printf("No manager has been created.\n");
		printf("Add at the end or beginning\n");
		printf("to create a new list.\n");
		printf("\n");
		return;

	}

	while (temp != NULL) {

		//Print all task information
		printf("Title: %s\n", temp->title);
		printf("Task: %s\n", temp->task);
		printf("Data: %d\n", temp->data);
		printf("\n");

		//Go to the next task
		temp = temp->next;

	}

}

//Print a range of manager tasks
void printRange(struct Node** head, int begin, int end) {

	//Calculations
	struct Node* temp = *head;
	begin--;
	end--;


	//Errpr handleing
	if (temp == NULL) {

		printf("\n");
		printf("No manager has been created.\n");
		printf("Add at the end or beginning\n");
		printf("to create a new list.\n");
		printf("\n");
		return;

	}
	// move the temp to the correct point in the list
	for (int i = 0; i < begin && temp != NULL; i++) {
		temp = temp->next;
	}
	// if that point does not exist, tell user and return
	if (temp == NULL) {
		printf("Your list is not large enough to print this range.\n");
		return;
	}
	// loop through and print all tasks between the range
	for (int i = begin; i <= end && temp != NULL; i++) {

		//Print all task information
		printf("\n");
		printf("Title: %s\n", temp->title);
		printf("Task: %s\n", temp->task);
		printf("Data: %d\n", temp->data);
		printf("\n");

		//Go to the next task
		temp = temp->next;

	}
	// if the range is larger then the size of the list, tell the user
	if (temp == NULL) {
		printf("\n");
		printf("The list does not have that many tasks in it so it printed until the end!\n");
		printf("\n");
	}
}

//Print all tasks in the manager
void searchTask(struct Node** head, int position) {

	//Declaration
	struct Node* temp = *head;
	int nodeCount = 1;

	//Error handleing
	if (temp == NULL) {

		printf("\n");
		printf("No manager has been created.\n");
		printf("Add at the end or beginning\n");
		printf("to create a new list.\n");
		printf("\n");
		return;

	}

	while (temp != NULL && nodeCount <= position) {

		//Verifiy the correct ID
		if (nodeCount == position) {
			printf("Title: %s\n", temp->title);
			printf("Task: %s\n", temp->task);
			printf("Data: %d\n", temp->data);
			return; //Exit the proccess
		}

		//Go to the next task
		temp = temp->next;
		nodeCount++;
	}

	printf("\n");
	printf("No such task has been found!\n");
	printf("\n");

}

//Updates information about a task
void updateTask(struct Node** head, int position) {

	//Delaration
	struct Node* temp = *head;
	int choice;
	int nodeCount = 1;
	char* newtask = NULL;
	char* newtitle = NULL;
	int newdata;

	//Error handleing
	if (temp == NULL) {

		printf("\n");
		printf("No manager has been created.\n");
		printf("Add at the end or beginning\n");
		printf("to create a new list.\n");
		printf("\n");
		return;

	}

	while (temp != NULL) {

		//Verifiy the correct ID
		if (nodeCount == position) {

			//Ask the user for a new title
			printf("Would you like to change the title?\n");
			printf("Enter 1 (yes) 0 (no): ");
			scanf_s("%d", &choice);
			if (choice == 1) {
				printf("Enter new title: ");
				getString(&newtitle);
				temp->title = newtitle;
			}

			//Ask the user for a new name
			printf("Would you like to change the task?\n");
			printf("Enter 1 (yes) 0 (no): ");
			scanf_s("%d", &choice);
			if (choice == 1) {
				printf("Enter new name: ");
				getString(&newtask);
				temp->task = newtask;
			}

			//Ask the user for a new title
			printf("Would you like to modify data?\n");
			printf("Enter 1 (yes) 0 (no): ");
			scanf_s("%d", &choice);
			if (choice == 1) {
				printf("Enter data: ");
				scanf_s("%d", &newdata);
				temp->data = newdata;
			}
			return;
		}

		//Traverse the list
		temp = temp->next;
		nodeCount++;

	}

	printf("\n");
	printf("No such task has been found!\n");
	printf("\n");

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

//Add a task within the list
void addAtPoint(struct Node** head, char* title, char* task, int data, int position) {


	// create newNode that will go before head
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	// insert all inputed info into newNode
	newNode->title = title;
	newNode->task = task;
	newNode->data = data;

	if (position == 1 ) {

		// make the newNode go before head
		newNode->next = *head;
		// set head back to the start by making it equal to new node
		*head = newNode;
		return;

	}

	//transverses through linked list until reaching user's desired position
	struct Node* temp = *head;
	for (int x = 1; temp != NULL && x < position - 1; x++)
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

void deleteAtBeginning(struct Node** head) {

	//Error handleing
	if (*head == NULL) {

		printf("\n");
		printf("Nothing to delete! Add\n");
		printf("at the end or beginning\n");
		printf("to create a new manager.\n");
		printf("\n");
		return;

	}

	// make a temp variable, then move the head down one
	struct Node* temp = *head;
	*head = temp->next;
	// free the temp variable
	free(temp);
}


//Delete a task at the end
void deleteAtEnd(struct Node** head) {

	//Error handleing
	if (*head == NULL) {

		printf("\n");
		printf("Nothing to delete! Add\n");
		printf("at the end or beginning\n");
		printf("to create a new manager.\n");
		printf("\n");
		return;

	}

	//Declaration
	struct Node* temp = *head;

	if (temp->next == NULL) {
		*head = temp->next;
		free(temp);
		return;
	}

	//If only one structure in list
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
	if (*head == NULL || position <= 0) {

		printf("\n");
		printf("Nothing to delete! Add\n");
		printf("at the end or beginning\n");
		printf("to create a new manager.\n");
		printf("\n");
		return;

	}

	//Using "temp" to free memory
	struct Node* temp = *head;
	if (position == 1) {
		*head = temp->next;
		free(temp);
		return;
	}

	// Loop to transverse throught linked list 
	for (int x = 1; temp->next != NULL && x < position - 1; x++) {
		temp = temp->next;
	}

	//Checks if there is another node after deleted one
	if (temp == NULL || temp->next == NULL) {
		return;
	}
	//Creates pointer after desired deleted Node
	struct Node* next = temp->next->next;

	//deletes node
	free(temp->next);
	//temp now points to next node
	temp->next = next;
}

//Saves list to file //Working
void fileSave(struct Node** head) {

	//If head = NULL, do not save any changes
	if (*head == NULL) {

		printf("\n");
		printf("Nothing to save! Create a new\n");
		printf("manager by adding at beginning\n");
		printf("or end to save any changes!\n");
		printf("\n");
		return;

	}
	
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
//Loads list from file //Working
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
		printf("Error: No such file created!\n");
		return;
	}
	// create a new node to get the info from the file
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	// loop through file to collect all information and put into list
	while (1 == 1) {

		// increase counter to know which variable the next line is for
		i++;
		// reseting varibles for next string
		string = NULL;
		size = 0;
		maxSize = 10;
		string = (char*)malloc(maxSize * sizeof(char));
		// loop through file until it reach the end of the line or the end of the file
		while ((c = getc(fp)) != '\n') {
			
			if (c == EOF) {
				// if the end of the file has been reached, free the node and close the file, then end the function
				free(newNode);
				fclose(fp);
				return;
			}

			string[size++] = (char)c;

			if (size >= maxSize - 1) {
				maxSize += 4;
				char* temp = (char*)realloc(string, maxSize * sizeof(char));
				string = temp;
			}

		}
		// remove extra memory that is being used
		char* temp = realloc(string, sizeof(char) * (size + 1));
		string = temp;
		string[size] = '\0';
		// check which varible the line
		switch (i) {
		case 1:
			newNode->title = string;
			break;
		case 2:
			newNode->task = string;
			break;
		case 3:
			newNode->data = atoi(string);
			free(string);
			// reset the counter and add the run the addToEnd() function to input the info to the list
			i = 0;
			addToEnd(head, newNode->title, newNode->task, newNode->data);
		}
		
	}
	// This point should not be reached but is here just in case
	// free the node and close the file
	free(newNode);
	fclose(fp);
}

//Get string function
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
		// add the character to the string
		string[size++] = (char)c;
		// if the string size is not big enough, allocate memory to the string
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
	printf("2: Print a range of tasks.\n");
	printf("3: Search for a task.\n");
	printf("4: Update a task in progress.\n");
	printf("5: Add a task to the beginning.\n");
	printf("6: Add a task to the end.\n");
	printf("7: Add a task at a point.\n");
	printf("8: Delete a task at the beginning.\n");
	printf("9: Delete a task at the end.\n");
	printf("10: Delete a task at a point.\n");
	printf("11: Save all data\n");
	printf("12: Exit.\n");
	printf("=--------------------------------=\n");
	printf("\n");

}

//Main function
int main() {

	//Decleration
	int result;
	int choice = 1;
	int position = -1;
	int rangeBegin = -1;
	int rangeEnd = -1;
	int loadValue = 0;
	struct Node* head = NULL;
	char* title = NULL;
	char* task = NULL;
	int data;

	/*if (head == NULL) {

		//Error Message
		printf("\n");
		printf("Warning: \n");
		printf("\n");
		
	}*/


	while (loadValue != 1 && loadValue != 2) {
		printf("Would you like to load your previous data?: ");
		printf("Enter 1 (yes) or 2 (no): ");


		//If loadValue equals 1 integer then break
		if (scanf_s("%d", &loadValue) == 1) {
			if (loadValue > 2 || loadValue <= 0) {
				printf("Invalid Input\n");
			}
		}
		else {
			printf("Invalid input\n");
			while (getchar() != '\n');
		}



		/*if (loadValue != 1) {
			while (getchar() != "\n");
			printf("Invalid Input, please input 1 or 2\n");
			loadValue = 0;

		}*/
	}


	if (loadValue == 1) {
		fileLoad(&head);
	}

	//Display menu
	displayMenu();

	//User input
	while (choice <= 12 && choice > 0) {
		printf("Choose an option from 1-12: ");

		//If loadValue equals 1 integer then break
		if (scanf_s("%d", &choice) == 1) {
			choice = (int)choice;

			//Print Invalid input if choice not between 1 - 12
			if (choice > 12 || choice <= 0) {
				printf("Invalid Input\n");

			}
		}
		//Get's rid of invalid Keyboard inputs
		else {
			printf("Invalid input\n");
			while (getchar() != '\n');
			continue;
		}
		
		// clear screen
		system("cls");

		//Display menu
		displayMenu();

		//Menu and function calls
		switch (choice) {

		case 1:

			//Search for the desired task
			printAllTasks(&head);

			break;
		case 2:

			//Search for the desired task
			// loop until user inputs good values
			while (rangeEnd - rangeBegin < 0 || rangeBegin <= 0 || rangeEnd <= 0) {


				//Error checking for input
				while (rangeBegin <= 0) {
					printf("What node would you like to start printing at?\n");
					printf("Range (integer): ");
					scanf_s("%d", &rangeBegin);
					printf("\n");
				}
				//Error checking for input
				while (rangeEnd <= 0) {
					printf("What node would you like to stop printing at?\n");
					printf("Range (integer): ");
					scanf_s("%d", &rangeEnd);
					printf("\n");
				}
				// reprint screen if loop is going to happen
				if (rangeEnd - rangeBegin < 0) {
					// clear screen
					system("cls");
					// Display menu
					displayMenu();
					// Tell user what was done wrong
					printf("The inputs must be beginning first, then end last.\n");
					
				}
			}
			// clear screen
			system("cls");
			//Display menu
			displayMenu();

			//Print the functions desired
			printRange(&head, rangeBegin, rangeEnd);
			//Reset range
			rangeBegin = -1; 
			rangeEnd = -1;

			break;
		case 3:

			//Search for the desired task

			//Error checking for input
			while (position <= 0) {
				printf("Which node would you like to see?\n");
				printf("Node number (integer): ");
				scanf_s("%d", &position);
				printf("\n");
			}

			//Search and print the desired node
			searchTask(&head, position);
			position = -1; //Reset position

			break;

		case 4:

			//Search for the desired task

			//Error checking for input
			while (position <= 0) {
				printf("which node would you like to modify?\n");
				printf("Node number: ");
				scanf_s("%d", &position);
				printf("\n");
			}

			//Update the desired task
			updateTask(&head, position);
			position = -1; //Reset position

			break;
		case 5:
			
			//Adds a task to the beginning of the mamanger

			//Enter data for the new mode
			printf("Input the title to your task: ");
			getString(&title);
			printf("Input your task: ");
			getString(&task);
			printf("Input extra data (number): ");
			scanf_s("%d", &data);
			//Function call
			addToBeginning(&head, title, task, data);

			break;
		case 6:

			//Adds a task to the end of the manager

			//Enter data for the new mode
			printf("Input the title to your task: ");
			getString(&title);
			printf("Input your task: ");
			getString(&task);
			printf("Input extra data (number): ");
			scanf_s("%d", &data);

			//Add the new node to the end of the list
			addToEnd(&head, title, task, data);

			break;
		case 7:

			//Adds a task to a point in the manager

			//Error checking for input
			position = -1;
			while (position <= 0) {
				printf("Where would you like to add a new node?\n");
				printf("Location (integer): ");
				scanf_s("%d", &position);
				printf("\n");
			}

			//Enter data for the new mode
			printf("Input the title to your task: ");
			getString(&title);
			printf("Input your task: ");
			getString(&task);
			printf("Input extra data (number): ");
			scanf_s("%d", &data);

			//Add a task within the manager
			addAtPoint(&head, title, task, 1, position);

			break;
		case 8:

			//Delete a task at the beginning of the manager
			deleteAtBeginning(&head);

			break;
		case 9:

			//Delete a task at the beginning of the manager
			deleteAtEnd(&head);

			break;
		case 10:

			//Error checking for input
			position = -1;
			while (position <= 0) {
				printf("Where would you like to delete a node?\n");
				printf("Location (integer): ");
				scanf_s("%d", &position);
				printf("\n");
			}

			//Delete a task within the manager
			deleteAtPoint(&head, position);

			break;

		case 11:

			//Save all data to the file
			fileSave(&head);
			printf("File Saved\n");

			break;
		case 12:

			//Exit the program
			exit(0);

			break;

		default:

			choice = 1; //Reset choice
			break;

		}
		printf("\n");
	}
	return 0;
}