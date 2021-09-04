#include "superior.h"
int MainMenu() {
	
	unsigned int choice = 0;
	cout << "+---------------------------------------+" << endl
		<< "|               Main  Menu              |" << endl
		<< "+---------------------------------------+" << endl
		<< "| 1. Show me Country!                   |" << endl
		<< "| 2. Show me Vector!                    |" << endl
		<< "| 3. End the program                    |" << endl 
		<< "+---------------------------------------+\n>>> ";

	cin >> choice;
	switch (choice) {
	case 1: {
		Release_Country();
		break;
	}
	case 2: {
		Release_Vector();
		break;
	}
	default:
		return 0;
	}
	return choice; 
}
void Main_Release() {
	while (true)
	{
		system("cls");
		if (!MainMenu())
			return;
	}
}

int Release_Country() {
	Country country;
	while (true) {
		system("cls");
		switch (unsigned int variator = Country_Main_Menu()) {
		case 1: {
			Create_a_Country(country);
			break;
		}
		case 2: {
			country.Display();
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			switch (unsigned int option = Change_Menu()) {
			case 1: {
				Change_the_Country(country);
				break;
			}
			case 2: {
				country.free_name();
				string ent = "";
				cout << "Enter Country Name: \n>>> ";
				cin >> ent;
				country.setName(ent.c_str());
				cin.get();
				break;
			}
			case 3: {
				country.free_continent();
				string ent = "";
				cout << "Enter Continent: \n>>> ";
				cin >> ent;
				country.setContinent(ent.c_str());
				cin.get();
				break;
			}
			case 4: {
				unsigned long int population = 0;
				cout << "Enter Population: \n>>> ";
				cin >> population;
				country.setPopulation(population);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4: {
			country.~Country();
			cout << "Memory has been freed" << endl;
			system("pause");
			break;
		}
		case 5: {
			Compare_it(country);
			break;
		}
		default: {
			return 1;
		}
		}
	}
}
void Compare_it(Country &country) {
	Country conter;
	cout << "Enter second country: " << endl;
	Create_a_Country(conter);
	cout << "Name compare:" << endl;
	cout << "fist name: " << country.getName() << endl;
	cout << "second name: " << conter.getName() << endl;
	cout << "   == " << endl;
	if (country == conter)
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   <   " << endl;
	if (country < conter)
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   >   " << endl;
	if (country > conter)
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   >=   " << endl;
	if (country >= conter)
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   <=   " << endl;
	if (country <= conter)
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "Population Compare: " << endl;
	cout << "First Population: " << country.getPopulation()<<endl;
	cout << "Second Population: " << conter.getPopulation()<<endl;
	cout << "==" << endl;
	if (country.getPopulation() == conter.getPopulation())
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   <   " << endl;
	if (country.getPopulation() < conter.getPopulation())
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   >   " << endl;
	if (country.getPopulation() > conter.getPopulation())
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   >=   " << endl;
	if (country.getPopulation() >= conter.getPopulation())
		cout << " Yes" << endl;
	else cout << " No" << endl;
	cout << "   <=   " << endl;
	if (country.getPopulation() <= conter.getPopulation())
		cout << " Yes" << endl;
	else cout << " No" << endl;
	system("pause");
}
int Country_Main_Menu() {
	unsigned int variant = 0;
	cout << "+---------------------------------------+" << endl
		<< "|             Country Release           |" << endl
		<< "+---------------------------------------+" << endl 
		<< "| 1. Create a Country                   |" << endl
		<< "| 2. Display the Country                |" << endl
		<< "| 3. Change the Country                 |" << endl
		<< "| 4. Free memory                        |" << endl
		<< "| 5. Compare Countries                  |" << endl
		<< "| 6. Back to main menu                  |" << endl
		<< "+---------------------------------------+\n>>> ";

	cin >> variant;
	return variant;
}
void Create_a_Country(Country& country) {
	string ent = "";
	cout << "Enter Country Name: \n>>> ";
	cin >> ent;
	country.setName(ent.c_str());
	cout << "Enter Continent: \n>>> ";
	cin >> ent;
	country.setContinent(ent.c_str());
	unsigned long int population = 0;
	cout << "Enter Population: \n>>> ";
	cin >> population;
	country.setPopulation(population);
	cin.get();
}
void Change_the_Country(Country& country) {
	country.~Country();
	Create_a_Country(country);
}
int Change_Menu() {
	unsigned int variant = 0;
	cout << "+---------------------------------------+" << endl
		<< "|      What need to be changed          |" << endl
		<< "+---------------------------------------+" << endl
		<< "| 1. Country                            |" << endl
		<< "| 2. Name                               |" << endl
		<< "| 3. Continent                          |" << endl
		<< "| 4. Population                         |" << endl
		<< "| 5. I don need to change anything      |" << endl
		<< "+---------------------------------------+\n>>> ";

	cin >> variant;
	return variant;
}


/// <summary>
/// +--------------------------------------------------------------------------+
/// |                                                                          |
/// |                                                                          |
/// |                                                                          |
/// +--------------------------------------------------------------------------+
/// </summary>
/// <returns></returns>
int Vector_Main_Menu() {
	unsigned int variant = 0;
	cout << "+---------------------------------------+" << endl
		<< "|             Victor  Release           |" << endl
		<< "+---------------------------------------+" << endl
		<< "| 1. Create  vector                     |" << endl
		<< "| 2. Delete  vector                     |" << endl
		<< "| 3. Resize vector                      |" << endl
		<< "| 4. Set the element                    |" << endl
		<< "| 5. Get the element                    |" << endl
		<< "| 6. Middle positive                    |" << endl
		<< "| 7. Display vector                     |" << endl
		<< "| 8. Compare two vectors                |" << endl
		<< "| 9. push_back the element              |"<<endl
		<< "| 10. push_front the element            |"<<endl
		<< "| 11. randomize empty elements          |"<< endl
		<< "| 12. Back to MainMenu                  |" << endl
		<< "+---------------------------------------+\n>>> ";
	cin >> variant;
	return variant;
	return 0; 
}
int Release_Vector() {
	Vector Victor;
	while (true) {
		system("cls");
		switch (int wtf = Vector_Main_Menu()) {
		case 1: {
			unsigned int n = 0;
			cout << "Enter size of vector\n>>> ";
			cin >> n;
			Victor.resize(n);
			break;
		}
		case 2: {
			Victor.~Vector();
			break;
		}
		case 3: {
			unsigned int n = 0;
			cout << "Enter new size of vector\n>>> ";
			cin >> n;
			Victor.resize(n);
			break;
		}
		case 4: {
			unsigned int n = 0;
			cout << "Choice the element that need to be set, from range 0 - " << Victor.getSize()-1<<endl<<">>> ";
			cin >> n;
			if (n > Victor.getSize() - 1) {
				cout << "Error, element not found"<<endl;
				break;
			}
			cout << " Enter new value:\n>>> ";
			int value= 0;
			cin >> value;
			Victor.IndexOf[n] = value;
			cout << "Element was changed"<<endl;
			system("pause");
			break;
		}
		case 5: {
			unsigned int n = 0;
			cout << "Choice the element that need to check, from range 0 - " << Victor.getSize() - 1 << endl << ">>> ";
			cin >> n;
			cout << " This element: " << Victor.IndexOf[n]<<endl;
			system("pause");
			break;
		}
		case 6: {
			cout << "Arithmetic mean of positive numbers: " << Victor.MidPositive()<<endl;
			system("pause");
			break;
		}
		case 7: {
			cout << "Vector:" << endl;
			Victor.Display();
			system("pause");
			break;
		}
		case 8: {
			cout << "Created second vector with Victor.size, and the same elements:\n>>> ";
			Vector second(Victor.getSize());
			for (unsigned int i = 0; i < second.getSize(); i++) {
				second.IndexOf[i] = Victor.IndexOf[i];
			}
			cout << "Compare (by size and vector): "<<endl;
			cout << "Victor:" << endl;
			Victor.Display();
			cout << "Another vector:" << endl;
			second.Display();
			cout << "   ==   " << endl;
			if (Victor == second)
				cout << "Victor == second"<<endl;
			else
				cout << " Vicotr != second"<<endl;
			cout << "resize second vector:\n";
			second.resize(Victor.getSize() + 2);
			second.Display();
			cout << "Compare by size::" << endl;
			cout << "   >   " << endl;
			if (Victor > second)
				cout << "Victor > second" << endl;
			else
				cout << "Victor < second" << endl;
			cout << "   >=   " << endl;
			system("pause");
			break;
		}
		case 9: {
			int element = 0;
			cout << "Enter number, that need to push_back:\n>>> ";
			cin >> element;
			Victor.push_back(element);
			break;
			
		}
		case 10: {
			int element = 0;
			cout << "Enter number, that need to push_front:\n>>> ";
			cin >> element;
			Victor.push_front(element);
			break;
		}
		case 11: {
			int start=0,end = 0;
			cout << "Enter lower limit:\n>>> ";
			cin >> start;
			cout << "Enter upper limit:\n>>> ";
			cin >> end;
			Victor.randomize(start, end);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}