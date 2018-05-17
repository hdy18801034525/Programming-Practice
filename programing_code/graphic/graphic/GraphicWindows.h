#pragma once
#include"Resource.h"
#include"stdafx.h"
using namespace std;
#define PI 3.1415926
#define POINT_NUM 1000
#define DOUBLE_PI 2*3.1415926

// shape ��
class Shape
{
public:
	virtual void move(double dx, double dy) = 0;
	virtual void SetColor(COLORREF mColor) = 0;
};

// ����
class Point :public Shape
{
public:
	double x, y;
	COLORREF color;

	Point() { x = 0; y = 0; }
	void setPoint(double x1, double y1)
	{
		x = x1; 
		y = y1;
	}
	Point(double x1, double y1)
	{
		x = x1;
		y = y1;
	}
	double get_x()const { return x; }
	double get_y()const { return y; }
	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy)
	{
		x += dx;
		y += dy;
	}
	virtual void SetColor(COLORREF mColor)
	{
		color = mColor;
	}
};

// ����
class Line :public Shape
{
public:
	Line() { }
	Line(Point p1, Point p2) { from = p1; to = p2; }
	Point get_start() const { return from; }
	Point get_end() const { return to; }
	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy)
	{
		from.move(dx, dy);
		to.move(dx, dy);
	}
	virtual void SetColor(COLORREF mColor) { color = mColor; }

private:
	Point from;
	Point to;
	COLORREF color;
};

// Բ��
class Circle :public Shape
{
public:
	Circle() { radius = 0.0; }
	Circle(Point p, double r) { center = p; radius = r; }
	void setCircle(Point p, double r){ center = p; radius = r; }
	Point get_center() const { return center; }
	double get_radius() const { return radius; }
	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy) { center.move(dx, dy); }
	virtual void SetColor(COLORREF mColor) { color = mColor; }
private:
	Point center;
	double radius;
	COLORREF color;
};

//�ı���Ϣ��
class Message
{
public:
	Message() {}
	Message(Point s, double x);
	Message(Point s, const string& m) { start = s; text = m; };
	Point get_start()const { return start; }
	string get_text()const { return text; }
	void move(double dx, double dy) { start.move(dx, dy); }
private:
	Point start;
	string text;
};
Message::Message(Point s, double x)
{
	start = s;
	char buf[20];
	sprintf_s(buf, "%g", x);
	text = buf;
};

//��ͼ��
class GraphicWindow {
public:
	GraphicWindow()
		:_user_xmin(-10), _user_xmax(10), _user_ymin(6), _user_ymax(-6)
	{ }
	// ���ô�������
	void coord(double xmin, double ymin, double xmax, double ymax)
	{
		_user_xmin = xmin, _user_xmax = xmax;
		_user_ymin = ymin, _user_ymax = ymax;
	}
	// �������
	void clear();
	GraphicWindow& operator<<(Point p);  // ��ʾһ����
	GraphicWindow& operator<<(Circle c);  // ��ʾһ��Բ
	GraphicWindow& operator<<(Line s);  // ��ʾһ����    
	GraphicWindow& operator<<(Message t);  // ��ʾһ���ı���
	void open(HWND hwnd, HDC mainwin_hdc);  // ��һ������
	HDC GetHDC() { return _hdc; }
private:
	int user_to_disp_x(double x) const;  // �߼����豸x����ת��
	int user_to_disp_y(double y) const;  // �߼����豸y����ת��
	double disp_to_user_x(int x) const;  // �豸���߼�x����ת��
	double disp_to_user_y(int y) const;  // �豸���߼�y����ת��
	void point(double x, double y, COLORREF mColor); // ��һ����
													 // ��һ����
	void line(double xfrom, double yfrom, double xto, double yto, COLORREF mColor);
	// ��һ����Բ
	void ellipse(double x, double y, double ra, double rb, COLORREF mColor);
	void text(string t, double x, double y); // ͼ�η�ʽ���һ���ı���
	
	
	// �߼�����
	double _user_xmin, _user_xmax, _user_ymin, _user_ymax;
	// �豸���꣨����Ϊ��λ��
	int _disp_xmax, _disp_ymax;
	// �豸�������
	HDC _hdc;
};
void GraphicWindow::open(HWND hwnd, HDC mainwin_hdc) {
	RECT rect;
	GetClientRect(hwnd, &rect);
	_disp_xmax = rect.right - 1;
	_disp_ymax = rect.bottom - 1;
	_hdc = mainwin_hdc;
	
	
	//������ɫ��ˢ
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 120, 215)); 
	SelectObject(_hdc, hbrush);  // ָ����ˢ
	SelectObject(_hdc, GetStockObject(BLACK_PEN));
	SelectObject(_hdc, GetStockObject(SYSTEM_FONT));
	clear();
}

void GraphicWindow::clear() {
	COLORREF color = RGB(0, 120, 215);
	HBRUSH brush = CreateSolidBrush(color);
	HBRUSH saved_brush = (HBRUSH)SelectObject(_hdc, brush);
	PatBlt(_hdc, 0, 0, _disp_xmax, _disp_ymax, PATCOPY);
	SelectObject(_hdc, saved_brush);
	DeleteObject(brush);
}
//�߼����豸����ת��
int GraphicWindow::user_to_disp_x(double x) const 
{
	return (int)((x - _user_xmin)*_disp_xmax / (_user_xmax - _user_xmin));
}
int GraphicWindow::user_to_disp_y(double y) const
{
	return (int)((y - _user_ymin)*_disp_ymax / (_user_ymax - _user_ymin));
}

//�豸���߼�����ת��
double GraphicWindow::disp_to_user_x(int x) const 
{
	return (double)x*(_user_xmax - _user_xmin) / _disp_xmax + _user_xmin;
}
double GraphicWindow::disp_to_user_y(int y) const 
{
	return (double)y*(_user_ymax - _user_ymin) / _disp_ymax + _user_ymin;
}

void GraphicWindow::point(double x, double y, COLORREF mColor) 
{
	const int POINT_RADIUS = 3;
	int disp_x = user_to_disp_x(x);
	int disp_y = user_to_disp_y(y);

	SelectObject(_hdc, CreatePen(PS_SOLID, 1, mColor));
	Ellipse(_hdc, disp_x - POINT_RADIUS, disp_y - POINT_RADIUS, disp_x + POINT_RADIUS, disp_y + POINT_RADIUS);
}

void GraphicWindow::line(double xfrom, double yfrom, double xto, double yto, COLORREF mColor) 
{
	SelectObject(_hdc, CreatePen(PS_SOLID, 1, mColor));
	MoveToEx(_hdc, user_to_disp_x(xfrom), user_to_disp_y(yfrom), 0);
	LineTo(_hdc, user_to_disp_x(xto), user_to_disp_y(yto));
}

void GraphicWindow::ellipse(double x, double y, double ra, double rb, COLORREF mColor) 
{
	SelectObject(_hdc, CreatePen(PS_SOLID, 1, mColor));
	Ellipse(_hdc, user_to_disp_x(x - ra), user_to_disp_y(y - rb), user_to_disp_x(x + ra), user_to_disp_y(y + rb));
}

void GraphicWindow::text(string s, double x, double y) 
{
	const char *t = s.c_str();
	SetBkMode(_hdc, TRANSPARENT);
	TextOut(_hdc, user_to_disp_x(x), user_to_disp_y(y), t, lstrlen(t));
}

GraphicWindow& GraphicWindow::operator<<(Point p)
{
	point(p.get_x(), p.get_y(), p.get_color());
	return *this;
}

GraphicWindow& GraphicWindow::operator<<(Circle c) 
{
	ellipse(c.get_center().get_x(), c.get_center().get_y(), c.get_radius(), c.get_radius(), c.get_color());
	return *this;
}

GraphicWindow& GraphicWindow::operator<<(Line s) 
{
	line(s.get_start().get_x(), s.get_start().get_y(), s.get_end().get_x(), s.get_end().get_y(), s.get_color());
	return *this;
}

GraphicWindow& GraphicWindow::operator<<(Message t) 
{
	text(t.get_text(), t.get_start().get_x(), t.get_start().get_y());
	return *this;
}

void mclock(GraphicWindow cwin)
{
	Shape *pShape;
	/* ������*/
	int radius = 6;
	Point org(0, 0);
	pShape = &org;
	pShape->SetColor(RGB(0, 0, 0)); // ��ɫ
	cwin << org;
	Circle clkPlate(org, radius);
	pShape = &clkPlate;
	pShape->SetColor(RGB(0, 120, 215));	// ��ɫ
	cwin << clkPlate;
	double x, y, x_s, y_s, x_m, y_m, x_h, y_h;
	int i;
	for (i = 0; i<12; i++)
	{
		x = 0.9*radius*sin(PI*i / 6);
		y = 0.9*radius*cos(PI*i / 6);
		Point mPoint(x, y);
		pShape = &mPoint;
		pShape->SetColor((RGB(255, 255, 255)));
		cwin << mPoint;
	}
	tm local;
	time_t t;

	t = time(NULL);  // ��ȡϵͳ����ʱ��	
	localtime_s(&local, &t); // ������ʱ��ת��Ϊ����ʱ��

	x_s = 0.89*radius*sin(PI*(local.tm_sec) / 30);
	y_s = 0.89*radius*cos(PI*(local.tm_sec) / 30);
	x_m = 0.7*radius*sin(PI*(local.tm_min) / 30);
	y_m = 0.7*radius*cos(PI*(local.tm_min) / 30);
	x_h = 0.5*radius*sin(PI*(local.tm_hour) / 6);
	y_h = 0.5*radius*cos(PI*(local.tm_hour) / 6);

	/* ������*/
	Point hEnd(x_h, y_h), mEnd(x_m, y_m), sEnd(x_s, y_s);
	Line hLine(org, hEnd), mLine(org, mEnd), sLine(org, sEnd);

	hLine.SetColor((RGB(50, 50, 50)));		//ʱ��	   
	mLine.SetColor((RGB(55, 20, 220)));	//����
	sLine.SetColor((RGB(215, 90, 90)));		//����
	cwin << hLine << mLine << sLine << org;
}

int n = 5;						//��ĸ���
int r[5], g[5], b[5];			//��ɫ
double x[5], y[5];				//λ��
double w[5];					//��б��

int Ccount;						//������
Point p[5];
Circle c[5];
bool GoLeft[5];
bool GoUp[5];


void init()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		r[i] = rand() % 256;
		g[i] = rand() % 256;
		b[i] = rand() % 256;
		x[i] = (rand() / 100) % 10;
		y[i] = (rand() / 100) % 6;
		p[i].setPoint(x[i], y[i]);
		c[i].setCircle(p[i], 0.7);
		w[i] = PI / 2 * (rand() % 200) / 200;
		if ((PI / 4) > w[i] || w[i] > 0)
		{
			GoUp[i] = true;
			GoLeft[i] = true;
		}
		else if (2 * (PI / 4) > w[i] || (PI / 4) < w[i])
		{
			GoUp[i] = true;
			GoLeft[i] = false;
		}
		else if (1.5*(PI / 4) > w[i] || 2 * (PI / 4) < w[i])
		{
			GoUp[i] = false;
			GoLeft[i] = false;
		}
		else if (2 * (PI / 4) > w[i] || 1.5 * (PI / 4) < w[i])
		{
			GoUp[i] = false;
			GoLeft[i] = true;
		}
		else if (PI / 4 == w[i])
		{
			GoLeft[i] = true;
		}
		else if (PI / 2 == w[i])
		{
			GoUp[i] = true;
		}
		else if (3 * PI / 4 == w[i])
		{
			GoLeft[i] = false;
		}
		else if (2 * PI == w[i])
		{
			GoUp[i] = false;
		}
	}
}

void DrawBall(GraphicWindow cwin)
{
	//λ�ñ仯
	for (int i = 0; i < n; ++i)
	{
		//�ж���û���е��߽�
		if (x[i] + 0.5 >= 10) { GoLeft[i] = false; }
		if (x[i] - 0.5 <= -10) { GoLeft[i] = true; }
		if (y[i] + 0.5 >= 6) { GoUp[i] = false; }
		if (y[i] - 0.5 <= -6) { GoUp[i] = true; }
		if (GoLeft[i])
		{
			x[i] += 0.3*cos(w[i]);
		}
		else
		{
			x[i] -= 0.3*cos(w[i]);
		}

		if (GoUp[i])
		{
			y[i] += 0.3*sin(w[i]);
		}
		else
		{
			y[i] -= 0.3*sin(w[i]);
		}
		
	}

	//��ɫ�仯
	Ccount++;
	srand((unsigned)time(NULL));
	if (Ccount == 20)
	{
		Ccount = 0;
		for (int i = 0; i < 5; ++i)
		{
			r[i] = rand() % 256;
			g[i] = rand() % 256;
			b[i] = rand() % 256;
		}
		HBRUSH hbrush = CreateSolidBrush(RGB(r, g, b));
		SelectObject(cwin.GetHDC(), hbrush);  // ָ����ˢ
	}
	
	//����
	for (int i = 0; i < n; ++i)
	{		
		HBRUSH hbrush = CreateSolidBrush(RGB(r[i], g[i], b[i]));
		SelectObject(cwin.GetHDC(), hbrush);  // ָ����ˢ
		p[i].setPoint(x[i], y[i]);
		c[i].setCircle(p[i], 0.7);
		cwin << c[i];
	}
}