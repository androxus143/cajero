#include <stdio.h>
#include <cstdlib>//libreria para limpiar pantalla
// Variables globales
int A; // Variable que selecciona y define qué usuario ingresa
int C;
int OpcionCajero; // Variable para seleccionar la opción del cajero
int terminarOp; // Variable que determina si el usuario desea realizar otra operación
float MontoInicial1 = 10000.00; // Monto inicial del usuario 1 "Leonardo Mondragon Fernandez"
float MontoInicial2 = 5000.00; // Monto inicial del usuario 2 "Pedro Infante Cruz"
int Retirar; // Cantidad a retirar
float Pagar; // Cantidad a pagar
float Ingresar; // Cantidad a ingresar al saldo inicial
char Usuario11[] = "Leonardo Mondragon Fernandez"; // Nombre del usuario 1
char Usuario22[] = "Pedro Infante Cruz"; // Nombre del usuario 2
int NIPUNO = 1234; // NIP del usuario 1
int NIPDOS = 5678; // NIP del usuario 2
int ChangeUsuario = 0;
int Pay;
int TerminarTODO;
// Generador de números pseudoaleatorios (LCG)
unsigned long semilla = 2; // Semilla inicial

// Función para establecer la semilla
void setSemilla(unsigned long nuevaSemilla) {
	semilla = nuevaSemilla;
}
// Función para generar el siguiente número aleatorio
unsigned long myRand() {
	semilla = (1103515245 * semilla + 12345) % 2147483648;
	return semilla;
}
int NipErroneo=0;
int ExitVali=0;
// Función para validar el NIP del usuario
void validarNIP(int nipEsperado, int A, char Usuario1or2[]) {
	int nipIngresado;
	do {
		printf("\n%s \n", Usuario1or2); // Mostrar nombre del usuario
		printf("Ingrese su NIP: ");
		scanf("%d", &nipIngresado); // Leer el NIP ingresado
		if (nipIngresado != nipEsperado) {// Verificar si el NIP es incorrecto
			system("cls");
			NipErroneo++;
			printf("NIP incorrecto. Intente nuevamente.\n\n");
			printf("%d", NipErroneo);
		}
		if (NipErroneo==3){
			system("cls");
			printf("Ah alcanzado el numero maximo de errores\n");
			printf("Finalizando operaciones\n\n\n");
			ExitVali=1;
		}
	} while (nipIngresado != nipEsperado && ExitVali!=1 ); // Repetir hasta que el NIP sea correcto
	if (ExitVali==1){
		printf("Gracias por usar el cajero automático. Lamentamos los inconvenientes ¡Hasta luego!\n");
		terminarOp=2;
		ChangeUsuario=2;
	}
	if(nipIngresado==nipEsperado){
	if (A == 1) {
		system("cls");
		printf("NIP correcto. Bienvenido, %s\n\n", Usuario11); // Mensaje para el Usuario 1
	} else if (A == 2) {
		system("cls");
		printf("NIP correcto. Bienvenido, %s\n\n", Usuario22); // Mensaje para el Usuario 2
	}
}
}
void DeseaHacer() {
	do{
		printf("----------------------------------------------------------------------------------------\n");
		printf("Desea realizar alguna otra operacion?\n");
		printf("si     (1)\n");
		printf("no     (2)\n");
		printf("----------------------------------------------------------------------------------------\n");
		scanf("%d", &terminarOp);
		if (terminarOp == 2) {
			ChangeUsuario=2;
			printf("\n Gracias por usar el cajero automático. ¡Hasta luego!\n");
		}
		if (terminarOp!=2 && terminarOp!= 1){
			system("cls");
			printf("\n\nOperacion no encontrada\n\n");
		}
	}while(terminarOp!=2 && terminarOp!= 1);
}
void DecoraSimple() {
	printf("\n----------------------------------------------------------------------------------------\n");
}
void DecoraDoble() {
	printf("----------------------------------------------------------------------------------------\n\n\n");
}
int validarLuzPaid1;
int validarLuzPaid2;
int validarAguaPaid1;
int validarAguaPaid2;
int validarInternetPaid1;
int validarInternetPaid2;
char User1y2[30];
int main() {
	setSemilla(123456789); // Semilla inicial fija
	do{//hacer eso mientras terminarOp sea diferente de 2(ciclo que se encargara de cambiar de usuario en caso de que asi se desee)
		if(terminarOp==1){//si en medio de la operacion del codigo el usuario desea cambiar de usuario, se limpiara la pantalla
			system("cls");
		}
		printf("Bienvenido al ''Banco Jorge Nitales'' \n \n");//menu de inicio 
		printf("Seleccione su Usuario \n"); 
		printf("Leonardo Mondragon Fernandez  (1)\n");
		printf("Pedro Infante Cruz            (2)\n \n");
		scanf("%d",&A); 
		if (A != 1 && A != 2) { 
			do {//ciclo que se repetira cuando el primer valor ingresado sea diferente de 1 o 2
				system("cls");//limpiar pantalla 
				printf("Usuario no encontrado, Por favor Intente nuevamente\n\n");//mostrara como usuaio no encontrado 
				printf("Seleccione su Usuario \n"); //se da la opcion nuevamente de seleccionar usuario 
				printf("Leonardo Mondragon Fernandez  (1)\n");
				printf("Pedro Infante Cruz            (2)\n\n");
				scanf("%d", &A);
			} while (A != 1 && A != 2);//ciclo mientras A diferente de 1 o 2
		}
		if (A == 1) {// si A igual a 1 , entonces mediante la funcion validarNIP, validara que el nip ingresado corresponda al del usuario 
			system("cls");//limpiar pantalla
			validarNIP(NIPUNO, A, Usuario11);
		} else if (A == 2) {// si A igual a 2 , entonces mediante la funcion validarNIP, validara que el nip ingresado corresponda al del usuario 
			system("cls");//Limpiar pantalla
			validarNIP(NIPDOS, A, Usuario22);
		} 
if (ExitVali!=1){
		do {
			if(terminarOp==1){
				system("cls");
			}
			DecoraSimple();//decoracion
			printf("Que desea hacer?:\n\n");//menu de opciones del cajero 
			printf("Consultar Saldo   (1)\n");
			printf("Retirar Efectivo  (2)\n");
			printf("Pagar             (3)\n");
			printf("Ingresar saldo    (4)\n");
			printf("Cambiar Usuario   (5)\n");
			printf("Salir             (6)\n");
			DecoraDoble();//decoracion 
			scanf("%d", &OpcionCajero);//scan que leera la opcion seleccionada por el usuario 
			switch (OpcionCajero) {//switch que dependiendo de la opcion seleccionada por el usuario realizara la accion 
			case 1:// si OpcionCajero=1 mostrara el saldo actual del usuario 1
				if (A == 1) {//si A=1 
					system("cls");//limpiar pantalla 
					DecoraSimple();//decoracion
					printf("-%s", Usuario11);//impimira en pantalla el nombre del usuario 1
					printf("\n Su saldo total es de: %.2f\n", MontoInicial1);//se imprimira en pantalla el saldo actual del usuario 1
					DecoraDoble();//decoracion
				} else if (A == 2) {
					system("cls");
					DecoraSimple();
					printf("-%s", Usuario22);
					printf("\n Su saldo total es de: %.2f\n", MontoInicial2);
					DecoraDoble();
				}
				DeseaHacer();
				break;
			case 2://Retirar saldo 
				system("cls");//limpia la pantalla 
				DecoraSimple();
				printf("\nIngrese el monto que desea retirar: ");//se muestra el mensaje en pantalla 
				scanf("%d", &Retirar);// el usuario ingresa el monto a retirar de su saldo 
				DecoraDoble();
				if (A == 1) {//si el usuario uno es el que esta realizando la operacion 
					system("cls");
					if (Retirar > MontoInicial1) {//operacion que verificara si el saldo es menor o igual a la cantidad a retirar
						DecoraSimple();
						printf("Fondos insuficientes.\n");// en caso de que el retirar sea mayor al saldo mostrara el texto en pantalla 
						DecoraDoble();
					} else {// en caso de que no se cumpla la condicion la operacion seguira 
						system("cls");
						MontoInicial1 -= Retirar;//indica que se le asginara al saldo del usuario 1 el resultado de la resta de saldo menos la cantidad a retirar 
						DecoraSimple();
						printf("-%s", Usuario11);
						//ticket de la operacion 
						printf("\n Retiro exitoso, ha retirado: %d\n", Retirar);//texto mostrado en pantalla
						printf("\n Su nuevo saldo es: %.2f\n", MontoInicial1);//texto montado en pantalla
						DecoraDoble();
					}
				} else if (A == 2) {// caso del usuario dos 
					system("cls");
					if (Retirar > MontoInicial2) {//operacion que verificara si el saldo es menor o igual a la cantidad a retirar
						DecoraSimple();
						printf("Fondos insuficientes.\n");// en caso de que el retirar sea mayor al saldo mostrara el texto en pantalla 
						DecoraDoble();
					} else {//en caso de que la condicion no se cumpla 
						system("cls");//limpiar pantalla
						MontoInicial2 -= Retirar;//indica que se le asginara al saldo del usuario 2 el resultado de la resta de saldo menos la cantidad a retirar 
						DecoraSimple();
						printf("-%s", Usuario22);
						//ticket de operacion exitosa
						printf("\n Retiro exitoso, ha retirado: %d\n", Retirar);//se mostrara en pantalla
						printf("Su nuevo saldo es: %.2f\n", MontoInicial2);//se mostrar en pantalla
						DecoraDoble();
					}
				}
				DeseaHacer();
				break;
			case 3: // Pagar
			{
				//generador de numeros random para el pago de los servicios
				unsigned long randLuz = myRand();
				unsigned long randAgua = myRand();
				unsigned long randInternet = myRand();
				float costoLuz = 100 + (randLuz % 601);
				float costoAgua = 100 + (randAgua % 601);
				float costoInternet = 100 + (randInternet % 601);
				if (A==1 and validarLuzPaid1==1){//validacion si el usuario 1 ya pago la luz 
					costoLuz=0;
				}
				if (A==2 and validarLuzPaid2==1){//validara si el usuario 2 ya pago la luz 
					costoLuz=0;
				}
				if (A==1 and validarAguaPaid1==1){//validacion si el usuario 1 ya pago el agua 
					costoAgua=0;
				}
				if (A==2 and validarAguaPaid2==1){//validacion si el usuario2  ya pago el agua 
					costoAgua=0;
				}
				if (A==1 and validarInternetPaid1==1){//validacion si el usuario 1 ya pago el internet
					costoInternet=0;
				}
				if (A==2 and validarInternetPaid2==1){//validacion si el usuario 2 ya pago el internet 
					costoInternet=0;
				}
				system("cls");//limpiar pantalla
				//muestra el menu en pantalla de opciones de pagar 
				DecoraSimple();
				printf("Que desea pagar?\n");
				printf("Luz      (1) - Costo: %.2f\n", costoLuz);
				printf("Agua     (2) - Costo: %.2f\n", costoAgua);
				printf("Internet (3) - Costo: %.2f\n", costoInternet);
				printf("otros    (4\n");
				printf("Salir    (5)\n");
				DecoraDoble();
				scanf("%d", &C);//se lee la entrada del usuario 
				if (A==1 and validarLuzPaid1==1 and C==1){//validacion si el usuario 1 ya pago la luz
					system("cls");//limpia la pantalla
					DecoraSimple();
					printf("Servicio pagado\n");//se muestra en pantalla 
					DecoraDoble();
					C=6;//asigna el valor de 6 para que se muestre el menu de si desea realizar alguna otra operacion 
				}
				if (A==2 and validarLuzPaid2==1 and C==1){// validacion si el usuario 2 ya pago la luz 
					system("cls");//se limpia el texto en pantalla 
					DecoraSimple();
					printf("Servicio pagado\n");//se muestra en pantalla 
					DecoraDoble();
					C=6;//asigna el valor de 6 para que se muestre el menu de si desea realizar alguna otra operacion 
				}
				if (A==1 and validarAguaPaid1==1 and C==2){
					system("cls");
					DecoraSimple();
					printf("Servicio pagado\n");//texto que se muestra en pantalla
					DecoraDoble();
					C=6;//asigna el valor de 6 para que se muestre el menu de si desea realizar alguna otra operacion 
				}
				if (A==2 and validarAguaPaid2==1 and C==2){//valida si el usuario ya ah pagado el agua 
					system("cls");//se limpia la pantalla
					DecoraSimple();
					printf("Servicio pagado\n");//texto que se muestra en pantalla
					DecoraDoble();
					C=6;//asigna el valor de 6 para que se muestre el menu de si desea realizar alguna otra operacion 
				}
				if (A==1 and validarInternetPaid1==1 and C==3){
					system("cls");//se limpia la pantalla
					DecoraSimple();
					printf("Servicio pagado\n");//texto que se muestra en pantalla
					DecoraDoble();
					C=6;//asigna el valor de 6 para que se muestre el menu de si desea realizar alguna otra operacion 
				}
				if (A==2 and validarInternetPaid2==1 and C==3){
					system("cls");//se limpia la pantalla
					DecoraSimple();
					printf("Servicio pagado\n");//texto que se muestra en pantalla
					DecoraDoble();
					C=6;//asigna el valor de 6 para que se muestre el menu de si desea realizar alguna otra operacion 
				}
				//switch segun el valor de C 
				switch (C){
				case 1:// en caso de que C=1
					system("cls");//se limpia la pantalla
					DecoraSimple();
					printf("El costo es:%.2f\n", costoLuz);//se le muestra en pantalla el costo de servicio (luz)
					printf("Pagar servicios?\n");//se le pregunta al usuario si desea pagar el servicio
					printf("si     (1)\n");
					printf("no     (2)\n");
					DecoraDoble();
					scanf("%d",&Pay);
					if (Pay==1){
						Pagar=costoLuz;
					}
					if(Pay==2){
						system("cls");
						DecoraSimple();
						printf("Vuelva pronto\n");
						DecoraDoble();
						DeseaHacer();
					}
					if(Pay==1){
						if (Pagar > 0) {
							if (A == 1) {
								if (Pagar > MontoInicial1) {
									system("cls");
									DecoraSimple();
									printf("Fondos insuficientes para realizar el pago.\n");
									DecoraDoble();
								} else {
									system("cls");
									validarLuzPaid1=1;
									MontoInicial1 -= Pagar;
									DecoraSimple();
									printf("Pago realizado con éxito. Su nuevo saldo es: %.2f\n", MontoInicial1);
									DecoraDoble();
								}
							} else if (A == 2) {
								if (Pagar > MontoInicial2) {
									system("cls");
									DecoraSimple();
									printf("Fondos insuficientes para realizar el pago.\n");
									DecoraDoble();
								} else {
									system("cls");
									validarLuzPaid2=1;
									MontoInicial2 -= Pagar;
									DecoraSimple();
									printf("Pago realizado con éxito. Su nuevo saldo es: %.2f\n", MontoInicial2);
									DecoraDoble();
								}
							}
						}
					}
					if(Pay!=1 && Pay!=2){
						printf("Operacion No Encontrada\n");
						printf("Regresando al menu de operaciones....\n");
						printf("(pulse 1 )");
						printf("para continuar\n\n");
						scanf("%d",&terminarOp);
					}
					if(Pay==1){
						DeseaHacer();
					}
					break;
				case 2://en caso de que C=2 
					system("cls");//se limpia en pantalla
					DecoraSimple();
					printf("El costo es:%.2f\n", costoAgua);//se le muestra en pantalla el costo de servicio (agua)
					printf("Pagar servicios?\n");//se le pregunta al usuario si desea pagar el servicio
					printf("si     (1)\n");
					printf("no     (2)\n");
					DecoraDoble();
					scanf("%d", &Pay);
					if (Pay==1){
						Pagar=costoAgua;
					} if(Pay==2){
						system("cls");
						DecoraSimple();
						printf("Vuelva pronto\n");
						DecoraDoble();
						DeseaHacer();
					}
					if(Pay==1){
						if (Pagar > 0) {
							if (A == 1) {
								if (Pagar > MontoInicial1) {
									system("cls");
									DecoraSimple();
									printf("Fondos insuficientes para realizar el pago.\n");
									DecoraDoble();
								} else {
									system("cls");
									validarAguaPaid1=1;
									MontoInicial1 -= Pagar;
									DecoraSimple();
									printf("Pago realizado con éxito. Su nuevo saldo es: %.2f\n", MontoInicial1);
									DecoraDoble();
								}
							} else if (A == 2) {
								if (Pagar > MontoInicial2) {
									system("cls");
									DecoraSimple();
									printf("Fondos insuficientes para realizar el pago.\n");
									DecoraDoble();
								} else {
									system("cls");
									validarAguaPaid2=1;
									MontoInicial2 -= Pagar;
									DecoraSimple();
									printf("Pago realizado con éxito. Su nuevo saldo es: %.2f\n", MontoInicial2);
									DecoraDoble();
								}
							}
						}
					}
					if(Pay!=1 && Pay!=2){
						printf("Operacion No Encontrada\n");
						printf("Regresando al menu de operaciones....\n");
						printf("(pulse 1 )");
						printf("para continuar\n\n");
						scanf("%d",&terminarOp);
					}
					if(Pay==1){
						DeseaHacer();
					}
					break;
				case 3://en caso de que C=3
					system("cls");
					DecoraSimple();
					printf("El costo es:%.2f\n", costoInternet);//se le muestra en pantalla el costo de servicio (internet)
					printf("Pagar servicios?\n");//se le pregunta al usuario si desea pagar el servicio
					printf("si     (1)\n");
					printf("no     (2)\n");
					DecoraDoble();
					scanf("%d", &Pay);
					if (Pay==1){
						Pagar=costoInternet;//se le asigna a la variable pagar el costo del intenet 
					} if(Pay==2){//si el usuario ingreso el numero 2 se cancela la operacion
						DecoraSimple();//decoraciones en pantalla
						printf("Vuelva pronto\n");//texto que se muestra en pantalla 
						DecoraDoble();//decoraciones en pantalla 
						DeseaHacer();//menu de opciones si desea realizar alguna otra operacion 
					}
					if(Pay==1){
						if (Pagar > 0) {//variable que verificar que pagar sea mayor a cero y que el servicio no haya sido pagado 
							if (A == 1) {//acciones a realizar en el menu del usuaio 1
								if (Pagar > MontoInicial1) {//si pagar es mayor al saldo del usuario entonces:
									system("cls");//limpia pantalla 
									DecoraSimple();
									printf("Fondos insuficientes para realizar el pago.\n");//muestra que no hay saldo suficiente y que no se puede realizar la operacion 
									DecoraDoble();
								} else {//si la condicion no se cumple entonces:
									system("cls");//limpia pantalla 
									validarInternetPaid1=1;
									MontoInicial1 -= Pagar;
									DecoraSimple();
									printf("Pago realizado con éxito. Su nuevo saldo es: %.2f\n", MontoInicial1);
									DecoraDoble();
								}
							} else if (A == 2) {
								if (Pagar > MontoInicial2) {
									system("cls");
									DecoraSimple();
									printf("Fondos insuficientes para realizar el pago.\n");
									DecoraDoble();
								} else {
									system("cls");
									validarInternetPaid2=1;
									MontoInicial2 -= Pagar;
									DecoraSimple();
									printf("Pago realizado con éxito. Su nuevo saldo es: %.2f\n", MontoInicial2);
									DecoraDoble();
								}
							}
						}
					}
					if(Pay!=1 && Pay!=2){
						printf("Operacion No Encontrada\n");
						printf("Regresando al menu de operaciones....\n");
						printf("(pulse 1 )");
						printf("para continuar\n\n");
						scanf("%d",&terminarOp);
					}
					if(Pay==1){
						DeseaHacer();
					}
					break;
				case 5:
					
					break;
				case 6:
					DeseaHacer();
					break;
				default:
					if (C!=1 && C!= 2 && C!=3 && C!=4 && C!=5 && C!=6){
						printf("Opción no válida. Cancelando operación.\n");
						printf("(pulse 1 )");
						printf("para continuar\n\n");
						scanf("%d",&terminarOp);
					}
					break;
				}
				break;
			}
			
			case 4: // Ingresar Saldo
				system("cls");
				printf("\nIngrese el monto que desea ingresar: ");
				scanf("%f", &Ingresar); // Leer la cantidad que desea ingresar
				if (A == 1) {
					MontoInicial1 += Ingresar;
					DecoraSimple();
					system("cls");
					printf("-%s", Usuario11);
					printf("\nDepósito exitoso.\n");
					printf("Su nuevo saldo es: %.2f\n", MontoInicial1);
					DecoraDoble();
				} else if (A == 2) {
					MontoInicial2 += Ingresar;
					DecoraSimple();
					system("cls");
					printf("-%s", Usuario22);
					printf("\nDepósito exitoso.\n");
					printf("Su nuevo saldo es: %.2f\n", MontoInicial2);
					DecoraDoble();
				}
				DeseaHacer();
				break;
			case 5: // Salir
				system("cls");
				printf("Cambiando de Usuario....\n");
				printf("Espere Un momento\n");
				printf("(pulse 1 )");
				printf("\npara continuar\n\n");
				scanf("%d",&ChangeUsuario);
				if(ChangeUsuario==1){
					terminarOp=2;
				}
				break;
			case 6:
				system("cls");
				printf("Gracias por usar el cajero automático. ¡Hasta luego!\n");
				terminarOp=2;
				ChangeUsuario=2;
				break;
			default: // Opción no válida
				printf("Opción no válida. Por favor, intente nuevamente.\n");
				printf("(pulse 1 )");
				printf("para continuar\n\n");
				scanf("%d",&terminarOp);
			}
		} while (OpcionCajero != 6 && terminarOp != 2); // El ciclo se detendrá cuando el usuario elija salir (opción 5)
	}
	} while(ChangeUsuario!=2 && TerminarTODO!=1);
	return 0;
}
