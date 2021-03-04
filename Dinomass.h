#pragma once
#include <iostream>
#include "Dino.h"

using namespace std;

class Dinomass
{
private:
	Dino* dinosaurs; 
	size_t size; 
	size_t capacity; 

private:
	///Canonic
	void copy(const Dinomass& other);
	void erase();
	void resize();
public:
	///Canonic
	Dinomass(); 
	Dinomass(const Dinomass& other);
	Dinomass& operator=(const Dinomass& other);
	Dino& operator[](int i)const;
	~Dinomass();
public:
	//Additional
	void saveDinos(ofstream& out);
	void readDinos(ifstream& in);
	Dinomass& AddDino(const Dino& newdino);
	Dinomass& DeleteDino(const char* name);
	int getsize()const;
};

