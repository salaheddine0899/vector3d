#pragma once
#include <iostream>
#include<assert.h>
#include<string>
#include<cmath>
using namespace std;
namespace Algebra {
	template<class T>
	class Vector3D
	{
	private:
		double vect[3];
	public:
		Vector3D(double x = 0, double y = 0, double z = 0);
		//Vector3D(const Vector3D&) = delete;
		void print() const;
		double at(int);
		double& operator[](int i);
		//Vector3D operator=(const Vector3D&);
		bool operator==(const Vector3D&)const;
		bool operator!=(const Vector3D&) const;
		double operator*(const Vector3D&) const;
		Vector3D& operator^(const Vector3D&);
		double norme();

	};

    template<class T>
    Vector3D<T>::Vector3D(double x, double y, double z)
    {
        this->vect[0] = x;
        this->vect[1] = y;
        this->vect[2] = z;
    }

    template<class T>
    void Vector3D<T>::print() const
    {
        cout << "(" << this->vect[0] << "," << this->vect[1] << "," << this->vect[2] << ")." << endl;
    }

    template<class T>
    double Vector3D<T>::at(int x)
    {
        assert(0 <= x && x < 3);
        try {
            if (x < 0 || x >= 3) throw "rang error";
            return this->vect[x];
        }
        catch (string e) {
            cout << e << endl;
        }
    }

    template<class T>
    double& Vector3D<T>::operator[](int i)
    {
        assert(0 <= i && i < 3);
        try {
            if (i < 0 || i >= 3) throw "rang error";
            return this->vect[i];
        }
        catch (string e) {
            cout << e << endl;
        }
    }

    template<class T>
    bool Vector3D<T>::operator==(const Vector3D& v)const
    {
        for (int i = 0; i < 3; i++) {
            if (this->vect[i] != v.vect[i])    return false;
        }
        return false;
    }

    template<class T>
    bool Vector3D<T>::operator!=(const Vector3D& v)const
    {
        return !(*this == v);
    }

    template<class T>
    double Vector3D<T>::operator*(const Vector3D& v) const
    {
        double res = 0;
        for (int i = 0; i < 3; i++)
            res += this->vect[i] * v.vect[i];
        return res;
    }

    template<class T>
    Vector3D<T>& Vector3D<T>::operator^(const Vector3D& v)
    {
        // TODO: insert return statement here.
        Vector3D* res = new Vector3D();
        res->vect[0] = this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1];
        res->vect[1] = this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2];
        res->vect[2] = this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0];

        return *res;
    }

    template<class T>
    double Vector3D<T>::norme()
    {

        return sqrt(pow(this->vect[0], 2) + pow(this->vect[1], 2) + pow(this->vect[2], 2));
    }
}

