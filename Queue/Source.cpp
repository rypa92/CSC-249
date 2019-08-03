#include <iostream>
#include <string>
#include <iomanip>
#include "Cars.h"
#include "DynamicCarQueue.h"

using namespace std;

int main()
{
	//Creating the list and filling it with data
	DynamicCarQueue tempQueue;
	Cars tempCar;
	try {
		tempCar.set_values("Porsche", "911", "Silver", 2005, 18990, 1237362);
		tempQueue.Enqueue(tempCar);
		tempCar.set_values("Ford", "Mustang", "Red", 2007, 49842, 7337372);
		tempQueue.Enqueue(tempCar);
		tempCar.set_values("Chevrolet", "Beretta", "Black", 1989, 90332, 2873644);
		tempQueue.Enqueue(tempCar);

		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		tempQueue.Display(&tempQueue.get_front());
		cout << endl;
	}
	catch (DynamicCarQueue::exEmptyList)
	{
		cout << "Queue was empty!" << endl;
	}

	cout << "Cars currently in inventory: " << tempQueue.Size(&tempQueue.get_front()) << endl;

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
		tempQueue.Enqueue(tempCar);

		//Display forwards
		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		tempQueue.Display(&tempQueue.get_front());
		cout << endl;

		//Display in reverse
		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		tempQueue.DisplayReverse(&tempQueue.get_front());
		cout << endl;
	}
	catch (DynamicCarQueue::exEmptyList)
	{
		cout << "Queue was empty!" << endl;
	}

	//Part 3 (Dequeueing two cars and getting their prices)
	try
	{
		int firPrice = tempQueue.Dequeue().get_VIN();
		int secPrice = tempQueue.Dequeue().get_VIN();

		cout << "The car with VIN: " << firPrice << " has been pulled from inventory!" << endl;
		cout << "The car with VIN: " << secPrice << " has been pulled from inventory!" << endl;

		//Display current inventory --
		cout << "Current inventory: " << endl;
		cout << setw(15) << "Make" << setw(15) << "Model" << setw(15) << "Color"
			<< setw(15) << "Year" << setw(15) << "Milage" << setw(15) << "VIN" << endl;
		tempQueue.Display(&tempQueue.get_front());
		cout << endl;
	}
	catch (DynamicCarQueue::exEmptyList)
	{
		cout << "Queue was empty!" << endl;
	}

	system("Pause");
}