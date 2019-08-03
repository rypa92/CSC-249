#ifndef CARS_H
#define CARS_H

using namespace std;

class Cars
{
private:
	string make, model, color;
	int year, milage, VIN;
public:
	//Constructor
	void set_values(string, string, string, int, int, int);

	//Sets
	void set_make(string x);
	void set_model(string x);
	void set_color(string x);
	void set_year(int x);
	void set_milage(int x);
	void set_VIN(int x);

	//Gets
	string get_make(void);
	string get_model(void);
	string get_color(void);
	int get_year(void);
	int get_milage(void);
	int get_VIN(void);

	//Functions
	void get_values(void);
	Cars get_data(void);

	//Exception Classes
	class exNegativeMilage {};
	class exYearBefore1970 {};
	class exInvalidMake {};
};

//Constructors
void Cars::set_values(string _make, string _model, string _color, int _year, int _milage, int _VIN)
{
	set_make(_make);
	set_model(_model);
	set_color(_color);
	set_year(_year);
	set_milage(_milage);
	set_VIN(_VIN);
}

//Long list of sets
void Cars::set_make(string x)
{
	if (x.length() > 3) {
		make = x;
	}
	else {
		throw(exInvalidMake());
	}
}
void Cars::set_model(string x)
{
	model = x;
}
void Cars::set_color(string x)
{
	color = x;
}
void Cars::set_year(int x)
{
	if (x > 1970) {
		year = x;
	}
	else {
		throw(exYearBefore1970());
	}
}
void Cars::set_milage(int x)
{
	if (x > 0) {
		milage = x;
	}
	else {
		throw(exNegativeMilage());
	}
}
void Cars::set_VIN(int x)
{
	VIN = x;
}

//Long list of gets
string Cars::get_make()
{
	return make;
}
string Cars::get_model()
{
	return model;
}
string Cars::get_color()
{
	return color;
}
int Cars::get_year()
{
	return year;
}
int Cars::get_milage()
{
	return milage;
}
int Cars::get_VIN()
{
	return VIN;
}

//Functions
void Cars::get_values()
{
	cout << setw(15) << make << setw(15) << model << setw(15) << color
		<< setw(15) << year << setw(15) << milage << setw(15) << VIN << endl;
}
#endif