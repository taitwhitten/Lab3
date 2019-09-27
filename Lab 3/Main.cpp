/*
	Tait Whitten
	C++ Fall 2019
	Due: 26 September 2019
	Lab 3: User and File I/O
	Create a program that calculates mean and standard deviation from a set of 4 numbers that outputs to the screen and to a file
*/


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

float mean(int num1, int num2, int num3, int num4);
float StaDev(int num1, int num2, int num3, int num4, float mean);


int main()
{
	//variable declaration
	int num1;
	int num2;
	int num3;
	int num4;
	string inputFileName = "inMeanStd.dat";
	string outputFileName = "outMeanStd.dat";
	ifstream inFile;
	ofstream outFile;

	inFile.open(inputFileName);
	outFile.open(outputFileName);

	cout << "Enter four real numbers to find the mean and standard deviation: ";
	cin >> num1 >> num2 >> num3 >> num4; //user input
	cout << "\nThe mean is: " << mean(num1, num2, num3, num4); //mean output
	cout << "\nThe standard deviation is: " << StaDev(num1, num2, num3, num4, mean(num1, num2, num3, num4)); //standard deviation output

	inFile >> num1 >> num2 >> num3 >> num4; //reading the numbers from the file
	outFile << "The mean is:" << mean << endl; //Output the mean to the file
	outFile << "The standard deviation is: " << StaDev;	//output the standard deviation from the file																																																							

	inFile.close(); //close the infile
	outFile.close(); //close the outfile

	return 0;
}

//function call
float mean(int num1, int num2, int num3, int num4)
{
	return float(num1 + num2 + num3 + num4) / 4;
}

//function call
float StaDev(int num1, int num2, int num3, int num4, float mean)
{
	return float(pow((((pow((num1 - mean), 2)) + (pow((num2 - mean), 2)) + (pow((num3 - mean), 2)) + (pow((num4 - mean), 2))) / 4), (0.5)));
}