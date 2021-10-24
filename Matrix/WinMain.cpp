#include "MyForm.h" 

using namespace Matrix; // Название проекта 

int rowCountA{ 0 }, columnCountA{ 0 }, rowCountB{ 0 }, columnCountB{ 0 }, rowCountC{ 0 }, columnCountC{ 0 };
double** A;
double** B;
double** C;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

//Вставка указанного количества столбцов и строк в матрицу A
System::Void Matrix::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView1);
	AddColumnRow(dataGridView1, textBox1, textBox2, &rowCountA, &columnCountA);
}

//Вставка указанного количества столбцов и строк в матрицу B
System::Void Matrix::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView2);
	AddColumnRow(dataGridView2, textBox3, textBox4, &rowCountB, &columnCountB);
}

//Записать данные в массив A[][]
System::Void Matrix::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	A = new double* [rowCountA];
	if (rowCountA > 0 && columnCountA > 0) {
		CreateArray(dataGridView1, A, rowCountA, columnCountA);
	}
}

//Записать данные в массив B[][]
System::Void Matrix::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	B = new double* [rowCountB];
	if (rowCountB > 0 && columnCountB > 0) {
		CreateArray(dataGridView2, B, rowCountB, columnCountB);
	}
}

//Удаление строк и столбцов из матрицы А
System::Void Matrix::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView1);
	A = nullptr;
	rowCountA = 0;
	columnCountA = 0;
}

//Удаление строк и столбцов из матрицы B
System::Void Matrix::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView2);
	B = nullptr;
	rowCountB = 0;
	columnCountB = 0;
}

//Вычисление суммы/разности матриц	
System::Void Matrix::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((rowCountA == rowCountB) && (columnCountA == columnCountB) && rowCountA!=0 && columnCountA!=0) {
		C = new double* [rowCountA];
		if (radioButton1->Checked) Summa(A, B, C, rowCountA, columnCountA);
		if (radioButton2->Checked) Difference(A, B, C, rowCountA, columnCountA);
		DeleteColumnRow(dataGridView3);
		PrintMatrix(dataGridView3, C, rowCountA, columnCountA);
		DeleteArray(C, rowCountA);
	}else System::Windows::Forms::MessageBox::Show("Размеры матриц не совпадают или они не созданы", "Ошибка!");
}

//Очистка результата суммы/разности матриц
System::Void Matrix::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView3);
}

//Вычислить умножение/деление матрицы на число
System::Void Matrix::MyForm::button10_Click(System::Object^ sender, System::EventArgs^ e) {
	double koef{ 0 }; //множитель/делитель
	DeleteColumnRow(dataGridView4);
	if (CheckTextBox(textBox5, &koef)) {
		if (radioButton18->Checked) {
			if (rowCountA != 0 && columnCountA != 0) {
				C = new double* [rowCountA];
				if (radioButton4->Checked) NumberMultiply(A, C, rowCountA, columnCountA, &koef);
				if (radioButton3->Checked) NumberDevide(A, C, rowCountA, columnCountA, &koef);
				if (C != nullptr) {
				PrintMatrix(dataGridView4, C, rowCountA, columnCountA);
				DeleteArray(C, rowCountA);
				}

			}
			else System::Windows::Forms::MessageBox::Show("Выбрана не та матрица или она не создана", "Ошибка!");
		}
		if (radioButton17->Checked) {
			if (rowCountB != 0 && columnCountB != 0) {
				C = new double* [rowCountB];
				if (radioButton4->Checked) NumberMultiply(B, C, rowCountB, columnCountB, &koef);
				if (radioButton3->Checked) NumberDevide(B, C, rowCountB, columnCountB, &koef);
				PrintMatrix(dataGridView4, C, rowCountB, columnCountB);
				DeleteArray(C, rowCountB);
			}
			else System::Windows::Forms::MessageBox::Show("Выбрана не та матрица или она не создана", "Ошибка!");
		}
	}
}

//Очистка результата умножения/деления на число
System::Void Matrix::MyForm::button9_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView4);
}






//Удаление начальных массивов перед закрытием формы
System::Void Matrix::MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("Вы действительно хотите выйти?", "Закрытие окна", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes) {
		DeleteArray(A, rowCountA);
		DeleteArray(B, rowCountB);
		return;
	}
	else e->Cancel = true;
}