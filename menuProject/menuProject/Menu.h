#ifndef MENU_H
#define MENU_H
#include "Header.h"

class Menu
{
public:
	Menu()
	{
		menuHeaderNames = { "Autos","SUVs","Sports","Pick-Ups" };
		menuContentNames = { "Audi","BMW","Mercedes","Volvo",
							 "BMW","Hummer","Jeep","Range Rover",
							 "Bentley","Ferrari","Lamborghini","Maserati",
							 "Ford","Nissan","Toyota","Volkswagen" };

		priceList = { 249, 299, 249, 249, 499, 599, 499, 599, 4999, 1999, 2999, 1999, 299, 299, 299, 299 };
		raiseMessage = "Not yet";
		saleMessage = "Not yet";

	}
	//Operator overloading
	vector <double>operator*(double);
	vector <double>operator/(double);
	int menuChart();
	int createMenu();
	int createRaiseChart();
	int createSaleChart();
protected:
	vector <string>menuHeaderNames;
	vector <string>menuContentNames;
	vector <double>priceList;
	string raiseMessage;
	vector <double>raiseList;
	string saleMessage;
	vector <double>saleList;
	int amount;
	int pointer;

	vector <string>menuHeaderName;
};
class Order : public Menu
{
public:
	void setLists();
	Order() { setListCheck = false; isOrdered = false; }
protected:
	vector <string>ordersNameList;
	vector <double>ordersQuantityList;
	vector <double>orderPriceList;
	bool setListCheck;
	bool isOrdered;
};
class Payment : public Order
{
public:
	Payment() { changeMessage = ""; }
	double calculateBill();
	double payTheBill(int);
	double payTheBill(double);
protected:
	double totalPrice;
	string changeMessage;

};




int Menu::menuChart()
{
	int res;
	int space = 0;
	cout << "|                            Entrance                           |\n";
	cout << "||                              ||                             ||\n";
	cout << "||       1.Cars Menu            ||       2.Create Order        ||\n";
	cout << "||                              ||                             ||\n";
	cout << "||       3.Show Orders          ||       4.Pay Bill            ||\n";
	cout << "||                              ||                             ||\n";
	cout << "||                          Management                         ||\n";
	cout << "||                              ||                             ||\n";
	cout << "||                           5.Raise                           ||\n";
	cout << "||                           6.Sale                            ||\n";
	cout << "||                                                             ||\n";
	cout << "||                    Status: " << raiseMessage << "           ||\n";
	cout << "||                    Status: " << saleMessage << "            ||\n";
	if (raiseList.size() != 0)
	{
		for (int i = 0; i < raiseList.size(); i++)
		{
			cout << setw(14) << "-" << raiseList[i] << "-";
			space += 14;
			if ((space / 3) == 14)
			{
				cout << "\n";
			}
		}
	}
	if (saleList.size() != 0)
	{
		for (int i = 0; i < saleList.size(); i++)
		{
			cout << setw(12) << "-" << saleList[i] << "-";
			space += 15;
			if ((space / 3) != 0)
			{
				cout << "\n";
			}
		}
	}

	cout << "\n";
	cout << "||                              ||                             ||\n";
	cout << "||                            9.EXIT                           ||\n";
	cout << "||                              ||                             ||\n";
	cin >> res;
	return res;
}
int Menu::createRaiseChart()
{
	double input = 0.0;
	string str = "";
	cout << "|                              RAISE                            |" << endl;
	cout << "|                                                               |" << endl;
	cout << "|                     Follow the Instructions                   |" << endl;
	cout << "|                 Exit without raise for goods '0'              |" << endl;
	cout << "|          Type percentage of raise then type '9' to EXIT!      |" << endl;
	cout << "|                                                               |" << endl;
	cout << "|                                                               |" << endl;
	cout << "\n\n";
	cout << "Raise Percentage(e.g. 5 - 15 - 20): ";
	cin >> input;

	if (input == 0)
	{
		return 9;
	}
	else 
	{
		operator*(input);
		raiseMessage = "Goods have raised";
		raiseList.push_back(input);
		return 9;
	}

}
int Menu::createSaleChart()
{
	double input = 0.0;
	string str = "";
	cout << "|                              SALE                             |" << endl;
	cout << "|                                                               |" << endl;
	cout << "|                     Follow the Instructions                   |" << endl;
	cout << "|                 Exit without sale for goods '0'               |" << endl;
	cout << "|          Type percentage of sale then type '9' to EXIT!       |" << endl;
	cout << "|                                                               |" << endl;
	cout << "|                                                               |" << endl;
	cout << "\n\n";
	cin >> input;

	if (input == 0)
	{
		return 9;
	}
	else
	{
		operator/ (input);
		saleMessage = "Goods have saled";
		saleList.push_back(input);
		return 9;
	}

}
int Menu::createMenu()
{
	int r;
	cout << "|                           CARS  MENU                          |" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         1.Autos              ||         2.SUVs              ||" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         1.Audi               ||         1.BMW               ||" << endl;
	cout << "||         2.BMW                ||         2.Hummer            ||" << endl;
	cout << "||         3.Mercedes           ||         3.Jeep              ||" << endl;
	cout << "||         4.Volvo              ||         4.Range Rover       ||" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         3.Sports             ||         4.Pick-Ups          ||" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         1.Bentley            ||         1.Ford              ||" << endl;
	cout << "||         2.Ferrari            ||         2.Nissan            ||" << endl;
	cout << "||         3.Lamborghini        ||         3.Toyota            ||" << endl;
	cout << "||         4.Maserati           ||         4.Volkswagen        ||" << endl;
	cout << "||                                                             ||" << endl;
	cout << "||                                                             ||" << endl;
	cout << "||                      Enter 9 to EXIT!                       ||\n";
	cout << "||                                                             ||\n";
	cin >> r;
	return r;
}
vector <double>Menu::operator*(double x)
{
	double raise = 0.00;
	raise = x / 100.0;
	for (int i = 0; i < priceList.size(); i++)
	{
		priceList[i] = (priceList[i] * raise) + priceList[i];
	}
	return priceList;
}
vector <double>Menu::operator/(double x)
{
	double sale = 0.00;
	sale = x * 100.0 ;
	for (int i = 0; i < priceList.size(); i++)
	{
		priceList[i] = priceList[i] - (priceList[i] / sale) ;
	}
	return priceList;
}

void Order::setLists()
{
	setListCheck = true;
	pointer = 0;
	
	for (int i = 0; i < menuContentNames.size(); i++)
	{
		if (pointer >= ordersNameList.size()) {
			break;
		}
		if (menuContentNames[i] == ordersNameList[pointer])
		{
			orderPriceList.push_back(priceList[i]);
			pointer++;
			i = -1;
		}
	}

	
	for (int i = 0; i < ordersNameList.size(); i++)
	{
		for (int j = 0; j < ordersNameList.size(); j++)
		{
			if (ordersNameList[i] == ordersNameList[j] && i < j)
			{
				ordersNameList.erase(ordersNameList.begin() + j);
				ordersQuantityList[i] += ordersQuantityList.at(j);
				i = -1;
			}
		}

	}
}

double Payment::calculateBill()
{
	double result = 0.0;
	double ret = 0;
	if (0 >= orderPriceList.size())
	{
		cout << "You haven't create any order, please make any order: " << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < orderPriceList.size(); i++)
		{
			totalPrice += orderPriceList[i] * ordersQuantityList[i];
		}
		return totalPrice;
	}
}
double Payment::payTheBill(double pay)
{
	if (pay < totalPrice)
	{
		changeMessage = "You need to pay more: ";
		totalPrice = totalPrice - pay;
		if (floor(totalPrice) == 0)
		{
			changeMessage = "Your Change: ";
		}
	}
	else
	{	
		changeMessage = "Your Change: ";
		totalPrice = pay - totalPrice;
	}

	return totalPrice;
}
double Payment::payTheBill(int pay)
{
	if (pay < totalPrice)
	{
		changeMessage = "Pay more: ";
		totalPrice = totalPrice - pay;
	}
	else
	{
		changeMessage = "Your Change: ";
		totalPrice = pay - totalPrice;
	}
	return totalPrice;
}
#endif 