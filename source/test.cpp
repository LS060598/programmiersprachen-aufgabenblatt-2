

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "vec2.hpp"
#include "Mat2.hpp"
#include "color.hpp"
#include "circel.hpp"
#include "rectangel.hpp"

#include <iostream>
#include <cmath>

/*
 Vec2 Constructors
*/


TEST_CASE("custom_constructor", "[custom_constructor]")
{
	Vec2 v1{1.5f,1.5f};
	REQUIRE(1.5f == v1.x_);
	REQUIRE(1.5f == v1.y_);
}

TEST_CASE("default_constructor", "[default_constructor]")
{
	Vec2 v2;
	REQUIRE(0.0f == v2.x_);
	REQUIRE(0.0f == v2.y_);
}

/*
 Vec2 Operator Overloading
*/

TEST_CASE("plus_operator", "[plus_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	
	Vec2 result1 = v0 + v2;
	Vec2 result2 = v1 + v2;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(-2.0f == result1.y_);
	
	REQUIRE(1.0f == result2.x_);
	REQUIRE(0.0f == result2.y_);
}

TEST_CASE("minus_operator", "[minus_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	
	Vec2 result1 = v0-v2;
	Vec2 result2 = v1-v2;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(2.0f == result1.y_);
	
	REQUIRE(1.0f == result2.x_);
	REQUIRE(4.0f == result2.y_);
}

TEST_CASE("skalar_mult_operator", "[skalar_mult_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	Vec2 result1 = v0*s;
	Vec2 result2 = v1*s;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);
	
	REQUIRE(5.0f == result2.x_);
	REQUIRE(10.0f == result2.y_);
}

TEST_CASE("division_operator", "[division_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;
	float zero = 0.0f;

	Vec2 result1 = v0/s;
	Vec2 result2 = v1/s;
	Vec2 result3 = v0/zero;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);

	REQUIRE(0.2f == result2.x_);
	REQUIRE(0.4f == result2.y_);

	REQUIRE(0.0f == result3.x_);
	REQUIRE(0.0f == result3.y_);
	
}

TEST_CASE("mult_operator_skalar_first", "[mult_operator_skalar_first]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	Vec2 result1 = v0*s;
	Vec2 result2 = v1*s;

	REQUIRE(0.0f == result1.x_);
	REQUIRE(0.0f == result1.y_);
	
	REQUIRE(5.0f == result2.x_);
	REQUIRE(10.0f == result2.y_);
}

TEST_CASE("plusgleich_operator", "[plusgleich_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 += v1;
	v1 += v2;

	REQUIRE(1.0f == v0.x_);
	REQUIRE(2.0f == v0.y_);
	
	REQUIRE(1.0f == v1.x_);
	REQUIRE(0.0f == v1.y_);
}

TEST_CASE("minusgleich_operator", "[minusgleich_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 -= v1;
	v1 -= v2;

	REQUIRE(-1.0f == v0.x_);
	REQUIRE(-2.0f == v0.y_);
	
	REQUIRE(1.0f == v1.x_);
	REQUIRE(4.0f == v1.y_);
}

	
TEST_CASE("multgleich_operator", "[multgleich_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;

	v0 *= s;
	v1 *= s;

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
	REQUIRE(5.0f == v1.x_);
	REQUIRE(10.0f == v1.y_);
}

TEST_CASE("divgleich_operator", "[divgleich_operator]")
{
	Vec2 v0;
	Vec2 v1{1.0f,2.0f};
	Vec2 v2{0.0f,-2.0f};
	float s = 5.0f;
	float zero = 0.0f;

	v0 /= s;
	v1 /= s;
	v2 /= zero;

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
	REQUIRE(0.2f == v1.x_);
	REQUIRE(0.4f == v1.y_);

	REQUIRE(0.0f == v0.x_);
	REQUIRE(0.0f == v0.y_);
	
}

/*
 Matrix Constructors
*/

TEST_CASE("default_construktor_matrix", "[default_construktor_matrix]")
{
	Mat2 mat0 {};
	
	REQUIRE(1.0f == mat0.v10_);
	REQUIRE(0.0f == mat0.v11_);
	REQUIRE(0.0f == mat0.v20_);
	REQUIRE(1.0f == mat0.v21_);	
}

TEST_CASE("user_construktor_operator_matrix", "[user_construktor_operator_matrix]")
{
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,1.5,-1};

	REQUIRE(1.0f == mat1.v10_);
	REQUIRE(2.0f == mat1.v11_);
	REQUIRE(3.0f == mat1.v20_);
	REQUIRE(4.0f == mat1.v21_);
	
	REQUIRE(0.0f == mat2.v10_);
	REQUIRE(0.5f == mat2.v11_);
	REQUIRE(1.5f == mat2.v20_);
	REQUIRE(-1.0f == mat2.v21_);
}

/*
 Matrix Multiplikation
*/

TEST_CASE("multlgleich_operator_matrix", "[multlgleich_operator_matrix]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	mat0 *= mat1;
	mat1 *= mat2;

	REQUIRE(1.0f == mat0.v10_);
	REQUIRE(2.0f == mat0.v11_);
	REQUIRE(3.0f == mat0.v20_);
	REQUIRE(4.0f == mat0.v21_);
	
	REQUIRE(0.2f == mat1.v10_);
	REQUIRE(-1.5f == mat1.v11_);
	REQUIRE(0.4f == mat1.v20_);
	REQUIRE(-2.5f == mat1.v21_);
}


TEST_CASE("mult_operator_matrix", "[mult_operator_matrix]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Mat2 res1 = mat0 * mat1;
	Mat2 res2 = mat1 * mat2;

	REQUIRE(1.0f == res1.v10_);
	REQUIRE(2.0f == res1.v11_);
	REQUIRE(3.0f == res1.v20_);
	REQUIRE(4.0f == res1.v21_);
	
	REQUIRE(0.2f == res2.v10_);
	REQUIRE(-1.5f == res2.v11_);
	REQUIRE(0.4f == res2.v20_);
	REQUIRE(-2.5f == res2.v21_);
}


/*
 Matrix * Vektor and Vetor * Matrix
*/

TEST_CASE("matrix*vektor", "[matrix*vektor]")
{
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Vec2 vec1 {1,2};

	Vec2 res1 = mat1 * vec1;
	Vec2 res2 = mat2 * vec1;

	REQUIRE(5.0f == res1.x_);
	REQUIRE(11.0f == res1.y_);
	
	REQUIRE(1.0f == res2.x_);
	REQUIRE(-1.9f == res2.y_);
}


TEST_CASE("vektor*matrix", "[vektor*matrix]")
{
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Vec2 vec1 {1,2};

	Vec2 res1 = vec1 * mat1;
	Vec2 res2 = vec1 * mat2;

	REQUIRE(5.0f == res1.x_);
	REQUIRE(11.0f == res1.y_);
	
	REQUIRE(1.0f == res2.x_);
	REQUIRE(-1.9f == res2.y_);
}


/*
 Matrix
Determinante, Inverse,
Transponierte, Rotationsmatrix
*/


TEST_CASE("det_matrix", "[det_matrix]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	REQUIRE(1.0f == mat0.det());
	REQUIRE(-2.0f == mat1.det());
	REQUIRE(-0.05f == mat2.det());
}

TEST_CASE("transpose_matrix", "[transpose_matrix]")
{
	Mat2 mat0 {};
	Mat2 mat1 {1,2,3,4};
	Mat2 mat2 {0,0.5,0.1,-1};

	Mat2 res0 = transpose(mat0);
	Mat2 res1 = transpose(mat1);
	Mat2 res2 = transpose(mat2);

	REQUIRE(1.0f == res0.v10_);
	REQUIRE(0.0f == res0.v11_);
	REQUIRE(0.0f == res0.v20_);
	REQUIRE(1.0f == res0.v21_);

	REQUIRE(1.0f == res1.v10_);
	REQUIRE(3.0f == res1.v11_);
	REQUIRE(2.0f == res1.v20_);
	REQUIRE(4.0f == res1.v21_);
	
	REQUIRE(0.0f == res2.v10_);
	REQUIRE(0.1f == res2.v11_);
	REQUIRE(0.5f == res2.v20_);
	REQUIRE(-1.0f == res2.v21_);
}

TEST_CASE("inverse_matrix", "[inverse_matrix]")
{
	Mat2 mat0 {}; //mat0 ist nicht invertierbar, return mat0
	Mat2 mat1 {1.0f,2.0f,3.0f,4.0f};
	Mat2 mat2 {0,0.5,0.1,-1};
	
	std::cout << mat1.v10_;
	std::cout << mat1.v11_;
	std::cout << mat1.v20_;
	std::cout << mat1.v21_;


	Mat2 res0 = inverse(mat0);
	Mat2 erg = inverse(mat1);
	Mat2 res2 = inverse(mat2);

	std::cout << erg.v10_;
	std::cout << erg.v11_;
	std::cout << erg.v20_;
	std::cout << erg.v21_;

	REQUIRE(1.0f == res0.v10_);
	REQUIRE(0.0f == res0.v11_);
	REQUIRE(0.0f == res0.v20_);
	REQUIRE(1.0f == res0.v21_);

	REQUIRE(-2.0f == erg.v10_);
	REQUIRE(1.0f == erg.v11_);
	REQUIRE((3.0f/2.0f) == erg.v20_);
	REQUIRE((-1.0f/2.0f) == erg.v21_);

	REQUIRE(20.0f == res2.v10_);
	REQUIRE(10.0f == res2.v11_);
	REQUIRE(2.0f == res2.v20_);
	REQUIRE(0.0f == res2.v21_);
}

TEST_CASE("rotate_matrix", "[rotate_matrix]")
{
	Mat2 res1 = make_rotation_mat2(1.0f);

	REQUIRE(0.54030f == Approx(res1.v10_));
	REQUIRE(0.84147f == Approx(res1.v11_));
	REQUIRE(-0.84147f == Approx(res1.v20_));
	REQUIRE(0.54030f == Approx(res1.v21_));
}

/*
 Color Constructors
*/

TEST_CASE("construstors_color", "[construstors_color]")
{
	Color c1{0.5f};
	REQUIRE(0.5f == c1.r_);
	REQUIRE(0.5f == c1.g_);
	REQUIRE(0.5f == c1.b_);

	Color c2{0.0f, 0.5f, 1.0f};

	REQUIRE(0.0f == c2.r_);
	REQUIRE(0.5f == c2.g_);
	REQUIRE(1.0f == c2.b_);
}

/*
Circle Constructors
*/

TEST_CASE("constructor_getter_circle", "[constructor_getter_circle]")
{
	Circle c1
	{
		Vec2{1.0f,2.0f},
		5.0f,
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(1.0f == c1.getCenter().x_);
	REQUIRE(2.0f == c1.getCenter().y_);

	REQUIRE(5.0f == c1.getRadius());

	REQUIRE(0.5f == c1.getColor().r_);
	REQUIRE(0.5f == c1.getColor().g_);
	REQUIRE(0.5f == c1.getColor().b_);

}

/*
 Circle Circumference
*/

TEST_CASE("circumference_circle","[circumference_circle]")
{
	Circle c1
	{
		Vec2{1.0f,2.0f},
		5.0f,
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(31.415927f == Approx(c1.circumference()));
	
	Circle c2
	{
		Vec2{1.0f,2.0f},
		10.0f,
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(62.831853f == Approx(c2.circumference()));
}

/*
 Rectangle Constructors, Circumference
*/


TEST_CASE("constructor_getter_rectangle", "[constructor_getter_rectangle]")
{
	Rectangle c1
	{
		Vec2{1.0f,2.0f},
		Vec2{4.0f,5.0f},
		Color{0.5f,0.5f,0.5f}
	};

	REQUIRE(1.0f == c1.getMin().x_);
	REQUIRE(2.0f == c1.getMin().y_);

	REQUIRE(4.0f == c1.getMax().x_);
	REQUIRE(5.0f == c1.getMax().y_);

	REQUIRE(0.5f == c1.getColor().r_);
	REQUIRE(0.5f == c1.getColor().g_);
	REQUIRE(0.5f == c1.getColor().b_);

}


/*
 Rectangle Circumference
*/


TEST_CASE("circumference_rectangle", "[circumference_rectangle]")
{
	Rectangle c1
	{
		Vec2{1.0f,2.0f},
		Vec2{4.0f,5.0f},
		Color{0.5f,0.5f,0.5f}
	};
	
	REQUIRE(12.0f == Approx(c1.circumference()));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
