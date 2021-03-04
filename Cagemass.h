#pragma once
#include <iostream>
#include "Cage.h"

using namespace std;

class Cagemass
{
private:
	size_t size;
	size_t capacity;
	Cage* cages;
private:
	void copy(const Cagemass& other); 
	void resize();
	void erase();
public:
	///Canonic
	Cagemass();
	Cagemass(const Cagemass& other); 
	Cagemass& operator=(const Cagemass& other);
	Cage& operator[](int i)const;
	~Cagemass();
public:
	///Additional
	Cagemass& AddCage(const Cage& newcage);
	void saveCages(ofstream& out);
	void readCages(ifstream& in);
	int getSize()const;
	
};

