#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

// --- CASO 1: Aventura en la Mazmorra ---
void caso1_mazmorra() {
    cout << "\nCASO 1: Ingrese la secuencia de trampas: ";
    string secuencia;
    cin >> secuencia;

    stack<char> trampas;
    int puntaje = 0;

    for (char c : secuencia) {
        if (c == '(' || c == '[' || c == '{') {
            trampas.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (!trampas.empty()) {
                char ultima_trampa = trampas.top();
                if (c == ')' && ultima_trampa == '(') {
                    puntaje += 1;
                    trampas.pop();
                }
                else if (c == ']' && ultima_trampa == '[') {
                    puntaje += 2;
                    trampas.pop();
                }
                else if (c == '}' && ultima_trampa == '{') {
                    puntaje += 3;
                    trampas.pop();
                }
            }
        }
    }
    cout << "=> Puntaje total: " << puntaje << "\n\n";
}

// --- CASO 2: Número Repetido ---
void caso2_repetido() {
    cout << "\nCASO 2: Ingrese la cantidad N de elementos: ";
    int n;
    cin >> n;

    cout << "Ingrese los " << n << " numeros separados por espacio: ";
    unordered_set<int> vistos;
    int numero;
    int primer_repetido = -1;
    bool encontrado = false;

    for (int i = 0; i < n; ++i) {
        cin >> numero;
        if (!encontrado) {
            if (vistos.find(numero) != vistos.end()) {
                primer_repetido = numero;
                encontrado = true;
            }
            else {
                vistos.insert(numero);
            }
        }
    }
    cout << "=> Primer numero repetido: " << primer_repetido << "\n\n";
}

// --- CASO 3: Pokémons ---
void caso3_pokemons() {
    cout << "\nCASO 3: Ingrese la cantidad de pokemons capturados: ";
    int n;
    cin >> n;

    cout << "Ingrese los nombres de los pokemons:\n";
    unordered_set<string> pokedex;
    string nombre_pokemon;

    for (int i = 0; i < n; ++i) {
        cin >> nombre_pokemon;
        pokedex.insert(nombre_pokemon);
    }

    int faltantes = 151 - pokedex.size();
    cout << "=> Falta(n) " << faltantes << " pokemon(s).\n\n";
}

int main() {
    int opcion;

    do {
        cout << "MENU\n";
        cout << "1) Aventura en la Mazmorra (Pilas)\n";
        cout << "2) Numero Repetido (Hash Set)\n";
        cout << "3) POKEMONS! (Hash Set)\n";
        cout << "0) Salir\n";
        cout << "Seleccione problema (0-3): ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            caso1_mazmorra();
            break;
        case 2:
            caso2_repetido();
            break;
        case 3:
            caso3_pokemons();
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n\n";
        }
    } while (opcion != 0);

    return 0;
}