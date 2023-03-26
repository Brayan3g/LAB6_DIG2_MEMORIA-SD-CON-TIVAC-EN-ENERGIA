/*
  UNIVERSIDAD DEL VALLE DE GUATEMNALA
  DEPARTAMENTO DE INGENIERIA MECATRONICA, ELECTRONICA & BIOMEDICA
  ELECTRONICA DIGITAL 2
  LABORATORIO No.6 - MANEJO DE MEMORIA SD.
  BRAYAN GABRIEL GIRON GARCIA
*/

// INCLUIMOS LIBRERIAS 
#include <SPI.h>//Liberia de SPI
#include <SD.h> //Libreria para leer la SD

// DEFINICIONES Y VARIABLES
char get;
File myFile;
File root;

//------------------------- RUTINA DE CONFIGURACIONES -------------------------//  
void setup()
{
  SPI.setModule(0);  // Seleccionamos el modulo 0 para la comunicacion por SPI.
  // Open serial communications and wait for port to open:
  Serial.begin(115200); // INICIALIZAMOS LA CONSOLA A 115200.
  
  while (!Serial) {
    ;} // wait for serial port to connect. Needed for Leonardo only
  
  Serial.print("Initializing SD card...");
  pinMode(PA_3, OUTPUT); // SELECCIONMAOS EL PIN PA_3 COMO EL CHIP SELEC (CS).

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;}
  
  Serial.println("initialization done.");

  root = SD.open("/");//Poder leer los archivos dentro de la SD

  //Menu para el usuario 
  MENU();
}

//-------------------------- RUTINA DE LOOP INFINITO --------------------------//  

void loop() {
  
  get = Serial.read();   // RECIBIMOS EL DATO DE LA CONSOLA Y LO ASIGNAMOS A get. 
  char  a = (get, DEC);

//--------------------- SWITCH PARA SELECION DE IMAGENES ----------------------//  
  
  switch (get) {
    
    case '1':
      myFile = SD.open("LOGO.txt");
      if (myFile) { //Serial.println("LOGO.txt:");
        // read from the file until there's nothing else in it:
        while (myFile.available()) {
          Serial.write(myFile.read());}
        // close the file:
        myFile.close();}
        else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");}
      MENU();
      break;

    case '2':
      myFile = SD.open("MARIO.txt");
      if (myFile) { //Serial.println("MARIO.txt:");
        // read from the file until there's nothing else in it:
        while (myFile.available()) {
          Serial.write(myFile.read());}
        // close the file:
        myFile.close();}
        else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");}
      MENU();
      break;

    case '3':
      myFile = SD.open("DRAGON.txt");
      if (myFile) { //Serial.println("DRAGON.txt:");
        // read from the file until there's nothing else in it:
        while (myFile.available()) {
          Serial.write(myFile.read());}
        // close the file:
        myFile.close();}
        else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");}
      MENU();
      break;

      
    case '4':
      myFile = SD.open("J.txt");
      if (myFile) { //Serial.println("J.txt:");
        // read from the file until there's nothing else in it:
        while (myFile.available()) {
          Serial.write(myFile.read());}
        // close the file:
        myFile.close();}
        else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");}
      MENU();
      break; 
  }
}

//-------------------------- FUNCION DE MENU --------------------------//  

void MENU(void){
      Serial.println("\nINGRESE EL NUMERO DE LA IMAGEN DESEADA: \n");
      Serial.println("-> Envie 1) si quiere mostrar LIVERPOOL");
      Serial.println("-> Envie 2) si quiere mostrar MARIO");
      Serial.println("-> Envie 3) si quiere mostrar DRAGON_UVG");
      Serial.println("-> Envie 4) si quiere mostrar J \n");
}
