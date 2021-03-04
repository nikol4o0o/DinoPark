#include "Cagemass.h"
#include <cstring>

void Cagemass::copy(const Cagemass& other)
{
	this->size = other.size; 
	this->capacity = other.capacity; 
	this->cages = new Cage[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		this->cages[i] = other.cages[i];
	}
}

void Cagemass::resize()
{
	this->capacity = capacity * 2;
	Cage * newcages = new Cage[this->capacity];
	for (size_t i = 0; i < this->size; i++) {
		newcages[i] = this->cages[i];
	}
	delete[] this->cages;
	this->cages = newcages;
}

void Cagemass::erase()
{
	delete[] this->cages;
}


Cagemass::Cagemass()
{
	this->size = 0; 
	this->capacity = 8;
	this->cages = new Cage[this->capacity];
}

Cagemass::Cagemass(const Cagemass& other)
{
	this->copy(other);
}

Cagemass& Cagemass::operator=(const Cagemass& other)
{
	if (this != &other)
	{
		this->erase(); 
		this->copy(other);
	}
	return *this;
}

Cage& Cagemass::operator[](int i)const
{
	if (i >= 0)
	{
		return cages[i];
	}
	else
	{
		cerr << "No such boundary!" << endl;
	}
}

Cagemass& Cagemass::AddCage(const Cage& newcage)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->cages[size++] = newcage;
	return *this;
}

void Cagemass::saveCages(ofstream& out)
{
	if (out.is_open())
	{
		out << this->size << endl;
		for (int i = 0; i < this->size; i++)
		{
			this->cages[i].saveCage(out);
		}
	}
}

void Cagemass::readCages(ifstream& in)
{
	int size = 0;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		Cage cage;
		cage.readCage(in);
		this->AddCage(cage);
	}
}

int Cagemass::getSize()const
{
	return this->size;
}

Cagemass::~Cagemass()
{
	this->erase();
}