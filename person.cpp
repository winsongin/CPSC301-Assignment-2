// Author: Winson Gin
// Course: CPSC 301 7-9:50pm
// Date created: February 19, 2019
// Last updated: April 11, 2019
#include <iostream>
#include "person.h"
#include <string>

Person::Person(string fName, string lName, float rate, float hours){
  firstName = fName;
  lastName = lName;
  payRate = rate;
  hoursWorked = hours;
}
void Person::setLastName(string lName){
  lastName = lName;
}
string Person::getLastName(){
  return lastName;
}
void Person::setFirstName(string fName){
  firstName = fName;
}
string Person::getFirstName(){
  return firstName;
}
void Person::setPayRate(float rate){
  payRate = rate;
}
float Person::getPayRate(){
  return payRate;
}
void Person::setHoursWorked(float hours){
  hoursWorked = hours;
}
float Person::getHoursWorked(){
  return hoursWorked;
}
float Person::totalPay(){
  return hoursWorked*payRate;
}
string Person::fullName(){
  return firstName + " " + lastName;
}
