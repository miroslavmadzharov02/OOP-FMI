#include "PlaneData.h"
#include "StringActions.h"
#include <iostream>

PlaneData::PlaneData() : id_(0), flightsAmount_(0)
{
	name_[0] = '\0';
	type_[0] = '\0';
}

PlaneData::PlaneData(const long long& id, const char* name, const char* type, const long long& flightsAmount) 
	: id_(id), flightsAmount_(flightsAmount)
{
	using namespace StringActions;
	strcpy_safe(name_, name, sizeof(name_));
	strcpy_safe(type_, type, sizeof(type_));
}

PlaneData::~PlaneData() { }

long long PlaneData::getId() const
{
	return id_;
}

void PlaneData::getName(char* name) const
{
	StringActions::strcpy_safe(name, name_, sizeof(name));
}

void PlaneData::getType(char* type) const
{
	StringActions::strcpy_safe(type, type_, sizeof(type));
}

long long PlaneData::getFlightsAmount() const
{
	return flightsAmount_;
}

void PlaneData::printInfo()
{
	std::cout << "Plane Id: " << id_
		<< "\nPlane name: " << name_
		<< "\nPlane type: " << type_
		<< "\nAmount of flights: " << flightsAmount_ << '\n';
}

bool PlaneData::isEmpty()
{
	return id_ == 0 && flightsAmount_ == 0 && name_[0] == '\0' && type_[0] == '\0';
}

void PlaneData::setId(const long long& id)
{
	id_ = id;
}

void PlaneData::setName(const char* name)
{
	StringActions::strcpy_safe(name_, name, sizeof(name_));
}

void PlaneData::setType(const char* type)
{
	StringActions::strcpy_safe(type_, type, sizeof(type_));
}

void PlaneData::setFlightsAmount(const long long& flightsAmount)
{
	flightsAmount_ = flightsAmount;
}

void PlaneData::initializePlaneThroughInput()
{
	std::cout << "Enter ID:\n";
	std::cin >> id_;
	std::cout << "Enter plane name:\n";
	std::cin >> name_;
	std::cout << "Enter plane type:\n";
	std::cin >> type_;
	std::cout << "Enter amount of flights plane has:\n";
	std::cin >> flightsAmount_;
}