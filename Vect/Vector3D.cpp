#include "pch.h"
#include "Vector3D.h"
#include <iostream>
#include<assert.h>
#include<string>
using namespace std;

namespace Algebra {
    Vector3D::Vector3D(double x, double y, double z)
    {
        this->vect[0] = x;
        this->vect[1] = y;
        this->vect[2] = z;
    }

    void Vector3D::print() const
    {
        cout << "(" << this->vect[0] << "," << this->vect[1] << "," << this->vect[2] << ")." << endl;
    }

    double Vector3D::at(int x)
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

    double& Vector3D::operator[](int i)
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

    bool Vector3D::operator==(const Vector3D& v)const
    {
        for (int i = 0; i < 3; i++) {
            if (this->vect[i] != v.vect[i])    return false;
        }
        return false;
    }

    bool Vector3D::operator!=(const Vector3D& v)const
    {
        return !(*this == v);
    }
}
