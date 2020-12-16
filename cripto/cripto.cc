/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Saúl Sosa
 * @date 15.dic.2020
 * @brief El Cifrado XOR requiere una clave secreta de encriptado/desencriptado. 
 *        A cada uno de los caracteres del fichero se le hará una transformacion, 
 *        que consistira en hacerle la operación xor con un carácter de la clave secreta.
 *        El método Cesar era usado ya en tiempos de los romanos. En este caso, 
 *        la codificación es como sigue: si una letra en el texto a codificar es la N-ésima letra del alfabeto, 
 *        sustitúyase esa letra por la (N + K)-ésima letra del alfabeto. 
 * @see https://es.wikipedia.org/wiki/Cifrado_XOR
 * @see https://es.wikipedia.org/wiki/Cifrado_C%C3%A9sar
 *
 */



#include "funciones_cripto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

int main(int argc, char* argv[]){
  std::string cifradoXor = "1", cesar = "2";
  std::string codificador = "+", descodificador = "-";  
  std::string contrasena = argv[4];
  Help(argc, argv[1]);
  //Declaracion de archivos
  FILE* paraCodificar;
  FILE* codificado;
  //Abrir los archivos en modo lectura y escritura
  paraCodificar = fopen(argv[1], "r");
	codificado = fopen(argv[2], "w");
  //Mensaje de error si no se puede abrir el documento 1
  if (!paraCodificar) { 
    std::cerr << "Uh oh, Tu archivo de texto no existe, prueba a crearlo!\n";
    exit(1);
  }

  
  if(argv[3]== cifradoXor){ //-----------------------------------------------------------cifrado Xor 
    if(argv[5] == codificador){
	    printf("Encriptando %s\n", argv[1]);
      printf("Los datos han sido encriptados en: %s\n", argv[2]);
  }
    if(argv[5] == descodificador){
	    printf("Desencriptando %s\n", argv[1]);
      printf("Los datos han sido desencriptados en: %s\n", argv[2]);
  }

	  //Aqui elige la contraseña
	  strip_newline(argv[4]);

    //Encripta el codigo
	  encrypt_data(paraCodificar, codificado, argv[4]);
	
	  //Cierra los archivos
	  fclose(paraCodificar);
	  fclose(codificado);

  return 0;
 }
  fclose(paraCodificar);
  fclose(codificado);
 
  if(argv[3] == cesar){ //------------------------------------------------------------cifrado cesar
    
    if(argv[5] == codificador){  //Para codificar
      //Declaramos los archivos
      std::ofstream codificado;
      std::ifstream paraCodificar;
      //Abrimos los archivos
      codificado.open(argv[2], std::ios::out);
      printf("Encriptando %s\n", argv[1]);
      paraCodificar.open(argv[1], std::ios::in);
      printf("Los datos han sido encriptados en: %s\n", argv[2]);
      //Mientras quede texto en el archivo
      while (paraCodificar) { 
        std::string strInput;
        std::getline(paraCodificar, strInput);  //Guarda una string hasta \n
        codificado << CesarCodi(strInput, contrasena);//Esta funcion codifica
   }
   return 0;
  }
  
  if(argv[5]==descodificador){  //Descodifica
    //Declaramos los archivos
    std::ofstream codificado;
    std::ifstream paraCodificar;

    printf("Desencriptando %s\n", argv[1]);
    printf("Desencriptado en %s\n", argv[2]);
    //Abrimos los archivos
    codificado.open(argv[2], std::ios::out);
    paraCodificar.open(argv[1], std::ios::in);
    //Mientras quede texto en el archivo
    while (paraCodificar) {
      std::string strInput;
      std::getline(paraCodificar, strInput); //Guarda una string hasta \n
      codificado << CesarDescodi(strInput, contrasena); //Esta funcion codifica
      return 0;
  }
  return 0;
  codificado.close();
  paraCodificar.close();
  
  }else{
     exit(1);
  }
}
}

