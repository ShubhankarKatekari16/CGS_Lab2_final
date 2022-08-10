#pragma once
#include "Definitions.h"

unsigned int twoDtoOneD(unsigned int x, unsigned int y, const unsigned int width)
{
	unsigned int TwoDtoOneD = (y * width) + x;
	return TwoDtoOneD;
}
Vertex NDCToScreen(Vertex cordinates_Vertex)
{
	Vertex newVertex;
	newVertex.x = (1 + cordinates_Vertex.x) * (screen_width / 2);
	newVertex.y = (1 - cordinates_Vertex.y) * (screen_height / 2);
	// 0.7 * 500 / 2
	return newVertex;
}


//Matrix4x4 MatXMat(Matrix4x4& a, Matrix4x4& b)
//{
//	Matrix4x4 mat;
//	
//	mat.m[0][0] = (a.m[0][0] * b.m[0][0]) + (a.m[0][1] * b.m[1][0]) + (a.m[0][2] * b.m[2][0]) + (a.m[0][3] * b.m[3][0]);
//	mat.m[0][1] = (a.m[0][0] * b.m[0][1]) + (a.m[0][1] * b.m[1][1]) + (a.m[0][2] * b.m[2][1]) + (a.m[0][3] * b.m[3][1]);
//	mat.m[0][2] = (a.m[0][0] * b.m[0][2]) + (a.m[0][1] * b.m[1][2]) + (a.m[0][2] * b.m[2][2]) + (a.m[0][3] * b.m[3][2]);
//	mat.m[0][3] = (a.m[0][0] * b.m[0][3]) + (a.m[0][1] * b.m[1][3]) + (a.m[0][2] * b.m[2][3]) + (a.m[0][3] * b.m[3][3]);
//
//	mat.m[1][0] = (a.m[1][0] * b.m[0][0]) + (a.m[1][1] * b.m[1][0]) + (a.m[1][2] * b.m[2][0]) + (a.m[1][3] * b.m[3][0]);
//	mat.m[1][1];
//	mat.m[1][2];
//	mat.m[1][3];
//	return a;
//}

Matrix4x4 mulMat(Matrix4x4 a, Matrix4x4 b) 
{
	Matrix4x4 ans;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ans.m[i][j] = 0;

			for (int k = 0; k < 4; k++) {
				ans.m[i][j] += a.m[i][k] * b.m[k][j];
			}

			
		}
	}
	return ans;
}

Matrix3x3 ThreeByThreeMult(Matrix3x3& arrOne, Matrix3x3& arrTwo)
{
	Matrix3x3 retArr;

	// Row 0
	retArr.m[0][0] = (arrOne.m[0][0] * arrTwo.m[0][0]) + (arrOne.m[0][1] * arrTwo.m[1][0]) + (arrOne.m[0][2] * arrTwo.m[2][0]);
	retArr.m[0][1] = (arrOne.m[0][0] * arrTwo.m[0][1]) + (arrOne.m[0][1] * arrTwo.m[1][1]) + (arrOne.m[0][2] * arrTwo.m[2][1]);
	retArr.m[0][2] = (arrOne.m[0][0] * arrTwo.m[0][2]) + (arrOne.m[0][1] * arrTwo.m[1][2]) + (arrOne.m[0][2] * arrTwo.m[2][2]);
	// Row 1
	retArr.m[1][0] = (arrOne.m[1][0] * arrTwo.m[0][0]) + (arrOne.m[1][1] * arrTwo.m[1][0]) + (arrOne.m[1][2] * arrTwo.m[2][0]);
	retArr.m[1][1] = (arrOne.m[1][0] * arrTwo.m[0][1]) + (arrOne.m[1][1] * arrTwo.m[1][1]) + (arrOne.m[1][2] * arrTwo.m[2][1]);
	retArr.m[1][2] = (arrOne.m[1][0] * arrTwo.m[0][2]) + (arrOne.m[1][1] * arrTwo.m[1][2]) + (arrOne.m[1][2] * arrTwo.m[2][2]);
	// Row 2
	retArr.m[2][0] = (arrOne.m[2][0] * arrTwo.m[0][0]) + (arrOne.m[2][1] * arrTwo.m[1][0]) + (arrOne.m[2][2] * arrTwo.m[2][0]);
	retArr.m[2][1] = (arrOne.m[2][0] * arrTwo.m[0][1]) + (arrOne.m[2][1] * arrTwo.m[1][1]) + (arrOne.m[2][2] * arrTwo.m[2][1]);
	retArr.m[2][2] = (arrOne.m[2][0] * arrTwo.m[0][2]) + (arrOne.m[2][1] * arrTwo.m[1][2]) + (arrOne.m[2][2] * arrTwo.m[2][2]);

	return retArr;
};



Vertex MultiplyMatrixVector(Vertex& i,  Matrix4x4& m)
{
	Vertex o;
	o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
	o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
	o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
	o.w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

	return o;
}

Matrix4x4 identityMatrix()
{
	Matrix4x4 matIdentity;
	// row 1
	matIdentity.m[0][0] = 1; //[X][X]
	matIdentity.m[0][1] = 0;
	matIdentity.m[0][2] = 0;
	matIdentity.m[0][3] = 0;
	// row 2
	matIdentity.m[1][0] = 0; 
	matIdentity.m[1][1] = 1; //[Y][Y]
	matIdentity.m[1][2] = 0;
	matIdentity.m[1][3] = 0;
	// row 3
	matIdentity.m[2][0] = 0;
	matIdentity.m[2][1] = 0;
	matIdentity.m[2][2] = 1; //[Z][Z]
	matIdentity.m[2][3] = 0;
	// row 4
	matIdentity.m[3][0] = 0;
	matIdentity.m[3][1] = 0;
	matIdentity.m[3][2] = 0;
	matIdentity.m[3][3] = 1; //[W][W]

	return matIdentity;
}



Matrix4x4 translateMatrix( float x, float y, float z)
{
	
	
	//LOCAL
	//TRANSLATION MATRIX USING X Y Z
	Matrix4x4 translation = identityMatrix();
	translation.m[3][0] = x;
	translation.m[3][1] = y;
	translation.m[3][2] = z;
	
	//RETURN MATRIX
	return translation;
}




Vertex MultiplyMatrixVertex(Vertex& i,  Matrix4x4& m)
{
	Vertex o;
	o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + i.w * m.m[3][0];
	o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + i.w * m.m[3][1];
	o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + i.w * m.m[3][2];
	o.w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + i.w * m.m[3][3];

	return o;
}

double DegreeToRadians(float degree)
{
	float pi = 3.14159265359;
	return (degree * (pi / 180));
}

//ROTATIONS
Matrix4x4 XRotationFourByFour(Matrix4x4& Matrix, float degree)
{
	
	Matrix.m[1][1] = cosf(DegreeToRadians(degree));
	Matrix.m[1][2] = -sinf(DegreeToRadians(degree));
	Matrix.m[2][1] = sinf(DegreeToRadians(degree));
	Matrix.m[2][2] = cosf(DegreeToRadians(degree));

	return Matrix;
}




Matrix4x4 YRotationFourByFour( float degree)
{
	Matrix4x4 Matrix = identityMatrix();
	Matrix.m[0][0] = cosf(DegreeToRadians(degree));
	Matrix.m[0][2] = sinf(DegreeToRadians(degree));
	Matrix.m[2][0] = -sinf(DegreeToRadians(degree));
	Matrix.m[2][2] = cosf(DegreeToRadians(degree));

	return Matrix;
}
Matrix4x4 ZRotationFourByFour( float radians)
{
	Matrix4x4 matrix;
	matrix.m[0][0] = cosf(DegreeToRadians(radians));
	matrix.m[0][1] = -sinf(DegreeToRadians(radians));
	matrix.m[1][0] = sinf(DegreeToRadians(radians));
	matrix.m[1][1] = cosf(DegreeToRadians(radians));

	return matrix;
}

Matrix4x4 transpose(Matrix4x4 mat)
{
	Matrix4x4 transMatrix = mat;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			transMatrix.m[j][i] = mat.m[i][j];
		}
	}
	transMatrix.m[3][0] = 0;
	transMatrix.m[3][1] = 0;
	transMatrix.m[3][2] = 0;
	transMatrix.m[3][3] = 1;
	transMatrix.m[0][3] = 0;
	transMatrix.m[1][3] = 0;
	transMatrix.m[2][3] = 0;

	return transMatrix;
}
float DotProduct(Vertex v1, const Vertex v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}
Vertex convertToVertex(const Matrix4x4 mIn, int num)
{
	Vertex vert;
	if (num == 0)
	{
		 vert.x = mIn.m[0][0];
		 vert.y = mIn.m[0][1];
		 vert.z = mIn.m[0][2];
		 vert.w = mIn.m[0][3];
	}
	if (num == 1)
	{
		  vert.x = mIn.m[1][0];
		  vert.y = mIn.m[1][1];
		  vert.z = mIn.m[1][2];
		  vert.w = mIn.m[1][3];
	}
	if (num == 2)
	{
		 vert.x = mIn.m[2][0];
		 vert.y = mIn.m[2][1];
		 vert.z = mIn.m[2][2];
		 vert.w = mIn.m[2][3];
	}
	if (num == 3)
	{
		 vert.x = mIn.m[3][0];
		 vert.y = mIn.m[3][1];
		 vert.z = mIn.m[3][2];
		 vert.w = mIn.m[3][3];
	}
	return vert;
}
Matrix4x4 inverseMatrix(const Matrix4x4& mIn)
{
	/*
				matrix OrthonormalInverse(const matrix &mIn)
		{
			matrix m;
			m = 3x3 transpose of mIn;
			set default 0.0s and 1.0s for the .w components of m;
			// calculate new position:
			m.AxisW.x  = -DotProduct(mIn.AxisX, mIn.AxisW);  // float3 dot product, not float 4
			m.AxisW.y  = -DotProduct(mIn.AxisY, mIn.AxisW);  // float3 dot product, not float 4 
			m.AxisW.z  = -DotProduct(mIn.AxisZ, mIn.AxisW);  // float3 dot product, not float 4

			return m;
		}
	
	*/


	Matrix4x4 m;

	m = transpose(mIn);
	
	m.m[3][0] = -DotProduct(convertToVertex(mIn, 0), convertToVertex(mIn, 3));  // float3 dot product, not float 4
	m.m[3][1] = -DotProduct(convertToVertex(mIn, 1), convertToVertex(mIn, 3));  // float3 dot product, not float 4 
	m.m[3][2] = -DotProduct(convertToVertex(mIn, 2), convertToVertex(mIn, 3)); // float3 dot product, not float 4
	
	return m;
}

Matrix3x3 ThreeByThreeTranspose(Matrix4x4& arrOne)
{
	Matrix3x3 retArr;

	// row 1
	retArr.m[0][0] = arrOne.m[0][0];
	retArr.m[0][1] = arrOne.m[1][0];
	retArr.m[0][2] = arrOne.m[2][0];
	// row 2
	retArr.m[1][0] = arrOne.m[0][1];
	retArr.m[1][1] = arrOne.m[1][1];
	retArr.m[1][2] = arrOne.m[2][1];
	// row 3
	retArr.m[2][0] = arrOne.m[0][2];
	retArr.m[2][1] = arrOne.m[1][2];
	retArr.m[2][2] = arrOne.m[2][2];

	return retArr;
}

Vertex VertexThreeByThreeMult(Vertex& vertex, Matrix3x3& arrOne)
{
	Vertex retVert;

	retVert.x = (arrOne.m[0][0] * vertex.x) + (arrOne.m[1][0] * vertex.y) + (arrOne.m[2][0] * vertex.z);
	retVert.y = (arrOne.m[0][1] * vertex.x) + (arrOne.m[1][1] * vertex.y) + (arrOne.m[2][1] * vertex.z);
	retVert.z = (arrOne.m[0][2] * vertex.x) + (arrOne.m[1][2] * vertex.y) + (arrOne.m[2][2] * vertex.z);

	return retVert;
}


