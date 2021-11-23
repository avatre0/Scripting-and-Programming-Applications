#include "student.h"


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

int* Student::getDaysInCourse()
{
	return daysInCourse;
}

DegreeProgram Student::getDegreeType()
{
	return DegreeType;
}


//Setters
void Student::setStudentID(string id)
{
	studentId = id;
}

void Student::setFirstName(string fName)
{
	firstName = fName;
}

void Student::setLastName(string lName)
{
	lastName = lName;
}

void Student::setEmail(string Email)
{
	email = Email;
}

void Student::setAge(int Age)
{
	age = Age;
}

void Student::setDaysInCourse(int* DaysInCourse)
{
	for (int i = 0; i < 3; i++)
	{
		daysInCourse[i] = DaysInCourse[i];
	}
}

void Student::setDegreeType(DegreeProgram Dtype)
{
	DegreeType = Dtype;
}

//constructor
Student::Student(string id, string fName, string lName, string Email, int Age, int DaysInCourse[3], DegreeProgram Dtype)
{
	setStudentID(id);
	setFirstName(fName);
	setLastName(lName);
	setEmail(Email);
	setAge(Age);
	setDaysInCourse(DaysInCourse);
	setDegreeType(Dtype);
	
}