#include <vector>

using namespace std;

//Sum elements in vector
double listSum(vector<double> list) {
	double sum = 0;
	for (int i = 0; i < list.size(); i++) {
	
		sum += list[i];
	
	}

	return sum;
}


