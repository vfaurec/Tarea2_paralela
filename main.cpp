#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

//multiplicar 2 matrices
void multiplicar(string matriz1, string matriz2){

    int i=0, j=0;
    int x[matriz1.length()], y[matriz2.length()];

    //*** *** matriz 1 *** ***

    while(i<matriz1.length()){
        if(matriz1[i]=='-'){
            x[j] = (-1)* (matriz1[i+1] - '0');
            j++, i++;
        }else{
            x[j] = matriz1[i] - '0';
            j++;
        }
        i++; 
    }
 
    // *** *** matriz 2 *** ***

    i=0; j=0;

    while(i<matriz2.length()){
        if(matriz2[i]=='-'){
            y[j] = (-1)* (matriz2[i+1] - '0');
            j++, i++;
        }else{
            y[j] = matriz2[i] - '0';
            j++;
        }
        i++; 
    }

    //Algoritmo para multiplicar dos matrices

    int resultado[sizeof(x)];

    resultado[0] = (x[0]*y[0])+(x[1]*y[3])+(x[2]*y[6]);
    resultado[1] = (x[0]*y[1])+(x[1]*y[4])+(x[2]*y[7]);
    resultado[2] = (x[0]*y[2])+(x[1]*y[5])+(x[2]*y[8]);

    resultado[3] = (x[3]*y[0])+(x[4]*y[3])+(x[5]*y[6]);
    resultado[4] = (x[3]*y[1])+(x[4]*y[4])+(x[5]*y[7]);
    resultado[5] = (x[3]*y[2])+(x[4]*y[5])+(x[5]*y[8]);

    resultado[6] = (x[6]*y[0])+(x[7]*y[3])+(x[8]*y[6]);
    resultado[7] = (x[6]*y[1])+(x[7]*y[4])+(x[8]*y[7]);
    resultado[8] = (x[6]*y[2])+(x[7]*y[5])+(x[8]*y[8]);

    //cout << "largo matriz resultante " << j << endl;

    int contador=0;
    
    //Mostrar matriz resultante 
    cout << "La matriz resultante es..." << endl;
    for(int i=0; i<(j-2);i++){
        contador=i;
        if(contador==3 || contador==6){
            cout << endl;
        }
        cout << resultado[i] << " | ";
    }
    cout << endl;

}

//limpiar caracteres "basura" de una linea y obtener las matrices
void limpiar_linea(string linea){
    
    //Imprime una línea de entrada
    cout << endl;
    cout << "Ingresa la línea -> " << linea << endl;

    string matriz_x, matriz1, matriz2;
    int posicion=0;
   
    for(int i=0; i<linea.length(); i++){
        //Limpio caracteres -> matriz_x
        if(linea[i]!='[' && linea[i]!=']' && linea[i]!=',' && linea[i]!=','){
            matriz_x.push_back(linea[i]);
        }
    }

    //obtengo posicion de corte en las matrices
    for(int i=0; i<matriz_x.length();i++){
        if(matriz_x[i]==':'){
            posicion=i;
        }
    }

    //Separar en dos matrices string
    for(int i=0; i<posicion;i++){
        if(matriz_x[i]!=',' && matriz_x[i]!=';'){
            matriz1.push_back(matriz_x[i]);
        }
    }

    int i=posicion+1;

    while((i>posicion) && (i<=matriz_x.length())){
        if(matriz_x[i]!=';' && matriz_x[i]!=','){
            matriz2.push_back(matriz_x[i]);
        }
        i++;
    }

    multiplicar(matriz1, matriz2);

}

int main(int argc, char* argv[]){

    ifstream archivo_entrada;
    string matrices;
    int i=0;

    //paso de parámetros y validación de argumentos
    string args_auxiliar;
    string argumentos;
    int contador_archivos = 0;

    for(int i=1; i<argc; i++){
        args_auxiliar = argv[i];
        cout << "el argumento " << i << " es: " << argv[i] << endl;
        if(args_auxiliar == "-m" && i!=argc-1)
        {
            argumentos = argv[i+1];
            contador_archivos++;
        }
    
    }

    cout << contador_archivos << endl;

    if(contador_archivos != 1){
        cout << "FALTAN O SOBRAN ARGUMENTOS" << endl;
        return 0;
    }

    //Abrir archivo en modo lectura 
    archivo_entrada.open("Matrices.txt",ios::in); 
    if(archivo_entrada.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    //Mientras no este en el final del archivo, obtengo cada línea y la guardo en matrices[i]
    while(!archivo_entrada.eof()){ 
        getline(archivo_entrada,matrices);
        limpiar_linea(matrices);
    }

    archivo_entrada.close();

    return 0;
}

