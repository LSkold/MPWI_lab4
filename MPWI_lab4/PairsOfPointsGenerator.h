#pragma once
#include"Consts.h"
#include<iostream>
#include <stdlib.h>
#include <iomanip> 
#include <time.h>
using namespace std;

class PairsOfPointsGenerator
{
private:
	int x = DEFAULT_VALUE;
	int y = DEFAULT_VALUE;
	int size = DEFAULT_SIZE;
	double **table_of_probability;
	double **density_matrix;
	
	//
	// adding every element of TAB in LINE
	//
	double sumInLine(int line,double **tab);

	//
	// alocating memory for tabs
	//
	void initTabs();

	//
	// filing TABLE_OF_PROBABILITY 
	//
	void fillTab();

public:
	
	PairsOfPointsGenerator();
	PairsOfPointsGenerator(int _size);

	//
	// main function of generation
	//
	void generate();

	//
	// printing TABLE_OF_PROBABILITY and DENSITY_MATRIX
	//
	void printTabs();

	~PairsOfPointsGenerator();
};

