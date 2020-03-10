#include <iostream>
using namespace std;

class Coffee
{
public:
    Coffee() {};
    virtual double GetCost() { return 0; }
};

class A_coffee:public Coffee
{
public:
    A_coffee() {};
    double GetCost()
    {
        return 5.5;
    }
};

class B_coffee :public Coffee
{
public:
    B_coffee() {};
    double GetCost()
    {
        return 1;
    }
};

class ADDmilk :public Coffee
{
public:
    ADDmilk(Coffee* aa)
    {
        this->coffeeToDe = aa;
    }
    double GetCost()
    {
        return 2 + coffeeToDe->GetCost();
    }
private:
    Coffee* coffeeToDe;
};

class ADDsuger :public Coffee
{
public:
    ADDsuger(Coffee* aa)
    {
        this->coffeeToDe = aa;
    }
    double GetCost()
    {
        return 3 + coffeeToDe->GetCost();
    }
private:
    Coffee* coffeeToDe;
};

int main()
{
    Coffee* my_coffee = new B_coffee();
    my_coffee = new ADDmilk(my_coffee);
    my_coffee = new ADDmilk(my_coffee);
    my_coffee = new ADDsuger(my_coffee);
    cout << "the coffe price is: " <<my_coffee->GetCost() << endl;
}

