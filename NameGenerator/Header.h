#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

int readList(string List[]) {
	ifstream namesFile ("Names.txt");
	string line;

	getline(namesFile, line);

	//int size = stoi(line, nullptr, 0);
	int size = stoi(line, nullptr, 0);

	for (int i = 0; i <= size; ++i) {

		getline(namesFile, List[i]);

	}

	namesFile.close();

	return size;

}

int printName(string List[], int size) {

	srand(time(NULL));
	int index = rand() % size;

	cout << "\n\tAND THE LUCKY NAME IS *DRUM ROLL*";

	this_thread::sleep_for(chrono::milliseconds(50)); cout << ".";
	this_thread::sleep_for(chrono::milliseconds(50)); cout << ".";
	this_thread::sleep_for(chrono::milliseconds(50)); cout << ".";
	this_thread::sleep_for(chrono::milliseconds(50)); cout << ".";
	this_thread::sleep_for(chrono::milliseconds(50)); cout << ".";
	
	this_thread::sleep_for(chrono::milliseconds(100)); cout << List[index] << "\n\t";

	return index;
	
}

void addToList(int* currentListSize, string newName, string List[]) {

	List[*currentListSize] = newName;
	*currentListSize += 1;
	List[*currentListSize] = "ENDOFTHELINEBUCKAROO";

}

void removeFromList(int nameSpace, string List[]) {

	int i = 0;

	List[nameSpace] = "";

	while (List[nameSpace + i + 1] != "ENDOFTHELINEBUCKAROO") {
		List[nameSpace + i] = List[nameSpace + i + 1];
		List[nameSpace + i + 1] = "";

		++i;
	}

}

void remakeList(string List[], int size) {

	ofstream namesFile ("Names.txt");

	namesFile << size << "\n";

	for (int i = 0; i < size; ++i) {
		namesFile << List[i] << "\n";
	}

	namesFile << "ENDOFTHELINEBUCKAROO\n";

	namesFile.close();

}
