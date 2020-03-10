#include <iostream>
#include <list>
#include <string>

using namespace std;

class Observer;
class Observerble;

class Observer
{
public:
	Observer(Observerble* obj, string name)
	{
		this->name = name;
		this->m_obj = obj;
	};
	virtual void update(int msg)
	{
		cout << "i am " << name << " i get a msg: " << msg << endl;
	}
protected:
	Observerble* m_obj;
private:
	string name;
};

class Observerble
{
public:
	Observerble() {};

	void registe(Observer* observer)
	{
		ObsList.push_back(observer);
	}

	void unregiste(Observer* observer)
	{
		ObsList.remove(observer);
	}

	virtual void updateAll(int msg)
	{
		std::list<Observer*>::iterator it;
		for (it = ObsList.begin(); it != ObsList.end(); ++it) {
			(*it)->update(msg);
		}
	}
private:
	list<Observer*> ObsList;
};


class OberverA:public Observer
{
public:
	OberverA(Observerble* obj, string name) :Observer(obj, name)
	{
		obj->registe(this);
	}
	void update(int msg)
	{
		Observer::update(msg);
		cout << " and i am a teacher!\n\n";
	}
};

class OberverB :public Observer
{
public:
	OberverB(Observerble* obj, string name) :Observer(obj, name)
	{
		obj->registe(this);
	}
	void update(int msg)
	{
		Observer::update(msg);
		cout << " and i am a student!\n\n";
	}
};

class OberverC :public Observer
{
public:
	OberverC(Observerble* obj, string name) :Observer(obj, name)
	{
		obj->registe(this);
	}
	void update(int msg)
	{
		Observer::update(msg);
		cout << " and i am a worker!\n\n";
	}

	void unres()
	{
		m_obj->unregiste(this);
	}
};


int main()
{
	Observerble* subject = new Observerble();
	Observer* AAA = new OberverA(subject ,"aaa");
	Observer* BBB = new OberverB(subject, "bbb");
	Observer* CCC = new OberverC(subject, "ccc");
	OberverC KKK(subject, "kkk");
	Observer XXX= OberverC(subject, "xxx");//这个命名失败！！！
	//直接调用构造函数得到的是对象的引用，在栈空间
	subject->updateAll(999);
	OberverC* my_c = dynamic_cast<OberverC*> (CCC);
	my_c->unres();
	subject->updateAll(777777);
}


