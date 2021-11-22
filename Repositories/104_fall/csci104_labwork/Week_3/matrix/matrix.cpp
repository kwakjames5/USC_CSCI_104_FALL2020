#include "matrix.h"
#include <iostream>

Matrix::Matrix() : rows(0), columns(0), data(nullptr) {}

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> initializer_list) {
	if (initializer_list.size() == 0 || initializer_list.begin()->size() == 0) {
		this->rows = 0;
		this->columns = 0;
		this->data = nullptr;
		return;
	}

	this->rows = initializer_list.size();
	this->columns = initializer_list.begin()->size();
	this->data = new int*[rows];

	for (size_t i = 0; i < this->rows; i++) {
		data[i] = new int[columns];
    }

	int i = 0;
	for (const std::initializer_list<int>& row : initializer_list) {
		int j = 0;
		for (int value : row) {
			data[i][j] = value;
			j++;
		}
		i++;
	}
}

Matrix::Matrix(const Matrix& other) {
	// TODO

	if (other.rows == 0 || other.columns == 0) {
		this->rows = 0;
		this->columns = 0;
		this->data = nullptr;
		return;
	}

	this->rows = other.rows;
	this->columns = other.columns;
	this->data = new int*[this->rows];

	/* 
	{
		{ , , , , }
		{ , , , , }
		{ , , , , }
	}
	*/


	for (size_t i = 0; i < this->rows; i++) {
		this->data[i] = new int[columns];
		for(size_t j = 0; j < this->columns; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
    }
}

Matrix::~Matrix() {
	// TODO
	for(size_t i = 0; i < this->rows; i++)
	{
		delete [] this->data[i];
	}

	delete [] this->data;
}

Matrix& Matrix::operator=(const Matrix& other) {
	// TODO
	for(size_t i = 0; i < this->rows; i++)
	{
		delete [] this->data[i];
	}

	delete [] this->data;

	if (other.rows == 0 || other.columns == 0) {
		this->rows = 0;
		this->columns = 0;
		this->data = nullptr;
		return *this;
	}

	this->rows = other.rows;
	this->columns = other.columns;
	this->data = new int*[this->rows];

	for (size_t i = 0; i < this->rows; i++) {
		this->data[i] = new int[columns];
		for(size_t j = 0; j < this->columns; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
	Matrix sum = {{ }};

	sum.rows = this->rows;
	sum.columns = this->columns;
	sum.data = new int*[this->rows];

	for(size_t i = 0; i < this->rows; i++)
	{
		sum.data[i] = new int[columns];
		for(size_t j = 0; j < this->columns; j++)
		{
			sum.data[i][j] = this->data[i][j] + other.data[i][j];
		}
	}
	// TODO
	return sum;
}

Matrix Matrix::operator*(const Matrix& other) const {
	Matrix product = {{ }};

	product.rows = this->rows;
	product.columns = other.columns;
	product.data = new int*[product.rows];

	for(size_t i = 0; i < product.rows; i++)
	{
		product.data[i] = new int[product.columns];
		for(size_t j = 0; j < product.columns; j++)
		{
			product.data[i][j] = 0;
		}
	}

	for(size_t i = 0; i < product.rows; i++)
	{
		for(size_t j = 0; j < product.columns; j++)
		{
			for(size_t k = 0; k < other.rows; k++)
			{
				product.data[i][j] += this->data[i][k] * other.data[k][j];
			}
		}
	}


/*
	for(size_t i = 0; i < this->rows; i++)
	{
		for(size_t j = 0; j < other.columns; j++)
		{

		}
	}
*/
	// TODO
	return product;
}

bool Matrix::operator==(const Matrix& other) const {
	if (this->columns != other.columns || rows != other.rows) {
		return false;
    }
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			if (this->data[i][j] != other.data[i][j]) {
				return false;
            }
        }
    }
	return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (size_t i = 0; i < m.rows; i++) {
		os << '[';
		for (size_t j = 0; j < m.columns; j++) {
			os << m.data[i][j];
			if (j != m.columns - 1) {
				os << '\t';
            }
		}
		os << ']' << std::endl;
	}
	return os;
}
