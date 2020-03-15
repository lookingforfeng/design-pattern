/**
 *原型模式，主要是实现实例的复制，属于创建模式,另一个不用接口就可以实现的接口
 */
#include <iostream>
using namespace std;

class class_to_clone
{
public:
    class_to_clone(int a) 
    {
        _secret_number = a;
        _is_origin = true;
    };

    class_to_clone(class_to_clone* prorotype) 
    {
        _secret_number = prorotype->_secret_number;
        _is_origin = false;
    };

    class_to_clone* colne()
    {
        return new  class_to_clone(this);
    }

    void show_secret_num()
    {
        cout <<"the secret number is:" <<_secret_number << endl;
        if (_is_origin)
        {
            cout << "i am the prototype!" << endl << endl;
        }
        else
        {
            cout << "i am clone form the other!" << endl << endl;
        }
    }
protected:
private:
    int _secret_number;
    bool _is_origin;
};


int main()
{
    std::cout << "Prototype Pattern Test\n\n";

    class_to_clone* test = new class_to_clone(123456789);
    class_to_clone* test1 = test->colne();
    class_to_clone* test2 = test->colne();
    test->show_secret_num();
    test1->show_secret_num();
    test1->show_secret_num();
}

