#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "Menu.h"

class Entrance : public Payment
{
public:
	void createOrder();
	void showMyOrders();
	int showTheBill();
	void cleanOrders();
	bool menuDecider(void);
protected:

};
bool Entrance::menuDecider(void)
{
	int a = 0;
	menuOrder: 
	switch (menuChart())
	{
	case 1:
		a = createMenu();
		if (a == 9)
		{
			goto menuOrder; 
			a = 0;
		}
		break;
	case 2:
		createOrder(); 
		break;
	case 3:
		showMyOrders(); 
		break;
	case 4:
		a = showTheBill(); 
		if (a == 9)
		{
			a = 0;
			goto menuOrder;
			
		}
		break;
	case 5:
		if (!setListCheck && !isOrdered)
		{
			a = createRaiseChart();
			if (a == 9)
			{
				a = 0;
				goto menuOrder;
			}
		}
		else 
		{
			cout << "Can't raise,Ordered something" << endl;
		}
	case 6:
		if (!setListCheck && !isOrdered)
		{
			a = createSaleChart();
			if (a == 9)
			{
				a = 0;
				goto menuOrder;
			}
		}
		else
		{
		cout << "Can't sale,Ordered something" << endl;
		}


		return 0;
	default:
		break;
	}
}
void Entrance::createOrder()
{
	int input = 0;
	int amount = 0;
	isOrdered = true;
	cout << "|                              MENU                             |" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         1.Autos              ||         2.SUVs              ||" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         1.Audi           249$||         1.BMW           499$||" << endl;
	cout << "||         2.BMW            299$||         2.Hummer        599$||" << endl;
	cout << "||         3.Mercedes       249$||         3.Jeep          499$||" << endl;
	cout << "||         4.Volvo          249$||         4.Range Rover   599$||" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         3.Sports             ||         4.Pick-Ups          ||" << endl;
	cout << "||                              ||                             ||" << endl;
	cout << "||         1.Bentley       4999$||         1.Ford          299$||" << endl;
	cout << "||         2.Ferrari       1999$||         2.Nissan        299$||" << endl;
	cout << "||         3.Lamborghini   2999$||         3.Toyota        299$||" << endl;
	cout << "||         4.Maserati      1999$||         4.Volkswagen    299$||" << endl;
	cout << "||                                                             ||" << endl;
	cout << "||                                                             ||" << endl;

picker:
	if (ordersNameList.size() == ordersNameList.max_size() - 1)
	{
		cout << "You have made all your order!" << endl;
		menuDecider();
	}

	cout << "You can make your choice, to finish your order Press 9." << endl << "E.g(1.Autos - 2.SUVs - 3.Sports - 4.Pick-Ups):" << endl;
	cin >> input;

	if (input == 9)
	{
		menuDecider();
	}

	switch (input)
	{
	case 1:
		menuHeaderName.push_back("Autos");
		cout << "1. Audi \n" << "2. BMW \n" << "3. Mercedes \n" << "4. Volvo \n" << endl << "Choose from here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Audi");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("BMW");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Mercedes");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Volvo");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	case 2:
		menuHeaderName.push_back("SUVs");
		cout << "1. BMW \n" << "2. Hummer \n" << "3. Jeep \n" << "4. Range Rover  \n" << endl << "Choose from here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("BMW");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Hummer");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Jeep");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Range Rover");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	case 3:
		menuHeaderName.push_back("Sports");
		cout << "1. Bentley \n" << "2. Ferrari \n" << "3. Lamborghini \n" << "4. Maserati \n" << endl << "Choose from here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Bentley");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Ferrari");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Lamborghini");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Maserati");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	case 4:
		menuHeaderName.push_back("Pick-Ups");
		cout << "1. Ford \n" << "2. Nissan \n" << "3. Toyota \n" << "4. Volkswagen \n" << endl << "Choose from here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Ford");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Nissan");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Toyota");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many days you want?: ";
			cin >> amount;
			ordersNameList.push_back("Volkswagen");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	default:
		break;
	}

}
void Entrance::showMyOrders()
{
	int input = 0;
	if (!isOrdered)
	{
		cout << "Return Entrance, Enter 9: ";
		cin >> input;
		if (input == 9)
		{
			menuDecider();
		}
	}
	else 
	{
		setLists();
		for (int i = 0; i < ordersNameList.size(); i++)
		{
			cout << fixed << setprecision(2) << ordersNameList[i] << "  " << orderPriceList[i] << " $" << " - " << ordersQuantityList[i] << " days  " << endl;
		}

		cout << "Return Entrance, Enter 9: ";
		cin >> input;
		if (input == 9)
		{
			menuDecider();
		}
	}
}
int Entrance::showTheBill()
{
	int ret;
	int iInput = 0;
	double dInput = 0;
	int check = 0;

	if (!setListCheck && isOrdered)
	{
		setLists();
	}

	cout << "|                              BILL                             |" << endl;
	cout << "|                                                               |" << endl;
	cout << "\n\n\n";
	for (int i = 0; i < ordersNameList.size(); i++)
	{
		cout << fixed << setprecision(2) << "     " << ordersNameList[i] << "  " << orderPriceList[i] << " $" << " - " << ordersQuantityList[i] << " days  "
			<< endl;

	}
	cout << "\n\n\n";
	cout << "                                          Total: " << calculateBill() << " $" << endl;
	cout << "\n\n\n\n\n\n";
	cout << "|                                                               |" << endl;
	cout << "|                                                               |" << endl;

payAgain:
	if (!isOrdered)
	{
		cout << "Enter '9' for MENU: ";
		cin >> ret;
		return ret;
	}
	else 
	{
		cout << "Payment method: \n1.Cash:\n2.Credit Card:\n ";
		cin >> check;

		if (check == 1)
		{
			cout << "Enter your payment amount: ";
			cin >> dInput;
			totalPrice = payTheBill(dInput);
			cout << fixed << setprecision(2) << changeMessage << totalPrice << endl;
			if (changeMessage == "Pay more: ")
			{
				goto payAgain;
			}
			cout << "Enter '9' for MENU:";
			cin >> ret;
			cleanOrders();
			return ret;
		}
		else if (check == 2)
		{
			cout << "Enter your amount: ";
			cin >> iInput;
			totalPrice = payTheBill(iInput);
			cout << changeMessage << totalPrice << endl;
			cout << "Enter '9' to return MENU:";
			cin >> ret;
			cleanOrders();
			return ret;
		}
	}
	
}
void Entrance::cleanOrders()
{
	setListCheck = false;
	isOrdered = false;
	ordersNameList.erase(ordersNameList.begin(), ordersNameList.begin() + ordersNameList.size());
	ordersQuantityList.erase(ordersQuantityList.begin(), ordersQuantityList.begin() + ordersQuantityList.size());
	orderPriceList.erase(orderPriceList.begin(), orderPriceList.begin() + orderPriceList.size());
	
	totalPrice = 0.00;
}

#endif 
