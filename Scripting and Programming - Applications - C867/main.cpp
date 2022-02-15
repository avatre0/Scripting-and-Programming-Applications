//main.cpp
//
//
// Created by Paul Overfelt for WGU C867
#include "roster.h"


int main()
{
	cout << "Scripting and Programming - Applications - C867\tC++\tWGUID# 009278142\tPaul Overfelt" << endl << endl;

	//Student Data Array
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Paul,Overfelt,poverfe@wgu.edu,30,30,35,40,SOFTWARE" };

	//creates a roster object
	roster classRoster;

	//fills the classRoster roster object with data from the studentData array
	for (int i = 0; i < 5; i++)
	{
		classRoster.parse(studentData[i]);
	}

	//Prints all data in the classRoster
	cout << "Print All" << endl;
	classRoster.printAll();
	cout << endl;

	//Prints all invald emails in classRoster
	cout << "Print Invalid Emails" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	//Prints the average days in course for each student in classRoster
	cout << "Print Average Days In Course" << endl;
	for (int i=0; i < 5; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i].getStudentId());
	}
	cout << endl;

	//Prints all students in the sofware program
	cout << "Print By Degree Program" << endl;
	classRoster.printByDegreeProgram("SOFTWARE");
	cout << endl;

	//Removes A3 student and then prints the roster
	cout << "Removing and A3 and Print" << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl;

	//check if error message works
	cout << "Removing A3 if in roster" << endl;
	classRoster.remove("A3");
}