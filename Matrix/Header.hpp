#pragma once

#ifndef HEADER_HPP
#define HEADER_HPP

#include<iostream>
#include <Windows.h> 

using namespace Matrix; // �������� ������� 

extern int rowCountA, columnCountA, rowCountB, columnCountB, rowCountC, columnCountC;
extern bool isArrayExistA, isArrayExistB, isArrayExistC;
extern double** A;
extern double** B;
extern double** C;

void AddColumnRow(System::Windows::Forms::DataGridView^, int*, int*);

void CreateArray(System::Windows::Forms::DataGridView^, double**, int, int, bool*);

void DeleteColumnRow(System::Windows::Forms::DataGridView^);

void DeleteArray(double**, int, int, bool);

void Summa(double**, double**, double**, int, int);

void Difference(double**, double**, double**, int, int);

void PrintMatrix(System::Windows::Forms::DataGridView^, double**, int, int);

void NumberMultiply(double**, double**, int, int, double*);

void NumberDevide(double**, double**, int, int, double*, bool*);

bool CheckTextBox(System::Windows::Forms::TextBox^, double*);

bool CheckTextBox(System::Windows::Forms::TextBox^, int*);

void MatrixMultiply(double**, double**, double**, int, int, int, int);

void ToStepMatrix(double**, double**, int, int);

void DiagonalNotNull(double**, int, int, int);

double DeterminantCalc(double**, int);

void InverseMatrixCalc(double**, double**, int);

int RangCalc(double**, int, int);

void TranspositionCalc(double**, double**, int, int);

#endif
