//roster.h
//
//
// Created by Paul Overfelt for WGU C867
#pragma once
#include "student.h"
#include <sstream>


class roster {
	public:
		void parse(string studentData); //constructor call
		~roster();
		vector<Student> classRosterArray;
		void addStudentData();
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(string degreeProgram);
};