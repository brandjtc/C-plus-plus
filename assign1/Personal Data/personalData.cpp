// File:    personalData.cpp
// Project: CSIS3400 Assignment 1
// Author:  Brandon Catalano 
// History: Version 1.0 Aug 27,2022
#include <iostream>
using namespace std;


int printPersonalData()
{
	string spacing = "\n\n";
	//  1) Name 
	cout << "Name: Brandon Catalano" <<spacing;
	//  2) Email address 
	cout << "Email Address: bc1491@mynsu.nova.edu" <<spacing;
	//  3) Major
	cout << "Major: Computer Science" <<spacing;
	//  4) Status at Nova (full-time, part-time, non-degree seeking) 
	cout << "Status at Nova: Full-Time student" <<spacing;
	//  5) Employment status (full-time, part-time, intern, student)
	cout <<"Employment Status : Part-time" <<spacing;
	//  6) Campus dorm or town where you now live
	cout << "Location of Residence: Coconut Creek, Florida." <<spacing;
	//  7) Hometown where you grew up
	cout<<"Hometown: This information is classified" <<spacing;
	//  8) Previous programming course(s) taken, where, and instructor’s name 
	cout << "Previous programming course(s) taken: This information is classified." <<spacing;
	//  9) Other CS or Tech course(s) taken (and where if not Nova)
	cout << "Other CS or Tech Course(s) taken: This information is classified" <<spacing;
	// 10) Programming languages with which you have even a little experience
	cout << "Programming languages with which you have even a little experience: C++, javascript, coffeescript, python, java" <<spacing;
	
	return 0;
}
int main()
{
	printPersonalData();
	return 0;
}