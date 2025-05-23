#pragma once
#include <string>
using namespace std;

struct Teacher {
    int age;
    string name;
    string surname;
    int num_of_group;
    int password;
};

struct Student {
    string name;
    int age;
};

int search(Teacher input, Teacher db1, Teacher db2);
int plan(int password, int num_of_group);
void addStudent(Student* group, int& count, int capacity);
void showStudents(Student* group, int count, int group_num);
