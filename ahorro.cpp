#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Categoria {
	string nombre;
	double porcentaje;
	double cantidad;
};

void mostrarTabla(const Categoria categorias[], int numCategorias, double ingresoTotal) {
	cout << "\nDistribución del Ingreso Mensual de Emiliano:\n"; //de Emiliano
	cout << "-------------------------------------------\n";
	cout << left << setw(25) << "Categoría" 
		<< setw(15) << "Porcentaje" 
		<< "Cantidad" << endl;
	cout << "-------------------------------------------\n";
	
	for (int i = 0; i < numCategorias; ++i) {
		cout << left << setw(25) << categorias[i].nombre
			<< right << setw(10) << fixed << setprecision(2) << categorias[i].porcentaje << "% "
			<< "$" << fixed << setprecision(2) << categorias[i].cantidad << endl;
	}
	
	cout << "-------------------------------------------\n";
	cout << left << setw(25) << "Total"
		<< right << setw(10) << "100.00% "
		<< "$" << fixed << setprecision(2) << ingresoTotal << endl;
}

int main() {
	double ingresoMensual;
	
	cout << "Aplicación de Presupuesto 50-15-25-10\n";
	cout << "Ingrese su ingreso mensual total: $";
	cin >> ingresoMensual;
	
	const int numCategorias = 4;
	Categoria categorias[numCategorias] = {
		{"Gastos esenciales", 50.00, ingresoMensual * 0.50},
	{"Objetivos financieros", 15.00, ingresoMensual * 0.15},
		{"Gastos discrecionales", 25.00, ingresoMensual * 0.25},
	{"Ahorro", 10.00, ingresoMensual * 0.10}
	};
	
	mostrarTabla(categorias, numCategorias, ingresoMensual);
	
	const double cuotaMadre = 3200.0;
	double saldoDespuesCuota = ingresoMensual - cuotaMadre;
	
	cout << "\nApoyo económico para tu madre:\n";
	cout << "Ingreso total: $" << fixed << setprecision(2) << ingresoMensual << endl;
	cout << "Cuota para madre: $" << fixed << setprecision(2) << cuotaMadre << endl;
	cout << "Saldo después de cuota: $" << fixed << setprecision(2) << saldoDespuesCuota << endl;
	
	if (saldoDespuesCuota < 0) {
		cout << "\n¡Advertencia! El ingreso no cubre la cuota para tu madre.\n";
	}
	
	return 0;
}
