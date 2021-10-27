#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using std::this_thread::sleep_for;

int main() {
	char choice = 'a';
	double price = 50;
	double asset = 0;
	double usd = 1000;
	double stock = 0;
	double buyVolume = 0;
	double sellVolume = 0;
	double diff = 0;
	double buy = 0;
	double sell = 0;
	double money = 0;
	diff = buyVolume - sellVolume;
	price = price + 0.01 * diff;
	asset = usd + stock * price;
	cout << "Welcome to the stock simulator!!!" << endl;
	cout << "Here's a summary of your account?" << endl;
	cout << "Your total assets: $" << asset << endl;
	cout << "USD avaliable: $" << usd << endl;
	cout << "You own " << stock << " stock" << endl;
	cout << endl << endl;
	cout << "Today's market: " << endl;
	cout << "Market price: $" << price << endl;
	cout << "Buying volume: " << buyVolume << " thousand" << endl;
	cout << "Selling volume: " << sellVolume << " thousand" << endl;

	cout << endl << endl;
	cout << "Operations: " << endl;
	cout << "Press <B> on your keybord and press <enter> to buy stocks" << endl;
	cout << "Press <S> on your keybord and press <enter> to sell stocks" << endl;
	cout << "Press <R> on your keybord and press <enter> to refreash market information" << endl;
	cout << "Press <Q> on your keybord and press <enter> to exit the program" << endl;

	cout << endl;
	cout << "Your choice: " << endl;
	cin >> choice;
	choice = tolower(choice);
	
	while (choice != 'q') {
		if (choice == 'b') {
			cout << endl << endl << endl;
			cout << "Stock price: $" << price <<endl;
			cout << "USD avaliable: $" << usd <<endl;
			cout << "How many stocks would you want to buy?" << endl;
			cout << "(You can enter the desired quantity and press <enter> key on your keybord)" << endl;
			cout << "You can also press any keys on your keybord and press <enter> to return to the operation selection page" << endl;
			
			cin >> buy;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << endl << endl;
				cout << "\nI'm taking you back to the opeion selection page now!!!" << endl;
				cout << endl << endl;
				sleep_for(2000ms);
			}
			else if (buy*price <= usd) {
				money = buy * price;
				cout << endl << endl;
				cout << "Are you sure you want to buy " << buy << " stocks? They cost you $"<<money<<" dollars" << endl;
				cout << "Enter <Y> to confirm and <N> to cancel purchase: ";
				cin >> choice;
				choice = tolower(choice);
				if (choice == 'y') {
					usd = usd - money;
					stock = buy;
					cout << "Your order has been placed!!!" << endl;
					sleep_for(2000ms);
				}
				else {
					cout << "Your purchase has been cancelled" << endl;
					sleep_for(2000ms);
				}
			}
			else {
				cout << endl << endl;
				cout << "Oops!!! You don't have that amount of USD avaliable." << endl;
				cout << "\nI'm taking you back to the opeion selection page now!!!" << endl;
				sleep_for(2000ms);
			}
		}
		else if (choice == 's') {
			cout << endl << endl << endl;
			cout << "Stock price: $" << price << endl;
			cout << "USD avaliable: $" << usd << endl;
			cout << "How many stocks would you want to sell?" << endl;
			cout << "(You can enter the desired quantity and press <enter> key on your keybord)" << endl;
			cout << "You can also press any keys on your keybord and press <enter> to return to the operation selection page" << endl;

			cin >> sell;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				cout << endl << endl;
				cout << "\nI'm taking you back to the opeion selection page now!!!" << endl;
				cout << endl << endl;
				sleep_for(2000ms);
			}
			else if (sell <= stock) {
				money = sell * price;
				cout << endl << endl;
				cout << "Are you sure you want to sell " << sell << " stocks? They are worth $" << money << " dollars" << endl;
				cout << "Enter <Y> to confirm and <N> to cancel purchase: ";
				cin >> choice;
				choice = tolower(choice);
				if (choice == 'y') {
					usd = usd + money;
					stock = stock - sell;
					cout << "Your order has been placed!!!" << endl;
					sleep_for(2000ms);
				}
				else {
					cout << "Your selling order has been cancelled" << endl;
					sleep_for(2000ms);
				}
			}
			else {
				cout << endl << endl;
				cout << "Oops!!! You don't have that amount of stocks avaliable." << endl;
				cout << "\nI'm taking you back to the opeion selection page now!!!" << endl;
				sleep_for(2000ms);
			}
		}

		else if (choice == 'r') {
			cout << "Market information has been refreshed!!!" << endl;
		}

		else {
			cout << "Invalid input. Please make your choice again. " << endl;
		}
		cout << endl << endl;
		cout << "Your total assets: $" << asset << endl;
		cout << "USD avaliable: $" << usd << endl;
		cout << "You own " << stock << " stock" << endl;
		cout << endl << endl;
		cout << "Today's market: " << endl;
		cout << "Market price: $" << price << endl;
		cout << "Buying volume: " << buyVolume << " thousand" << endl;
		cout << "Selling volume: " << sellVolume << " thousand" << endl;
		cout << endl << endl;
		cout << "Operations: " << endl;
		cout << "Press <B> on your keybord and press <enter> to buy stocks" << endl;
		cout << "Press <S> on your keybord and press <enter> to sell stocks" << endl;
		cout << "Press <R> on your keybord and press <enter> to refreash market information" << endl;
		cout << "Press <Q> on your keybord and press <enter> to exit the program" << endl;
		cout << endl;
		cout << "Your choice: " << endl;
		cin >> choice;
		choice = tolower(choice);
	}
	
	cout << endl << endl <<endl <<endl<<endl<<endl<< endl << endl << endl<< endl << endl << endl << endl << endl << endl << "Thank you for using the program!!!" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	return 0;
}