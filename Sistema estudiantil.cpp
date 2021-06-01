#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

ofstream datos_a;

void menu_principal();
void creditos();

bool carreras_creadas=false, alumnos_creados=false;

//Estructura para recolectar datos de las clases 'Carrera' y 'Ciclo'
struct carrera_ciclo {
	string nombre;
	char tcarrera;
	int nciclos;
	int c_materia[4];
	string nom_materia[4];
} info[4];

//Clase, constructor y función de 'Carrera' (Terminado)
class carrera {
	public:
		carrera();
		string nom[4];
		int n_ciclos[4];
		char tipo_ca[4];
		void menu_ca();
};

carrera::carrera() {
}

void carrera::menu_ca() {
	int m=1;
	while(m!=0) {
		system("title Sistema estudiantil: opciones para carrera");
		cout<<"\n\tMenú de opciones del alumno"<<endl;
		cout<<"1. Agregar carreras."<<endl;
		cout<<"2. Mostrar carreras disponibles."<<endl;
		cout<<"0. Volver al menú principal."<<endl;
		cout<<"Digite el menú de opciones que desea utilizar: ";
		cin>>m;
		while (((m!=0)&&(m!=1))&&(m!=2)) {
			cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
			getch();
			cerr<<"Digite la opción a utilizar: ";
			cin>>m;
		}
		if (m==1) {
			int i=1;
			system("title Sistema estudiantil: agregar carreras");
			cout<<"\n\tAgregar información de carreras"<<endl;
			do {
				cout<<"Ingrese el nombre de la carrera No. "<<i<<": ";
				cin.ignore();
				cin>>nom[i];
				do {
					cout<<"Ingrese el número de ciclos de la carrera "<<nom[i]<<": ";
					cin>>n_ciclos[i];
					if (n_ciclos[i]<=0) {
						cerr<<"\aEl número ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while(n_ciclos[i]<=0);
				do {
					cout<<"Ingrese el tipo de carrera."<<endl;
					cout<<"\"T\" si es técnico o \"L\" si es licenciatura (se acepta mayúscula y/o minúscula): ";
					cin>>tipo_ca[i];
					if ((((tipo_ca[i]!='t')&&(tipo_ca[i]!='T'))&&(tipo_ca[i]!='l'))&&(tipo_ca[i]!='L')) {
						cerr<<"a\El carácter ingresado es inválido, intente de nuevo."<<endl<<endl;
					}
				} while ((((tipo_ca[i]!='t')&&(tipo_ca[i]!='T'))&&(tipo_ca[i]!='l'))&&(tipo_ca[i]!='L'));
				info[i].nombre=nom[i];
				info[i].nciclos=n_ciclos[i];
				info[i].tcarrera=tipo_ca[i];
				i++;
			} while(i<=3);
			carreras_creadas=true;
		} else if (m==2) {
			system("title Sistema estudiantil: mostrar carreras disponibles");
			cout<<"\n\tMostrar carreras disponibles"<<endl;
			if (carreras_creadas==false) {
				cerr<<"\a\nPor favor ingrese a la primera opción para agregar carreras y poder verlas."<<endl;
			} else {
				for(int j=1; j<=3; j++) {
					cout<<endl<<"---------------"<<endl;
					cout<<"Nombre: "<<nom[j]<<endl;
					cout<<"Número de ciclos: "<<n_ciclos[j]<<endl;
					cout<<"Tipo de carrera: ";
					if ((tipo_ca[j]=='t')||(tipo_ca[j]=='T')) {
						cout<<"Técnico";
					} else if ((tipo_ca[j]=='l')||(tipo_ca[j]=='L')) {
						cout<<"Licenciatura";
					}
					cout<<endl<<"---------------"<<endl;
				}
				cout<<"Estas son las carreras registradas."<<endl;
			}
		} else if (m==0) {
			return;
		}
	}
}

//Clase, constructor y función de 'Ciclo' //terminado
class ciclo {
	public:
		ciclo();
		int codigo_ma[4];
		string materia[4];
		void menu_ci();
};

ciclo::ciclo() {
}

void ciclo::menu_ci() {
	system("title Sistema estudiantil: opciones para ciclos de una carrera");
	if (carreras_creadas==false) {
		cerr<<"\a\nPor favor agregue carreras para ingresar a esta opción."<<endl;
	} else {
		int m=1;
		while(m!=0) {
			cout<<"\n\tLista de carreras para editar sus ciclos"<<endl;
			for (int i=1; i<=3; i++) {
				cout<<i<<"."<<info[i].nombre<<"."<<endl;
			}
			cout<<"(Si desea volver al menú principal digite \"0\")"<<endl;
			cout<<"Digite el número de la carrera que desea agregar materias: ";
			cin>>m;
			while ((((m!=0)&&(m!=1))&&(m!=2))&&(m!=3)) {
				cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
				getch();
				cerr<<"Digite el número de la carrera que desea agregar materias: ";
				cin>>m;
			}
			if (m!=0) {
				cout<<"Carrera: "<<info[m].nombre<<endl;
				cout<<"Número de ciclos: "<<info[m].nciclos<<endl;
				for(int i=1; i<=3; i++) {
					codigo_ma[i]=i;
					cout<<"Ingrese el nombre de la materia No. "<<codigo_ma[i]<<": ";
					cin>>materia[i];
					info[m].c_materia[i]=codigo_ma[i];
					info[m].nom_materia[i]=materia[i];
				}
				cout<<"Las materias se han registrado con éxito"<<endl;
			}
		}
	}
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
	if (carreras_creadas==false) {
		cerr<<"\a\nPor favor agregue carreras para ingresar a esta opción."<<endl;
	} else {
		int m=1, carrera;
		while(m!=0) {
			system("title Sistema estudiantil: opciones para alumnos");
			cout<<"\n\tMenú de opciones del alumno"<<endl;
			cout<<"1. Agregar datos de un alumno."<<endl;
			cout<<"2. Mostrar datos de alumnos registrados."<<endl;
			cout<<"0. Volver al menú principal."<<endl;
			cout<<"Digite el menú de opciones que desea utilizar: ";
			cin>>m;
			while(((m!=0)&&(m!=1))&&(m!=2)) {
				cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
				getch();
				cerr<<"Digite la opción a utilizar: ";
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
						cout<<"Ingrese el sexo del alumno. ";
						cout<<"\"M\" si es masculino o \"F\" si es femenino (se acepta mayúscula y/o minúscula): ";
						cin>>sexo[i];
						if ((((sexo[i]!='m')&&(sexo[i]!='M'))&&(sexo[i]!='f'))&&(sexo[i]!='F')) {
							cerr<<"a\El carácter ingresado es inválido, intente de nuevo."<<endl<<endl;
						}
					} while((((sexo[i]!='m')&&(sexo[i]!='M'))&&(sexo[i]!='f'))&&(sexo[i]!='F'));

					cout<<"\n\tLista de carreras para inscribirse"<<endl;
					for (int j=1; j<=3; j++) {
						cout<<j<<"."<<info[j].nombre<<"."<<endl;
					}
					cout<<"Digite el número de la carrera que desea estudiar: ";
					cin>>carrera;
					while ((((carrera!=0)&&(carrera!=1))&&(carrera!=2))&&(carrera!=3)) {
						cerr<<"\aEl número digitado es inválido, intente de nuevo... ";
						getch();
						cerr<<"Digite el número de la carrera que desea estudiar: ";
						cin>>carrera;
					}
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
								datos_a<<"\n"<<"Carrera: "<<info[carrera].nombre<<"\n";
								datos_a<<"Tipo de carrera: ";
								if ((info[carrera].tcarrera=='t')||(info[carrera].tcarrera=='T')) {
									datos_a<<"Técnico";
								} else if ((info[carrera].tcarrera=='l')||(info[carrera].tcarrera=='L')) {
									datos_a<<"Licenciatura";
								}
								datos_a<<"\nNo. de Ciclos: "<<info[carrera].nciclos<<"\n";
								datos_a<<"Materias: "<<"\n";
								for(int k=1; k<=3; k++) {
									datos_a<<info[carrera].c_materia[k]<<". "<<info[carrera].nom_materia[k]<<"\n";
								}
								datos_a<<"---------------\n";
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
				alumnos_creados=true;
			} else if (m==2) {
				system("title Sistema estudiantil: mostrar datos de alumnos");
				if (alumnos_creados==false) {
					cerr<<"\a\nPor favor agregue alumnos para ingresar a esta opción."<<endl;
				} else {
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
				}
			} else if (m==0) {
				return;
			}
		}
	}
}

int main () {
	setlocale(LC_ALL, "spanish");
	system("color f0");
	menu_principal();
	return 0;
}

void menu_principal() {
	int m;
	carrera x = carrera();
	ciclo y = ciclo();
	alumno z = alumno();
	system ("title Sistema estudiantil: menú principal");
	cout<<"\tMenu principal"<<endl;
	cout<<"1. Carrera."<<endl;
	cout<<"2. Ciclos."<<endl;
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
			creditos();
			break;
		case 1:
			x.menu_ca();
			break;
		case 2:
			y.menu_ci();
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

void creditos () {
	cout<<"\nEste proyecto fue realizado el día 30/05/2021 por el grupo #1 de programación I ^u^"<<endl;
	cout<<"Integrantes del grupo:"<<endl;
	cout<<"\t- Jonathán Josué Florián Sipaque 7490-20-3403"<<endl;
	cout<<"\t- Swany Celine Rivera Hernández 7490-20-12172"<<endl;
	cout<<"\t- Pablo Josué López de León 7490-20-24416"<<endl;
	cout<<"\t- Mauricio Rodolfo Mejía Alevon 7490-20-17072"<<endl;
	exit(1);
}
