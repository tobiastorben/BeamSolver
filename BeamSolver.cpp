#include <vector>
#include "Load.h"

using namespace std;


int main() {

	//---------------Input Section----------------\\

	//Define beam:

	//Length [m]
	double l = 10;

	//Modulus of elasticity [Pa]
	double E = 210e9;

	//Modulus of rigidity [Pa]
	double G = 10000;

	//Second moment of inertia [m^4]
	double I = 0.001;

	//Section area [m^2]
	double A = 0.1;

	//Largest distance from centroid (signed) [m]
	double yMax = 0.1;

	//Define boundry conditions [0 = free, 1 = pinned, 2 = roller, 3 = fixed]:

	int end1 = 1;
	int end2 = 2;

	//Define loads

	//Concentrated shear forces [N] at given distance from end1 [m]
	vector<pair<double, double>> shearForces;

	shearForces.push_back(make_pair(10000.0, 5.0));

	//Axial force [N]
	double axialForce = 10000;


	//Concentradet moments [Nm] at given distance from end1 [m]
	vector<pair<double, double>> moments;

	moments.push_back(make_pair(5000, 2));

	//Distributed loads. Create Load object with "start" and "end" attributes which gives
	//the area of the beam the load applies for  (in [m]from end1), and a function pointer which gives the load intensitye
	//as a function of distance from end1 [N/m]

	vector<Load> distributedLoads;

	distributedLoads.push_back(Load(0, 10, &q));
}




double q(double x) {

	return 5;
}