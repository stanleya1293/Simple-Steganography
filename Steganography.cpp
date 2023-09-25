#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Steganography::getNthBit(char cipherChar, int n) {
  cipherChar >> n;
  return (cipherChar % 2);
}

void Steganography::readImage(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  inFile >> (magicNumber);
  inFile >> width;
  inFile >> height;
  inFile >> maxColor;
  int temp;
  while (inFile) {
    inFile >> temp;
    colorData.push_back(temp);
  }
  inFile.close();
}

void Steganography::readCipherText(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  inFile >> cipherText;
  inFile.close();
}

void Steganography::printCipherText(std::string fileName) {
  ofstream outFile;
  outFile.open(fileName);
  outFile << cipherText;
  outFile.close();
}

void Steganography::cleanImage() {
  for (int i = 0; i < colorData.size(); i++) {
    if (colorData[i] % 2 == 1) {
      colorData[i] = colorData[i] - 1;
    }
  }
}

void Steganography::encipher() {
  
}

void Steganography::decipher() {
  
}
