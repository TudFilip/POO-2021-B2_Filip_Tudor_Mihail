#include "Canvas.h"

Canvas::Canvas(int w, int h)
{
	matrix[h][w];
	width = w;
	height = h;

	int i, j;
	for (i = 0; i <= h; i++)
		for (j = 0; j <= w; j++)
			matrix[i][j] = 32;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x - ray<0 || x + ray>width || y - ray<0 || y + ray>height)
		cout << "Nu se poate desena cercul la coordonatele " << x << " si " << y << " si cu raza de " << ray << '\n';
	else
	{
		int i, j;
		for (i = x - ray; i <= x + ray; i++)
			for (j = y - ray; j <= y + ray; j++)
				if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
					matrix[j][i] = ch;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x - ray<0 || x + ray>width || y - ray<0 || y + ray>height)
		cout << "Nu se poate desena cercul la coordonatele " << x << " si " << y << " si cu raza de " << ray << '\n';
	else
	{
		int i, j;
		for (i = x - ray; i <= x + ray; i++)
			for (j = y - ray; j <= y + ray; j++)
				if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
					matrix[j][i] = ch;
	}
}

void Canvas::Print()
{
	int i, j;
	for (i = 0; i <= width; i++)
	{
		for (j = 0; j <= height; j++)
			cout << matrix[j][i] << ' ';
		cout << '\n';
	}
}

void Canvas::Clear()
{
	int i, j;
	for (i = 0; i <= width; i++)
		for (j = 0; j <= height; j++)
			matrix[j][i] = 32;
}