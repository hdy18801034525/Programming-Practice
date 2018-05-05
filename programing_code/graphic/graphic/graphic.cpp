//graphic.cpp: ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "graphic.h"
#include"stdafx.h"
#include"point.h"
#include<cmath>


#define MAX_LOADSTRING 100
#define POINT_NUM 1000
#define DOUBLE_PI 2*3.1415926


//����ĺ���
void DrawPixels(HWND hwnd, HDC hdc)
{
	// ��ÿͻ�����
	RECT r;
	GetClientRect(hwnd, &r);

	// ����ӳ��ģʽ
	SetMapMode(hdc, MM_ISOTROPIC);

	// ���ô������귶Χ
	SetWindowExtEx(hdc, 100, 100, NULL);

	// �����ӿ����귶Χ
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);


	TextOut(hdc, 50, 50, TEXT("TEST"), lstrlen(TEXT("TEST")));

	//��
	for (int i = 0; i<20; i++)
	{
		SetPixelV(hdc, 20 + i, 20 + i, RGB(0, 0, 0));
	}

	//��
	MoveToEx(hdc, 30, 40, NULL);
	LineTo(hdc, 100, 10);
}

//�������εĺ���
void DrawTriangle(HWND hwnd, HDC hdc)
{
	RECT r;
	GetClientRect(hwnd, &r);
	// ����ӳ��ģʽ
	SetMapMode(hdc, MM_ISOTROPIC);

	// ���ô������귶Χ
	SetWindowExtEx(hdc, 100, 100, NULL);

	// �����ӿ����귶Χ
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

//����������
void DrawSin(HWND hwnd, HDC hdc)
{
	// ��ÿͻ�����
	RECT r;
	GetClientRect(hwnd, &r);

	// ����ӳ��ģʽ
	SetMapMode(hdc, MM_ANISOTROPIC);

	// ���ô������귶Χ
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// �����ӿ����귶Χ
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 1000 / 2, NULL);
	
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 1000 / 2);				//��������

	point pt[POINT_NUM];
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

void DrawPA(HWND hwnd, HDC hdc)
{
	// ��ÿͻ�����
	RECT r;
	GetClientRect(hwnd, &r);

	// ����ӳ��ģʽ
	SetMapMode(hdc, MM_ANISOTROPIC);

	// ���ô������귶Χ
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// �����ӿ����귶Χ
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 800, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 800);						//��������

	MoveToEx(hdc, 1000/2, 0, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000/2, 1000);						//��������

	point pt[POINT_NUM];
	for (int i = 0; i < POINT_NUM; i++)
	{
		pt[i].x = i;
		int temp = pow(abs(500 - i), 2)/50;
		pt[i].y = (800 - temp);
	}
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(255, 0, 0)));
	MoveToEx(hdc, pt[0].x, pt[0].y, NULL);
	for (int i = 1; i < POINT_NUM; i++)
	{
		LineTo(hdc, pt[i].x, pt[i].y);
	}
}

//����
void DrawHeart(HWND hwnd, HDC hdc)
{
	// ��ÿͻ�����
	RECT r;
	GetClientRect(hwnd, &r);

	// ����ӳ��ģʽ
	SetMapMode(hdc, MM_ANISOTROPIC);

	// ���ô������귶Χ
	SetWindowExtEx(hdc, 1000, 1000, NULL);

	// �����ӿ����귶Χ
	SetViewportExtEx(hdc, r.right, r.bottom, NULL);

	MoveToEx(hdc, 0, 500, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000, 500);						//��x������

	MoveToEx(hdc, 1000 / 2, 0, NULL);
	SelectObject(hdc, CreatePen(PS_SOLID, 1, RGB(0, 0, 0)));
	LineTo(hdc, 1000 / 2, 1000);				//��y������

	point pt[1000], pt_rl[1000];

	for (int i = 0; i < POINT_NUM; ++i)
	{
		
	}

}

void DrawClock(HWND hwnd, HDC hdc)
{

}

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������

												// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: �ڴ˷��ô��롣

	// ��ʼ��ȫ���ַ���
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_GRAPHIC, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GRAPHIC));

	MSG msg;

	// ����Ϣѭ��: 
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GRAPHIC));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GRAPHIC);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
int menue = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		case POINT:
			menue = POINT;
			InvalidateRect(hWnd, NULL, true);
			break;

		case TRIANGLE:
			menue = TRIANGLE;
			InvalidateRect(hWnd, NULL, true);
			break;

		case PA:
			menue = PA;
			InvalidateRect(hWnd, NULL, true);
			break;

		case SIN:
			menue = SIN;
			InvalidateRect(hWnd, NULL, true);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		TEXTMETRIC tm;								// ȡ�����ı���ص�����     
		GetTextMetrics(ps.hdc, &tm);
		RECT rect;
		rect.top = 0L;
		rect.left = ps.rcPaint.left;
		rect.right = ps.rcPaint.right;
		rect.bottom = rect.top + tm.tmHeight;
		DrawText(ps.hdc, L"Welcome to use zyz's Graphic program!", -1, &rect, DT_CENTER);
	

		switch (menue) 
		{

		case POINT:
			DrawPixels(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		
		case TRIANGLE:
			DrawTriangle(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		case PA:
			DrawPA(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		case SIN:
			DrawSin(hWnd, hdc);
			EndPaint(hWnd, &ps);
			break;
		}
		
		
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

