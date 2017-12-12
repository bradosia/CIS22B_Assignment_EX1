﻿/*
Branden Lee
CIS 22B
Fall 2017
Assignment OEC
Problem OEC1

Used Microsoft Visual Studio 2017

Car class
Reads data from "data.txt" and prints it.
Uses STL vector of Car objects
*/
#include <iostream>
#include <iomanip>      // std::setw
#include <string>
#include <fstream>      // std::fstream
#include <vector>
using namespace std;

/**************************************************
** Car class
**************************************************/
class Car
{
private:
	string reportingMark;
	int carNumber;
	string kind;
	bool loaded;
	string destination;
public:
	Car() { setup("", 0, "other", false, "NONE"); } //default constructor
	Car(const Car &CarObj) { setup(CarObj.reportingMark, CarObj.carNumber, CarObj.kind, CarObj.loaded, CarObj.destination); } //copy constructor
	Car(string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit) { setup(reportingMarkInit, carNumberInit, kindInit, loadedInit, destinationInit); } //other constructor
	~Car() {} // destructor
	void setup(string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit);
	void output();
	Car & Car::operator=(const Car & carB);
};

/**************************************************
** StringOfCars class
**************************************************/

class StringOfCars
{
private:
	vector<Car> carVector;
public:
	StringOfCars() {} //default constructor
	StringOfCars(const vector<Car> &StringOfCarsObj)  //copy constructor
	{
		carVector = StringOfCarsObj;
	}
	~StringOfCars() {} // destructor

	void output();
	void push(Car &CarObj);
	void pop(Car &CarObj);
};

/**************************************************
** global functions, and variables
**************************************************/

void input(StringOfCars & StringOfCarsObj);

int main()
{
	// Test the Car operator=   function. 
	cout << "TEST 1" << endl;
	Car car1("SP", 34567, "business", true, "Salt Lake City");
	Car car2;
	car2 = car1;
	car2.output();
	// Test the StringOfCar push function.
	cout << "TEST 2" << endl;
	StringOfCars string1;
	input(string1);
	cout << "STRING 1" << endl;
	string1.output();
	// Test the StringOfCars pop function. 
	cout << "TEST 3" << endl;
	Car car3;
	string1.pop(car3);
	cout << "CAR 3" << endl;
	car3.output();
	cout << "STRING 1" << endl;
	string1.output();
	system("pause");
	return 0;
}

/**************************************************
** Car class method definitions
**************************************************/

/******************* Car::setup *******************
** Puts the car data into the object
**************************************************/
void Car::setup(string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit)
{
	reportingMark = reportingMarkInit;
	carNumber = carNumberInit;
	kind = kindInit;
	loaded = loadedInit;
	destination = destinationInit;
}

/********************* Car::output ****************
** Prints the car data in a neat format
**************************************************/
void Car::output()
{
	// cout << bool will output an integer
	// we create a temporary string to output the bool
	// std::boolalpha can also be used
	string loadedString = (!loaded) ? "false" : "true";
	cout << setw(16) << left << "reportingMark:" << reportingMark << endl
		<< setw(16) << left << "carNumber: " << carNumber << endl
		<< setw(16) << left << "kind: " << kind << endl
		<< setw(16) << left << "loaded: " << loadedString << endl
		<< setw(16) << left << "destination: " << destination << endl << endl;
}

/********************* operator= ******************
** operator over load for Car class assignment =
**************************************************/
Car & Car::operator=(const Car & carB)
{
	setup(carB.reportingMark, carB.carNumber, carB.kind, carB.loaded, carB.destination);

	return *this;
}

/**************************************************
** StringOfCars class method definitions
**************************************************/

/************* StringOfCars::output ***************
** Outputs each car data. Prints "NO cars" if
** StringOfCars is empty.
**************************************************/
void StringOfCars::output()
{
	unsigned int i, n;
	n = carVector.size();
	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			cout << "Car #" << i + 1 << endl;
			carVector[i].output();
		}
	}
	else
	{
		cout << "NO cars" << endl;
	}
}

/*************** StringOfCars::push ***************
** Puts a Car into the StringOfCars array
**************************************************/
void StringOfCars::push(Car &CarObj)
{
	carVector.push_back(CarObj);
}

/*************** StringOfCars::pop ****************
** Removes the last Car added from the StringOfCars
** assigns removed Car to the argument
**************************************************/
void StringOfCars::pop(Car &CarObj)
{
	if (carVector.size() > 0)
	{
		Car tempCar = carVector.back();
		carVector.pop_back();
		CarObj = tempCar;
	}
	else
	{
		cout << "string of cars is empty";
		exit(EXIT_FAILURE);
	}
}

/**************************************************
** global function definitions
**************************************************/

/********************* input **********************
** Reads the car data from the text file "data.txt"
** Prints data from the file
**************************************************/
void input(StringOfCars & StringOfCarsObj)
{
	string carType, reportingMarkInit, kindInit, destinationInit, loadedInit;
	int carNumberInit;
	std::fstream inputFile;
	inputFile.open("data.txt");
	if (!inputFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	while (inputFile.peek() != EOF)
	{
		while (inputFile.peek() == ' ')
			inputFile.get();
		inputFile >> carType >> reportingMarkInit >> carNumberInit >> kindInit >> loadedInit;
		while (inputFile.peek() == ' ')
			inputFile.get();
		getline(inputFile, destinationInit);
		// If the carType is not "Car", send an error message and do nothing.
		if (carType == "Car")
		{
			// If the carType is "Car", declare a Car object named temp using the constructor that takes 5 parameters.
			Car temp(reportingMarkInit, carNumberInit, kindInit, loadedInit == "true" ? true : false, destinationInit);
			StringOfCarsObj.push(temp);
		}
		// If the carType is not "Car", send an error message and do nothing.
		else cerr << "Not a car" << endl;
	}
	inputFile.close();
}

/* Execution results
TEST 1
reportingMark:  SP
carNumber:      34567
kind:           business
loaded:         true
destination:    Salt Lake City

TEST 2
STRING 1
Car #1
reportingMark:  CN
carNumber:      819481
kind:           maintenance
loaded:         false
destination:    NONE

Car #2
reportingMark:  SLSF
carNumber:      46871
kind:           business
loaded:         true
destination:    Memphis

Car #3
reportingMark:  AOK
carNumber:      156
kind:           tender
loaded:         true
destination:    McAlester

TEST 3
CAR 3
reportingMark:  AOK
carNumber:      156
kind:           tender
loaded:         true
destination:    McAlester

STRING 1
Car #1
reportingMark:  CN
carNumber:      819481
kind:           maintenance
loaded:         false
destination:    NONE

Car #2
reportingMark:  SLSF
carNumber:      46871
kind:           business
loaded:         true
destination:    Memphis
*/