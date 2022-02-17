//student.cpp
//
//
// Created by Paul Overfelt for WGU C867

#include "student.h"


//empty constructor
Student::Student()
{
}

//constructor
Student::Student(string id, string fName, string lName, string Email, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram Dtype)
{
	setStudentID(id);
	setFirstName(fName);
	setLastName(lName);
	setEmail(Email);
	setAge(Age);
	setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
	setDegreeType(Dtype);
}

//destrctor
Student::~Student()
{
}

//Getters
string Student::getStudentId()
{
	return studentId;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

int Student::getAge()
{
	return age;
}

int Student::getDaysInCourse1()
{
	return daysInCourse.at(0);
}

int Student::getDaysInCourse2()
{
	return daysInCourse.at(1);
}

int Student::getDaysInCourse3()
{
	return daysInCourse.at(2);
}

//returns a string version of the degree type for easer checking
string Student::getDegreeType()
{
	switch (DegreeType)
	{
	case SECURITY:
			return "SECURITY";
			break;
	case NETWORK:
			return "NETWORK";
			break;
	case SOFTWARE:
			return "SOFTWARE";
			break;
	default:
		break;
	}
}

//Setters
void Student::setStudentID(string id)
{
	studentId = id;
	return;
}

void Student::setFirstName(string fName)
{
	firstName = fName;
	return;
}

void Student::setLastName(string lName)
{
	lastName = lName;
	return;
}

void Student::setEmail(string Email)
{
	email = Email;
	return;
}

void Student::setAge(int Age)
{
	age = Age;
	return;
}

//creats a vector of the list of days in course
void Student::setDaysInCourse(int day1, int day2 , int day3)
{
	{
		vector<int> vecDaysInCourse = { day1, day2, day3 };
		daysInCourse = vecDaysInCourse;
	}
}

void Student::setDegreeType(DegreeProgram Dtype)
{
	DegreeType = Dtype;
	return;
}

//print the student info
void Student::print()
{
	cout << getStudentId() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
//	cout << "Email: " << getEmail() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "Days in Course: ";
	cout << "{" << getDaysInCourse1();
	cout << ", " << getDaysInCourse2();
	cout << ", " << getDaysInCourse3() << "} ";
	cout << "Degree Program: ";
	cout << getDegreeType();
	cout << endl;
};