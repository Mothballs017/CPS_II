// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: shapes_base.cpp
// Course: Computational Problem Solving CPET-II
// Developer: Dr G.H. Zion
// Date : Fall 2019 (2191)
// Description : Inheritance - base shape
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Shape
{
	protected:
		string sName;
		char sColor;   // R = Red; G = Green; B = Blue

	public:
	    Shape()
	      { sName = " "; sColor = ' '; }

		void setShape(string name, char color)
		{
			sName = name;
			sColor = color;
			return;
		}

		void showShape()
		{
			cout << "Name : " << sName << endl;
			switch (sColor)
			{
				case 'R' :
				case 'r' : cout << "Color : Red" << endl;
					       break;
				case 'G' :
				case 'g' : cout << "Color : Green" << endl;
					       break;
				case 'B' :
				case 'b' : cout << "Color : Blue" << endl;
					       break;
				default  : cout << "Color : Unknown" << endl;
					       break;
			}
			return;
		}
};

class Rectangle:public Shape{
protected:
	float width,height;
public:
	Rectangle(){ width = 0; height = 0; }

	void setSides(float w, float h)
	{
		width = w;
		height = h;
		return;
	}

	float calArea()
	{
		float area=width*height;
		return area;
	}
};

class Cuboid:public Rectangle{
private:
	float length;
public:
	Cuboid(){ length = 0; }

	void setLength(float l)
	{
		length = l;
		return;
	}

	float calVolume()
	{
		float volume=calArea()*height;
		return volume;
	}
};

class Circle:public Shape{
protected:
	float radius;
public:
	Circle(){ radius = 0; }

	void setRadius(float r)
	{
		radius = r;
		return;
	}

	float calArea()
	{
		float area=3.1415*pow(radius,2.0);
		return area;
	}
};

class Cylinder:public Circle{
protected:
	float height;
public:
	Cylinder(){ height = 0; }

	void setHeight(float h)
	{
		height = h;
		return;
	}

	float calVolume()
	{
		float vol=calArea()*height;
		return vol;
	}
};

class Sphere:public Circle{
protected:
	float volume;
public:
	float calVolume()
	{
		volume=calArea()*1.3333*radius;
		return volume;
	}
};

class Spherelinder:public Circle, public Sphere{
public:
	float calVolume()
	{
		float sl=Cylinder::calVolume() + Sphere::calVolume();
		return sl;
	}
};

int main()
{
	Shape s1, s2;

	s1.setShape("Fred", 'R');
	s1.showShape();

	s2.setShape("Mary", 'B');
	s2.showShape();

	Rectangle r1;
	r1.setShape("Rect", 'R');
	r1.setSides(3,4);
	float area = r1.calArea();
	r1.showShape();
	cout << "Area: " << area << endl;

	Cuboid c1;
	c1.setShape("Cube", 'R');
	c1.setSides(3,4);
	c1.showShape();
	float area1 = c1.calArea();
	cout << "Area: " << area1 << endl;
	c1.setLength(5);
	float vol = c1.calVolume();
	cout << "Volume: " << vol << endl;

	Circle c2;
	c2.setShape("Circle", 'R');
	c2.setRadius(2);
	c2.showShape();
	float area2=c2.calArea();
	cout << "Area: " << area2 << endl;

	Sphere s3;
	s3.setShape("Sphere", 'R');
	s3.setRadius(2);
	s3.showShape();
	float area3=s3.calArea();
	cout << "Area: " << area3 << endl;
	float vol=s3.calVolume();
	cout << "Volume: " << vol << endl;

	Cylinder c3;
	c3.setShape("Sphere", 'R');
	c3.setRadius(2);
	c3.showShape();
	float area4=c3.calArea();
	cout << "Area: " << area4 << endl;
	float vol1=c3.calVolume();
	cout << "Volume: " << vol1 << endl;
}