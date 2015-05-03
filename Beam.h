#ifndef BEAM_H
#define BEAM_H


class Beam {

public:
	double lenght, area, E, G, I, yMax;
	int end1, end2;
	Beam(double l, double A, double e, double g, double i, double y, int e1, int e2);

};

#endif