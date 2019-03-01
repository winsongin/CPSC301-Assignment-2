// Author: Winson Gin
// Course: CPSC 301 7-9:50pm
// Date created: February 19, 2019
// Last updated: February 28, 2019
//begin person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
class Person
{
private:
    string lastName;
    string firstName;
    float  payRate;
    float  hoursWorked;
public:
    Person();
    void setLastName(string lName);
    string getLastName();
    void setFirstName(string fName);
    string getFirstName();
    void setPayRate(float rate);
    float getPayRate();
    void setHoursWorked(float hours);
    float getHoursWorked();
    float totalPay();
    string fullName();
};
#endif // end person.h
