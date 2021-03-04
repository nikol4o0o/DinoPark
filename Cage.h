#pragma once
#include <iostream>
#include <fstream>
#include "Dino.h"
#include "Dinomass.h"
class Cage
{
private:
	size_t size; 
	char climate[32]; 
	Dinomass dinosinthecage[10];
	char erainthecage[128];
public:
	Cage(); 
	Cage(size_t size, const char* climate, const char* eraintecage);
	void saveCage(ofstream& os);
	void readCage(ifstream& is);
	void AddDinosinthecage(Dino& dinosaur);
	bool havespace();

public:
	///Setters
	void setSize(size_t size);
	void setClimate(const char* climate);
	void setErainthecage(const char* era);

	///Getters
	size_t getSize()const;
	const char* getClimate()const; 
	const char* getErainthecage()const;

};

