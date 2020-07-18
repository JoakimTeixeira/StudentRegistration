#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define clearScreen() printf("\e[1;1H\e[2J")
#define MAX 60 // set maximum constant

// student record structure
typedef struct
{
	char name[MAX];
	int registryNumber;
	char birthDate[MAX];
	float grade1;
	float grade2;
	float average;
	int active;
} student;

// array "Students" have type "student" (up to 60 positions)
student Students[MAX];

// global counter variable, records the number of students registered
int counter = 0;

// initialize functions
void menu();
void registerStudent();
void consultStudent();
void printClassData();
void printStudentSituation();

// main function: call "menu" functions, which call the menu options functions
int main()
{
	setlocale(LC_ALL, "English");
	menu();
	return 0;
}

void printStudentData(int index)
{
	printf("\nStudent %d: \n", index + 1);
	printf("Name: %s\n", Students[index].name);
	printf("Registry number: %d\n", Students[index].registryNumber);
	printf("Birth date: %s\n", Students[index].birthDate);
	printf("1st grade: %.1f\n", Students[index].grade1);
	printf("2nd grade: %.1f\n", Students[index].grade2);
}

// global variables to use in "chooseOption" function
char chooseToTypeZero[] = "\nType [0] to return: ";
char chooseBetweenTwo[] = "\nChoose an option: ";

int chooseOption(int option, char string[])
{
	printf("%s", string);
	scanf("%d", &option);
	return option;
}

// menu declarations
void menu()
{
	// cleans window
	clearScreen();
	int option = 0;

	do
	{
		printf("====== Biology course - Class 825 ======\n");
		printf("\n  [1] Register students\n");
		printf("  [2] Query student data\n");
		printf("  [3] Print class data\n");
		printf("  [4] Students grade situation\n");
		printf("  [5] Exit\n");
		printf("\n========================================\n");

		option = chooseOption(option, chooseBetweenTwo);

		// asks the user to choose which menu option he wants.
		// selecting an option, a function is called
		switch (option)
		{
		case 1:
			registerStudent();
			break;

		case 2:
			consultStudent();
			break;

		case 3:
			printClassData();
			break;

		case 4:
			printStudentSituation();
			break;
		}
	} while ((option > 0) && (option < 5));
}

//======= menu declaration 1: register =======
void registerStudent()
{
	clearScreen();
	int option = 0;

	do
	{
		if (counter >= MAX)
		{
			printf("\nYou have reached the maximum number of records!\n");
			getchar();
			break;
		}
		else
		{
			clearScreen();
			printf("\nName: ");
			scanf("%s", Students[counter].name);

			printf("\nRegistry number: ");
			scanf("%d", &Students[counter].registryNumber);

			printf("\nBirth date: ");
			scanf("%s", Students[counter].birthDate);

			printf("\n1st grade: ");
			scanf("%f", &Students[counter].grade1);

			printf("\n2nd grade: ");
			scanf("%f", &Students[counter].grade2);

			Students[counter].average = (Students[counter].grade1 + Students[counter].grade2) / 2;
			// adds whenever a student is registered
			counter++;

			// menu declaration 1 repeats until user chooses to leave
			// or register size exceeds 60 students
			if (counter >= MAX)
			{
				printf("\nYou have reached the maximum number of records!\n");
				break;
			}
			else
			{
				printf("\nStudent registered!\n");
			}
		}
		printf("\nWould you like to register a new student? ");
		printf("\n[0] No    [1] Yes\n");
		option = chooseOption(option, chooseBetweenTwo);

	} while (option != 0);
	clearScreen();
}

//======= menu declaration 2 - query data =======
void consultStudent()
{
	clearScreen();
	// variable "success" serves as a test (false or true) to check if a student was found
	int option, success = 0;

	do
	{
		printf("\nType [1] to search through registry number");
		printf("\nType [2] to search through student name\n");
		option = chooseOption(option, chooseBetweenTwo);
		clearScreen();

		if (option == 1)
		{
			int i = 0;
			int registryNumber = 0;

			printf("\nType the registry number: ");
			scanf("%d", &registryNumber);

			// global variable "counter": storages the number of registered students
			for (i = 0; i < counter; i++)
			{
				if (registryNumber == (Students[i].registryNumber))
				{
					success = 1;
					break;
				}
				else
				{
					success = 0;
					break;
				}
			}

			// if 1 (true), print the student data for current position
			if (success == 1)
			{
				printStudentData(i);
			}
			// else 0 (false)
			else if (success == 0)
			{
				printf("\n==== Registry not found ====\n");
			}
		}

		else if (option == 2)
		{
			int i = 0;
			success = 0;
			char name[MAX];

			clearScreen();
			printf("\nType the student name: ");
			scanf("%s", name);

			for (i = 0; i < counter; i++)
			{
				// function "strstr" is used to search strings
				if (strstr(Students[i].name, name) != NULL)
				{
					success = 1;
					break;
				}
				else
				{
					success = 0;
					break;
				}
			}

			if (success == 1)
			{
				printStudentData(i);
			}
			else if (success == 0)
			{
				printf("\n==== Name not found ====\n");
			}
		}

		printf("\nType [0] if you want to leave");
		printf("\nType [1] if you want to continue searching\n");
		option = chooseOption(option, chooseBetweenTwo);
		clearScreen();

	} while (option != 0);

	clearScreen();
}

//======= menu declaration 3: print =======
void printClassData()
{
	int option, i;
	clearScreen();

	if (counter == 0)
	{
		printf("Nothing to print\n");
		option = chooseOption(option, chooseToTypeZero);
		clearScreen();
	}
	else
	{
		printf("\n===== Printing data =====\n");
		// creates method to inform that there is no registration, if option 3 is selected without having a student in the system
		do
		{
			for (i = 0; i < counter; i++)
			{
				printStudentData(i);
			}
			option = chooseOption(option, chooseToTypeZero);
			clearScreen();

		} while (option != 0);
		clearScreen();
	}
}

//======= menu declaration 4: grade situation =======
void printStudentSituation()
{
	clearScreen();
	int option, i;
	if (counter == 0)
	{
		printf("Nothing to print\n");
		option = chooseOption(option, chooseToTypeZero);
		clearScreen();
	}
	else 
	{
		do
		{
			for (i = 0; i < counter; i++)
			{
				//---------------------------------------------------------------
				if (Students[i].average >= 7)
				{
					printf("\n%s, Grade average: %.1f, situation: Approved\n", Students[i].name, Students[i].average);
				}
				//---------------------------------------------------------------
				else if ((Students[i].average >= 3) && (Students[i].average < 7))
				{
					printf("\n%s, Grade average: %.1f, situation: Final test\n", Students[i].name, Students[i].average);
				}
				//---------------------------------------------------------------
				else if (Students[i].average < 3)
				{
					printf("\n%s, Grade average: %.1f, situation: Reproved\n", Students[i].name, Students[i].average);
				}
			}
			option = chooseOption(option, chooseToTypeZero);

		} while (option != 0);
		clearScreen();
	}	
}