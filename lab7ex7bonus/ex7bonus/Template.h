#pragma once
template <class T>
class Vector
{
private:
	T* vector;
	int index;
public:
	Vector() {
		this->index = 0;
		this->vector = new T[100];
		for (int i = 0; i < 100; i++)
			vector[i] = 0;
	}
	~Vector()
	{
		delete[] vector;
	}
	void insert(int nr, T elem)
	{
		if (nr <= 99)
		this->vector[nr] = elem;
		if (nr > index)
			this->index = nr;
			
	}
	void remove(int nr)
	{
		if (nr <= index)
		for (int i = nr; i <index; i++)
			vector[i] = vector[i + 1];
		this->index--;
	}
	void print()
	{
		for (int i = 0; i <= index; i++)
			std::cout << vector[i] << " ";
	}
	T operator[](int i)
	{
		return vector[i];
	}
	Vector(const Vector& d)
	{
		this->vector = new T[100];
		this->index= d.index;
		//this->vector = d.vector; (face figuri)!!!!
		for (int i = 0; i <= index; i++)
			this->vector[i] = d.vector[i];

	}
	Vector(Vector&& d)
	{
		this->index = d.index;
		char* copy = d.vector;
		d.vector = nullptr;
		this->vector= copy;

	}
	void sort(int (*callback)(int a, int b))
	{
		if (callback != nullptr)
		{
			for(int i=0;i<index;i++)
				for(int j=i;j<=index;j++)
					if (callback(vector[i], vector[j]) > 0)
					{
						int aux;
						aux = vector[i];
						vector[i] = vector[j];
						vector[j] = aux;
					}
		}
	}


};