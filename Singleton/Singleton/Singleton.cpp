#include <iostream>
using namespace std;

class Singleton
{
private:
	Singleton() {}
	static Singleton* m_pInstance;
public:
	static Singleton* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new Singleton();
		return m_pInstance;
	}

	void ShowMsg()
	{
		cout << "i am a singleton class!\n";
	}
};

Singleton* Singleton::m_pInstance = 0;

int main()
{
	Singleton* aaa = Singleton::GetInstance();
	aaa->ShowMsg();
	return 0;
}

