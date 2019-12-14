/*
Sarah Monthofer
2317035
monthofer@chapman.edu
CPSC 350 - Assignment 6

Description: Main method for sorting algorithms whcih verifies a file was sent in
      through the command line then makes an instace of the file and sends the file
      to be read from
*/

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

#include "Assignment6.h"

using namespace std;

int main(int argc, char** argv) {
  Sort me;

  // make sure a second argument is sent in command line
  if (argc != 2) {
    cout << endl << "Error - INVALID NUMBER OF ARGUMENTS" << endl << endl;
    exit(1);
  }

  // // read from file if file exits in command line
  if (argc >= 2) {
    cout << "Reading from file..." << endl;
    cout << endl;
    string myFile = argv[1];
    me.readFile(myFile);
  }
}
