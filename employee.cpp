//Write a program to create Book class, with data members as follows - book_no, book_name, author,
//edition, price, qty, bill, discount, netbill.Calculate bill and apply discount 5 % on them, also calculate
//netbill.Initialize these data members by the objects of its class


#include <iostream>
using namespace std;

class Book {
private:
	int book_no;
	string book_name;
	string author;
	int edition;
	float price;
	int qty;
	float bill;
	float discount;
	float netbill;
public :
	int book_no;
	string book_name;
	string author;
	int edition;
	float price;
	int qty;
	float bill;
	float discount;
	float netbill;


	void input() {
		cout << "enter the valuse of book_no:";
		cin >> book_no;
		cout << "enter the value of book_name:";
		cin >> book_name;
		cout << "enter the value of author:";
		cin >> author;
		cout << "enter the value of edition:";
		cin >> edition;
		cout << "enter the value of price:";
		cin >> price;
		cout << "enter the value of qty:";
		cin >> qty;
		cout << "enter the value of bill:";
		cin >> bill;
		cout << "enter the discount";
		cin >> discount;
		cout << "enter the value of netbill:";
		cin >> netbill;

	}
	/*void author() {
		cout << "book no is:" << book_no << endl;
		cout << "book name is:" << book_name << endl;
		cout << "author name is:" << author << endl;
		cout << "edition is:" << edition << endl;
		cout << "price is:" << price << endl;
		cout << "qty is:" << qty << endl;
		cout << "bill is:" << bill << endl;
		cout << "discount is:" << discount << endl;
		cout << "netbill is:" << netbill << endl;

		

	}*/
	void calculate() {
		bill = price * qty;
		discount = bill * 0.05;
		netbill = bill - discount;
	}
	void displays() {
		cout << "Book no is:" << book_no << endl;
		cout << "Book name is:" << book_name << endl;
		cout << "Author name is:" << author << endl;
		cout << "Edition is:" << edition << endl;
		cout << "Price is:" << price << endl;
		cout << "Qty is:" << qty << endl;
		cout << "Bill is:" << bill << endl;
		cout << "Discount is:" << discount << endl;
		cout << "Netbill is:" << netbill << endl;
	}
};
int main() {
	Book b;
	b.input();
	
	b.calculate();
	b.displays();
}