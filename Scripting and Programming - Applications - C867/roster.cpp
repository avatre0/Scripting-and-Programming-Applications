//roster.cpp
//
//
// Created by Paul Overfelt for WGU C867
#include "roster.h"

//student data parser, it takes in a "line" delemated by , and adds them to the roster
//data should be formated: ID,FirstName,LastName,email,Age,Days in course 1, days in course 2, days in course 3, degree program
void roster::parse(string studentData)
{
	//this is an expanded parsing example from the course tips #9 Parsing a string using a delimiter
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);
	
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degreeProgramS = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degreeprogram;
	if (degreeProgramS == "SECURITY")
	{
		degreeprogram = SECURITY;
	}
	if (degreeProgramS == "NETWORK")
	{
		degreeprogram = NETWORK;
	}
	if (degreeProgramS == "SOFTWARE")
	{
		degreeprogram = SOFTWARE;
	}

	//takes the parced data and send its to the add function to create the student
	add(studentID,  firstName,  lastName,  emailAddress,  age,  daysInCourse1,  daysInCourse2,  daysInCourse3,  degreeprogram);
}

//destructor
roster::~roster()
{

}

//adds to array of pointers student data
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	//creats a student object
	Student student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	//then pushes student into array
	classRosterArray.push_back(student);
}

//removes student by ID number
void roster::remove(string studentID)
{
	//default state of if a student hasn't been removed
	bool notRemoved = true;
	//loop for all students
	for (int i = 0; i < classRosterArray.size(); i++)
	{	// check if ID is in the array
		if (classRosterArray[i].getStudentId() == studentID)
		{	//If it is it removes it
			classRosterArray.erase(classRosterArray.begin() + (i));
			notRemoved = false; // removed a student
		}
		//if student isnt in the array and this method hasnt removed a student print an error
		if (i == (classRosterArray.size()-1) && notRemoved == true)
		{
			cout << "Student not found" << endl;
		}
	}
}

//Prints all studnets in array
void roster::printAll()
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		//calls the student to print info
		classRosterArray[i].print();
	}
}

//Prints the avarage days in course prvided a student ID
void roster::printAverageDaysInCourse(string studentID)
{
	//loop for finding student ID in roster
	for (unsigned int i = 0; i < classRosterArray.size(); i++)
	{
		//if the Found ID == the input ID
		if (classRosterArray[i].getStudentId() == studentID) {
			//finds the average days in course
			int average = (classRosterArray[i].getDaysInCourse1() + classRosterArray[i].getDaysInCourse2() + classRosterArray[i].getDaysInCourse3()) / 3;
			//Prints the data
			cout << classRosterArray[i].getStudentId() << " Average days in course: " << average << endl;
		}
	}
}

//Checks the data for invalid emails
void roster::printInvalidEmails()
{
	//loops through roster
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		//gets the email for the student at index
		string s = classRosterArray[i].getEmail();
		// if doesnt conntain "@","." or does conntain a " " then prints invalid email
		if ( s.find("@") == string::npos || s.find(" ") != string::npos || s.find(".") == string::npos)
		{
			cout << classRosterArray[i].getStudentId() << "\t";
			cout << classRosterArray[i].getFirstName() << "\t";
			cout << " Invalid Email: " << classRosterArray[i].getEmail() << endl;
		}
	}
}

//Prints the students in input degree program
void roster::printByDegreeProgram(string degreeProgram)
{
	//loops through roster
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		//if the degreetype = the supplied degree type
		if (classRosterArray[i].getDegreeType() == degreeProgram)
		{
			//Print!
			classRosterArray[i].print();
		}
	}
}