#pragma once

#ifndef HEADER_HPP
#define HEADER_HPP

#include<iostream>
#include <Windows.h> 

using namespace Matrix; // Название проекта 

int rowCountA{ 0 }, columnCountA{ 0 }, rowCountB{ 0 }, columnCountB{ 0 }, rowCountC{ 0 }, columnCountC{ 0 };
double** A;
double** B;
double** C;

void AddColumnRow(System::Windows::Forms::DataGridView^, int*, int*);

void CreateArray(System::Windows::Forms::DataGridView^, double**, int, int);

void DeleteColumnRow(System::Windows::Forms::DataGridView^);

void DeleteArray(double**, int, int);

void Summa(double**, double**, double**, int, int);

void Difference(double**, double**, double**, int, int);

void PrintMatrix(System::Windows::Forms::DataGridView^, double**, int, int);

void NumberMultiply(double**, double**, int, int, double*);

void NumberDevide(double**, double**, int, int, double*, bool*);

bool CheckTextBox(System::Windows::Forms::TextBox^, double*);

bool CheckTextBox(System::Windows::Forms::TextBox^, int*);

#endif
