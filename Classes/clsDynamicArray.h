#pragma once

#include <iostream>
using namespace std;

template <class T>

class clsDynamicArray
{
protected: 

	int _Size = 0;

public:

	T* OriginalArray; //array type pointer 
	
	clsDynamicArray(int Size = 0) //Constructor
	{
		if (Size < 0)
		{
			Size = 0;
		}

		_Size = Size;

		OriginalArray = new T[_Size]; //Dynamic Array size (_size) in memory
	}

	~clsDynamicArray() //destructor (the last method called in class)
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || _Size < 0)
			return false;

		OriginalArray[Index] = Value;
		return true;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	int Size()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int Index = 0; Index < _Size; Index++)
		{
			cout << OriginalArray[Index] << "   ";
		}

		cout << "\n";
	}





};

