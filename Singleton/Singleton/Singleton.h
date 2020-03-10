#pragma once
class Singleton
{
private:
	Singleton() {}

public:
	static Singleton* m_pInstance;
	static Singleton* GetInstance();
};

