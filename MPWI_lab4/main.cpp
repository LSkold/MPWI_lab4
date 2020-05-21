#include<iostream>
#include"PairsOfPoints.h"
using namespace std;

//
// checking if DATA is greater than 0
//
void checkValue(int data);

//
//  creating table with values from exercise 
//
void task1();

//
// creating your own table and values
//
void task2();

//
// printing menu on screen
//
void printMenu();

int main() {
	char choice = '0';
	while (choice != '3') {
		system("cls");
		printMenu();
		cin >> choice;
		switch (choice) {
		case '1':
			task1();
			break;
		case '2':
			task2();
			break;
		case '3':
			exit(2115);
			break;
		default:
			cout << "Unknown operation!";
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}

void checkValue(int data) {
	if (data <= 0) {
		cout << "Wrong data!";
		system("pause");
		exit(-1);
	}
}

void task1() {
	PairsOfPoints exercise = PairsOfPoints();

	for (int i = 0; i < DEFAULT_NUMBER_OF_GENERATION; i++)
		exercise.generate();

	cout << endl;
	exercise.printTabs();
	system("pause");
}

void task2() {
	int size, number_of_gen;

	cout << "Enter size of table:"; cin >> size;
	checkValue(size);
	cout << "Enter number of generation:"; cin >> number_of_gen;
	checkValue(number_of_gen);

	PairsOfPoints exercise = PairsOfPoints(size);

	for (int i = 0; i < number_of_gen; i++)
		exercise.generate();

	cout << endl;
	exercise.printTabs();
	system("pause");
}

void printMenu() {
	cout << "1. Do the task with default values" << endl;
	cout << "2. Create your own table and generate as many times, as u wish" << endl;
	cout << "3. Exit!" << endl;
	cout << "Your choice: ";
}
