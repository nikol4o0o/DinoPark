#include "Dinomass.h"
#include <cstring>


void Dinomass::erase()
{
	delete [] this->dinosaurs;
}

void Dinomass::copy(const Dinomass& other)
{
	this->size = other.size; 
	this->capacity = other.capacity;
	this->dinosaurs = new Dino[this->capacity];
	
		for (size_t i = 0; i < this->size; i++)
		{
			this->dinosaurs[i] = other.dinosaurs[i];
		}
}

void Dinomass::resize()
{
	this->capacity *= 2;
	Dino* temp = new Dino[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->dinosaurs[i];
	}
	this->erase();
	this->dinosaurs = temp;
}


Dinomass::Dinomass()
{
	this->size = 0; 
	this->capacity = 16;
	this->dinosaurs = new Dino[this->capacity];
}

Dinomass::Dinomass(const Dinomass& other)
{
	this->copy(other);
}

Dinomass& Dinomass::operator=(const Dinomass& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
} 

Dinomass& Dinomass::AddDino(const Dino& newdino)
{
	if (this->size >= this->capacity)
	{
		this->resize();
	}
	this->dinosaurs[size++] = newdino;
	return *this;
}

Dinomass& Dinomass::DeleteDino(const char* name)
{
	if (size > 0)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			if (strcmp(dinosaurs[i].getName(), name) == 0)
			{
				for (int j = i; j < size - 1; j++)
				{
					dinosaurs[i] = dinosaurs[i + 1];
				}
			}
		}
		size--;
	}
	return *this;
}

Dino& Dinomass::operator[](int i)const
{
	if (i >= 0)
	{
		return dinosaurs[i];
	}
	else
	{
		cerr << "No such boundary!" << endl;
	}
}

void Dinomass::saveDinos(ofstream& out)
{
	if (out.is_open())
	{
		out << this->size << endl;
		for (int i = 0; i < this->size; i++)
		{
			this->dinosaurs[i].saveDino(out);
		}
	}
}

void Dinomass::readDinos(ifstream& in)
{
	int size = 0;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		Dino dino;
		dino.readDino(in);
		this->AddDino(dino);
	}
}

int Dinomass::getsize()const
{
	return this->size;
}
Dinomass::~Dinomass()
{
	this->erase();
}