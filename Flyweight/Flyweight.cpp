#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

static vector<string> colors=
{ "Red", "Green", "Blue", "White", "Black" };

class Shape
{
public:
	Shape() {};
	virtual void draw(double raduis) {};
	virtual void setX(double x) {};
	virtual void setY(double y) {};
protected:
private:
};

class Circle :public Shape
{
public:
	Circle(string color)
	{
		_x = 0;
		_y = 0;
		_color = color;
	};
	~Circle() {};
	void draw(double raduis) override
	{
		cout << endl;
		cout << "draw a circle----" << "positon:" << _x << "," << _y << endl;
		cout << "radius:" << raduis << "     color:" << _color << endl << endl;
	}

	void setX(double x)override
	{
		_x = x;
	}

	void setY(double y)override
	{
		_y = y;
	}
protected:

private:
	double _x, _y;
	string _color;
};

class ShapeFactory
{
public:

	ShapeFactory() {};
	~ShapeFactory() {};
	Shape* getShape(string color)
	{
		map < string, Shape* >::iterator it = all_shapes.find(color);
		if (it != all_shapes.end())
			return all_shapes[color];
		else
		{
			Shape* _shape = new Circle(color);
			all_shapes.insert(pair<string, Shape*>(color, _shape));
			cout << "_________________________new color circle:" << color << endl;
			return _shape;
		}
	};
protected:

private:
	map < string, Shape* > all_shapes;
};

string get_random_color()
{
	int a = rand();
	int c = colors.size();
	int b = rand()%c;
	return colors.at(b);
}

int main()
{
	ShapeFactory* _shapefactory = new ShapeFactory();
	for (double i = 1; i <= 20; i++)
	{
		Shape* _circle = _shapefactory->getShape(get_random_color());
		_circle->setX(i * 10);
		_circle->setY(i * 10);
		_circle->draw(i * 100);
	}
	return 0;
}


