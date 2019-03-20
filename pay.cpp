// Author: Winson Gin
// Course: CPSC 301 7-9:50pm
// Date created: February 19, 2019
// Last updated: February 28, 2019
//Purpose of this program:
//This program will read the input.txt file and use the member function of the Person class to store the variables.
//Then, it will create a new output.txt file and write to it.
#include <iostream>
#include "person.cpp"
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//function prototypes
int readData(Person employees[], int size);
void writeData(Person workers[], int size);

int main(){
  int size = 0;
  Person employees[20];
  size = readData(employees, 20); //number of lines that is returned from readData is stored into variable size
  writeData(employees, size); //variable size is passed as an argument to writeData in order to know how many lines
                              //to write out to the output.txt file
  return 0;
}

//readData will read in the file and set the variables to the private member variables of the Person class.
//It will make use of the Person class set functions. The function will return the number of lines that are
//in the input.txt file.
int readData(Person employees[], int size){
  ifstream file;
  file.open("input.txt");
  string fname;
  string lname;
  float hours;
  float rate;
  int i = 0; //counter

  if(!file){
    cout << "Error: Could not open file." << endl;
  }

  while(file >> fname){
    file >> lname;
    file >> hours;
    file >> rate;
    employees[i].setFirstName(fname);
    employees[i].setLastName(lname);
    employees[i].setHoursWorked(hours);
    employees[i].setPayRate(rate);
    i++;
  }

  file.close();
  return i;
}

//writeData will use the member functions that belong to the Person class to write to the output.txt file
void writeData(Person employees[], int size){
  ofstream file;
  file.open("output.txt");
  int i = 0;

  while(i < size){
    file << employees[i].fullName() << " ";
    file << fixed << setprecision(2) << employees[i].totalPay();
    file << endl;
    i++;
  }

  file.close();
}
