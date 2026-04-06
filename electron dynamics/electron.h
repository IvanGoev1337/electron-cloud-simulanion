#pragma once

#include "vector.cpp"
const double m_e = 1;
const double q_e = -1;
class electron
{
public:
	vector position;
	vector velociti;
	void newStep(double dt, vector force) {
		this->position = this->position + this->velociti * dt;
		this->velociti = this->velociti + force * dt / m_e;
	}
	vector getElectricField(vector x) {
		vector delta = x - this->position;
		vector res = delta * q_e / (delta.sqrNorm()  * delta.Norm());
		return res;
	}
	void set(vector x, vector v) {
		this->position = x;
		this->velociti = v;
	}
	std::string to_string() {
		std::string res =this->position.to_string() + '\t' + this->velociti.to_string();
		return res;
	}
	void print() {
		std::cout << this->to_string() << std::endl;
	}
};

