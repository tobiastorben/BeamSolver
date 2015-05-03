#ifndef METHODS_H
#define METHODS_H

#include <vector>

using namespace std;

double listSum(vector<double> list);

//Trapezoidal integration

template<typename Func>

double integrate(Func f, double lower, double upper, double step) {

	double sum = 0.5*(f(lower) + f(upper));
	double i = lower + step;

	while (i < upper) {

		sum += f(i);
		i += step;
	}

	return sum*step;
};

#endif