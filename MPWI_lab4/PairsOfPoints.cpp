#include "PairsOfPoints.h"

PairsOfPoints::PairsOfPoints()
{
	srand(time(NULL));
	initTabs();

	table_of_probability[0][0] = 0;
	table_of_probability[0][1] = 0;
	table_of_probability[0][2] = 0.1;
	table_of_probability[0][3] = 0.1;

	table_of_probability[1][0] = 0.2;
	table_of_probability[1][1] = 0;
	table_of_probability[1][2] = 0;
	table_of_probability[1][3] = 0.2;

	table_of_probability[2][0] = 0;
	table_of_probability[2][1] = 0;
	table_of_probability[2][2] = 0.3;
	table_of_probability[2][3] = 0;

	table_of_probability[3][0] = 0;
	table_of_probability[3][1] = 0.05;
	table_of_probability[3][2] = 0;
	table_of_probability[3][3] = 0.05;

}

PairsOfPoints::PairsOfPoints(int _size)
{
	srand(time(NULL));
	size = _size;
	initTabs();
	fillTab();
}

void PairsOfPoints::generate() {
	x = rand()%size; 
	y = DEFAULT_VALUE;
	double sum_of_probs_in_line = sumInLine(x,table_of_probability);

	for (int i = 0; i < size; i++) {
		double a = (rand() % 100);
		a /= 100; // now the range of variable A is 0.0-1.0, the same as probability
		if (a < (table_of_probability[x][i]*table_of_probability[x][i] / sum_of_probs_in_line)) {
			y = i;
			break;
		}
	}

	density_matrix[x][y]++;
}

double PairsOfPoints::sumInLine(int line,double **tab) {

	double sum = 0.0;
	for (int i = 0; i < this->size; i++) {
		sum += tab[line][i];
	}
	return sum;
}

void PairsOfPoints::fillTab() {
	double sum = 0.0;
	double temp;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			cout << "Current sum: " << sum << endl;
			cout << "Enter the value of cell (" << i << "," << j << ") :";
			cin >> temp;
			if (sum + temp > 1.0) { // probability cannot be greater than 1
				cout << "Wrong data!" << endl;
				system("pause");
				exit(-1);
			}
			table_of_probability[i][j] = temp;
			sum += temp;
		}
	}

}

void PairsOfPoints::printTabs() {
	cout << "Table of matrix densities" << endl;
	cout << "xy";
	for (int i = 0; i < this->size; i++) {
		cout << "\t" << i;
	}
	cout << endl;
	for (int i = 0; i < this->size; i++) {
		cout << i<<"\t";
		for (int j = 0; j < this->size; j++) {
			cout << (int)density_matrix[i][j]<<"\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Table of probability" << endl;
	cout << "xy";
	for (int i = 0; i < this->size; i++) {
		cout << "\t" << i;
	}
	cout << endl;

	for (int i = 0; i < this->size; i++) {
		double sum_of_probability = sumInLine(i,table_of_probability);
		double sum_of_density = sumInLine(i, density_matrix);
		cout << i << "\t";
		for (int j = 0; j < this->size; j++) {
			cout <<setprecision(2)<< density_matrix[i][j]/sum_of_density*sum_of_probability<<"\t";
		}
		cout << endl;
	}
}

void PairsOfPoints::initTabs() {
	density_matrix = new double*[size];
	table_of_probability = new double*[size];
	for (int i = 0; i < this->size; i++) {
		table_of_probability[i] = new double[size];
		density_matrix[i] = new double[size];
		for (int j = 0; j < this->size; j++) {
			density_matrix[i][j] = 0;
		}
	}
}

PairsOfPoints::~PairsOfPoints()
{
	for (int i = 0; i < this->size; i++) {
		delete[] table_of_probability[i];
		delete[] density_matrix[i];
	}
	delete[] table_of_probability;
	delete[] density_matrix;
}
