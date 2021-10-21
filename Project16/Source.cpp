#include <iostream>
#include <locale>

using namespace std;

template <class T>

class TDStack
{
	T* mas;
	int SizeMas;
	int NumLast1, NumLast2;
public:
	TDStack()
	{
		SizeMas = 20;
		mas = new T[SizeMas];
		NumLast1 = -1;
		NumLast2 = SizeMas;
	}
	TDStack(const TDStack& c)
	{
		SizeMas = c.SizeMas;
		mas = new T[SizeMas];
		NumLast1 = c.NumLast1;
		NumLast2 = c.NumLast2;
	
		for (int i = 0; i <= NumLast1; i++)
		{
			mas[i] = c.mas[i];
		}
		for (int i = SizeMas-1; i >= NumLast2; i--)
		{
			mas[i] = c.mas[i];
		}
	}
	~TDStack()
	{
		delete[] mas;
	}
	void Push1(const T& p)
	{
		if (NumLast1 + 1 < NumLast2)
		{
			NumLast1++;
			mas[NumLast1] = p;
		}
		else
			cout << "Îøèáêà" << endl;
	}
	
	void Push2(const T& p)
	{
		if (NumLast2 - 1 > NumLast1)
		{
			NumLast2--;
			mas[NumLast2] = p;
		}
		else
			cout << "Îøèáêà" << endl;
	}

	T Pop1()
	{
		NumLast1--;
		return mas[NumLast1 + 1];
	}
	
	T Pop2()
	{
		NumLast2++;
		return mas[NumLast2 + 1];
	}

	bool isEmpty1()
	{
		if (NumLast1 == -1)
			return true;
		else 
			return false;
	}

	bool isEmpty2()
	{
		if (NumLast2 == SizeMas)
			return true;
		else
			return false;
	}

	bool isFull()
	{
		if (abs(NumLast1 - NumLast2) == 1)
			return true;
		else
			return false;
	}

	int GetSize()
	{
		return SizeMas;
	}
	T Get(int i)
	{
		return mas[i];
	}

	friend ostream& operator<<(ostream& os,  TDStack c)
	{
		for (int i = 0; i < c.GetSize(); i++)
			os << c.Get(i) << ' ';
		return os;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	TDStack<int> st;
	st.Push1(5);
	st.Push1(1);
	st.Push1(1);
	st.Push2(2);
	st.Push2(2);
	st.Pop1();
	st.Pop2();
	cout << st.isEmpty1() << endl;
	cout << st.isEmpty2() << endl;
	cout << st.isFull() << endl;
	cout << st;
}

