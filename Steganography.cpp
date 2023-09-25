#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int Steganography::getNthBit(char cipherChar, int n) {
  return ((cipherChar >> n) % 2);
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

void Steganography::printImage(std::string fileName) {
  ofstream outFile;
  outFile.open(fileName);
  outFile << magicNumber << endl
	  << width << " " << height << endl
	  << maxColor << endl;
  int counter = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      outFile << colorData[counter];
      counter++;
      outFile << " ";
      outFile << colorData[counter];
      counter++;
      outFile << " ";
      outFile << colorData[counter];
      counter++;
      outFile << " ";
    }
    outFile << endl;
  }
  outFile.close();
}

void Steganography::readCipherText(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  getline(inFile, cipherText);
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
  int colorDataIndex = 0;
  for (int i = 0; i < cipherText.size(); i++) {
    for (int j = 0; j <= 7; j++) {
      colorData[colorDataIndex] = getNthBit(cipherText[i], j) + colorData[colorDataIndex];
      colorDataIndex++;
    }
  }
}

void Steganography::decipher() {
  
}
