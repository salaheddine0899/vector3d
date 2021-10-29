#pragma once
namespace Algebra {
	class Vector3D
	{
	private:
		double vect[3];
	public:
		Vector3D(double x = 0, double y = 0, double z = 0);
		Vector3D(const Vector3D&) = delete;
		void print() const;
		double at(int);
		double& operator[](int i);
		Vector3D operator=(const Vector3D&) = delete;
		bool operator==(const Vector3D&)const;
		bool operator!=(const Vector3D&) const;

	};
}

