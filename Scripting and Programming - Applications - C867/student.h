#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
	public
		//getters
		string getStudentId();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int* getDaysInCourse();
		DegreeProgram getDegreeType();

		//setters
		void setStudentID(string);
		void setFirstName(string);
		void setLastName(string);
		void setEmail(string);
		void setAge(int);
		void setDaysInCourse(int[3]);
		void setDegreeType(DegreeProgram);

		//constructor
		Student(string, string, string, string, int, int*, DegreeProgram);
		~Student();

		private
			string studentId, firstName, lastName, email;
			int age, daysInCourse[3];
			DegreeProgram DegreeType;
};