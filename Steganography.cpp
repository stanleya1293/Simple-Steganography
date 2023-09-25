#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>

void Steganography::readImage(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  inFile.getline(magicNumber);
  inFile >> width;
  inFile >> height;
  inFile >> maxColor;
  int temp;
  while(inFile) {
    inFile >> temp;
    vector.push_back(temp);
  }
  inFile.close();
}

void Steganography::readCipherText(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  inFile.getline(cipherText);
  inFile.close();
}

void Steganography::printCipherText(std::string fileName) {
  ofstream outFile;
  outFile.open(fileName);
  outFile.write(cipherText);
  outFile.close();
}

void Steganography::cleanImage() {

}

void Steganography::encipher() {

}

void Steganography::decipher() {
  
}
