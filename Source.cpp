/*Name: Hector Dominguez-Maceda
Class: CSC 2430
Assignment: Lab 3 - C String Phone Numbers\
Descriptiom: This lab takes in numbers and formats them into a nice format
*/

#include <iostream> //Libraries needed for program
#include <cstring>

using namespace std;

const int PHONE_NUMBER_LENGTH = 256;
const int AREA_PREFIX_LENGTH = 4;
const int RAW_NUM_LENGTH = 5;

void Name(char[]);
void instructions(char[]); //all
void AutoArea(char[], char[]); //of
void UserArea(char[], char[], char[], char[]); //my
void DisplayNumParts(char[], char[], char[]); //function
void DisplayWholeNum(char[], char[], char[], char[]); //prototypes
void SPUEval(char[], char[], char[], char[]);


int main()
{
	system("cls"); //clears the screen
	char UserName[20]; //storage for username

	Name(UserName); //Calling the function

	instructions(UserName); //Calling the function

	//various char c strings
	char AreaCode[AREA_PREFIX_LENGTH];
	char Prefix[AREA_PREFIX_LENGTH];
	char RawNum[RAW_NUM_LENGTH];
	char WholeNum[PHONE_NUMBER_LENGTH];
	char FormNum[PHONE_NUMBER_LENGTH];
	int lenName = 0;

	cin.getline(WholeNum, PHONE_NUMBER_LENGTH); //Gets the phone number from the user

	lenName = strlen(WholeNum); //will determine if we need to use the default area code

	if (lenName < 8)
	{
		AutoArea(AreaCode, WholeNum); //Calling the function
	}

	UserArea(AreaCode, Prefix, WholeNum, RawNum); //Calling the function

	DisplayNumParts(AreaCode, Prefix, RawNum); //Calling the function

	DisplayWholeNum(AreaCode, Prefix, RawNum, FormNum); //Calling the function

	SPUEval(UserName, AreaCode, Prefix, RawNum); //Calling the function

	return 0;
}

//give the user instructions about the program
void instructions(char UserName[])
{
	cout << "Hey " << UserName << ". I want you to enter some phone numbers." << endl;

	cout << "Enter the area code, the prefix, and the four digit number." << endl;

	cout << "Here is an example of what your input can look like:" << endl;

	cout << "\t2062812945 OR 9974321" << endl;

	cout << "Any number that does not include an area code will default a 206 area code." << endl;

	cout << "I am ready when you are " << UserName << "! :)" << endl;

	cout << "\tUnformated phone number: ";
}

//this is called if we need to use the default area code
void AutoArea(char AreaCode[], char WholeNum[])
{
	char TempStorage[PHONE_NUMBER_LENGTH];

	strcpy_s(TempStorage, PHONE_NUMBER_LENGTH, "206");

	strcat_s(TempStorage, PHONE_NUMBER_LENGTH, WholeNum);

	strcpy_s(WholeNum, PHONE_NUMBER_LENGTH, TempStorage);
}

//this function is called to finish the rest of the number
void UserArea(char AreaCode[], char Prefix[], char WholeNum[], char RawNum[])
{

	strncpy_s(AreaCode, AREA_PREFIX_LENGTH, WholeNum, 3);

	strncpy_s(Prefix, AREA_PREFIX_LENGTH, WholeNum + 3, 3);

	strncpy_s(RawNum, RAW_NUM_LENGTH, WholeNum + 6, 4);
}

//This function displays all of the separate parts of the number
void DisplayNumParts(char AreaCode[], char Prefix[], char RawNum[])
{
	cout << "\tArea code: ";

	for (int d = 0; d < AREA_PREFIX_LENGTH; d++)
	{
		cout << AreaCode[d];
	}

	cout << ", Prefix: ";

	for (int e = 0; e < AREA_PREFIX_LENGTH; e++)
	{
		cout << Prefix[e];
	}

	cout << ", Raw Number: ";

	for (int f = 0; f < RAW_NUM_LENGTH; f++)
	{
		cout << RawNum[f];
	}
}

//this function displays all of the parts all in one
void DisplayWholeNum(char AreaCode[], char Prefix[], char RawNum[], char FormNum[])
{
	cout << "\nI will now format your number :)\n\t";

	strcpy_s(FormNum, PHONE_NUMBER_LENGTH, "(");
	strcat_s(FormNum, PHONE_NUMBER_LENGTH, AreaCode);
	strcat_s(FormNum, PHONE_NUMBER_LENGTH, ")");
	strcat_s(FormNum, PHONE_NUMBER_LENGTH, " ");
	strcat_s(FormNum, PHONE_NUMBER_LENGTH, Prefix);
	strcat_s(FormNum, PHONE_NUMBER_LENGTH, "-");
	strcat_s(FormNum, PHONE_NUMBER_LENGTH, RawNum);


	for (int e = 0; e < 15; e++)
	{
		cout << FormNum[e];
	}

	cout << "\n";
}

//this function evaluates if it is an spu number and if it is a washington number
void SPUEval(char UserName[], char AreaCode[], char Prefix[], char RawNum[])
{
	if ((strcmp(AreaCode, "206") == 0) && (strcmp(Prefix, "281") == 0))
	{
		cout << UserName << ", this number is an SPU number because of 281." << endl;
	}
	else if ((strcmp(AreaCode, "206") == 0) && (strcmp(Prefix, "286") == 0))
	{
		cout << UserName << ", this number is an SPU number because of 286." << endl;
	}
	else if ((strcmp(AreaCode, "206") == 0) || (strcmp(AreaCode, "253") == 0))
	{
		cout << "Hey " << UserName << ", this number's area code indicates that it is from the state of Washington." << endl;
	}
	else
	{
		cout << "Sorry, I don't know much about your number :(" << endl;
	}
}

void Name(char UserName[])
{
	cout << "Hey user, can you enter your name please?" << endl;


	cin.getline(UserName, 20, '\n');
}