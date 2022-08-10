#include "RasterSurface.h"
#include "rasterization.h"
#include "XTime.h"
#include<ctime>
// these will be initialized at the bottom of this file
unsigned int image_width = 0;
unsigned int image_height = 0;
double timePassed = 0;
const unsigned int* image_pixels = nullptr; // 4 byte bgra color assumed
// info about this application

//unsigned int screen_array[480000]; // on heap
// create a window and display the image in the center

int main() {
#pragma region MyRegion
	//// we will assume the target image is smaller than this. (bad practice!)
	//Vertex pointA;
	//Vertex pointB;
	//Vertex pointC;
	//pointA.x = 0;
	//pointA.y = 0;
	//pointA.z = 0;
	//pointA.w = 1;
	//pointA.color = 0xFFFFFFFF;

	//pointB.x = 0.3;
	//pointB.y = 0;
	//pointB.z = 0;
	//pointB.w = 0;
	//pointB.color = 0xFFFFFFFF;

	//pointC.x = 0.15;
	//pointC.y = 0.2;
	//pointC.z = 0;
	//pointC.w = 0;
	//pointC.color = 0xFFFFFFFF;

	//
	//Vertex check;
	//check.x = 1;
	//check.y = 2;
	//check.z = 3;
	//check.w = 4;

	//Matrix4x4 worldMatrix = { 0 };
	//Matrix4x4 b = {1,0,0,0,0,0.309,0.951,0,0,-0.951,0.309,0,7,-2.282,9.153,1 };
	//inverseMatrix(b);

	//
	//

	//Vertex o;
	//
	//worldMatrix = translateMatrix(worldMatrix, 0, 0.25, 0);
	//o = MultiplyMatrixVertex(check, b);
#pragma endregion

	Matrix4x4 worldMatrix = { 0 };
	Matrix4x4 b = {1,0,0,0,0,0.309,0.951,0,0,-0.951,0.309,0,7,-2.282,9.153,1 };
	b = inverseMatrix(b);
	XTime timer;

	SV_WorldMatrix = identityMatrix();
	SV_ProjectionMatrix = identityMatrix();
	SV_ViewMatrix = identityMatrix();


	// CAMERA
	SV_ViewMatrix = identityMatrix();
	SV_ViewMatrix = mulMat(translateMatrix(0, 0, -1), XRotationFourByFour(SV_ViewMatrix, -18.0f));
	SV_ViewMatrix = inverseMatrix(SV_ViewMatrix); 

	// Building perspective
	float yScale = 1 / tanf(DegreeToRadians(90 * 0.5f));
	float xScale = yScale * (screen_height / screen_width);
	float zScale = 10.0f / (10.0f - 0.1f);
	float wScale = -(10.0f * 0.1f) / (10.0f - 0.1f);

	SV_ProjectionMatrix = identityMatrix();
	SV_ProjectionMatrix = { xScale, 0, 0, 0,
							0, yScale, 0, 0,
							0, 0, zScale, 1,
							0, 0, wScale, 0 };

	
	timer.Restart();
	Matrix4x4 translate;
	Matrix4x4 rotate;
	RS_Initialize("Shubhankar_Katekari", screen_width, screen_height);
	do {

		setToColor(0x00000000);
		timer.Signal();
		
		VertexShader = VS_World;
		PixelShader = PS_White;
		SV_WorldMatrix = identityMatrix();
		
		for (int i = 0; i < 43; i += 2)
		{
			parametricLineDraw(gridLines[i], gridLines[i + 1]);
		}

		timePassed += timer.Delta();

		VertexShader = VS_World;
		PixelShader = PS_GREEN;

		translate = translateMatrix(0, 0.25, 0);
		rotate = YRotationFourByFour(timePassed*25);

		SV_WorldMatrix = mulMat(translate, rotate);

		for (int i = 0; i < 24; i += 2)
		{
			parametricLineDraw(cube[i], cube[i + 1]);
		}

	} while (RS_Update(screen_array, sizeof(screen_array) >> 2));
	RS_Shutdown();

}