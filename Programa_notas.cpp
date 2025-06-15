#include <iostream> 
#include <iomanip>
#include <vector> // Es para vectores
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h> // Para manejo de colores en consola Windows
#endif
using namespace std;

struct Alumno {
    string nombre;
    string apellido1;
    string apellido2;
    int cedula;
    int ciclo;
    float notas[5];
    float promedio;
};

float calcularPromedio(const float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}

int main() {
    int cantidad;
    cout << "¿Cuántos alumnos desea evaluar?: ";
    cin >> cantidad;
    cin.ignore(); // Para usar getline sin errores

    vector<Alumno> alumnos;

    for (int i = 0; i < cantidad; i++) {
        Alumno a;
        cout << "\n--- Alumno #" << (i + 1) << " ---" << endl;

        cout << "Nombre: ";
        getline(cin, a.nombre);

        cout << "Primer apellido: ";
        getline(cin, a.apellido1);

        cout << "Segundo apellido: ";
        getline(cin, a.apellido2);

        cout << "Cédula: ";
        cin >> a.cedula;

        cout << "Ciclo que cursa: ";
        cin >> a.ciclo;

        for (int j = 0; j < 5; j++) {
            cout << "Ingrese nota #" << (j + 1) << ": ";
            cin >> a.notas[j];
        }

        a.promedio = calcularPromedio(a.notas, 5);
        cin.ignore(); // Limpiar buffer para el siguiente getline
        alumnos.push_back(a);
    }

    // Mostrar todos los alumnos con promedio
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

    // Mostrar sólo los aprobados (promedio >= 70) en color verde
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int COLOR_VERDE = 10; // Verde claro
#endif

    cout << "\n======= LISTA DE APROBADOS (PROMEDIO >= 70) =======\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(12) << "Cédula"
         << setw(8)  << "Ciclo"
         << "Promedio" << endl;

    cout << "-------------------------------------------------------------\n";

    for (const Alumno& a : alumnos) {
        if (a.promedio >= 70) {
            string nombreCompleto = a.nombre + " " + a.apellido1 + " " + a.apellido2;
#ifdef _WIN32
            SetConsoleTextAttribute(hConsole, COLOR_VERDE);
#endif
            cout << left << setw(30) << nombreCompleto
                 << setw(12) << a.cedula
                 << setw(8)  << a.ciclo
                 << fixed << setprecision(2) << a.promedio << endl;
#ifdef _WIN32
            SetConsoleTextAttribute(hConsole, 7); // Volver al color normal (blanco)
#endif
        }
    }

    return 0;
}
