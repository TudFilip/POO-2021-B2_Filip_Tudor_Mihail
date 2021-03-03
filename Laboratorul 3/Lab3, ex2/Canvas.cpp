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

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || left > width || top < 0 || top > height || right < 0 || right > width || bottom < 0 || bottom > height)
		cout << "Nu se poate desena paralelogramul la coordonatele date" << '\n';
	else
	{
		if (left > right)
		{
			int tmp = left;
			left = right;
			right = tmp;
		}
		if (top > bottom)
		{
			int tmp = top;
			top = bottom;
			bottom = tmp;
		}

		int i, j;
		for (i = left; i <= right; i++)
			matrix[top][i] = ch;
		for (i = top; i <= bottom; i++)
			matrix[i][right] = ch;
		for (i = right; i >= left; i--)
			matrix[bottom][i] = ch;
		for (i = bottom; i >= top; i--)
			matrix[i][left] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || left > width || top < 0 || top > height || right < 0 || right > width || bottom < 0 || bottom > height)
		cout << "Nu se poate desena paralelogramul la coordonatele date" << '\n';
	else
	{
		if (left > right)
		{
			int tmp = left;
			left = right;
			right = tmp;
		}
		if (top > bottom)
		{
			int tmp = top;
			top = bottom;
			bottom = tmp;
		}

		int i, j;
		for (i = top; i <= bottom; i++)
			for (j = left; j <= right; j++)
				matrix[i][j] = ch;
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, sx, sy, err, e2;
	dx = abs(x2 - x1);
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	dy = -abs(y2 - y1);
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (1)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = err * 2;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::Print()
{
	int i, j;
	for (i = 0; i <= width; i++)
	{
		for (j = 0; j <= height; j++)
			cout << matrix[i][j] << ' ';
		cout << '\n';
	}
}

void Canvas::Clear()
{
	int i, j;
	for (i = 0; i <= width; i++)
		for (j = 0; j <= height; j++)
			matrix[i][j] = 32;
}