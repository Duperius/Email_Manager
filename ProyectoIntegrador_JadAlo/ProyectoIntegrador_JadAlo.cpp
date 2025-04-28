// ProyectoIntegrador_Jad.cpp 
//Jadiel Ortiz Santiago
//Y00632364


#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <locale.h> //Lenguaje del teclado
using namespace std;

//Arreglos

string cuentas[11][4];
string aguante[4];

//Variables
int opcmenu;
int opcguardar;
int opcselect;
int opcselect2;
int opccopiar;
string nombre;
string apellido;
string contrasena;
string cuentauser;

const string arroba = "@gmail.com";


//Funciones


//Guarda la informacion en txt
void GuardarTexto()
{
	ofstream datos("cuentas.txt"); //Bucle para guardar en el texto
	for (int i = 1; i <= 10; i++) {
		
		datos << cuentas[i][0] << "\n";
		datos << cuentas[i][1] << "\n";
		datos << cuentas[i][2] << "\n";
		datos <<  cuentas[i][3] << "\n";
	}

	datos.close();
}

void LeerDatos()
{
	ifstream datos("cuentas.txt");

	if (!datos.is_open()) {     //Si no encuentra archivo, genera otro
		ofstream crearDatos("cuentas.txt");
	    crearDatos.close();
		return;
	}

	
	for (int i = 1; i <= 10; i++) {        //Lee toda la linea del texto
		getline(datos, cuentas[i][0]); 
		getline(datos, cuentas[i][1]); 
		getline(datos, cuentas[i][2]); 
		getline(datos, cuentas[i][3]); 
	}

	datos.close(); //Cierra el archivo de texto
}

//copia los elementos de un usuario al otro
void CopiarCuenta()
{
	system("Cls");
	cout << "¿A dónde le gustaría copiar esta cuenta? \n";
	for (int i = 1; i < 11; i++) {
		cout << i << ") " << cuentas[i][2] << "\n";
	}
	cout << "\n";
	cout << "11) Cancelar \n";
	do {
		cin >> opccopiar;
	} while (opccopiar < 1 || opccopiar > 11);
	if (opccopiar == 11) {
		return;
	}
	cuentas[opccopiar][0] = cuentas[opcselect][0];
	cuentas[opccopiar][1] = cuentas[opcselect][1];
	cuentas[opccopiar][2] = cuentas[opcselect][2];
	cuentas[opccopiar][3] = cuentas[opcselect][3];
	//opcselect es el usuario que escogistes
	//opccopiar es a donde lo quieres copiar
}


//Elimina la informacion
void BorrarCuenta()
{
	
	cuentas[opcselect][0] = "";
	cuentas[opcselect][1] = "";
	cuentas[opcselect][2] = "";
	cuentas[opcselect][3] = "";
	
}

//Guarda la cuenta en la posicion que desees
void GuardarCuenta()
{
	system("cls"); //Borra la pantalla

	cout << "¿En que posición desea guardarlo? \n";
	cout << "\n";
	for (int i = 1; i <= 10; i++) {
		cout << i << ") " << cuentas[i][2] << "\n";
	}

	cout << "\n";
	do {
		cin >> opcguardar;
	} 
	while (opcguardar < 1 || opcguardar > 10); 

	cuentas[opcguardar][0] = aguante[0];
	cuentas[opcguardar][1] = aguante[1];
	cuentas[opcguardar][2] = aguante[2];
	cuentas[opcguardar][3] = aguante[3];
}


//Genera la informacion de la cuenta
void CrearCuenta()
{
	system("cls");
	cout << "Ingrese su primer nombre: ";
	cin >> nombre;
	do {
		if (nombre.find('@') != string::npos) { //Busca el @
			cout << "No puede tener ese carácter, ingrese su nombre de nuevo: \n";
			cin >> nombre;
		}
		else {
			break;
		}

	} while (nombre.find('@') != string::npos);
	cout << "Ingrese su segundo nombre: ";
	cin >> apellido;
	do {
		if (apellido.find('@') != string::npos) {
			cout << "No puede tener ese carácter, ingrese su apellido de nuevo: \n";
			cin >> apellido;
		}
		else {
			break;
		}

	} while (apellido.find('@') != string::npos);

	// Aqui conviertes nombre y apellido a minuscula
	for (char& c : nombre) {
		c = tolower(c);
	}
	for (char& c : apellido) {
		c = tolower(c);
	}

	
	string mail = nombre + apellido + arroba;

	cout << "Este será tu Gmail: " << mail << "\n";

	cout << "Ingrese una contraseña: ";
	cin >> contrasena;

	aguante[0] = nombre;
	aguante[1] = apellido;
	aguante[2] = mail;
	aguante[3] = contrasena;
	//La informacion se almacena en un
	//arreglo especifico

	GuardarCuenta();
}


//Aqui te permite ver la informacion
//que agregastes en cada cuenta
void VerCuentas()
{
	system("Cls");
	cout << "¿A cuál usuario le gustaría entrar? \n";
	cout << "\n";
	for (int i = 1; i <= 10; i++) {
		cout << i << ") " << cuentas[i][2] << "\n";
	}

	cout << "\n";
	cout << "11) Salir \n";
	cout << "\n";
	do {
		cin >> opcselect;
	} while (opcselect < 1 || opcselect > 11);
	if (opcselect == 11) {
		return;
	}
	
	system("Cls");
	cout << "Nombre: " << cuentas[opcselect][0] << "\n";
	cout << "Segundo Nombre: " << cuentas[opcselect][1] << "\n";
	cout << "Email: " << cuentas[opcselect][2] << "\n";
	cout << "Contraseña: " << cuentas[opcselect][3] << "\n";
	cout << "¿Qué desea hacer? \n";
	cout << "\n";
	cout << "1) Copiar \n";
	cout << "2) Borrar \n";
	cout << "3) Volver \n";

	do {
		cin >> opcselect2;
		switch (opcselect2) {
			
		case 1:
			CopiarCuenta();
			break;

		case 2:
			BorrarCuenta();
			break;

		case 3:
			break;
		}
	} while (opcselect2 < 1 || opcselect2 > 3);
}


int main()
{
	setlocale(LC_CTYPE, "Spanish"); //Cambia el teclado a español
	LeerDatos();
	do {
		
		system("cls");
		cout << "Email Manager! ++ \n";
		cout << "\n";
		cout << "Selecciona una opción: \n";
		cout << "\n";
		cout << "1) Crear Cuenta \n";
		cout << "2) Ver Cuentas \n";
		cout << "3) Salir \n";
		cin >> opcmenu;

		switch (opcmenu) {

		case 1:
			CrearCuenta();
			break;

		case 2:
			VerCuentas();
			break;

		case 3:
			cout << "Bye bye \n";
			GuardarTexto();
			break;

		}

	} while (opcmenu != 3);
	return 0;
}


