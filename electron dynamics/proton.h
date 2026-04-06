#pragma once
#include "electron.h"
const double q_p = 1;
class proton
{
public:
	vector position;
	vector getElectricField(vector x) {
		vector delta = x - this->position;
		vector res = delta * q_p / (delta.sqrNorm() * delta.Norm());
		return res;
	}
	void set(vector x) {
		this->position = x;
	}
	void set(double x, double y, double z) {
		this->position.x = x;
		this->position.y = y;
		this->position.z = z;
	}
};

