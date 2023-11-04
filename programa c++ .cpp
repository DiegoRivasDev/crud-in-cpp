//3er semestre ing sistemas seccion b
//Realizado por:
//Diego Rivas 28.715.829 
//Gherson Sánchez 25.402.264


//Realizar un sistema que permita guardar en varios archivos,

//- Nomina. (nombre, apellido, telefono, cargo, cedula).
//- Salario. (cedula, salario).

//Validaciones.
//- El salario no puede ser menor a 0.

//Debe ser entregado vía correo a   leroy.g3c@gmail.com
//indicando: nombre, apellido, cédula, semestre y sección.-

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string nombre, Apellido, telefono, cargo;
int Cedula=0, auxCedula=0, salario;
char opca;
bool encontrado = false;

void registro()
{
    ofstream escritura;
    ifstream consulta;

    do{
    escritura.open("nomina.txt", ios::out | ios::app);
    consulta.open("nomina.txt", ios::in);

    if (escritura.is_open() && consulta.is_open()){

            bool repetido=false;

            cout<<"\n";
            cout<<"\tIngresa la Cedula:    ";
            cin>>auxCedula;
            
            
            consulta>>Cedula;
            while (!consulta.eof()){
                consulta>>nombre>>Apellido>>telefono>>cargo>>salario;
                if (auxCedula==Cedula){
                cout<<"\t\tse a encontrado esa misma cedula ya registrada\n";
                cout<<"\t\tno debe introducirla otra vez\n";
                repetido=true;
                break;
                }
                consulta>>Cedula;
            }

            if (repetido==false){
                cout<<"\tIngresa el nombre:   ";
                cin>>nombre;
                cout<<"\tIngresa el Apellido: ";
                cin>>Apellido;
                cout<<"\tIngresa el telefono:   ";
                cin>>telefono;
                cout<<"\tIngresa el cargo:     ";
                cin>>cargo;
                cout<<"\tIngresa el salario:     ";
                cin>>salario; 
                
				if (salario<0) {
					cout<<"\n\n";
                	cout << "\tEl valor del salario no puede ser menor a 0 intente de nuevo.";
                    repetido=true;
                    break;
                
				}
                
        escritura<<auxCedula<<" "<<nombre<<" "<<Apellido<<" "<<telefono<<" "<<cargo<<" "<<salario<<endl;
                cout<<"\n\tEl registro se realizo de forma exitosa.\n";
            }

            cout<<"\n\tDeseas ingresar otra entrada? (S/N): ";
            cin>>opca;

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    escritura.close();
    consulta.close();

    }while (opca=='S' or opca=='s');

}

void nominas()
{

    ifstream lectura;
    lectura.open("nomina.txt", ios::out | ios::in);
    if (lectura.is_open()){
       lectura>>Cedula;
       while (!lectura.eof()){
            lectura>>nombre>>Apellido>>telefono>>cargo>>salario;
            cout<<"\n\n";
            cout<<"\tNomina ";
            cout<<"\n\n";
            cout<<"\tCedula:   "<<Cedula<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tApellido: "<<Apellido<<endl;
            cout<<"\ttelefono: "<<telefono<<endl;
            cout<<"\tcargo:    "<<cargo<<endl;
            cout<<"\n\n";
            cout<<"\tSalario ";
            cout<<"\n\n";
            cout<<"\tCedula:   "<<Cedula<<endl;
            cout<<"\tsalario:  "<<salario<<endl;
            lectura>>Cedula;
            cout<<"\n\n";
       }

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
}

void realizado()
{
            cout<<"\n\n";
            cout<<"\trealizado por: ";
            cout<<"\n\n";
            cout<<"\n\n";
            cout<<"\tDiego Rivas 28.715.829     ";
            cout<<"\n\n";
            cout<<"\tGherson Sanchez 25.402.264 ";
            cout<<"\n\n";
            cout<<"\n\n";
            cout<<"\tcarrera ";
            cout<<"\n\n";
            cout<<"\ting en sistemas         ";
			cout<<"\n\n";
            cout<<"\t3er semastre seccion b  ";
            cout<<"\n\n";
					cout<<"\n\n";        
}

int main()
{
    system ;
    int opc;

    do{
    system("cls");

    cout<<"\n\tManejo de archivos en c++\n\n";
    cout<<"\n\t1.-Crear entrada";
    cout<<"\n\t2.-Registros";
    cout<<"\n\t3.-Realizado por:";
    cout<<"\n\t4.-Salir";
    cout<<"\n\n\tElige una opcion:  ";
    cin>>opc;
    switch (opc)
    {
case 1:{
    system("cls");
    registro();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 2:{
    system("cls");
    nominas();
    cout<<"\n\t\t";
    system ("pause");
    break;
}

case 3:{
    system("cls");
    realizado();
    cout<<"\n\t\t";
    system ("pause");
    break;
    }
case 4:{
    cout<<"\n\n\tHasta la proxima\n\n\t\t"; system ("pause");
    break;
}
default:{
    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t"; system ("pause");
    break;
}
    }

    }while (opc!=4);

    system("cls");

    return 0;}

