#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Beam.h"
#include "Load.h"
#include <vector>

using namespace std;
class Model {

public:
	Beam* beam;
	vector<Load> distributedLoads;
	vector<pair<double, double>> shearForces;
	vector<pair<double, double>> moments;
	double axialForce;
	Model(Beam* b, vector<Load> dl, vector<pair<double, double>> sf, vector<pair<double, double>> m, double af);

};

#endif