// This code was inspired from the Machine Learning class and implemented in CS 2410, Data Structures and Algorithms.
// Getting C++ working in a Jupyter notebook is possible but not worth the time it takes. 

// This file reads in the Iris dataset and uses the classical perceptron model to predict on 4 test flowers.
// It turns out that doing matrix multiplications for machine learning applications is complicated in C++ and provided
// plenty of challenge.

// This is the main file that runs, but the perceptron class and class methods are included in the perceptron.cpp and perceptron.h files that are included.


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "perceptron.h"

using namespace std;

// ******************************************* Function Definitions *******************************************
// Function for reading the training input data X, which is a vector of vectors.
// Each vector holds 4 values, corresponding to 4 measurements of one flower sample.

vector< vector<double>> readingInputX()
{
	string line;
	ifstream myFileStream("Iris_Data_X.csv");
	if (!myFileStream.is_open())
	{
		cout << "File failed to open" << endl;
	}

	vector< vector<double> > X;												// Vector of vectors to hold inputs, X

	while (getline(myFileStream, line))										// Reading in lines of our csv, storing each in a vector.
	{
		string a, b, c, d, y, Y;
		stringstream ss(line);
		double A, B, C, D;
		getline(ss, a, ',');
		A = stof(a);
		getline(ss, b, ',');
		B = stof(b);
		getline(ss, c, ',');
		C = stof(c);
		getline(ss, d, ',');
		D = stof(d);
		X.push_back(vector < double > {A, B, C, D});						// Push this one instance of an Iris flower vector to our X vector (of vectors)
	}
	return X;
}

// Function for reading the training data labels Y
vector <double> readingInputY()
{
	string line;
	ifstream myFileStream("Iris_Data_Y.csv");
	if (!myFileStream.is_open())
	{
		cout << "File failed to open" << endl;
	}

	vector<double> Y;
	while (getline(myFileStream, line))										// Reading in lines of our csv, storing each in a vector.
	{
		string y;
		stringstream ss(line);
		getline(ss, y, ',');
		if (y == "Iris-setosa")												// Here we need to change our string labels into numerical values.  
		{
			Y.push_back(1);
		}
		else
		{
			Y.push_back(-1);
		}
	}
	return Y;
}



int main()
{
	// ******************************************Reading Input Variables****************************************************************
	// First thing we need to do in the main function is read in our data. It has been split manually into training and testing data.
	// Vector X holds our training data and vector Y holds the corresponding labels (species of flower). 
	
	vector< vector<double> > X;
	vector<double> Y;
	X = readingInputX();
	Y = readingInputY();


	// **************************************************Test Data*****************************************************************
	// Our predict function needs new data to predict on that does not exist in our training set (otherwise it wouldn't be predicting!)
	// This code names 4 new vectors that we will send through
	
	vector <double> test_set1 = { 4.8, 3.1, 1.6, 0.2 }; // Expected output = 1, Iris-Setosa
	vector <double> test_set2 = { 6.3, 2.3, 4.4, 1.3 }; // Expected output = -1, Iris-Versicolor
	vector <double> test_set3 = { 4.5, 2.3, 1.3, 0.3 }; // Expected output = 1, Iris-Setosa
	vector <double> test_set4 = { 5.7, 2.8, 4.1, 1.3 }; // Expected output = -1, Iris-Versicolor




	// ******************************************Perceptron Class Creation, Weight Training********************************************
	// Calling our perceptron constructor which sets the alpha value to 0.05 and the number of training iterations to 100
	perceptron perceptron(0.01, 1000);

	// This section is the real core of the perceptron. It is where our weights are updated. A perceptron takes in constant training data and it
	// modifies the weights associated with each input variable. A perceptron is just a linear combination of input variables and weights.
	// In c++, this means nested for loops to multiply each element of our input vector and our weight vector.
	perceptron.modifyWeights(X, Y);


	// ************************************************************Prediction***********************************************************
	// Now that our model is trained, the next step is to predict on our testing data vectors (new data)

	// Test 1:
	int pred;
	pred = perceptron.predict(test_set1);
	if (pred == 1) 
	{
		cout << "The prediction for test 1 is Iris-Setosa." << endl;
	}
	else
		cout << "The prediction for test 1 is Iris-Versicolor." << endl;
	cout << "The actual species is Iris-Setosa." << endl << endl;


	// Test 2:
	pred = perceptron.predict(test_set2);
	if (pred  == 1)
	{
		cout << "The prediction for test 2 is Iris-Setosa." << endl;
	}
	else
		cout << "The prediction for test 2 is Iris-Versicolor." << endl;
	cout << "The actual species is Iris-Versicolor." << endl << endl;;


	// Test 3:
	pred = perceptron.predict(test_set3);
	if (pred == 1)
	{
		cout << "The prediction for test 3 is Iris-Setosa." << endl;
	}
	else
		cout << "The prediction for test 3 is Iris-Versicolor." << endl;
	cout << "The actual species is Iris-Setosa." << endl << endl;;


	// Test 4
	pred = perceptron.predict(test_set4);
	if (pred  == 1)
	{
		cout << "The prediction for test 4 is Iris-Setosa." << endl;
	}
	else
		cout << "The prediction for test 4 is Iris-Versicolor." << endl;
	cout << "The actual species is Iris-Versicolor." << endl << endl;;


	system("pause");
}



