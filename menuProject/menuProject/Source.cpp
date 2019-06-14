#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Menu
{
public:
	Menu()
	{
		menuHeaderNames = { "Alcohol","Softs","Coffees","Smoothies" };
		menuContentNames = { "Beer","Viskey","Vine","Vodka","Coke","Sprite","Tonic","Mineral Water","Filtered Coffee","Mocha",
			"Macchiato","Latte","Lemonade","Cranberry Juice","Apple Juice","Atom" };
		priceList = { 7.49, 18.99, 15.25, 11.49, 3.49, 3.49, 4.49, 1.0, 4.50, 7.50, 9.90, 6.45, 5.49, 7.90, 6.90, 11.20 };
	}
	int menuChart();
	int createMenu();
protected:
	vector <string>menuHeaderNames;
	vector <string>menuContentNames;
	vector <double>priceList;
	int amount;
	int pointer;

	vector <string>menuHeaderName;
};
class Order : public Menu
{
public:
	void setLists();
	Order() { setListsTrick = false; }
protected:
	vector <string>ordersNameList;
	vector <double>ordersQuantityList;
	vector <double>orderPriceList;
	bool setListsTrick;
};
class Payment : public Order
{
public:
	double calculateBill();
	double payTheBill(int);
	double payTheBill(float);
protected:
	double totalPrice;

};
class Entrance : public Payment
{
public:
	void createOrder();
	void showMyOrders();
	void showTheBill();
	bool menuDecider(void);
protected:

};


bool Entrance::menuDecider(void)
{
	int a = 0;
menuOrder: /// Jump to over here
	switch (menuChart())
	{
	case 1:
		a = createMenu();
		if (a == 9)
		{
			goto menuOrder; //Jump for the menu infinities
		}
		break;
	case 2:
		createOrder(); // Press 2 to create your Order
		break;
	case 3:
		showMyOrders(); // Press 3 to show all orders with quantities
		break;
	case 4:
		showTheBill();
		//a = calculateBill();
		//if (a == 0)
		//{
		//	goto menuOrder;
		//}
		break;
	case 5:
		return 0;
	default:
		break;
	}
}
int Menu::menuChart()
{
	int res;
	cout << "|--------------------------- Entrance --------------------------|\n";
	cout << "||------------------------------||-----------------------------||\n";
	cout << "||       1.Show Menu            ||       2.Create Order        ||\n";
	cout << "||------------------------------||-----------------------------||\n";
	cout << "||       3.Show Orders          ||       4.Create Bill         ||\n";
	cout << "||------------------------------||-----------------------------||\n";
	cout << "||                           5.EXIT                            ||\n";
	cout << "||------------------------------||-----------------------------||\n";
	cin >> res;
	return res;
}
int Menu::createMenu()
{
	int r;
	cout << "|----------------------------- MENU ----------------------------|" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         1.Alcohol            ||         2.Softs             ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         1.Beer               ||         1.Coke              ||" << endl;
	cout << "||         2.Viskey             ||         2.Sprite            ||" << endl;
	cout << "||         3.Vine               ||         3.Tonic             ||" << endl;
	cout << "||         4.Vodka              ||         4.Mineral Water     ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         3.Coffees            ||         4.Smoothies         ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         1.Filtered Coffee    ||         1.Lemonade          ||" << endl;
	cout << "||         2.Mocha              ||         2.Cranberry Juice   ||" << endl;
	cout << "||         3.Macchiato          ||         3.Apple Juice       ||" << endl;
	cout << "||         4.Latte              ||         4.Atom              ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||-------------------------------------------------------------||" << endl;
	cout << "||                      Enter 9 to EXIT!                       ||\n";
	cout << "||-------------------------------------------------------------||\n";
	cin >> r;
	return r;
}
void Entrance::createOrder()
{
	int input = 0;
	int amount = 0;
	cout << "|----------------------------- MENU ----------------------------|" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         1.Alcohol            ||         2.Softs             ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         1.Beer               ||         1.Coke              ||" << endl;
	cout << "||         2.Viskey             ||         2.Sprite            ||" << endl;
	cout << "||         3.Vine               ||         3.Tonic             ||" << endl;
	cout << "||         4.Vodka              ||         4.Mineral Water     ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         3.Coffees            ||         4.Smoothies         ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||         1.Filtered Coffee    ||         1.Lemonade          ||" << endl;
	cout << "||         2.Mocha              ||         2.Cranberry Juice   ||" << endl;
	cout << "||         3.Macchiato          ||         3.Apple Juice       ||" << endl;
	cout << "||         4.Latte              ||         4.Atom              ||" << endl;
	cout << "||------------------------------||-----------------------------||" << endl;
	cout << "||-------------------------------------------------------------||" << endl;

picker:
	if (ordersNameList.size() == ordersNameList.max_size() - 1)
	{
		cout << "You have made all your order!" << endl;
		menuDecider();
	}

	cout << "You can make your choice, to finish your order Press 9." << endl << "E.g(1.Alcohol - 2.Beverage - 3.Coffees - 4.Smoothies):" << endl;
	cin >> input;

	if (input == 9)
	{
		menuDecider();
	}

	switch (input)
	{
	case 1:
		menuHeaderName.push_back("Alcohol");
		cout << "1. Beer \n" << "2. Viskey \n" << "3. Vine \n" << "4. Vodka \n" << endl << "Enter your choose here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Beer");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Viskey");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Vine");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Vodka");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	case 2:
		menuHeaderName.push_back("Beverages");
		cout << "1. Coke \n" << "2. Sprite \n" << "3. Tonic \n" << "4. Mineral Water  \n" << endl << "Enter your choose here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Coke");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Sprite");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Tonic");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Mineral Water");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	case 3:
		menuHeaderName.push_back("Coffees");
		cout << "1. Filtered Coffee \n" << "2. Mocha \n" << "3. Macchiato \n" << "4. Latte \n" << endl << "Enter your choose here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Filtered Coffee");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Mocha");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Macchiato");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Latte");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		default:
			break;
		}
	case 4:
		menuHeaderName.push_back("Smoothies");
		cout << "1. Lemonade \n" << "2. Cranberry Juice \n" << "3. Apple Juice \n" << "4. Atom \n" << endl << "Enter your choose here: ";
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Lemonade");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 2:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Cranberry Juice");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 3:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Apple Juice");
			ordersQuantityList.push_back(amount);
			amount = 0;
			goto picker;
		case 4:
			cout << "How many do you want?: ";
			cin >> amount;
			ordersNameList.push_back("Atom");
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
void Order::setLists()
{
	setListsTrick = true;
	//find money at that point!
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
	//order the garbage values in vector!!
	//e.g beer sprite vine beer. There are two beer in vector, so erase that multiple inputs and add quantity to original one
	for (int i = 0; i < ordersNameList.size(); i++)
	{
		for (int j = 0; j < ordersNameList.size(); j++)
		{
			if (ordersNameList[i] == ordersNameList[j] && i < j)
			{
				ordersNameList.erase(ordersNameList.begin() + j);
				ordersQuantityList[i] += ordersQuantityList.at(j);//
				i = -1;//makes the first loop's starting value 0, i++ sets i=-1 to i=0 !
			}
		}

	}
}
void Entrance::showMyOrders()
{
	int input = 0;
	setLists();
	for (int i = 0; i < ordersNameList.size(); i++)
	{
		cout << ordersNameList[i] << "  " << orderPriceList[i] << " $" << " - " << ordersQuantityList[i] << " piece  " << endl;
	}

	cout << "You can return Entrance, Enter 9: ";
	cin >> input;
	if (input == 9)
	{
		menuDecider();
	}
}
void Entrance::showTheBill()
{
	int iInput = 0;
	float dInput = 0.0;
	int check = 0;
	if (!setListsTrick)
	{
		setLists();
	}

	cout << "|----------------------------- BILL ----------------------------|" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "\n\n\n";
	for (int i = 0; i < ordersNameList.size(); i++)
	{
		cout << "     " << ordersNameList[i] << "  " << orderPriceList[i] << " $" << " - " << ordersQuantityList[i] << " piece  "
			<< endl;

	}
	cout << "\n\n\n";
	cout << "                                          Total: " << calculateBill() << " $" << endl;
	cout << "\n\n\n\n\n\n";
	cout << "|---------------------------------------------------------------|" << endl;
	cout << "|---------------------------------------------------------------|" << endl;

	cout << "You can choose your payment methodology (1.Credit Cart, 2.Cash): ";
	cin >> check;
	if (check == 1)
	{
		cout << "You can enter your payment amount: ";
		cin >> iInput;
		totalPrice = payTheBill(dInput);
		cout << "Total: " << totalPrice;
	}
	else if (check == 2)
	{
		cout << "You can enter your payment amount: ";
		cin >> iInput;
		payTheBill(iInput);
	}
}
double Payment::calculateBill()
{
	double result = 0.0;
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

double Payment::payTheBill(int pay)
{
	totalPrice -= pay;
	return totalPrice;
}
double Payment::payTheBill(float pay)
{
	totalPrice -= pay;
	return totalPrice;
}
int main()
{
	Entrance en;
	en.menuDecider();

	system("pause");
	return 0;
}