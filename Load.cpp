
class Load {

	/*
	start = start of applied load [m]
	end = end of applied load [m]
	q(x) = intensity of load [N/m] at x [m] from end1*/


public:
	double start, end;
	double (*q)(double);
	Load(double start, double end, double (*q)(double));

};

Load::Load(double s, double e, double (*i)(double)) {

	start = s;
	end = e;
	q = i;

}