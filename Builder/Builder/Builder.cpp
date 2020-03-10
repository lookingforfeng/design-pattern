#include <iostream>
#include <string>
#include <list>
using namespace std;

class Packing
{
public:
	Packing() {};
	virtual string getPackNmae()
	{
		return "virtual packing";
	}
private:

};

class Wraper :public Packing
{
public:
	Wraper() {};
	string getPackNmae()
	{
		return "wraper";
	}
};

class Bottle : public Packing
{
public:
	Bottle() {};
	string getPackNmae()
	{
		return "botle";
	}
private:

};

class MealItem
{
public:
	MealItem() {};
	virtual string getPacking() { return "no_packing"; };
	virtual string getName() { return "no_name"; };
	virtual double getPrice() { return 0; };
private:

};

class Buger :public MealItem
{
public:
	Buger()
	{
		this->m_packing = new Wraper();
	};
	string getPacking()
	{
		return this->m_packing->getPackNmae();
	}

	string getName()
	{
		return "Buger";
	}
private:
	Packing* m_packing = 0;
};

class VegBuger :public Buger
{
public:
	VegBuger() {};
	string getName()
	{
		return "VegBuger";
	}

	double getPrice()
	{
		return 5.5;
	}
};

class MeatBuger :public Buger
{
public:
	MeatBuger() {};
	string getName()
	{
		return "MeatBuger";
	}

	double getPrice()
	{
		return 8.8;
	}
};

class ColdDrink :public MealItem
{
public:
	ColdDrink()
	{
		this->m_packing = new Bottle();
	};
	string getPacking()
	{
		return this->m_packing->getPackNmae();
	}

	string getName()
	{
		return "ColdDrink";
	}
private:
	Packing* m_packing = 0;
};

class Pepsi :public ColdDrink
{
public:
	Pepsi() {};
	string getName()
	{
		return "Pepsi";
	}

	double getPrice()
	{
		return 1.1;
	}
};

class Coco :public ColdDrink
{
public:
	Coco() {};
	string getName()
	{
		return "Coco";
	}

	double getPrice()
	{
		return 3.3;
	}
};

class Meal
{
public :
	Meal() {};
	void addMeal(MealItem* item)
	{
		m_meal_list.push_back(item);
	}
	void  showItem()
	{
		cout << "Item: ";
		list<MealItem*>::iterator it = m_meal_list.begin();
		for (; it != m_meal_list.end(); it++)
		{
			cout<<(*it)->getName()<<"--"<< (*it)->getPacking()<<"     ";
		}
		cout << endl;
	}
	
	double  getPrice()
	{
		double temp_price=0;
		list<MealItem*>::iterator it = m_meal_list.begin();
		for (; it != m_meal_list.end(); it++)
		{
			temp_price = temp_price + (*it)->getPrice();
		}
		return temp_price;
	}
private:
	list<MealItem*> m_meal_list;

};

class MealBuilder
{
public:
	MealBuilder() 
	{
	};
	Meal* prepaerVegMeal()
	{
		Meal* m_VegMeal = new Meal();
		m_VegMeal->addMeal(new VegBuger());
		m_VegMeal->addMeal(new Pepsi());
		cout << "VegMeal is prepareing" << endl;
		return m_VegMeal;
	}

	Meal*  prepaerNoVegMeal()
	{
		Meal* m_NoVegMeal = new Meal();
		m_NoVegMeal->addMeal(new MeatBuger());
		m_NoVegMeal->addMeal(new Coco());
		cout << "NoVegMeal is prepareing" << endl;
		return m_NoVegMeal;
	}
private:
};

int main()
{
	std::cout << "Builder pattern\n";

	Meal* MyMeal;
	MealBuilder* test = new MealBuilder();
	MyMeal=test->prepaerVegMeal();
	MyMeal->showItem();
	cout << "the total price is: " << MyMeal->getPrice() << endl << endl;

	MyMeal=test->prepaerNoVegMeal();
	MyMeal->showItem();
	cout << "the total price is: " << MyMeal->getPrice() << endl << endl;
}
