// == == == == == == == == == == == == == == = Book Management == == == == == == == == == == == == == == ==



#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class book {
	int bookId = 0;
	string bookName = "";
	float bookPrice = 0.0;
public:
	void getData();
	void showData(int, string);


	friend void show_menu(book obj);
};
void book::getData()
{
	cout << "Enter Book id: " << endl;
	cin >> bookId;
	cout << "Enter Price of book: " << endl;
	cin >> bookPrice;
	cin.ignore();
	cout << "Enter name of book: " << endl;
	getline(cin, bookName);

	ofstream out("books_information.txt", ios::app);
	out << " " << bookId << " " << bookPrice << " " << bookName << endl;
	out.close();
}

void show_menu(book obj);
void rename_remove(void);

int main()
{
	book ob1;
	char ch = '\0';
	while (ch != 'y')
	{
		show_menu(ob1);
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
	cout << " 4) Enter 4 for Delete data of book by id: " << endl;
	cout << " 5) Enter 5 for Update data of book by id: " << endl;
	cout << "\n    Enter: ";
	cin >> num;
	switch (num)

	{
	case 1:
		//input_from_user();
	{
		obj.getData();
		break;
	}
	case 2:
		//output_from_user();
	{
		obj.showData(1, " ");
		break;
	}
	case 3:
	{
		string s = " ";
		string search = "";
		cin.ignore();
		cout << "Enter ID to search: " << endl;
		getline(cin, search);
		search.append(s);
		obj.showData(2, search);
		break;
	}
	//end of case 3
	case 4:
	{
		string d = " ";
		string deleteData = "";
		cin.ignore();
		cout << "Enter ID to Delete: " << endl;
		getline(cin, deleteData);
		deleteData.append(d);
		obj.showData(3, deleteData);
		rename_remove();
		break;
	}
	//end of case 4
	   //=======  
	case 5:
		string Upd = " ";
		string updateData = "";
		cin.ignore();
		cout << "Enter ID to To Update Data: " << endl;
		getline(cin, updateData);
		updateData.append(Upd);
		obj.showData(4, updateData);
		rename_remove();
		break;

	}
}

void book::showData(int comp, string searc)
{

	system("cls");
	cout << "\n                  --==========================--  Book Management System Menu  --==============================--\n\n" << endl;

	cout << setw(12) << "Id" << setw(19) << "Price" << setw(21) << "Name" << endl;
	string myText = "";
	ofstream out1("temporary.txt", ios::app);
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

		string price = "";
		c = '\0';
		while (c != ' ') {
			price += myText[i];
			c = myText[i];
			i++;
		}
		//int balance = stoi(amount);
		//cbalance += balance;
		string name = "";
		for (i; i < myText.length(); i++) {
			name += myText[i];
		}
		if (comp == 1) {
			cout << setw(12) << id << setw(20) << price << "                " << name << endl;
		}
		else if (comp == 2)
		{
			if (id == searc)
			{

				cout << setw(12) << id << setw(20) << price << setw(25) << name << endl;
			}

		}
		else if (comp == 3)
		{
			if (id == searc)
			{
				cout << setw(12) << id << setw(20) << price << setw(25) << name << endl;
			}
			else
			{
				out1 << " " << id << price << name << endl;
			}
		}
		else if (comp == 4)
		{
			if (id == searc)
			{
				cout << setw(12) << id << setw(20) << price << setw(25) << name << endl;
				cout << "This Bokk is going to be update." << endl;
				int book_id = 0;
				string book_name;
				float book_price = 0.0;
				cout << "Enter Book id: " << endl;
				cin >> book_id;

				cout << "Enter Price of book: " << endl;
				cin >> book_price;
				cin.ignore();
				cout << "Enter name of book: " << endl;
				getline(cin, book_name);

				out1 << " " << book_id << " " << book_price << " " << book_name << endl;
				continue;
			}
			out1 << " " << id << price << name << endl;
		}
	}
	out1.close();
	in.close();
}


//rename/remove
void rename_remove(void) {
	/*	Deletes the file if exists */
	char filename[] = "books_information.txt";
	if (remove(filename) != 0)
	{
		perror("File deletion failed");
	}
	else
	{
		cout << "File deleted successfully" << endl;
	}

	//rename
	char oldname[] = "temporary.txt";
	char newname[] = "books_information.txt";

	if (rename(oldname, newname) != 0)

	{
		perror("Error renaming file");
	}
	else
	{
		cout << "Process Complete Successfully!" << endl;
	}
}
//======================================================The End=======================================
