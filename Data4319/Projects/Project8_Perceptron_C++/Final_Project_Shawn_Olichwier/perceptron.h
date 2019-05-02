#pragma once

using namespace std;

class perceptron
{
private:
	double alpha;								// Our step length, or how fast we train
	int iterations;								// Number of iterations of training to run.
	vector<double> weights;

public:
	perceptron(double alpha, int iterations);
	~perceptron();
	double inputSum(vector<double> X);
    int predict(vector<double> X);
	void modifyWeights(vector< vector<double> > X, vector<double> y);
};

