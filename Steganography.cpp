/**
 * @file Steganography.cpp
 * @author Arden Stanley, Trey Wright
 * @date 2023-09-25
 * @brief implementations for steganography class
 * 
 * 
 */

#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to get the nth bit of a character
int Steganography::getNthBit(char cipherChar, int n) {
  return ((cipherChar >> n) % 2);
}

// Function to write the PPM image to a file
void Steganography::readImage(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  inFile >> (magicNumber); // Read P3 (magic number)
  inFile >> width; // Read image width
  inFile >> height; // Read image height
  inFile >> maxColor; // Read maximum color depth
  int temp;
  while (inFile) {
    inFile >> temp; // Read color data value
    colorData.push_back(temp); // Store color data in the vector
  }
  inFile.close();
}

// Function to write the PPM image to a file
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

// Function to read the cipher text from a file
void Steganography::readCipherText(std::string fileName) {
  ifstream inFile;
  inFile.open(fileName);
  getline(inFile, cipherText); // Read the entire line as cipher text
  inFile.close();
}

// Function to write the cipher text to a file
void Steganography::printCipherText(std::string fileName) {
  ofstream outFile;
  outFile.open(fileName);
  outFile << cipherText; // Write the entire cipher text
  outFile.close();
}

// Function to zero out the least significant bit of each color value
void Steganography::cleanImage() {
  for (int i = 0; i < colorData.size(); i++) {
    if (colorData[i] % 2 == 1) {
      colorData[i] = colorData[i] - 1; // Zero out the least significant bit
    }
  }
}
// Function to encode the cipher text into the image
void Steganography::encipher() {
  int colorDataIndex = 0;
  for (int i = 0; i < cipherText.size(); i++) {
    for (int j = 0; j <= 7; j++) {
      colorData[colorDataIndex] = getNthBit(cipherText[i], j) + colorData[colorDataIndex];
      colorDataIndex++;
    }
  }
}

// Function for decoding the hidden text from the image
void Steganography::decipher() {
  cipherText.clear();
  char currentChar = 0;
  int bitCount = 0;

  for (int i = 0; i < colorData.size(); i++) {
    int lsb = colorData[i] & 1; //Extracts the least significant bit

    currentChar |= (lsb << bitCount);
    bitCount++;

    if (bitCount == 8) {
      cipherText += currentChar;
      currentChar = 0;
      bitCount = 0;
    }
  }
}
