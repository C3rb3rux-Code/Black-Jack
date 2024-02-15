#include <iostream>
#include<stdlib.h>
#include <cstdlib>

using namespace std;

int decisionPalo;

int seguirJugando;

int decisionCarta;

string arrayPalos[] = { "Picas", "Treboles", "Diamantes", "Corazones"};

int arrayCartas[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

int cartasTotalJugador;

int cartasJugador[10];

int cartasBanca;

int cartasRepartidasBanca;

int totalCartasBanca[10];

int valorAS;

int respuestaCarta;

int indice = 0;

int i = 0;

bool juegoAcaba = false;
bool juego = false;
bool cartaRepartida = false;

void valorASfuncion() {
	cout << "Con que valor del AS quieres jugar? (11 o 1)\n";
	cout << "[1] Jugar con AS de 11\n";
	cout << "[2] Jugar con AS de 1\n";
	cin >> valorAS;
}

void repartirCartas() 
{
	decisionPalo = rand() % (5 - 1);
	arrayPalos[decisionPalo];
	decisionCarta = rand() % (12 - 1);
	arrayCartas[decisionCarta];
	cartasTotalJugador += decisionCarta;
}

int main()
{
	int listoJugar;
	cout << "Bienvenido jugador\n";
	cout << "Estás listo para empezar la partida de BlackJack?\n";
	cout << "[1] Si\n";
	cout << "[2] No\n";

	while (!juego)
	{
		cin >> listoJugar;
		
		switch (listoJugar)
		{
		case 1:
			cout << "El croupier empieza a repartir las cartas...\n";
			valorASfuncion();
			while (i < 2)
			{
				if (valorAS == 1)
				{
					repartirCartas();
					cout << "Recibes la carta " << arrayCartas[decisionCarta] << " " << arrayPalos[decisionPalo] << "\n";
				}
				else if (valorAS == 2)
				{
					repartirCartas();
					cout << "Recibes la carta " << arrayCartas[decisionCarta] << " " << arrayPalos[decisionPalo] << "\n";
				}
				else
				{
					cout << "Error...\n";
					exit(0);
				}
				i++;
			}

			cout << "Total: " << cartasTotalJugador << "\n";

			int recibirOtraCarta;
			cout << "Quieres recibir otra carta?\n";
			cout << "[1] Si\n";
			cout << "[2] No\n";
			cin >> recibirOtraCarta;
			if (recibirOtraCarta == 1)
			{
				repartirCartas();
				cout << "Recibes la carta " << arrayCartas[decisionCarta] << " de " << arrayPalos[decisionPalo] << "\n"; 
				i++;
			}

			if (cartasTotalJugador > 21)
			{
				cout << "Has perdido, tu numero total de cartas supera el 21\n";
			}
			
			cout << "Es el turno del croupier\n";

			i = 0;

			while (cartasBanca <= cartasTotalJugador)
			{
				repartirCartas();
				cout << "El croupier recibe la carta " << arrayCartas[decisionCarta] << " de " << arrayPalos[decisionPalo] << "\n";
				i++;
			}

			if (cartasBanca >= cartasTotalJugador && cartasBanca <= 21)
			{
				cout << "El croupier gana!!!\n";
			}
			else if (cartasTotalJugador > cartasBanca && cartasTotalJugador <= 21) 
			{
				cout << "Has ganado!!! Felicidades...\n";
			}

			cout << "Quieres jugar otra partida?\n";
			cout << "[1] Si\n";
			cout << "[2] No\n";
			cin >> seguirJugando;

			switch (seguirJugando)
			{
			case 1:
				#ifdef _WIN32;

				system("cls");

				#endif
				break;
			case 2:
				cout << "Gracias por jugar\n";
				juego = true;
				break;
			default:
				break;
			}
						
		default:
			exit(0);
			break;
		}

	}
}