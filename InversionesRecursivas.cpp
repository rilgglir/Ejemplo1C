/*
Descripción

Escribe un programa que implemente el siguiente algoritmo recursivo "f", el cual opera sobre una secuencia "S"
de enteros y realiza los siguientes pasos:

    1.- Invierte el orden de los elementos de "S".
    2.- Si "S" tiene más de dos elementos, entonces:
        -Ejecuta "f" sobre la mitad izquierda de "S".
        -Ejecuta "f" sobre la mitad derecha de "S".

Entrada

Un entero "N" seguido de los "N" enteros de "S" separados por espacios. 
Puedes suponer que "N" es una potencia de 2 menor que 10 a la 5a potencia, y que todos los 
elementos de "S" están entre 0 y 10 a la 6a potencia.

Salida

La secuencia "S" después de ejecutar "f" sobre ella.
*/

// agregando un comentario Cesar Benavides Alvarez
//Comentario Julio Cesar_Tapia Herrera
====================

#include <iostream>
//Variables Globales
int N;

using namespace std;

void imprimir(int S[]);
void invertir(int inf, int sup, int S[], int N);

int main() {
	

	cin >> N;
	
	int S[N];
	
	//cout << "\n Se ha ingresado el numero N: " << N << " .\n";
	
	for(int i=0;i<N ; i++){
            
        cin >> S[i];
        //cout << "\n Se ha ingresado el número: " << S[i] << ", en la posicion: " << i << " .\n";
    }
    
	//cout << "\n El arreglo inicia con: \n";
   //imprimir(S,N);
    
    invertir(0,N-1,S,N);
    
    
  //	cout << "\n El arreglo termina con: \n";  
  	imprimir(S);
	
	return 0;
};

void imprimir(int S[]){

	
	for(int i=0;i<N ; i++){
            
        cout << S[i] << " ";

    }
	
};

void invertir(int inf, int sup, int S[], int N){
	
	int aux, medio, nuevoN, infIzq, infDer, supIzq, supDer;
	int *ptr_S = S;
	
	nuevoN = 1+(sup - inf)/2; //sacando cantidad de intercambios y nuevo N para recursividad

	medio = (sup - inf)/2 + inf; //sacando mitad


	for(int i=0; i<nuevoN; i++){ //numero de intercambios
	
		//aux = S[inf+i]; //guardando 1er elemento
		aux = *(ptr_S+inf+i); //guardando 1er elemento con puntero
		//S[inf+i] = S[nuevoN+i]; //moviendo el elento de la mitad derecha a la mitad izquierda
		*(ptr_S+inf+i) = *(ptr_S+sup-i); //moviendo el elento de la mitad derecha a la mitad izquierda
		//S[nuevoN+i]=aux; //moviendo el elemento de la mitad izquierda guardado a la mitad derecha
		*(ptr_S+sup-i)=aux;
	}
	
	if(N>2){
		
		
		infIzq = inf;
		supIzq = medio;
		infDer = medio+1;
		supDer = sup;
		
		invertir(infIzq,supIzq,S,nuevoN);
		invertir(infDer,supDer,S,nuevoN);
	}
}