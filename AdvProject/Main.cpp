#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char passport[20];
	char name[20];
	char surname[20];
	int yearBorn;
	char email[30];
	int area;
	int travelClass;
	int numOfTrips;
	int duration;
	struct node* NEXT;
};


void addToStart(struct node** top);
void addPassenger(struct node* top);
void addElementAtPos(struct node* top, int position);
void deleteElementAtEnd(struct node* top);
void deleteElementAtStart(struct node** top);
void deleteElementAtPos(struct node* top, int position);
void displayFull(struct node* top);
void displayList(struct node* top);
int searchList(struct node* top, char search[]);
int length(struct node* top);
void displayListToFile(struct node* top);

void main()
{
	struct node* headPtr = NULL;
	int choice;
	int temp;
	int pos;
	char search[20];

	printf("1) Add passenger (Note: Passport Number must be unique)\n");
	printf("2) Display all passenger to screen\n");
	printf("3) Display passenger Details\n");
	printf("4) Update a passenger statistic\n");
	printf("5) Delete passenger\n");
	printf("6) Generate statistics (a to i) based on the user selecting one of the criteria listed in I - II\n");
	printf("7) Print all passenger details into a report file\n");
	printf("8) List all the passenger of the following the UK in order of year born\n");
	printf("Please enter -1 to exit\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		switch (choice)
		{
		case 1:
			if (headPtr == NULL)
			{
				addToStart(&headPtr);
			}
			else
			{
				addPassenger(headPtr);
			}
			break;
		case 2:
			displayList(headPtr);
			break;
		case 3:
			displayFull(headPtr);
		case 4:
			printf("Deleting from the end of the list\n");
			if (headPtr->NEXT != NULL)
			{
				deleteElementAtEnd(headPtr);
			}
			else
			{
				deleteElementAtStart(&headPtr);
			}
			break;
		case 5:
			printf("Displaying the length of the list\n");
			break;
		case 6:
			printf("A. percent of players who travel from the UK\n");
			printf("B. percent of players who travel from the Rest of Europe\n");

			break;
		case 7:
			if (headPtr != NULL)
			{
				deleteElementAtStart(&headPtr);
			}
			break;
		case 8:
			if (headPtr == NULL)
			{
				printf("Sorry the list is empty");
			}

			else
			{
				printf("Please the position you wish to add the node at\n");
				scanf("%d", &pos);

				if (pos < 2)
				{
					deleteElementAtStart(&headPtr);
				}
				else if (pos >= 2 && pos < length(headPtr))
				{
					deleteElementAtPos(headPtr, pos);
				}
				else
				{
					deleteElementAtEnd(headPtr);
				}
			}
			break;
		case 9:
			printf("Please the position you wish to add the node at\n");
			scanf("%d", &pos);

			if (pos < 2)
			{
				addToStart(&headPtr);
			}
			else if (pos > length(headPtr))
			{
				addPassenger(headPtr);
			}
			else
			{
				addElementAtPos(headPtr, pos);
			}
			break;
		default:
			printf("Invalid option\n");
		}

		printf("1) Add passenger (Note: Passport Number must be unique)\n");
		printf("2) Display all passenger to screen\n");
		printf("3) Display passenger Details\n");
		printf("4) Update a passenger statistic\n");
		printf("5) Delete passenger\n");
		printf("6) Generate statistics (a to i) based on the user selecting one of the criteria listed in I - II\n");
		printf("7) Print all passenger details into a report file\n");
		printf("8) List all the passenger of the following the UK in order of year born\n");
		printf("Please enter -1 to exit\n");
		scanf("%d", &choice);
	}


}

// This method is run first to add passenger at the start of the list
void addToStart(struct node** top)
{
	char passport[20];
	int result;
	struct node* newNode;

	printf("Please enter your passport number\n");
	scanf("%s", passport);

	// Checking to see if passport number is already being used
	result = searchList(*top, passport);
	if (result != -1)
	{
		printf("Passport number is already in database\n");
		return;
	}

	newNode = (struct node*)malloc(sizeof(struct node) * 1);

	printf("Please enter the your name\n");
	scanf("%s", newNode->name);

	printf("Please enter the your surname\n");
	scanf("%s", newNode->surname);

	printf("Please enter the year the you were born\n");
	scanf("%d", &newNode->yearBorn);

	// String copy for passport number
	strcpy(newNode->passport, passport);

	printf("Please enter your email\n");
	scanf("%s", newNode->email);

	printf("Which of the following areas did you travel from\n");
	printf("1. UK \n2. Rest of Europe \n3. Asia \n4. Americas \n5. Australasia\n");
	scanf("%d", &newNode->area);

	printf("What travel class did you use to travel to Ireland?\n");
	printf("1. Economy \n2. Premium Economy \n3. Business Class \n4.First Class\n");
	scanf("%d", &newNode->travelClass);

	printf("How many trips to Ireland do you make per year?\n");
	printf("1. Less than three times per year \n2. Less than five times per year \n3. More than fives per year\n");
	scanf("%d", &newNode->numOfTrips);

	printf("On average how long is your duration?\n");
	printf("1. One day \n2. Less than 3 days \n3. Less than 7 day \n4. More than 7 day\n");
	scanf("%d", &newNode->duration);

	newNode->NEXT = *top;
	*top = newNode;

	printf("\n");
}

// Adding passengers to the end of the list
void addPassenger(struct node* top)
{
	struct node* curr;
	struct node* newNode;
	char passport[20];
	int result;

	printf("Please enter your passport number\n");
	scanf("%s", passport);

	// Checking to see if passport number is already being used
	result = searchList(top, passport);
	if (result != -1)
	{
		printf("Passport number is already in database\n");
		return;
	}

	newNode = (struct node*)malloc(sizeof(struct node) * 1);

	printf("Please enter the your name\n");
	scanf("%s", newNode->name);

	printf("Please enter the your surname\n");
	scanf("%s", newNode->surname);

	printf("Please enter the year the you were born\n");
	scanf("%d", &newNode->yearBorn);

	// String copy for passport number
	strcpy(newNode->passport, passport);

	printf("Please enter your email\n");
	scanf("%s", newNode->email);

	printf("Which of the following areas did you travel from\n");
	printf("1. UK \n2. Rest of Europe \n3. Asia \n4. Americas \n5. Australasia\n");
	scanf("%d", &newNode->area);

	printf("What travel class did you use to travel to Ireland?\n");
	printf("1. Economy \n2. Premium Economy \n3. Business Class \n4. First Class\n");
	scanf("%d", &newNode->travelClass);

	printf("How many trips to Ireland do you make per year?\n");
	printf("1. Less than three times per year \n2. Less than five times per year \n3. More than fives per year\n");
	scanf("%d", &newNode->numOfTrips);

	printf("On average how long is your duration?\n");
	printf("1. One day \n2. Less than 3 days \n3. Less than 7 day \n4. More than 7 day\n");
	scanf("%d", &newNode->duration);

	curr = top;
	while (curr->NEXT != NULL)
	{
		curr = curr->NEXT;
	}

	curr->NEXT = newNode;
	newNode->NEXT = NULL;

}

// Displaying just all passenger names to the list
void displayList(struct node* top) {
	struct node* curr;
	curr = top;

	while (curr != NULL)
	{
		printf("Passenger: %s %s Number: %s\n\n", curr->name, curr->surname, curr->passport);
		curr = curr->NEXT;
	} // End of while

	printf("\n");
}

// Displaying all passenger details to the screen
void displayFull(struct node* top)
{
	struct node* curr;
	curr = top;

	while (curr != NULL)
	{
		printf("Passport Number: %s\n", curr->passport);
		printf("Full name: %s %s\n", curr->name, curr->surname);
		printf("Year born: %d\n", curr->yearBorn);
		printf("Email address: %s\n", curr->email);
		// Switch statement areas travelling from
		printf("Traveling from: ");
		switch (curr->area)
		{
		case 1:
			printf("UK\n");
			break;
		case 2:
			printf("Rest of Europe\n");
			break;
		case 3:
			printf("Asia\n");
			break;
		case 4:
			printf("Americas\n");
			break;
		case 5:
			printf("Australasia\n");
			break;
		default:
			printf("Unknown. Wrong information was entered\n");
			break;
		} // End of Switch
		
		// Switch statement travel classes
		printf("Travel class: ");
		switch (curr->travelClass)
		{
		case 1:
			printf("Economy\n");
			break;
		case 2:
			printf("Premium Economy\n");
			break;
		case 3:
			printf("Business Class\n");
			break;
		case 4:
			printf("First Class\n");
			break;
		default:
			printf("Unknown. Wrong information was entered\n");
			break;
		} // End of switch

		// Switch statement for trips per year
		printf("Trips to Ireland per year: ");
		switch (curr->numOfTrips)
		{
		case 1:
			printf("Less than three times per year\n");
			break;
		case 2:
			printf("Less than five times per year\n");
			break;
		case 3:
			printf("More than five times per year\n");
			break;
		default:
			printf("Unknown. Wrong information was entered\n");
			break;
		} // End of switch

		// Switch statement for duration
		printf("Average length of duration: ");
		switch (curr->duration)
		{
		case 1:
			printf("One day\n");
			break;
		case 2:
			printf("Less than 3 days\n");
			break;
		case 3:
			printf("Less than 7 days\n");
			break;
		case 4:
			printf("More than 7 days\n");
			break;
		default:
			printf("Unknown. Wrong information was entered\n");
			break;
		} // End of switch
		
		curr = curr->NEXT;
		printf("\n");
	} // End of while

	printf("\n");
}


void displayListToFile(struct node* top)
{
	struct node* curr;
	FILE* temp;

	curr = top;
	temp = fopen("Output.txt", "w");

	if (temp != NULL)
	{
		while (curr != NULL)
		{
			fprintf(temp, "The name is %s\n", curr->name);

			curr = curr->NEXT;

		}

		fclose(temp);
	}

}

void deleteElementAtEnd(struct node* top)
{
	struct node* curr;
	struct node* prev_curr;

	curr = top;

	while (curr->NEXT != NULL)
	{
		prev_curr = curr;
		curr = curr->NEXT;
	}



	prev_curr->NEXT = NULL;
	free(curr);
}

int searchList(struct node* top, char search[])
{

	struct node* curr;
	int index = 0;

	curr = top;

	while (curr != NULL)
	{
		index++;
		if (strcmp(curr->passport, search) == 0)
		{
			return index;
		}
		curr = curr->NEXT;

	}

	return -1;
}

int length(struct node* top)
{
	struct node* curr;
	int len = 0;
	curr = top;

	while (curr != NULL)
	{
		len++;
		curr = curr->NEXT;
	}

	return len;
}

void addElementAtPos(struct node* top, int position)
{
	int i;
	struct node* temp;
	struct node* newNode;
	char ID[20];
	int result;


	printf("Please enter the student ID\n");
	scanf("%s", ID);

	result = searchList(top, ID);

	if (result != -1)
	{
		printf("Not a unique ID\n");
		return;
	}


	newNode = (struct node*)malloc(sizeof(struct node) * 1);

	printf("Please enter the students name\n");
	scanf("%s", newNode->name);


	temp = top;

	for (i = 0; i < position - 2; i++)
	{
		temp = temp->NEXT;
	}

	newNode->NEXT = temp->NEXT;
	temp->NEXT = newNode;

}

void deleteElementAtStart(struct node** top)
{
	struct node* temp;

	temp = *top;

	*top = temp->NEXT;

	free(temp);
}

void deleteElementAtPos(struct node* top, int position)
{
	struct node* temp;
	struct node* prev;
	int i;

	temp = top;

	for (i = 0; i < position - 1; i++)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	prev->NEXT = temp->NEXT;
	free(temp);
}
