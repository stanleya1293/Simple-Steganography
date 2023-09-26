#include "Steganography.h"
#include <iostream>

using namespace std;

int main() {
  
  Steganography stegy;
  char choice;
  string ppmName;
  string cipherTxtName;
  string newFileName;
  
  cout << "Would you like to (e)ncode or (d)ecode? ";
  cin >> choice; // user input 

  // Encoding process
  if ((choice == 'e') || (choice == 'E')) {
    
    cout << "What is the ppm file name? ";
    cin >> ppmName;
    
    cout << "What is the cipher text file name? ";
    cin >> cipherTxtName;
    
    cout << "What would you like the name to be for the encoded image file? ";
    cin >> newFileName;
    
    stegy.readImage(ppmName);
    stegy.readCipherText(cipherTxtName);
    stegy.cleanImage();
    stegy.encipher();
    stegy.printImage(newFileName);
  }

  // Decoding process
  else if ((choice == 'd') || (choice == 'D')) {
    
    cout << "What is the encoded ppm file name? ";
    cin >> ppmName;
    
    cout << "What is the output cipher text file? ";
    cin >> cipherTxtName;
    
    stegy.readImage(ppmName);
    stegy.decipher();
    stegy.printCipherText(cipherTxtName);
  }

  // Invalid choice
  else {
    cout << "Character Not Found Please Try Again with (e) or (d)\n";
  }
}
