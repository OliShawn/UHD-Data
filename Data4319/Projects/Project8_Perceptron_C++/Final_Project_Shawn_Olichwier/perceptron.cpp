#include <iostream>
#include <vector>
#include "perceptron.h"

using namespace std;


// Perceptron class constructor
perceptron::perceptron(double learning_rate, int num)
{
	iterations = num;
	alpha = learning_rate;
}


double perceptron::inputSum(vector<double> X)
{
	// This function calculates the sum of the input vector times its corresponding weights
	// (Sum of weightvector * input vector) + bias.
	
	double total = weights[0];																 // Add the bias term before we add the rest.
	for (int i = 0; i < X.size(); i++)
	{
		total += X[i] * weights[i + 1];														// We start from the second element, because we are only updating the weights. 
	}
	return total;
}


void perceptron::modifyWeights(vector<vector<double>> X, vector<double> Y)
{
	// This function will modify our weights depending on the output that is calculated.
	// We make a prediction with our predict function and calculate the loss.
	// We then update the loss based on what the erors were. We have to add a bias term, 
	// so the first term in our weight vector is our bias.
	
	for (int i = 0; i < X[0].size() + 1; i++)												// We add 1 index to account for our bias
	{
		weights.push_back(0);																// Filling our weight vector with all zeros (it can be any number, but 0 is convenient)

	}

	for (int i = 0; i < iterations; i++)													//Iterating through for each iteration we chose when we created our perceptron
	{
		for (int j = 0; j < X.size(); j++)													// Iterating through each vector in our input matrix X
		{
			double loss =  alpha *(Y[j] - predict(X[j]));									// Calculate theloss for our weights  

			for (int w = 1; w < weights.size(); w++)										// Iterating through each member of our weight vector (not counting our bias term)
			{
				weights[w] += loss * X[j][w-1];												// Perceptron learning algorithm. It updates the current weight if it does not match the current Y output.
			}
			weights[0] = loss;																// update the bias	
		}
	}
}


int perceptron::predict(vector<double> X)
{
	// The predict function is a fairly simple function which returns a (+ or -) 1, 
	// depending if the sum of the weights and input vector is positive or negative. 
	// This result will later be compared to the actual output Y for further updating.
	
	if (inputSum(X) > 0)
	{
		return 1;
	}
	else
		return -1;
}


// perceptron destructor
perceptron::~perceptron()
{

}