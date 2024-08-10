#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <algorithm>

class Line {
private:

public:

	int x1, x2, y1, y2, steps, dx, dy;
	//Circulo completo por medio de DDA
	void DrawCirculeDDA(int xa, int ya, int radiou, Color color) {
		int angleStep = 10;
		for (int angle = 0; angle < 180; angle += angleStep) {
			float radIni = angle * (PI / 180.0f);
			float radFin = (angle + 180) * (PI / 180.0f);
			// Puntos iniciales y finales de la línea
			int xi = xa + radiou * cosf(radIni);
			int yi = ya + radiou * sinf(radIni);
			int xf = xa + radiou * cosf(radFin);
			int yf = ya + radiou * sinf(radFin);
			DrawLineDDA(xi, yi, xf, yf, color);
		}
	}
	//Circulo hecho por lineas de DDA
	void DrawCirculeDDShape(int xa, int ya, int radiou, Color color) {
		int angleStep = 10;
		for (int angle = 0; angle < 360; angle += angleStep) {

			float radIni = angle * (PI / 180.0f);
			int xi = xa + radiou * cosf(radIni);
			int yi = ya + radiou * sinf(radIni);

			
			float radFin = (angle + angleStep) * (PI / 180.0f);
			int xf = xa + radiou * cosf(radFin);
			int yf = ya + radiou * sinf(radFin);

			// Dibujar línea entre los puntos
			DrawLineDDA(xi, yi, xf, yf, color);
		}
	}

	std::vector<int> e1, e2, e3;
	//Lineas hechas por DDA
	void DrawLineDDA(int xa, int ya, int xb, int yb, Color color) { 

		dx = xb - xa;

		dy = yb - ya;

		steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

		float xinc = dx / (float)steps;
		float yinc = dy / (float)steps;

		float x = xa;
		float y = ya;

		for (int i = 0; i <= steps; i++) {
			DrawPixel(round(x), round(y), color);
			x += xinc;
			y += yinc;

		}
	}
	//Lineas hechas por bresenham
	void DrawLineBresenham(int xa, int ya, int xb, int yb, Color color)
	{
		
		if (xa == xb) {
			// Línea vertical Brensenham
			int IniY = ya < yb ? ya : yb;
			int FinY = ya > yb ? ya : yb;
			for (int y = IniY; y <= FinY; y++) {
				DrawPixel(xa, y, color);
			}
			return;
		}
		if (ya == yb) {
			// Línea horizontal Bresenham
			int IniX = xa < xb ? xa : xb;
			int FinX = xa > xb ? xa : xb;
			for (int x = IniX; x <= FinX; x++) {
				DrawPixel(x, ya, color);
			}
			return;
		}

		dx = fabs(xb - xa);
		dy = fabs(yb - ya);

		int xi = (xa < xb) ? 1 : -1;
		int yi = (ya < yb) ? 1 : -1;
		int err = (dx > dy ? dx : -dy) / 2, e2;

		while (true) {
			DrawPixel(xa, ya, color);
			if (xa == xb && ya == yb) break; 
			e2 = err;
			if (e2 > -dx) {
				err -= dy;
				xa += xi;
			}
			if (e2 < dy) {
				err += dx;
				ya += yi;
			}
		}
	}
	//Circulo hecho por Bresenham
	void DrawCirclelBresenham(int xa, int ya, int radiou, Color color) {
		int angleStep = 10;
		for (int angle = 0; angle < 180; angle += angleStep) {
			float radIn = angle * (PI / 180.0f);
			float radFin = (angle + 180) * (PI / 180.0f);
			// Puntos iniciales y finales de la línea
			int xi = xa + radiou * cosf(radIn);
			int yi = ya + radiou * sinf(radIn);
			int xf = xa + radiou * cosf(radFin);
			int yf = ya + radiou * sinf(radFin);
			DrawLineBresenham(xi, yi, xf, yf, color);
		}
	}
	//Circulo hechas por las lineas de Bresenham
	void DrawCircleLinesBresenham(int xa, int ya, int radiou, Color color) {
		int angleStep = 10;
		for (int angle = 0; angle < 360; angle += angleStep) {

			float radIn = angle * (PI / 180.0f);
			int xi = xa + radiou * cosf(radIn);
			int yi = ya + radiou * sinf(radIn);

			float radFin= (angle + angleStep) * (PI / 180.0f);
			int xf = xa + radiou * cosf(radFin);
			int yf = ya + radiou * sinf(radFin);

			// Dibujar línea entre los puntos
			DrawLineBresenham(xi, yi, xf, yf, color);
		}
	}
	//Triangulo hecho por DDA
	void DrawTriangleDDA(int xa, int ya, int xb, int yb, int xc, int yc, Color color)
	{
		DrawLineDDA(xa, ya, xb, yb, color);
		DrawLineDDA(xb, yb, xc, yc, color);
		DrawLineDDA(xc, yc, xa, ya, color);
	}
	//Triangulo hecho por Bresenham
	void DrawTriangleBresenham(int xa, int ya, int xb, int yb, int xc, int yc, Color color)
	{
		DrawLineBresenham(xa, ya, xb, yb, color);
		DrawLineBresenham(xb, yb, xc, yc, color);
		DrawLineBresenham(xc, yc, xa, ya, color);
	}
	//Cuadrado hecho por DDA
	void DrawRectDDA(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd, Color color)
	{
		DrawLineDDA(xa, ya, xb, yb, color);
		DrawLineDDA(xb, yb, xc, yc, color);
		DrawLineDDA(xc, yc, xd, yd, color);
		DrawLineDDA(xd, yd, xa, ya, color);
	}
	//Cuadrado hecho por Bresenham
	void DrawRectBresenham(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd, Color color)
	{
		DrawLineBresenham(xa, ya, xb, yb, color);
		DrawLineBresenham(xb, yb, xc, yc, color);
		DrawLineBresenham(xc, yc, xd, yd, color);
		DrawLineBresenham(xd, yd, xa, ya, color);
	}
	//Relleno del triangulo por puntos maximos y minimos que asemejan una linea
	void FillTriangleMaxMin(int xa, int ya, int xb, int yb, int xc, int yc, Color color)
	{
		int xmin = xa < xb ? xa : xb;
		xmin = xmin < xc ? xmin : xc;

		int ymin = ya < yb ? ya : yb;
		ymin = ymin < yc ? ymin : yc;

		int xmax = xa > xb ? xa : xb;
		xmax = xmax > xc ? xmax : xc;

		int ymax = ya > yb ? ya : yb;
		ymax = ymax > yc ? ymax : yc;

		for (int y = ymin; y <= ymax; y++) {
			std::vector<int> nodeX;


			if (ya != yb) LinesIntersection(xa, ya, xb, yb, y, nodeX);
			if (yb != yc) LinesIntersection(xb, yb, xc, yc, y, nodeX);
			if (yc != ya) LinesIntersection(xc, yc, xa, ya, y, nodeX);

			// Dibuja líneas horizontales entre los puntos de intersección
			std::sort(nodeX.begin(), nodeX.end());
			for (size_t i = 0; i < nodeX.size(); i += 2) {
				if (i + 1 < nodeX.size()) {
					DrawLineBresenham(nodeX[i], y, nodeX[i + 1], y, color);
				}
			}
		}
	}
	//Relleno del Circulo por media de lineas
	void FillCircle(int xa, int ya, int radiou, Color color)
	{
		for (int y = ya - radiou; y <= ya + radiou; y++) {
			// Calcula los puntos de intersección x para esta línea y
			int x1 = xa - sqrt(radiou * radiou - (y - ya) * (y - ya));
			int x2 = xa + sqrt(radiou * radiou - (y - ya) * (y - ya));

			DrawLineBresenham(x1, y, x2, y, color);
		}
	}
	//Relleno del cuadrado medio del relleno de triangulos
	void FillSquareWithTriangles(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd, Color color)
	{
		FillTriangleMaxMin(xa, ya, xb, yb, xc, yc, color);

		FillTriangleMaxMin(xa, ya, xd, yd, xc, yc, color);
	}
	//Las interseccion de las lineas
	void LinesIntersection(int x1, int y1, int x2, int y2, int y, std::vector<int>& nodeX) {
		if (y1 == y2) return; 

		if (x1 == x2) { 
			if ((y >= std::min(y1, y2)) && (y <= std::max(y1, y2))) {
				nodeX.push_back(x1);
			}
		}
		else {
			float slope = (float)(y2 - y1) / (x2 - x1);
			float xIntersect = x1 + (y - y1) / slope;
			if ((y >= std::min(y1, y2)) && (y <= std::max(y1, y2))) {
				nodeX.push_back(static_cast<int>(round(xIntersect)));
			}
		}
	}
};