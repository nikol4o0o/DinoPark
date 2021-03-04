#include "Cage.h"
#include <cstring>

Cage::Cage()
{
	this->size = 0; 
	strcpy_s(this->climate, 31, "");
	strcpy_s(this->erainthecage, 127, "");
}

Cage::Cage(size_t size, const char* climate, const char* erainthecage)
{
	setSize(size);
	setClimate(climate);
	setErainthecage(erainthecage);

}
void Cage::setSize(size_t size)
{
	this->size = size;
}

void Cage::setClimate(const char* climate)
{
	strcpy_s(this->climate, 31, climate);
}

void Cage::setErainthecage(const char* erainthecage)
{
	strcpy_s(this->erainthecage, 127, erainthecage);
} 

void Cage::AddDinosinthecage(Dino& dinosaur)
{
		this->dinosinthecage->AddDino(dinosaur);
}

bool Cage::havespace()
{
	if (dinosinthecage->getsize() < this->size)
	{
		return true;
	}
	return false;
}

void Cage::saveCage(ofstream& os)
{
	if (os.is_open())
	{
		os << strlen(this->climate) << " ";
		os << this->climate << endl;
		os << strlen(this->erainthecage) << " ";
		os << this->erainthecage << endl;
		os << this->size << endl;
	}
	else
	{
		cout << "Cannot open stream for saving cage!" << endl;
	}
}

void Cage::readCage(ifstream& is)
{
	if (is.is_open())
	{
		int ClimateLength = 0;
		int ErainTheCageLength = 0;
		

		is >> ClimateLength;
		is.seekg(1, ios::cur);
		is.getline(this->climate, ClimateLength + 1);
		is >> ErainTheCageLength;
		is.seekg(1, ios::cur);
		is.getline(this->erainthecage, ErainTheCageLength + 1);
		is >> this->size;

	}
}

size_t Cage::getSize()const
{
	return this->size;
}

const char* Cage::getClimate()const
{
	return this->climate;
}

const char* Cage::getErainthecage()const
{
	return this->erainthecage;
}