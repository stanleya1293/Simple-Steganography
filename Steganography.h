#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <iostream>
#include <vector>

class Steganography {
  
 private:                                     // Private member functions
  std::string magicNumber;                    // Stores the magic number
  int width;                                  // Stores the image width
  int height;                                 // Stores the image height
  int maxColor;                               // Stores the maximum color depth
  std::vector<int> colorData;                 // Stores the color data of the image
  std::string cipherText;                     // Stores the hidden cipher text
  int getNthBit(char cipherChar, int n);      // Private helper function to get the nth bit of a character
  
 public:                                      // Public member functions
  void readImage(std::string fileName);       // Function to read a PPM image from a file 
  void printImage(std::string fileName);      // Function to write a PPM image to a file
  void readCipherText(std::string fileName);  // Function to read cipher text from a file
  void printCipherText(std::string fileName); // Function to write cipher text to a file
  void cleanImage();                          // Function to clean the image by zeroing out the lcb 
  void encipher();                            // Function to encipher the cipher text into the image
  void decipher();                            // Function to decipher the hidden text from the image
};

#endif
