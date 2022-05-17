#pragma once

#ifndef PLANEDATA
#define PLANEDATA

class PlaneData
{
private:
	long long id_;
	char name_[256];
	char type_[256];
	long long flightsAmount_;

public:
	PlaneData();	
	PlaneData(const long long& id, const char* name, const char* type, const long long& flightsAmount);
	~PlaneData();

	long long getId() const;
	void getName(char* name) const;
	void getType(char* type) const;
	long long getFlightsAmount() const;
	void printInfo();
	bool isEmpty();

	void setId(const long long& id);
	void setName(const char* name);
	void setType(const char* type);
	void setFlightsAmount(const long long& flightsAmount);
	void initializePlaneThroughInput();
};

#endif