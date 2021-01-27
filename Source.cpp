// == == == == == == == == == == == == == == = Book Management == == == == == == == == == == == == == == ==


#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class book{
	int bookId = 0;
	string bookName = "";
	float bookPrice = 0.0;
public:
	void getData();
	void showData();

	friend void show_menu(book obj);
};
void book::getData()
{
	cout << "Enter Book id: " << endl;
	cin >> bookId;
	cin.ignore();
	cout << "Enter name of book: " << endl;
	getline(cin, bookName);
	cout << "Enter Price of book: " << endl;
	cin >> bookPrice;
	ofstream out("books_information.txt", ios::app);
	out << " " << bookId << " " << bookName << " " << bookPrice << endl;
	out.close();
}

void show_menu(book obj);


int main()
{
	book ob1;
	char ch = '\0';
	while (ch != 'y')
	{
		show_menu( ob1);
		cout << "\nEnter y for close program else input any key to continue: " << endl;
		cin >> ch;
	}

	system("pause");
	return 0;
}




// function for show menu
void show_menu(book obj)
{
	system("cls");
	int num = 0;
	cout << "\n                  --==========================--  Book Management System Menu  --==============================--\n\n" << endl;
	cout << " 1) Enter 1 for add Book Information: " << endl;
	cout << " 2) Enter 2 for add Display Book Information: " << endl;
	cout << " 3) Enter 3 for Search detail of Book: " << endl;
	cout << " 4) Enter 4 for display detail of credit: " << endl;
	cout << "\n    Enter: ";
	cin >> num;
	switch (num)

	{
	case 1:
		//input_from_user();
		obj.getData();
		break;
	case 2:
		//output_from_user();
		
		obj.showData();
		break;
		/* case 3:

		break;
		case 4:

		break;*/

	}

}

void book::showData()
{
	system("cls");
	cout << setw(12) << "id" << setw(19) << "name" << setw(21) << "price" << endl;
	string myText = "";

	//ifstream in("debit.txt");
	ifstream in("books_information.txt", ios::in);
	while (getline(in, myText)) {
		string id = "";
		int i = 1;
		char c = '\0';
		while (c != ' ') {
			
			id += myText[i];
			c = myText[i];
			i++;
		}

		string name = "";
		c = '\0';
		while (c != ' ') {
			name += myText[i];
			c = myText[i];
			i++;
		}
		//int balance = stoi(amount);
		//cbalance += balance;
		string price = "";
		for (i; i < myText.length(); i++) {
			price += myText[i];
		}

		
		cout << setw(12) << id << setw(20) << name << setw(20) << price << endl;
	}

	in.close();
}