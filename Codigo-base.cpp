#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Estructura para guardar datos del alumno
struct Alumno {
    string nombre;
    string apellido1;
    string apellido2;
    int cedula;
    int ciclo;
    float notas[5];
    float promedio;
};

// Funcion para calcular el promedio de 5 notas
float calcularPromedio(const float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}

// Función para validar texto (nombre/apellidos)
bool validarTexto(const string& texto) {
    if (texto.empty()) return false;
    for (char c : texto) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

//  Función para leer enteros positivos (como cantidad, cédula, ciclo)
bool leerEnteroPositivo(int &valor) {
    cin >> valor;
    if (cin.fail() || valor <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool validarCedula(int cedula) {
    string cedulaStr = to_string(cedula);
    return cedula > 0 && cedulaStr.length() >= 9 && cedulaStr.length() <= 12;
}


int main() {
    int cantidad;

    cout << "¿Cuántos alumnos desea evaluar?: ";
    while (!leerEnteroPositivo(cantidad)) {
        cout << "⚠️  Error: Ingrese un número entero positivo: ";
    }

    // Limpiar el salto de línea pendiente
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Alumno> alumnos;

    for (int i = 0; i < cantidad; i++) {
        Alumno a;
        cout << "\n--- Alumno #" << (i + 1) << " ---" << endl;

        // Nombre
        do {
            cout << "Nombre: ";
            getline(cin, a.nombre);
            if (!validarTexto(a.nombre)) {
                cout << "Error: El nombre solo debe contener letras. Intente de nuevo.\n";
            }
        } while (!validarTexto(a.nombre));

        // Primer apellido
        do {
            cout << "Primer apellido: ";
            getline(cin, a.apellido1);
            if (!validarTexto(a.apellido1)) {
                cout << "Error: El apellido solo debe contener letras. Intente de nuevo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validarTexto(a.apellido1));

        // Segundo apellido
        do {
            cout << "Segundo apellido: ";
            getline(cin, a.apellido2);
            if (!validarTexto(a.apellido2)) {
                cout << "Error: El apellido solo debe contener letras. Intente de nuevo.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validarTexto(a.apellido2));

        // Cedula
        do {
    cout << "Cédula: ";
    if (leerEnteroPositivo(a.cedula) && validarCedula(a.cedula)) break;
    cout << "Error: La cédula debe tener entre 9 y 12 dígitos numéricos. Intente de nuevo.\n";
} while (true);

        // Codigo para Ciclo
do {
    cout << "Ciclo que cursa (1 al 3): ";
    if (leerEnteroPositivo(a.ciclo) && a.ciclo >= 1 && a.ciclo <= 3) break;
    cout << "Error: El ciclo debe estar entre 1 y 3.\n";
} while (true);

        // Notas
        for (int j = 0; j < 5; j++) {
            cout << "Ingrese nota #" << (j + 1) << ": ";
            while (!(cin >> a.notas[j]) || a.notas[j] < 0 || a.notas[j] > 100) {
                cout << "Error: La nota debe estar entre 0 y 100. Intente de nuevo: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        a.promedio = calcularPromedio(a.notas, 5);
        cin.ignore(); // limpiar el buffer antes de siguiente getline
        alumnos.push_back(a);
    }

    // Mostrar resultados
    cout << "\n======= LISTA DE ALUMNOS CON PROMEDIO =======\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(12) << "Cédula"
         << setw(8)  << "Ciclo"
         << "Promedio" << endl;

    cout << "-------------------------------------------------------------\n";


    for (const Alumno& a : alumnos) {
        string nombreCompleto = a.nombre + " " + a.apellido1 + " " + a.apellido2;
        cout << left << setw(30) << nombreCompleto
             << setw(12) << a.cedula
             << setw(8)  << a.ciclo
             << fixed << setprecision(2) << a.promedio << endl;
    }

// Clasificar y mostrar aprobados y reprobados
vector<Alumno> aprobados, reprobados;

for (const Alumno& a : alumnos) {
    if (a.promedio >= 70.0)
        aprobados.push_back(a);
    else
        reprobados.push_back(a);
}

cout << "\n======= ALUMNOS APROBADOS =======\n";
for (const Alumno& a : aprobados) {
    string nombreCompleto = a.nombre + " " + a.apellido1 + " " + a.apellido2;
    cout << left << setw(30) << nombreCompleto
         << setw(12) << a.cedula
         << setw(8)  << a.ciclo
         << fixed << setprecision(2) << a.promedio << endl;
}

cout << "\n======= ALUMNOS REPROBADOS =======\n";
for (const Alumno& a : reprobados) {
    string nombreCompleto = a.nombre + " " + a.apellido1 + " " + a.apellido2;
    cout << left << setw(30) << nombreCompleto
         << setw(12) << a.cedula
         << setw(8)  << a.ciclo
         << fixed << setprecision(2) << a.promedio << endl;
}


    return 0;
}