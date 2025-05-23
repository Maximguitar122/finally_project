

#include <iostream>
#include <fstream>
#include <string>
#include "student_base.h"
using namespace std;










int main()
{
	cout << "========================================================================================================================\n";
	cout<<"                                          STUDENT BASE\n";
	cout << "========================================================================================================================\n";
	cout << "                                     LOGIN FOR TEACHER\n";



	Teacher db1 = { 35, "Maxym", "Schevchyk", 1 };
	Teacher db2 = { 40, "Alex", "Schevchenko", 2 };
	Teacher input;

	

	cout << "Enter your age\n";
	cin >> input.age;
	cout << "Enter your name\n";
	cin >> input.name;
	cout << "Enter your surname\n";
	cin >> input.surname;
	cout << "Enter your group number\n";
	cin >> input.num_of_group;

	// Перевірка, чи існує вчитель у базі даних
	int result = search(input, db1, db2);
	if (result == 1) {
		cout << "=======================================================================================================================\n";
		cout << "                                   Office found\n";
		cout << "========================================================================================================================\n";
	}
	
	else {
		cout << "========================================================================================================================\n";
		cout << "                                  Office no found\n";
		cout << "=========================================================================================================================\n";
		return 0;
	}
    int password;
	
	cout << "Enter a password\n";
	cin >> password;
	

	int output = plan(password, input.num_of_group);
	if (output == 1) {
		cout << " Learn programming fundamentals:\n";
		cout << "1. Data types (strings, numbers, booleans)\n";
		cout << "2. Conditional statements (if/else)\n";
		cout << "3. Loops (for, while)\n";
		cout << "4. Functions and how to use them\n";
		cout << "5. Practice: simple calculator or (Guess the number) game\n";
	}
	if (output == 2) {
		cout << " Strengthen coding skills and build small projects:\n";
		cout << "1. Review of basic concepts\n";
		cout << "2. Arrays and dictionaries (maps)\n";
		cout << "3. Object-oriented programming (classes, objects)\n";
		cout << "4. File handling (read/write files)\n";
		cout << "5. Building a GUI or simple web page\n";
		cout << "6. Project: To-Do List app or simple game\n";
	}
	// Ініціалізація змінних для динамічних масивів студентів
	int capacity1 = 10, capacity2 = 10;
	int count1 = 5, count2 = 4;
	Student* group1 = new Student[capacity1]{ {"Petro", 17}, {"Olena", 16}, {"Alex", 18}, {"Andrew", 16}, {"Yehor", 17} };
	Student* group2 = new Student[capacity2]{ {"Petro", 19}, {"Anton", 16}, {"Yaroslav", 18}, {"Maxym", 18} };

	// Цикл меню, що виконується доки користувач не вибере вихід
	int choice;
	do {
		cout << " \t What do you want to do?\n";
		cout << "1. Add a student\n";
		cout << "2. Show students\n";
		cout << "3. Exit\n";
		cout << "4. Save students to file\n";
		cin >> choice;
		switch (choice) {
		case 1:
			if (input.num_of_group == 1)
				addStudent(group1, count1, capacity1);
			else if (input.num_of_group == 2)
				addStudent(group2, count2, capacity2);
			else
				cout << "Invalid group number!\n";
			break;
		case 2:
			if (input.num_of_group == 1)
				showStudents(group1, count1, 1);
			else if (input.num_of_group == 2)
				showStudents(group2, count2, 2);
			else
				cout << "Invalid group number!\n";
			break;
		case 3:
			cout << "Goodbye!\n";
			break;
		case 4:
			if (input.num_of_group == 1) {
				ofstream file("group1.txt");
				for (int i = 0; i < count1; i++) {
					file << group1[i].name << " " << group1[i].age << "\n";
				}
			file.close(); 
			cout << "Done!\n"; // запис у файл
			}
			if (input.num_of_group == 2) {
				ofstream file("group2.txt");
				for (int i = 0; i < count2; i++) {
					file << group2[i].name << " " << group2[i].age << "\n";
				}
				file.close();
				cout << "Done!\n"; // запис у файл
			}

			

		default:
			cout << "Invalid choice. Try again.\n";
		}
	}while (choice != 3);

	// Звільняємо пам’ять, виділену під динамічні масиви студентів
	delete[] group1;
	delete[] group2;

	return 0;

}

