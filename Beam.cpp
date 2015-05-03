class Beam {

public:
	double lenght, area, E, G, I, yMax;
	int end1, end2;
	Beam(double l, double A, double e, double g, double i, double y, int e1, int e2);

};

Beam::Beam(double l, double A, double e, double g, double i, double y, int e1, int e2) {

	lenght = l;
	area = A;
	E = e;
	G = g;
	I = i;
	yMax = y;
	end1 = e1;
	end2 = e2;
}