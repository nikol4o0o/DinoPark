#pragma once
#include <fstream>
using namespace std;
class Dino
{
private:
	char name[256];
	bool gender;
	char era[128]; 
	char clade[64];
	char category[32];
	char food[32];
	char climateneeded[32];
public:
	//Canonic
	Dino();
	Dino(const char* name, bool gender, const char* era, const char* clade, const char* category, const char* food,const char* climateneeded);
	void saveDino(ofstream& os);
	void readDino(ifstream& is);

public:
		///Setters
		void setName(const char* name);
		void setGender(bool gender); 
		void setEra(const char* era);
		void setClade(const char* clade); 
		void setFood(const char* food); 
		void setCategory(const char* category);
		void setClimate(const char* climateneeded);

		///Getters
		const char* getName()const;
		bool getGender()const;
		const char* getEra()const; 
		const char* getClade()const; 
		const char* getFood()const;
		const char* getCategory()const;
		const char* getClimate()const;
};

