#include <cmath>
#include <iostream>
#include <string>

class vector {
public:
	double component[3];
	double &x= component[0];
	double &y= component[1];
	double &z= component[2];
	void operator=(vector a) {
		for (int i = 0;i < 3;i++) {
			this->component[i] = a.component[i];
		}
	}
//vector() {
//			component[0] = 0;
//			component[1] = 0;
//			component[2] = 0;
//			x = 0;
//			y = 0;
//			z = 0;
//		 }
	std::string to_string() {
		std::string res = std::to_string(this->x) + '\t' + std::to_string(this->y) + '\t' + std::to_string(this->z);
		return res;
	}
	double sqrNorm() {
		return (this->x) * (this->x) + (this->y) * (this->y) + (this->z) * (this->z);
	};
	double Norm() {
		return sqrt(this->sqrNorm());
	};
	vector operator + (vector a) {
		vector b;
		b.x = a.x + this->x;
		b.y = a.y + this->y;
		b.z = a.z + this->z;
		return b;
	};
	vector operator - (vector a) {
		vector b;
		b.x = this->x - a.x;
		b.y = this->y - a.y;
		b.z = this->z - a.z;
		return b;
	};
	vector operator * (double a) {
		vector b;
		b.x = this->x * a;
		b.y = this->y * a;
		b.z = this->z * a;
		return b;
	};
	vector operator / (double a) {
		vector b;
		b.x = this->x / a;
		b.y = this->y / a;
		b.z = this->z / a;
		return b;
	};
	double operator *(vector a) {
		double b;
		b = this->x * a.x + this->y * a.y + this->z * a.z;
		return b;
	}
	void normalize() {
		double N = this->Norm();
		this->x = this->x / N;
		this->y = this->y / N;
		this->z = this->z / N;
	}
	void setUnitVector(double phi, double psi) {
		this->x = cos(phi) * sin(psi);
		this->y = sin(phi) * sin(psi);
		this->z = cos(psi);
	}
	void set(vector a) {
		this->x = a.x;
		this->y = a.y;
		this->z = a.z;
	}
	void set(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	void zero() {
		this->set(0, 0, 0);
	}
	vector X (vector a) {
		vector res;
		res.x = this->y * a.z - this->z * a.y;
		res.y = a.x * this->z - a.z * this->x;
		res.z = this->x * a.y - this->y * a.x;
		return res;
	}
	void print() {
		std::cout << this->x << '\t' << this->y << '\t' << this->z << std::endl;
		
	}
};



