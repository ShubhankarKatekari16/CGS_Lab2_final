#pragma once
#include "shaders.h"
unsigned int lerp(unsigned int src, unsigned int dst, float ratio)
{
	return (((int)dst - (int)src) * ratio + src);
}

void drawPixel(unsigned int x, unsigned int y, unsigned int Color)
{
	
	int iResultAlpha;
	if (x < screen_width && y < screen_height)
	{
		screen_array[twoDtoOneD(x, y, 500)] = Color;
	}
}
void parametricLineDraw(Vertex pointA, Vertex pointB)
{

	
	Vertex copy_start = pointA;
	Vertex copy_end = pointB;

	if (VertexShader)
	{
		VertexShader(copy_start);
		VertexShader(copy_end);
	}

	
	Vertex screen_start = NDCToScreen(copy_start);
	Vertex screen_end = NDCToScreen(copy_end);

	

	float xDiff = 0;
	float yDiff = 0;

	float differenceX = screen_start.x - screen_end.x;
	float differenceY = screen_start.y - screen_end.y;

	xDiff = abs(differenceX);
	yDiff = abs(differenceY);

	float total = fmaxf(xDiff, yDiff);

	unsigned int currColor = 0xFFFFFFFF;
	for (float i = 0; i < total; i++)
	{
		float ratio = i / total;
		Pixel pixelColor;
		pixelColor.color = currColor;
		if (PixelShader)
		{
			PixelShader(currColor);
		}
		int currX = lerp(screen_start.x, screen_end.x, ratio);
		int currY = lerp(screen_start.y, screen_end.y, ratio);
		drawPixel(currX, floor(currY + 0.5f), pixelColor.color);

	}
	
}

void DrawTriangle(Vertex a , Vertex b, Vertex c , short col = 0x000F)
{
	parametricLineDraw(a, b);
	parametricLineDraw(b, c);
	parametricLineDraw(c, a);
}

void setToColor(unsigned int imagePix)
{
    for (size_t i = 0; i < screen_width * screen_height; i++)
    {
        screen_array[i] = imagePix;
    }
}
