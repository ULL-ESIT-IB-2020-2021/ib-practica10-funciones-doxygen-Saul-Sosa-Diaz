#include "funciones_cripto.h"
using namespace std;



void Help(int argc, char* palabra){
  std::string ayuda = "--help";
  //Si solo se introduce el nombre del programa se mostrara esto
  if(argc == 1){
    std::cout << "./cripto -- Cifrado de ficheros" << std::endl <<
    "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl <<
    "Pruebe ./cripto --help para más información"<< std::endl;
    exit(1);
  }
  //Si ademas de introducir el nombre del programa, se le agrega --help se mostrara esto
  if(palabra == ayuda){
    std::cout << "./cripto -- Cifrado de ficheros" << std::endl <<
    "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación" << std::endl 
    << "fichero_entrada: Fichero a codificar" << std::endl 
    << "fichero_salida:  Fichero codificado" << std::endl 
    << "método:          Indica el método de encriptado" << std::endl 
    << "                 1: Cifrado xor" << std::endl << "                 2: Cifrado de César" << std::endl
    << "password:        Palabra secreta en el caso de método 1, Valor de K en el método 2" << std::endl
    << "operación:       Operación a realizar en el fichero" << std::endl
    <<"                 +: encriptar el fichero" <<  std::endl << "                 -: desencriptar el ficheror" << std::endl;
    exit(1);
  }
}

void encrypt_data(FILE* input_file, FILE* output_file, char* key){
	int key_count = 0;                                                    //usado para restaurar la clave si strlen(key) < strlen(encriptado)
	int encrypt_byte;
	
	while( (encrypt_byte = fgetc(input_file)) != EOF) //bucle hasta que se acaba el archivo
	{
		
		fputc(encrypt_byte ^ key[key_count], output_file);

		
		key_count++;
		if(key_count == strlen(key))
			key_count = 0;
	}
}

void strip_newline(char* to_strip){  //borra los enters
	
	if (to_strip[strlen(to_strip) - 1] == '\n')
	{
		to_strip[strlen(to_strip) - 1] = '\0';
	}
}


std::string CesarCodi(std::string frase, std::string contrasena){  //Codifica en formato Cesar
  std::string cesarString = frase;
  int suma;
  for(int i = 0; i < frase.size(); i++){
    suma = int(frase[i])+stoi(contrasena);
    cesarString[i] = char(suma);
  }
return cesarString;
}
std::string CesarDescodi(std::string frase, std::string contrasena){ // descodifica en formato cesar
  std::string cesarString = frase;
  int suma;
  for(int i = 0; i < frase.size(); i++){
    suma = int(frase[i])-stoi(contrasena);
    cesarString[i] = char(suma);
  }
return cesarString;
}