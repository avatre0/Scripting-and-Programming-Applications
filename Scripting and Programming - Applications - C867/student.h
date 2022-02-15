//student.h
//
//
// Created by Paul Overfelt for WGU C867
#pragma once
#include <iostream>
#include "degree.h"
#include <vector>
using namespace std;

class Student 
{
	public:
		//getters
		string getStudentId();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int getDaysInCourse1();
		int getDaysInCourse2();
		int getDaysInCourse3();
		string getDegreeType();

		//setters
		void setStudentID(string);
		void setFirstName(string);
		void setLastName(string);
		void setEmail(string);
		void setAge(int);
		void setDaysInCourse(int, int, int);
		void setDegreeType(DegreeProgram);
		void print();

		//constructor
		//empty construtor
		Student();
		//fill param constructor
		Student(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysIncourse3 , DegreeProgram DegreeType);
		//destructor
		~Student();


	private:
			string studentId;
			string firstName;
			string lastName;
			string email;
			int age;
			vector<int> daysInCourse;
			DegreeProgram DegreeType;
};