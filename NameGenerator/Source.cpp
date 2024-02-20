/*	DnD Out of the Abyss Random Name Selector
*	David Tebo	
	Last Updated: February 19, 2024

		This selector takes a text file filled with the names put forward by my players in the 
	Out of the Abyss campaign I am running for them. 

	Source.Cpp contains funcions calls, UI, and this descriptor
	Header.h contains all functions and libraries
	Names.txt contains the names proposed by my players
	
	readList()
	This function reads the text file, who's first line is the number of names contained and the 
	last is a signifier that tells my program the end of the file is reached. All of the names are
	placed into an array of strings that the program then works with.

	printName()
	Prints a random name from the read text file and prints it to the screen.

	addToList()
	Asks the user to input a new name which it then adds to the array the function created from 
	readList(). Places the newest name at the end. 

	removeFromList()
	After the user has gotten a randomly selected name from printName() the user has the option to
	remove that name from the pool of available names. Remvoing the name clears the spot in the array 
	and then shifts the remainder of the array back one index. 

	remakeList()
	At the end of this program remakeList() is called which rewrites the text file used to hold the
	names. This updates the text file with names that have been added and excludes the names that have 
	been removed on top of updating the count at the top of the file for the number of names within the 
	file. 

*/




#include "Header.h"

using namespace std;


int main() {

	int notDone = 1;
	int selection = -1;

	int nameSelected = 0;

	int currentListSize = 0;

	string newName;
	string firstWord;

	string List[500];



	cout << "\n\n\tWELCOME to the DnD character random name picker\n";

	currentListSize = readList(List);

	while (notDone) {

		cout << "\tWhat do you want to do?\n\t[1] Make a Selection\n\t[2] Add to List\n\t[3] Exit Program\n\n\t";
		cin >> selection;

		while (selection < 1 || selection > 3) {
			cout << "\n\tPlease make a valid selection, 1 2 or 3 and then ENTER\n\t";
			cin >> selection;
		}

		if (selection == 1) {

			selection = -1;

			nameSelected = printName(List, currentListSize);

			cout << "\n\tDo you want to remove the name from the pool? \n\t[1] Yes\n\t[2] No\n";
			while (selection < 1 || selection > 2) {
				cout << "\n\tPlease make a valid selection, 1 or 2 and then ENTER\n\t";
				cin >> selection;
			}

			if (selection == 1) {
				--currentListSize;
				removeFromList(nameSelected, List);
			}
			else {
				selection = -1;
			}

			cout << "\n\n";

		}

		if (selection == 2) {

			cout << "\n\tPlease input the name you want to add: \n\t";
			cin >> firstWord;
			getline(cin, newName);

			newName = firstWord + newName;

			addToList(&currentListSize, newName, List);

			cout << "\n\n";

			selection = 2;

		}

		if (selection == 3) {
			notDone = 0;

			cout << "\n\tThanks for using the generator!! Hope some laughs were had from the results <3\n\n";

			remakeList(List, currentListSize);

			selection = 3;

		}



	}


	return 0;
}