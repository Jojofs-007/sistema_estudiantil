#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;
ofstream datos_a;

void menu_principal();

//Clase, constructor y función de 'Carrera'
class carrera {
	public:
		carrera();
		string nom[3];
		int n_ciclos[3];
		void menu_ca();
};

carrera::carrera() {
}

void carrera::menu_ca() {
	system("title Sistema estudiantil: opciones para alumnos");
	int m;
	cout<<"\n\tMenú de opciones del alumno"<<endl;
	cout<<"1. Agregar carreras."<<endl;
	cout<<"2. Mostrar carreras disponibles."<<endl;
	cout<<"0. Volver al menú principal."<<endl;
	cout<<"Digite el menú de opciones que desea utilizar: ";
	cin>>m;
	while((((m!=0)&&(m!=1))&&(m!=2))&&(m!=3)) {
		cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
		getch();
		cerr<<"Digite el menú de opciones a utilizar: ";
		cin>>m;
	}


}

//Clase, constructor y función de 'Ciclo'
void menu_ciclo();
void menu_ciclo() {

}

//Clase, constructor y funcion de 'Alumno' (Terminado)
class alumno {
	public:
		alumno();
		string nombre[10];
		char sexo[10];
		int edad[10];
		int contador;
		void menu_a();
};

alumno::alumno() {
}

void alumno::menu_a() {
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
		while(((m!=0)&&(m!=1))&&(m!=2)) {
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
					cout<<"¿Desea guardar los datos del alumno en un archivo de texto?"<<endl;
					cout<<"s/n: ";
					cin>>x;
					if ((x=='n')||(x=='N')) {
						cout<<"No se guardarán los datos del alumno."<<endl;
					} else if ((x=='s')||(x=='S')) {
						datos_a.open("Alumnos.txt",ios::app);
						if (datos_a.fail()) {
							cerr<<"\aNo se pudo crear el archivo."<<endl;
							exit(1);
						} else {
							datos_a<<"---------------\n";
							datos_a<<"Nombre: "<<nombre[i]<<"\n";
							datos_a<<"Edad: "<<edad[i]<<" años"<<"\n";
							datos_a<<"Sexo: ";
							if ((sexo[i]=='m')||(sexo[i]=='M')) {
								datos_a<<"Masculino";
							} else if ((sexo[i]=='f')||(sexo[i]=='F')) {
								datos_a<<"Femenino";
							}
							datos_a<<"\n---------------\n";
							datos_a.close();
							cout<<"Los datos se han guardado con éxito."<<endl;
						}
					} else {
						cerr<<"\aEl carácter ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while((((x!='s')&&(x!='S'))&&(x!='n'))&&(x!='N'));
				x=0;
				do {
					cout<<"¿Desea agregar otro alumno?"<<endl;
					cout<<"s/n: ";
					cin>>x;
					if ((x=='n')||(x=='N')) {
						cout<<"Usted ingresó los datos de "<<i<<" alumnos."<<endl;
						contador=i;
					} else if ((x=='s')||(x=='S')) {
						i++;
					} else {
						cerr<<"\aEl carácter ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while((((x!='s')&&(x!='S'))&&(x!='n'))&&(x!='N'));
			} while((x=='s')||(x=='S'));
		} else if (m==2) {
			system("title Sistema estudiantil: mostrar datos de alumnos");
			cout<<"\n\tMostrar datos de alumnos"<<endl;
			cout<<"Estos son los datos de alumnos registrados."<<endl;
			for(int j=1; j<=contador; j++) {
				cout<<endl<<"---------------"<<endl;
				cout<<"Nombre: "<<nombre[j]<<endl;
				cout<<"Edad: "<<edad[j]<<" años"<<endl;
				cout<<"Sexo: ";
				if ((sexo[j]=='m')||(sexo[j]=='M')) {
					cout<<"Masculino";
				} else if ((sexo[j]=='f')||(sexo[j]=='F')) {
					cout<<"Femenino";
				}
				cout<<endl<<"---------------"<<endl;
			}
			cout<<"Estos son los datos de "<<contador<<" alumnos registrados."<<endl;
		} else if (m==0) {
			menu_principal();
		}
	}
}

//int main y el menu principal (Terminado)
int main () {
	setlocale(LC_ALL, "spanish");
	system("color f0");
	menu_principal();
	return 0;
}

void menu_principal() {
	int m;
	carrera x = carrera();
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
			x.menu_ca();
			break;
		case 2:
			menu_ciclo();
			break;
		case 3:
			z.menu_a();
			break;
	}
	cout<<"\nIngrese cualquier tecla para volver al menú principal... ";
	getch();
	system("cls");
	menu_principal();
}

/*
Este proyecto fue realizado el día 30/05/2021 por el grupo #1 de programación I ^u^
Integrantes del grupo:
	- Jonathán Josué Florián Sipaque 7490-20-3403
	- Swany Celine Rivera Hernández 7490-20-12172
	- Pablo Josué López de León 7490-20-24416
	- Mauricio Rodolfo Mejía Alevon 7490-20-17072
*/
