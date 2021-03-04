#include <iostream>
#include "Dino.h"
#include <cstring>

Dino::Dino()
{
	setName("");
	setGender(true);
	setEra("");
	setClade("");
	setFood("");
	setCategory("");
	setClimate("");
}
Dino::Dino(const char* name, bool gender, const char* era, const char* clade,const char* category, const char* food, const char* climateneeded)
{
	setName(name);
	setGender(gender);
	setEra(era);
	setClade(clade);
	setFood(food);
	setCategory(category);
	setClimate(climateneeded);
}

void Dino::saveDino(ofstream& os)
{
	if (os.is_open())
	{
		os << strlen(this->name) << " ";
		os << this->name << endl;
		os << strlen(this->era) << " ";
		os << this->era << endl;
		os << strlen(this->clade) << " ";
		os << this->clade << endl;
		os << strlen(this->category) << " ";
		os << this->category << endl;
		os << strlen(this->food) << " ";
		os << this->food << endl;
		os << this->gender << endl;
	}
	else
	{
		cout << "Cannot open stream for saving dino!" << endl;
	}
}

void Dino::readDino(ifstream& is)
{
	if (is.is_open())
	{
		int NameLength = 0;
		int EraLength = 0;
		int CladeLength = 0;
		int CategoryLength = 0;
		int FoodLength = 0;

		is >> NameLength;
		is.seekg(1, ios::cur);
		is.getline(this->name, NameLength + 1);
		is >> EraLength;
		is.seekg(1, ios::cur);
		is.getline(this->era, EraLength + 1);
		is >> CladeLength;
		is.seekg(1, ios::cur);
		is.getline(this->clade, CladeLength + 1);
		is >> CategoryLength;
		is.seekg(1, ios::cur);
		is.getline(this->category, CategoryLength + 1);
		is >> FoodLength;
		is.seekg(1, ios::cur);
		is.getline(this->food, FoodLength + 1);
		//is.seekg(1, ios::cur);
		is >> this->gender;
		
	}
}

void Dino::setName(const char* name)
{
	strcpy_s(this->name, 255, name);
}

void Dino::setGender(bool gender)
{
	this->gender = gender;
}

void Dino::setClade(const char* clade)
{
	strcpy_s(this->clade, 63, clade);
}

void Dino::setEra(const char* era)
{
	strcpy_s(this->era, 127, era);
}

void Dino::setFood(const char* food)
{
	strcpy_s(this->food, 31, food);
}

void Dino::setCategory(const char* category)
{
	strcpy_s(this->category, 31, category);
}

void Dino::setClimate(const char* climateneeded)
{
	strcpy_s(this->climateneeded, 31, climateneeded);
}

const char* Dino::getName()const
{
	return this->name;
}

bool Dino::getGender()const
{
	return this->gender;
}

const char* Dino::getEra()const
{
	return this->era;
}

const char* Dino::getClade()const
{
	return this->clade;
}

const char* Dino::getFood()const
{
	return this->food;
}

const char* Dino::getCategory()const
{
	return this->category;
}

const char* Dino::getClimate()const
{
	return this->climateneeded;
}