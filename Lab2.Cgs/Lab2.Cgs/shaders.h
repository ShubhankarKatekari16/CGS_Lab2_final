#pragma once
#include "mathCalculation.h"



// vertex & pixel
void (*VertexShader)(Vertex&) = 0;
void (*PixelShader)(unsigned int&) = 0;

// Shader matrix
Matrix4x4 SV_WorldMatrix;
Matrix4x4 SV_ViewMatrix;
Matrix4x4 SV_ProjectionMatrix;



void VS_World(Vertex& mult)
{
    mult = MultiplyMatrixVertex(mult, SV_WorldMatrix);
    mult = MultiplyMatrixVertex(mult, SV_ViewMatrix);
    mult = MultiplyMatrixVertex(mult, SV_ProjectionMatrix);

    // Divide by w
    mult.x = mult.x / mult.w;
    mult.y = mult.y / mult.w;
    mult.z = mult.z / mult.w;
}

// // Basic pixel shader returns the color white
void PS_White(unsigned int& makeWhite)
{
    makeWhite = 0xFFFFFFFF;
}

void PS_GREEN(unsigned int& color)
{
    color = 0x7FFFD4;
    //color = 0x008000;
}




