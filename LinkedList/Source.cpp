#include <iostream>
#include <string>
#include <iomanip>
#include "Cars.h"
#include "CarList.h"

using namespace std;

int main()
{
	//Part 1 (Creating the first chunk of data)
	CarList TempList;
	Cars tempCar;
	try {
		tempCar.set_values("Porsche", "911", "Silver", 2005, 18990, 1237362);
		TempList.Add(tempCar);
		tempCar.set_values("Ford", "Mustang", "Red", 2007, 49842, 7337372);
		TempList.Add(tempCar);
		tempCar.set_values("Chevrolet", "Beretta", "Black", 1989, 90332, 2873644);
		TempList.Add(tempCar);

		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		TempList.Display(&TempList.get_head());
	}
	catch (CarList::exEmptyList)
	{
		cout << "List was empty!" << endl;
	}
	
	//Part 2 (Creating a new car and inserting it into the list)
	string make, model, color;
	int year, milage, VIN;

	//Get input from user
	cout << "Please enter the information for a new car.\n";
	cout << "Make: ";
	cin >> make;
	cout << "Model: ";
	cin >> model;
	cout << "Color: ";
	cin >> color;
	cout << "Year: ";
	cin >> year;
	cout << "Milage: ";
	cin >> milage;
	cout << "VIN: ";
	cin >> VIN;

	//Make car
	try
	{
		tempCar.set_values(make, model, color, year, milage, VIN);
		TempList.Insert(tempCar);

		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		TempList.Display(&TempList.get_head());
	}
	catch (CarList::exEmptyList)
	{
		cout << "List was empty!" << endl;
	}

	//Part 3 (Removing a car from the list)
	try
	{
		cout << "Please choose a car VIN to delete from the list:";
		cin >> VIN;
		TempList.Remove(&TempList.get_head(), &TempList.get_head(), VIN);

		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		TempList.Display(&TempList.get_head());
	}
	catch (CarList::exEmptyList)
	{
		cout << "List was empty!" << endl;
	}
	catch (CarList::exValueNotFound)
	{
		cout << "Value was not found in the list" << endl;
	}
	
	system("Pause");
}