// Author: Winson Gin
// Course: CPSC 301 7-9:50pm
// Date created: February 19, 2019
// Last updated: April 11, 2019
//Purpose of this program:
//This program will read the input.txt file and use the member function of the Person class to store the variables.
//Then, it will create a new output.txt file and write to it.
#include <iostream>
#include "person.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//function prototypes
void readData(vector<Person> &employees);
void writeData(vector<Person> employees);

int main(){
  vector<Person> employees;
  readData(employees); //passing employees vector as arugment
  writeData(employees); //passing employees vector as argument
  return 0;
}

//readData will read in the file and set the variables to the private member variables of the Person class.
void readData(vector<Person> &employees){
  ifstream file;
  file.open("input.txt");
  string fname;
  string lname;
  float hours;
  float rate;

  if(!file){
    cout << "Error: Could not open file." << endl;
  }

  while(file >> fname){
    file >> lname;
    file >> hours;
    file >> rate;
    employees.emplace_back(fname, lname, rate, hours); //emplace_back will automatically find the matching function or constructor in the Person class based on data types and number of arguments
  }

  file.close();
}

//writeData will use the member functions that belong to the Person class to write to the output.txt file
void writeData(vector<Person> employees){
  ofstream file;
  file.open("output.txt");

  for(int i = 0; i < employees.size(); i++){
    file << employees.at(i).fullName() << " ";
    file << fixed << setprecision(2) << employees.at(i).totalPay();
    file << endl;
  }

  file.close();
}
