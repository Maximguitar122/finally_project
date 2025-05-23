#include <iostream>
#include "student_base.h"
using namespace std;
// Функція для перевірки вчителя в базі
int search(Teacher input, Teacher db1, Teacher db2) {
	if (input.age == db1.age && input.name == db1.name && input.surname == db1.surname && input.num_of_group == db1.num_of_group) {
		return 1;
	}
	if (input.age == db2.age && input.name == db2.name && input.surname == db2.surname && input.num_of_group == db2.num_of_group) {
		return 1;
	}

	return 0;
}
// функція для перевірки безпеки 
int plan(int password, int num_of_group) {
	int bd_password = 342;
	int bd_num_of_group = 1;


	int bd_password2 = 342;
	int bd_num_of_group2 = 2;

	if (password == bd_password && num_of_group == bd_num_of_group) {
		return 1;
	}
	if (password == bd_password2 && num_of_group == bd_num_of_group2) {
		return 2;
	}

	return 0;
}

// функція яка приймає  для додавання студента до списку студентів, 
// Параметри:
//   group   - вказівник на масив 
//   count   - посилання на поточну кількість студентів 
//   capacity - максимальна кількість студентів, які може містити група
void addStudent(Student* group, int& count, int capacity) {
	if (count < capacity) {
		cout << "Enter students name: ";
		cin >> group[count].name;
		cout << "Enter students age: ";
		cin >> group[count].age;
		count++;
		cout << "Student successfully added!\n";
	}
	else {
		cout << "Group is full or incorrect group number!\n";
	}
}

// Функція виводу студентів групи
void showStudents(Student* group, int count, int group_num) {
	cout << "\nStudents of group " << group_num << ":\n";
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ") Name: " << group[i].name << ", Age: " << group[i].age << "\n";
	}
}