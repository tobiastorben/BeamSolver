#include <vector>
#include "Load.h"
#include "Beam.h"
#include "Model.h"
#include "Methods.h"
#include <iostream>

using namespace std;


double inten(double x) {

	return 5;
}

int main() {

	//---------------Input Section----------------\\

	//Give step lenght of integration
	double step = 0.0001;

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

	distributedLoads.push_back(Load(0, 10, &inten));


	//--------------End of input section--------------------\\
	//Create beam model object from input data
	Beam beam = Beam(l, A, E, G, I, yMax, end1, end2);


	//Create model object from input data
	Model model = Model(&beam, distributedLoads, shearForces, moments, axialForce);

	//Solve for reaction forces
	double Ay, By, Ma, Mb;

	//Check for degrees of freedom
	if (end1 == 0 || end1 == 2) Ma = 0;
	if (end2 == 0 || end2 == 2) Mb = 0;
	if (end1 == 0) Ay = Ma = 0;
	if (end2 == 0) By = Mb = 0;
	if (end1 == 1) Ma = 0;
	if (end2 == 1) Mb = 0;



	double yLoad = 0;
	double momentsAboutA = 0;
	double integral = 0;
	double(*momFunc)(double);


	for (int i = 0; i < moments.size(); i++) {
	
		momentsAboutA += moments[i].first;
	
	}

	for (int i = 0; i < shearForces.size(); i++) {
	
		yLoad += shearForces[i].first;
		momentsAboutA -= shearForces[i].first*shearForces[i].second;
	}

	for (int i = 0; i < distributedLoads.size(); i++) {

		integral = integrate(distributedLoads[i].q, distributedLoads[i].start, distributedLoads[i].end, step);
		yLoad += integral;
		momentsAboutA -= integrate(

			[&](double x) {

			double(*intensity)(double) = distributedLoads[i].q;
			return intensity(x)*x; },
				distributedLoads[i].start, distributedLoads[i].end, step);
	}

	
			return 0;

	}