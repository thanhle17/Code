#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct GradeBook
{
	char FirstName[30];
	char LastName[30];
	double sub1, sub2, sub3, sub4, sub5;
	double AverageGrades;
	char LetterGrade;
};

GradeBook arrayBook[30];

class Student
{
public:
	double total;
	double sum;
	double highest;
	void ReadFile(ifstream& inputfile, string fileName)
	{
		inputfile.open(fileName);
		for (int i = 1; i <= 20; i++)
		{
			inputfile >> arrayBook[i].FirstName;
			inputfile >> arrayBook[i].LastName;
			inputfile >> arrayBook[i].sub1;
			inputfile >> arrayBook[i].sub2;
			inputfile >> arrayBook[i].sub3;
			inputfile >> arrayBook[i].sub4;
			inputfile >> arrayBook[i].sub5;
		}
		inputfile.close();
	}
public:
	void printdata()
	{
		for (int i = 1; i <= 20; i++)
		{
			cout << arrayBook[i].FirstName;
			cout << setw(10) << arrayBook[i].LastName;
			cout << setw(10) << arrayBook[i].sub1;
			cout << setw(10) << arrayBook[i].sub2;
			cout << setw(10) << arrayBook[i].sub3;
			cout << setw(10) << arrayBook[i].sub4;
			cout << setw(10) << arrayBook[i].sub5 << endl;
		}
	}
public:
	void FindGrades()
	{
		sum = 0, highest = 0;
		for (int i = 1; i <= 25; i++)
		{
			total = (arrayBook[i].sub1 + arrayBook[i].sub2 + arrayBook[i].sub3 + arrayBook[i].sub4 + arrayBook[i].sub5);
			arrayBook[i].AverageGrades = total / 5;
			if (arrayBook[i].AverageGrades >= 90)
				arrayBook[i].LetterGrade = 'A';
			else if (arrayBook[i].AverageGrades >= 80)
				arrayBook[i].LetterGrade = 'B';
			else if (arrayBook[i].AverageGrades >= 70)
				arrayBook[i].LetterGrade = 'C';
			else if (arrayBook[i].AverageGrades < 70)
				arrayBook[i].LetterGrade = 'F';
			sum = sum + total;
			if (highest < arrayBook[i].AverageGrades)
			{
				highest = arrayBook[i].AverageGrades;
			}
		}
	}
public:
	void GradesReport(ofstream& outfile)
	{
		outfile.open("GradeReport.txt");
		outfile << "Firstname\tLastName\tExam1\tExam2\tExam3\tExam4\Final\tAvearge\tLetterGrade" << endl;
		cout << "Firstname\tLastName\tExam1\tExam2\tExam3\tExam4\Final\tAvearge\tLetterGrade" << endl;
		for (int i = 1; i <= 20; i++)
		{
			outfile << arrayBook[i].FirstName << setw(10) << arrayBook[i].LastName << setw(10) << arrayBook[i].sub1 << setw(10) 
				<< arrayBook[i].sub2 << setw(10) << arrayBook[i].sub3 << setw(10) << arrayBook[i].sub4 << setw(10) << arrayBook[i].sub5 << setw(15) 
				<< arrayBook[i].AverageGrades << setw(15) << arrayBook[i].LetterGrade << endl;
			cout << arrayBook[i].FirstName << setw(10) << arrayBook[i].LastName << setw(10) << arrayBook[i].sub1 << setw(10) 
				<< arrayBook[i].sub2 << setw(10) << arrayBook[i].sub3 << setw(10) << arrayBook[i].sub4 << setw(10) 
				<< arrayBook[i].sub5 << setw(15) << arrayBook[i].AverageGrades << setw(15) << arrayBook[i].LetterGrade << endl;
		}
		cout << "Overall Test Average is: " << sum << endl;
		outfile << "Total Score is: " << sum;
		cout << "The Highest Average Grade is: " << highest << endl;
		outfile << "Highest Test Grade : " << highest << endl;
		
		outfile.close();
	}
};
int main()
{
	Student obj;
	cout << "***Student Grades ***" << endl;
	ifstream inputfile;
	obj.ReadFile(inputfile, "CIT1325.txt");
	obj.ReadFile(inputfile, "CIT1350.txt");
	cout << "\n The Data is:" << endl;
	obj.printdata();
	cout << "\n Calculating Grades" << endl;
	obj.FindGrades();
	cout << "\n The Grade Report" << endl;
	ofstream outfile;
	obj.GradesReport(outfile);
	return 0;
}
