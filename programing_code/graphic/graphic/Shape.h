#pragma once
#include<string>
using namespace std;

// shape ��
class Shape
{
public:
	virtual void move(double dx, double dy) = 0;
	virtual void Setcolor(COLORREF mColor) = 0;
};

// ����
class Point :public Shape
{	
public:
	double x, y;
	COLORREF color;

	Point() { x = 0; y = 0; }
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
	virtual void Setcolor(COLORREF mColor)
	{
		color = mColor;
	}
};

// ����
class Line :public Shape
{
private:
	Point from, to;
	COLORREF color;

public:
	Line(){}
	Line(Point p1, Point p2)
	{
		from = p1;
		from = p2;
	}
	Point get_start()const { return from; }
	Point get_end()const { return to; }

	COLORREF get_color() const { return color; }

	virtual void move(double dx, double dy)
	{
		from.move(dx, dy);
		to.move(dx, dy);
	}
	virtual void Setcolor(COLORREF mColor)
	{
		color = mColor;
	}

};

// Բ��

//�ı���Ϣ
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
