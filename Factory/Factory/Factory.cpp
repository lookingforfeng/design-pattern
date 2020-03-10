#include <iostream>
using namespace std;

enum class ShapeType { Circle = 1, Rectangle, Triagle ,LookingFeng};

class Shape
{
public:
	Shape() {};
	virtual void  draw() {};
};

class rectangle :public Shape
{
public:
	rectangle() {};
	void draw()
	{
		cout << "this is a rectangle!" << endl;
	}
};

class triangle :public Shape
{
public:
	triangle() {};
	void draw()
	{
		cout << "this is a triangle!" << endl;
	}
};

class circle :public Shape
{
public:
	circle() {};
	void draw()
	{
		cout << "this is a circle!" << endl;
	}
};

class lookingfeng :public Shape
{
public:
	lookingfeng() {};
	void draw()
	{
		cout << "this is a lookingfeng!" << endl;
	}
};

class factory
{
public:
	factory() {};
	factory(ShapeType default_type)
	{
		m_ShapeType = default_type;
	}

	void DrawShape()
	{
		Shape* aShape = createShape(m_ShapeType); 
		aShape->draw();
	}

	virtual Shape* createShape(ShapeType type)
	{
		return new Shape();
	}

	void setShapeType(ShapeType a)
	{
		m_ShapeType = a;
	}
private:
	ShapeType m_ShapeType;
};

class concreateFactory:public factory
{
public:
	concreateFactory(ShapeType default_type);
	~concreateFactory();

	virtual Shape* createShape(ShapeType type)
	{
		switch (type)
		{
		case ShapeType::Circle:
			return new circle();
		case ShapeType::Rectangle:
			return new rectangle();
		case ShapeType::Triagle:
			return new triangle();
		case ShapeType::LookingFeng:
			return new lookingfeng();
		default:
			break;
		}
	}

private:

};

concreateFactory::concreateFactory(ShapeType default_type )
{
	setShapeType(default_type);
}

concreateFactory::~concreateFactory()
{
}

int main()
{
	std::cout << "this is a factory test\n\n";
	concreateFactory* test = new concreateFactory(ShapeType::Rectangle);
	test->DrawShape();
	test = new concreateFactory(ShapeType::Circle);
	test->DrawShape();
	test = new concreateFactory(ShapeType::Triagle);
	test->DrawShape();
	test = new concreateFactory(ShapeType::LookingFeng);
	test->DrawShape();
}


