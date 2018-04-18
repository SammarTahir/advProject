/*
$$\   $$\ $$\     $$\ $$$$$$$$\        $$$$$$\  $$\                                          $$\     
$$ |  $$ |\$$\   $$  |\____$$  |      $$  __$$\ \__|                                         $$ |    
\$$\ $$  | \$$\ $$  /     $$  /       $$ /  $$ |$$\  $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\ $$$$$$\   
 \$$$$  /   \$$$$  /     $$  /        $$$$$$$$ |$$ |$$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\\_$$  _|  
 $$  $$<     \$$  /     $$  /         $$  __$$ |$$ |$$ |  \__|$$ /  $$ |$$ /  $$ |$$ |  \__| $$ |    
$$  /\$$\     $$ |     $$  /          $$ |  $$ |$$ |$$ |      $$ |  $$ |$$ |  $$ |$$ |       $$ |$$\ 
$$ /  $$ |    $$ |    $$$$$$$$\       $$ |  $$ |$$ |$$ |      $$$$$$$  |\$$$$$$  |$$ |       \$$$$  |
\__|  \__|    \__|    \________|      \__|  \__|\__|\__|      $$  ____/  \______/ \__|        \____/ 
															    $$ |                                
															    $$ |                                
													 		    \__|                                 
																										*/

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
	struct node* PREV;
};


void addToStart(struct node** top, struct node** bottom);
void addPassenger(struct node** top, struct node** bottom);
void deleteElementAtEnd(struct node* top);
void deleteElementAtStart(struct node** top);
void deletePassenger(struct node* top, struct node* bottom, int position);
void displayFull(struct node* top);
void displayList(struct node* top);
int searchList(struct node* top, char search[]);
void updateDetails(struct node* top, char search[]);
int length(struct node* top);
void printToFile(struct node* top);
//void deletePassenger(struct node** top, char search[20]);
void genStats(struct node* top, char stat);

void main()
{
	struct node* headPtr = NULL;
	struct node* tailPtr = NULL;
	int choice;
	int temp;
	int pos;
	char search[20];
	char stat = ' ';
	
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

	while (choice != -1) {
		switch (choice) {
		case 1:
			if (headPtr == NULL) {
				addToStart(&headPtr, &tailPtr);
			}
			else {
				addPassenger(&headPtr, &tailPtr);
			}
			break;
		case 2:
			displayList(headPtr);
			break;
		case 3:
			displayFull(headPtr);
			break;
		case 4:
			printf("Please enter your passport number\n");
			scanf("%s", search);

			updateDetails(headPtr, search);
			break;
		case 5:
			printf("Please enter your passport number\n");
			scanf("%s", search);

		//	deletePassenger(headPtr, search);
			break;
		case 6:
			printf("A. percent of passenger who travel from the UK\n");
			printf("B. percent of passenger who travel from the Rest of Europe\n");
			printf("C. percent of passenger who travel from the Asia\n");
			printf("D. percent of passenger who travel from the Americas\n");
			printf("E. percent of passenger who travel from the Australasia\n");
			printf("F. percent of passenger who spent on average one day in Ireland\n");
			printf("G. percent of passenger who spent on average less than 3 days in Ireland\n");
			printf("H. percent of passenger who spent on average less than 7 days in Ireland\n");
			printf("I. percent of passenger who spent on average more than 7 days in Ireland\n");
			scanf("%s", &stat);
			genStats(headPtr, stat);
			break;
		case 7:
			printToFile(headPtr);
			break;
		case 8:
			
			break;
		default:
			printf("Invalid option\n");
			break;
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
void addToStart(struct node** top, struct node** bottom)
{
	char passport[20];
	int result;
	struct node* newNode;
	struct node* curr;

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

	if (*top == NULL) {
		*top = newNode;
		*bottom = newNode;
		newNode->NEXT = NULL;
		newNode->PREV = NULL;
	}
	else {
		newNode->PREV = NULL;
		newNode->NEXT = curr;
		curr->PREV = newNode;
		*top = newNode;
	}

	printf("\n");
}

// Adding passengers to the end of the list
void addPassenger(struct node** top, struct node** bottom)
{
	struct node* curr;
	struct node* newNode;
	char passport[20];
	int result;

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
	printf("1. Economy \n2. Premium Economy \n3. Business Class \n4. First Class\n");
	scanf("%d", &newNode->travelClass);

	printf("How many trips to Ireland do you make per year?\n");
	printf("1. Less than three times per year \n2. Less than five times per year \n3. More than fives per year\n");
	scanf("%d", &newNode->numOfTrips);

	printf("On average how long is your duration?\n");
	printf("1. One day \n2. Less than 3 days \n3. Less than 7 day \n4. More than 7 day\n");
	scanf("%d", &newNode->duration);

	curr = *bottom;

	if (*top == NULL)
	{
		*top = newNode;
		*bottom = newNode;
		newNode->PREV = NULL;
		newNode->NEXT = NULL;
	}

	else
	{
		newNode->NEXT = NULL;
		newNode->PREV = curr;
		curr->NEXT = newNode;
		*bottom = newNode;
	}

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

// Updating details of passenger using passport number;
void updateDetails(struct node* top, char search[]) {
	struct node* curr;
	int index = 0;

	curr = top;
	while (curr != NULL)
	{
		index++;
		if (strcmp(curr->passport, search) == 0)
		{
			printf("Please enter the year the you were born\n");
			scanf("%d", &curr->yearBorn);

			printf("Please enter your email\n");
			scanf("%s", curr->email);

			printf("Which of the following areas did you travel from\n");
			printf("1. UK \n2. Rest of Europe \n3. Asia \n4. Americas \n5. Australasia\n");
			scanf("%d", &curr->area);

			printf("What travel class did you use to travel to Ireland?\n");
			printf("1. Economy \n2. Premium Economy \n3. Business Class \n4. First Class\n");
			scanf("%d", &curr->travelClass);

			printf("How many trips to Ireland do you make per year?\n");
			printf("1. Less than three times per year \n2. Less than five times per year \n3. More than fives per year\n");
			scanf("%d", &curr->numOfTrips);

			printf("On average how long is your duration?\n");
			printf("1. One day \n2. Less than 3 days \n3. Less than 7 day \n4. More than 7 day\n");
			scanf("%d", &curr->duration);
		}
		curr = curr->NEXT;

	}

}

// Outputting all of the passenger details to a file
void printToFile(struct node* top)
{
	struct node* curr;
	FILE* temp;

	curr = top;
	temp = fopen("Output.txt", "w");

	if (temp != NULL)
	{
		while (curr != NULL)
		{
			fprintf(temp, "Passport Number: %s\n", curr->passport);
			fprintf(temp, "Full name: %s %s\n", curr->name, curr->surname);
			fprintf(temp, "Year born: %d\n", curr->yearBorn);
			fprintf(temp, "Email address: %s\n", curr->email);
			// Switch statement areas travelling from
			fprintf(temp, "Traveling from: ");
			switch (curr->area)
			{
			case 1:
				fprintf(temp, "UK\n");
				break;
			case 2:
				fprintf(temp, "Rest of Europe\n");
				break;
			case 3:
				fprintf(temp, "Asia\n");
				break;
			case 4:
				fprintf(temp, "Americas\n");
				break;
			case 5:
				fprintf(temp, "Australasia\n");
				break;
			default:
				fprintf(temp, "Unknown. Wrong information was entered\n");
				break;
			} // End of Switch

			  // Switch statement travel classes
			fprintf(temp, "Travel class: ");
			switch (curr->travelClass)
			{
			case 1:
				fprintf(temp, "Economy\n");
				break;
			case 2:
				fprintf(temp, "Premium Economy\n");
				break;
			case 3:
				fprintf(temp, "Business Class\n");
				break;
			case 4:
				fprintf(temp, "First Class\n");
				break;
			default:
				fprintf(temp, "Unknown. Wrong information was entered\n");
				break;
			} // End of switch

			  // Switch statement for trips per year
			fprintf(temp, "Trips to Ireland per year: ");
			switch (curr->numOfTrips)
			{
			case 1:
				fprintf(temp, "Less than three times per year\n");
				break;
			case 2:
				fprintf(temp, "Less than five times per year\n");
				break;
			case 3:
				fprintf(temp, "More than five times per year\n");
				break;
			default:
				fprintf(temp, "Unknown. Wrong information was entered\n");
				break;
			} // End of switch

			  // Switch statement for duration
			fprintf(temp, "Average length of duration: ");
			switch (curr->duration)
			{
			case 1:
				fprintf(temp, "One day\n");
				break;
			case 2:
				fprintf(temp, "Less than 3 days\n");
				break;
			case 3:
				fprintf(temp, "Less than 7 days\n");
				break;
			case 4:
				fprintf(temp, "More than 7 days\n");
				break;
			default:
				fprintf(temp, "Unknown. Wrong information was entered\n");
				break;
			} // End of switch
			curr = curr->NEXT;
			fprintf(temp, "\n");
		} // End of while
		// Closing file
		fclose(temp);
	} // End of if statement

	printf("\nOutputting information to file: output.txt\n\n");
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

void deleteElementAtStart(struct node** top)
{
	struct node* temp;

	temp = *top;

	*top = temp->NEXT;

	free(temp);
}

// Delete passenger by passport number
void deletePassenger(struct node* top,struct node* bottom, int position)
{
	struct node* temp;
	struct node* prev;
	int i;

	temp = top;
	prev = bottom;

	for (i = 0; i < position - 1; i++)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	printf("%d",position);
	prev->NEXT = temp->NEXT;
	free(temp);
}

void deletePassenger(struct node* top, char search[20]) {
	struct node *temp;
	struct node *oldtemp;
	int i;
	temp = (struct node*)malloc(sizeof(struct node));
	oldtemp = (struct node*)malloc(sizeof(struct node));
	temp = top;

	// loop through list till you get the element at position
	for (i = 0; i < length(top); i++) {
		if (temp->passport == search) {
			break;
		}
		oldtemp = temp;
		temp = temp->NEXT;
	}

	// bypass the deleted element
	oldtemp->NEXT = temp->NEXT;

	// free up deleted element memory
	free(temp);
	printf("Passenger has been deleted\n\n");
}

// Generating stats for passengers
void genStats(struct node* top, char stat){
	struct node* curr;
	int option = 0, countYear = 0;
	int countUK = 0, countEurope = 0, countAsia = 0, countAmerica = 0, countAustralasia = 0;
	int countOne = 0, countLess3 = 0, countLess7 = 0, countMore7 = 0;
	int countEco = 0, countPEco = 0, countBusiness = 0, countFirst = 0;
	curr = top;

	// Getting count for all stats
	while (curr != NULL)
	{
		switch (curr->area)
		{
		case 1:
			 countUK++;
			break;
		case 2:
			countEurope++;
			break;
		case 3:
			countAsia++;
			break;
		case 4:
			countAmerica++;
			break;
		case 5:
			countAustralasia++;
			break;
		default:
			break;
		} // End of Switch
		
		switch (curr->duration)
		{
		case 1:
			countOne++;
			break;
		case 2:
			countLess3++;
			break;
		case 3:
			countLess7++;
			break;
		case 4:
			countMore7++;
			break;
		default:
			break;
		} // End of switch

		switch (curr->travelClass)
		{
		case 1:
			countEco++;
			break;
		case 2:
			countPEco++;
			break;
		case 3:
			countBusiness++;
			break;
		case 4:
			countFirst++;
			break;
		default:
			break;
		} // End of switch

		if (curr->yearBorn < 1980) {
			countYear++;
			printf("here");
		}
		curr = curr->NEXT;
	} // while

	do {
		printf("Please choose a criteria: \n");
		printf("1. Travel class \n2. Born before 1980 \n");
		scanf("%d", &option);
		if (option != 1 && option != 2) {
			printf("Error - try again\n");
		} // if
	} while (option != 1 && option != 2); // doWhile


	switch(stat) {
	case 'A':
	case 'a':
		if (option == 1) {
			printf("Percentage of passengers of Economy from the UK: %d%%\n", ((countUK / countEco) * 100));
			printf("Percentage of passengers of Premium Economy from the UK: %d%%\n", ((countUK / countPEco) * 100));
			printf("Percentage of passengers of Business Class from the UK: %d%%\n", ((countUK / countBusiness) * 100));
			printf("Percentage of passengers of First Class from the UK: %d%%\n", ((countUK / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers from the UK: %d%%\n", ((countUK / countYear) * 100));
		}
		break;
	case 'B':
	case 'b':
		if (option == 1) {
			printf("Percentage of passengers of Economy from the Rest of Europe: %d%%\n", ((countEurope / countEco) * 100));
			printf("Percentage of passengers of Premium Economy from the Rest of Europe: %d%%\n", ((countEurope / countPEco) * 100));
			printf("Percentage of passengers of Business Class from the Rest of Europe: %d%%\n", ((countEurope / countBusiness) * 100));
			printf("Percentage of passengers of First Class from the Rest of Europe: %d%%\n", ((countEurope / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers from the Rest of Europe: %d%%\n", ((countEurope / countYear) * 100));
		}
		break;
	case 'C':
	case 'c':
		if (option == 1) {
			printf("Percentage of passengers of Economy from the Asia: %d%%\n", ((countAsia / countEco) * 100));
			printf("Percentage of passengers of Premium Economy from the Asia: %d%%\n", ((countAsia / countPEco) * 100));
			printf("Percentage of passengers of Business Class from the Asia: %d%%\n", ((countAsia / countBusiness) * 100));
			printf("Percentage of passengers of First Class from the Asia: %d%%\n", ((countAsia / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers from the Asia: %d%%\n", ((countAsia / countYear) * 100));
		}
		break;
	case 'D':
	case 'd':
		if (option == 1) {
			printf("Percentage of passengers of Economy from the America: %d%%\n", ((countAmerica / countEco) * 100));
			printf("Percentage of passengers of Premium Economy from the America: %d%%\n", ((countAmerica / countPEco) * 100));
			printf("Percentage of passengers of Business Class from the America: %d%%\n", ((countAmerica / countBusiness) * 100));
			printf("Percentage of passengers of First Class from the America: %d%%\n", ((countAmerica / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers from the America: %d%%\n", ((countAmerica / countYear) * 100));
		}
		break;
	case 'E':
	case 'e':
		if (option == 1) {
			printf("Percentage of passengers of Economy from the  Australasia: %d%%\n", ((countAustralasia / countEco) * 100));
			printf("Percentage of passengers of Premium Economy from the Australasia: %d%%\n", ((countAustralasia / countPEco) * 100));
			printf("Percentage of passengers of Business Class from the Australasia: %d%%\n", ((countAustralasia / countBusiness) * 100));
			printf("Percentage of passengers of First Class from the Australasia: %d%%\n", ((countAustralasia / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers from the Australasia: %d%%\n", ((countAustralasia / countYear) * 100));
		}
		break;
	case 'F':
	case 'f':
		if (option == 1) {
			printf("Percentage of passengers of Economy who spent on average one day in Ireland: %d%%\n", ((countOne / countEco) * 100));
			printf("Percentage of passengers of Premium Economy who spent on average one day in Ireland: %d%%\n", ((countOne / countPEco) * 100));
			printf("Percentage of passengers of Business Class who spent on average one day in Ireland: %d%%\n", ((countOne / countBusiness) * 100));
			printf("Percentage of passengers of First Class who spent on average one day in Ireland: %d%%\n", ((countOne / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers who spent on average one day in Ireland: %d%%\n", ((countOne / countYear) * 100));
		}
		break;
	case 'G':
	case 'g':
		if (option == 1) {
			printf("Percentage of passengers of Economy who spent on average less than 3 days in Ireland: %d%%\n", ((countLess3 / countEco) * 100));
			printf("Percentage of passengers of Premium Economy who spent on average less than 3 days in Ireland: %d%%\n", ((countLess3 / countPEco) * 100));
			printf("Percentage of passengers of Business Class who spent on average less than 3 days in Ireland: %d%%\n", ((countLess3 / countBusiness) * 100));
			printf("Percentage of passengers of First Class who spent on average less than 3 days in Ireland: %d%%\n", ((countLess3 / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers who spend on average less than 3 days in Ireland: %d%%\n", ((countLess3 / countYear) * 100));
		}
		break;
	case 'H':
	case 'h':
		if (option == 1) {
			printf("Percentage of passengers of Economy who spent on average less than 7 days in Ireland: %d%%\n", ((countLess7 / countEco) * 100));
			printf("Percentage of passengers of Premium Economy who spent on average less than 7 days in Ireland: %d%%\n", ((countLess7 / countPEco) * 100));
			printf("Percentage of passengers of Business Class who spent on average less than than 7 days in Ireland: %d%%\n", ((countLess7 / countBusiness) * 100));
			printf("Percentage of passengers of First Class who spent on average less than than 7 days in Ireland: %d%%\n", ((countLess7 / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers who spend on average less than than 7 days in Ireland: %d%%\n", ((countLess7 / countYear) * 100));
		}
		break;
	case 'I':
	case 'i':
		if (option == 1) {
			printf("Percentage of passengers of Economy who spent on average more than 7 days in Ireland: %d%%\n", ((countMore7 / countEco) * 100));
			printf("Percentage of passengers of Premium Economy who spent on average more than 7 days in Ireland: %d%%\n", ((countMore7 / countPEco) * 100));
			printf("Percentage of passengers of Business Class who spent on average more than than 7 days in Ireland: %d%%\n", ((countMore7 / countBusiness) * 100));
			printf("Percentage of passengers of First Class who spent on average more than than 7 days in Ireland: %d%%\n", ((countMore7 / countFirst) * 100));
		}
		else if (option == 2)
		{
			printf("Percentage of passengers who spend on average more than than 7 days in Ireland: %d%%\n", ((countMore7 / countYear) * 100));
		}
		break;
	default:
		break;
	} // Switch for stats

}