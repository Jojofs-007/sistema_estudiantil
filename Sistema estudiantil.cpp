#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;
ofstream datos_ca, datos_ci, datos_a;

void menu_principal();
void retorno(int);

void menu_carrera();
void menu_ciclo();
void menu_alumno();

class alumno {
	public:
		alumno();
		string nombre[10];
		char sexo[10];
		int edad[10];
		int contador;
		void menu_alumno();
};

alumno::alumno() {
}

int main () { //terminado
	setlocale(LC_ALL, "spanish");
	system("color f0");
	menu_principal();
	return 0;
}

void menu_principal() { //terminado
	int m;
	alumno z = alumno();
	system ("title Sistema estudiantil: menú principal");
	cout<<"\tMenu principal"<<endl;
	cout<<"1. Carrera."<<endl;
	cout<<"2. Ciclo."<<endl;
	cout<<"3. Alumnos."<<endl;
	cout<<"0. Salir del programa."<<endl;
	cout<<"Digite el menú de opciones que desea utilizar: ";
	cin>>m;
	while((((m!=0)&&(m!=1))&&(m!=2))&&(m!=3)) {
		cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
		getch();
		cerr<<"Digite el menú de opciones a utilizar: ";
		cin>>m;
	}
	switch(m) {
		case 0:
			cout<<"\nGracias por usar este programa."<<endl;
			exit(1);
			break;
		case 1:
			menu_carrera();
			break;
		case 2:
			menu_ciclo();
			break;
		case 3:
			z.menu_alumno();
			break;
	}
	menu_principal();
}


void menu_carrera() {
}
void menu_ciclo() {
}

void alumno::menu_alumno() {
	int m=1;
	while(m!=0) {
		system("title Sistema estudiantil: opciones para alumnos");
		int m;
		cout<<"\n\tMenú de opciones del alumno"<<endl;
		cout<<"1. Agregar datos de un alumno."<<endl;
		cout<<"2. Mostrar datos de alumnos registrados."<<endl;
		cout<<"0. Volver al menú principal."<<endl;
		cout<<"Digite el menú de opciones que desea utilizar: ";
		cin>>m;
		while((((m!=0)&&(m!=1))&&(m!=2))&&(m!=3)) {
			cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
			getch();
			cerr<<"Digite el menú de opciones a utilizar: ";
			cin>>m;
		}
		if (m==1) {
			char x;
			int i=1;
			system("title Sistema estudiantil: agregar alumnos");
			cout<<"\n\tAgregar datos de un alumno"<<endl;
			do {
				cout<<"Ingrese el nombre del alumno: ";
				cin.ignore();
				cin>>nombre[i];
				do {
					cout<<"Ingrese la edad del alumno: ";
					cin>>edad[i];
					if (edad[i]<=0) {
						cerr<<"\aEl número ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while(edad[i]<=0);
				do {
					cout<<"Ingrese el sexo del alumno (m/f): ";
					cin>>sexo[i];
					if ((((sexo[i]!='m')&&(sexo[i]!='M'))&&(sexo[i]!='f'))&&(sexo[i]!='F')) {
						cerr<<"a\El carácter ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while((((sexo[i]!='m')&&(sexo[i]!='M'))&&(sexo[i]!='f'))&&(sexo[i]!='F'));
				do {
					cout<<"¿Desea agregar otro alumno?"<<endl;
					cout<<"s/n: ";
					cin>>x;
					if ((x=='n')||(x=='N')) {
						cout<<"Usted ingresó los datos de "<<i<<" alumnos."<<endl;
						contador=i;
					} else if ((x=='s')||(x=='S')) {
						cout<<nombre[i]<<" "<<edad[i]<<endl;
						i++;
					} else {
						cerr<<"\aEl carácter ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while((((x!='s')&&(x!='S'))&&(x!='n'))&&(x!='N'));
			} while((x=='s')||(x=='S'));
		} else if (m==2) {
			system("title Sistema estudiantil: agregar alumnos");
			cout<<"\n\tMostrar datos de alumnos"<<endl;
			for(int j=1; j<=contador; j++) {
				cout<<endl<<"---------------"<<endl;
				cout<<"Nombre: "<<nombre[j]<<endl;
				cout<<"Edad: "<<edad[j]<<" años"<<endl;
				cout<<"Sexo: ";
				if ((sexo[j]=='m')||(sexo[j]=='M')) {
					cout<<"Masculino"<<endl;
				} else if ((sexo[j]=='f')||(sexo[j]=='F')) {
					cout<<"Femenino"<<endl;
				}
				cout<<endl<<"---------------"<<endl;
			}
			cout<<"Estos son los datos de alumnos registrados."<<endl;
		} else if (m==0) {
			menu_principal();
		}
	}
}
