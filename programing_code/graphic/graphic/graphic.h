#include "resource.h"
#include"stdafx.h"
#include"Resource.h"
#include"GraphicWindows.h"



#define POINT_NUM 1000
#define DOUBLE_PI 2*3.1415926


//画点的函数
void DrawPixels(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 100, 100, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);


	TextOut(hdc, 50, 50, TEXT("TEST"), lstrlen(TEXT("TEST")));

	//点
	for (int i = 0; i<20; i++)
	{
		SetPixelV(hdc, 20 + i, 20 + i, RGB(0, 0, 0));
	}

	//线
	MoveToEx(hdc, 30, 40, NULL);
	LineTo(hdc, 100, 10);
}

//画三角形的函数
void DrawTriangle(HWND hwnd, HDC hdc)
{
	RECT r;
	GetClientRect(hwnd, &r);
	// 设置映像模式
	SetMapMode(hdc, MM_ISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 100, 100, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);
	Point p[] = { Point(10,10),Point(10,19),Point(22,19) };
	MoveToEx(hdc, p[0].get_x(), p[0].get_y(), NULL);
	for (int i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			LineTo(hdc, p[0].get_x(), p[0].get_y());
			continue;
		}
		LineTo(hdc, p[i + 1].get_x(), p[i + 1].get_y());
	}
}

//画正弦曲线
void DrawSin(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ANISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 1000 / 2, NULL);

	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 1000 / 2);				//画坐标轴

	Point pt[POINT_NUM];
	for (int i = 0; i < POINT_NUM; i++)
	{
		pt[i].x = i * 1000 / POINT_NUM;
		pt[i].y = (int)(1000 / 2 * (1 - sin(DOUBLE_PI*i / POINT_NUM)));
	}
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));

	MoveToEx(hdc, pt[0].x, pt[0].y, NULL);
	for (int i = 1; i < POINT_NUM; i++)
	{
		LineTo(hdc, pt[i].x, pt[i].y);
	}
}

//画二次函数
void DrawPA(HWND hwnd, HDC hdc)
{
	// 获得客户区域
	RECT r;
	GetClientRect(hwnd, &r);

	// 设置映像模式
	SetMapMode(hdc, MM_ANISOTROPIC);

	// 设置窗口坐标范围
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// 设置视口坐标范围
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 800, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 800);						//画坐标轴

	MoveToEx(hdc, 1000 / 2, 0, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000 / 2, 1000);						//画坐标轴

	Point pt[POINT_NUM];
	for (int i = 0; i < POINT_NUM; i++)
	{
		pt[i].x = i;
		int temp = pow(abs(500 - i), 2) / 50;
		pt[i].y = (800 - temp);
	}
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));
	MoveToEx(hdc, pt[0].x, pt[0].y, NULL);
	for (int i = 1; i < POINT_NUM; i++)
	{
		LineTo(hdc, pt[i].x, pt[i].y);
	}
}
