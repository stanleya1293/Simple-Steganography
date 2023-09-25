#include "Steganography.h"
#include <iostream>

using namespace std;

int main() {
  Steganography steg;
  char choice;
  string ppmName;
  string cipherTxtName;
  string newFileName;
  cout << "Would you like to (e)ncode or (d)ecode? ";
  cin >> choice;
  if (choice == 'e') {
    cout << "What is the ppm file name? ";
    cin >> ppmName;
    cout << "What is the cipher text file name? ";
    cin >> cipherTxtName;
    cout << "What would you like the name to be for the encoded image file? ";
    cin >> newFileName;
    steg.readImage(ppmName);
    steg.readCipherText(cipherTxtName);
    steg.cleanImage();
    steg.encipher();
    steg.printImage(newFileName);
  }
  else if (choice == 'd') {
    cout << "What is the encoded ppm file name? ";
    cin >> ppmName;
    cout << "What is the output cipher text file? ";
    cin >> cipherTxtName;
    steg.readImage(ppmName);
    steg.decipher();
    steg.printCipherText(cipherTxtName);
  }
}
