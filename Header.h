#ifndef LOAD_H
#define LOAD_H

class Load {

public:
	double start, end;
	double(*q)(double);
	Load(double start, double end, double(*q)(double));

};

#endif