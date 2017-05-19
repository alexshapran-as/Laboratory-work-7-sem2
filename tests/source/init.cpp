#include <Laboratory-work-7-sem2.hpp>
#include <catch.hpp>

SCENARIO ("default"){
	Matrix<double> mat;
	REQUIRE (mat.rows == 0);
	REQUIRE (mat.columns == 0);
}

SCENARIO ("Matrix"){
	double** element;
	Matrix<double> mat(2,2,element);
	REQUIRE (mat.rows == mat.columns);
}
/*SCENARIO("addTest","[!mayfail]"){
	Matrix<int> mat3(3,3);
	std::ifstream("mat3");
	
	Matrix<int> mat4(3,3);
	std::ifstream ("mat4") >> mat4;
	
	Matrix<int> matRes(3,3);
	std::ifstream("addRes") >> matRes;
	
	REQUIRE ((mat3 + mat4) == matRes);
}

SCENARIO("multiTest","[!mayfail]"){
	Matrix<int> mat1(2,3);
	Matrix<int> mat2(3,2);
	
	std::ifstream("mat1") >> mat1;
	std::ifstream("mat2") >> mat2;
	
	Matrix<int> res(2,2);
	std::ifstream("multRes") >> res;
	
	REQUIRE((mat1*mat2) == res);
}

SCENARIO("op="){
	Matrix<int> mat1(2,2);
	Matrix<int> mat2 = mat1;
	REQUIRE (mat1 == mat2);
}

SCENARIO("op=="){
	Matrix<int> mat1(2,2);
	Matrix<int> mat2(2,2);
	
	REQUIRE(mat1 == mat2);
}
SCENARIO("fillMat","[!mayfail]"){
	Matrix<int> mat3(3,3);
	Matrix<int> mat3fill(3,3);
	std::ifstream("mat3") >> mat3;
	mat3fill.fillMatrix("mat3");
	REQUIRE(mat3 == mat3fill);
}*/
