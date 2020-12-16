#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Help(int , char*);
void strip_newline(char* );
void encrypt_data(FILE* , FILE* , char *);
std::string CesarCodi(std::string, std::string);
std::string CesarDescodi(std::string, std::string);