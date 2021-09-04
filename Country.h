#pragma once
#include "Libraries.h"

class Country
{
private:
	char* name;
	char* continent;
	unsigned int population;
public:
	Country() {
		name = nullptr;
		continent = nullptr;
		population = 0;
	}
	Country(const char* name, const char* continent, const unsigned int population){
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->continent = new char[strlen(continent) + 1];
		strcpy(this->continent , continent);
		this->population = population;
	}
	char* getName() {
		return this->name;
	}
	char* getContinent() {
		return this->continent;
	}
	unsigned int getPopulation() {
		return this->population;
	}
	void setName(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void setContinent(const char* continent) {
		this->continent = new char[strlen(continent) + 1];
		strcpy(this->continent, continent);
	}
	void setPopulation(const unsigned int population) {
		this->population = population;
	}
	void changeName(const char* name) {
		delete[]this->name;
		setName(name);
	}
	void changeContinent(const char* continent) {
		delete[] this->continent;
		setContinent(continent);
	}
	void changePopulation(const unsigned int population) {
		this->population = population;
	}
	void free_name() {
		delete[]name;
		name = nullptr;
	}
	void free_continent() {
		delete[] continent;
		continent = nullptr;
	}
	bool operator ==(const Country &another) {
		if (!strcmp(this->name, another.name))
					return true;
		return false;
	}
	bool operator <(const Country &another) {
		if (strcmp(this->name, another.name) < 0)
			return true;
		return false;
	}
	bool operator >(const Country &another) {
		if (strcmp(this->name, another.name) > 0)
			return true;
		return false;
	}
	bool operator <=(const Country &another) {
		if (strcmp(this->name, another.name) <= 0)
			return true;
		return false;
	}
	bool operator >=(const Country &another) {
		if (strcmp(this->name, another.name) >= 0)
			return true;
		return false;
	}
	void Display() {
		if (this->name == nullptr && this->continent == nullptr){
			cout << "Country Doesn't exist "<<endl;
			return;
		}
		cout << "Country: " 
			<< this->name << "\nContinent: " 
			<< this->continent << "\nPopulation " 
			<< this->population << endl;
	}
	~Country() {
		if (name != nullptr && continent != nullptr) {
			free_name();
			free_continent();
			this->population = 0;
		}
	}
};