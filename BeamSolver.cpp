#include <vector>

using namespace std;


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


//Concentrated forces [N] at given distance from end1 [m]
vector<pair<double, double>> forces;

forces.push_back(make_pair(10000.0, 5.0));

