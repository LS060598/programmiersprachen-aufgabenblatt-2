#include "Mat2.hpp"
#include "Mat2.hpp"
#include <cmath>
#include <iostream>

//User construktor
Mat2::Mat2(float a, float b, float c, float d) :
	v10_{a},
	v11_{b},
	v20_{c},
	v21_{d} {}

//Default construktor -> Einheitsmatrix
Mat2::Mat2() :
	v10_{1.0f},
	v11_{0.0f},
	v20_{0.0f},
	v21_{1.0f} {}

//Matrizenmultiplikaton
Mat2& Mat2::operator *= (Mat2 const& v)
{
	float old_v10 = v10_;
	float old_v11 = v11_;
	float old_v20 = v20_;
	float old_v21 = v21_;

	v10_ = old_v10 * v.v10_ + old_v11 * v.v20_;
	v11_ = old_v10 * v.v11_ + old_v11 * v.v21_;

	v20_ = old_v20 * v.v10_ + old_v21 * v.v20_;
	v21_ = old_v20 * v.v11_ + old_v21 * v.v21_;

	return *this;
}

//Matrizenmultiplikation
Mat2 operator * (Mat2 const& u, Mat2 const& v)
{
	Mat2 result;

	result.v10_ = u.v10_ * v.v10_ + u.v11_ * v.v20_;
	result.v11_ = u.v10_ * v.v11_ + u.v11_ * v.v21_;

	result.v20_ = u.v20_ * v.v10_ + u.v21_ * v.v20_;
	result.v21_ = u.v20_ * v.v11_ + u.v21_ * v.v21_;

	return result;
}


//Determinante berechnen
float Mat2::det() const
{
	return (v10_*v21_ - v20_*v11_);
}

//Matrix * Vektor
Vec2 operator *( Mat2 const & m , Vec2 const & v )
{
	Vec2 result;

	result.x_ = m.v10_ * v.x_ + m.v11_ * v.y_;
	result.y_ = m.v20_ * v.x_ + m.v21_ * v.y_;

	return result;
}

Vec2 operator *( Vec2 const & v , Mat2 const & m )
{
	return m*v;
}

//Inverse berechnen
Mat2 inverse ( Mat2 const & m )
{
	if (m.det() == 0.0f)
	{
		std::cout << "Fehler: Matrix ist nicht invertierbar, det = 0";
		return m;
	}
	else
	{
		Mat2 res{};
		float det = m.det();

		res.v10_ = m.v21_ / det;
	 	res.v11_ = -m.v11_ / det;
		res.v20_ = -m.v20_ / det;
		res.v21_ = m.v10_ / det;

		return res;
	}
}

// Matrix transponieren
Mat2 transpose ( Mat2 const & m )
{
	Mat2 result = m;

	result.v11_ = m.v20_;
	result.v20_ = m.v11_;

	return result;
}

//Rotationsmatrix von Winkel in Bogenmaß
Mat2 make_rotation_mat2 ( float phi )
{
	return Mat2 {(float)cos(phi), (float)sin(phi),
				-1.0f * (float)sin(phi), (float)cos(phi)};
}