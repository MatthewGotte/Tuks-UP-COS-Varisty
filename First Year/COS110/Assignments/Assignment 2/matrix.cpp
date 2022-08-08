#include "matrix.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

ostream  & operator<<(ostream & output, const Matrix & mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            output << setw(10) << setprecision(3) << mat.matrix[i][j];
        }
        output << endl;
    }
    return output;
}

istream & operator>>(istream & input, Matrix & mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            input >> mat.matrix[i][j];
        }
    }
    return input;
}

//Constructor
Matrix::Matrix(unsigned int r, unsigned int c) {
    this->rows = r;
    this->cols = c;
    this->matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        this->matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] = 0;
        }
    }
    ///////////???
    linearDeterminants = NULL;
}

//Copy Constructor
Matrix::Matrix(const Matrix &rhs) {
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    this->denominator = rhs.denominator;
    this->matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        this->matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

//Destructor
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete matrix[i];
    }
    delete [] matrix;
    matrix = nullptr;
}

//Overloaded =
const Matrix & Matrix::operator=(const Matrix &rhs) {
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    this->denominator = rhs.denominator;
    this->linearDeterminants = rhs.linearDeterminants;
    this->linearSolutions = rhs.linearSolutions;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }
    return *this;
}

double & Matrix::operator()(const unsigned int r, const unsigned int c) {
    return this->matrix[r][c];
}

const double & Matrix::operator()(const unsigned int r, const unsigned int c) const {
    return this->matrix[r][c];
}

Matrix Matrix::operator[](const unsigned int r) const {
    Matrix x(1, this->cols);
    x.rows = 1;
    x.cols = this->cols;
    for (int i = 0; i < this->cols; i++) {
        x.matrix[0][i] = this->matrix[r][i];
    }
    return x;

}

unsigned int Matrix::getRows() const {
    return this->rows;
}

unsigned int Matrix::getCols() const {
    return this->cols;
}

//Matrix scalar Multiplication:
Matrix Matrix::operator*(const double &rhs) {
    Matrix x(this->rows, this->cols);
    x.setMatrix(this->matrix);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            x.matrix[i][j] = this->matrix[i][j] * rhs;
        }
    }
    return x;
}

Matrix operator*(const double & x, const Matrix & mat) {
    Matrix temp(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            temp.matrix[i][j] = mat.matrix[i][j] * x;
        }
    }
    return temp;
}

//Matrix Division:
Matrix Matrix::operator/(const double &rhs) {
    if (rhs != 0) {
        Matrix x(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                x.matrix[i][j] = this->matrix[i][j] / rhs;
            }
        }
        return x;
    }
    else {
        cout << "Error: division by zero" << endl;
    }
    return *this;
}

//Matrix Addition:
Matrix Matrix::operator+(const Matrix &rhs) {
    if ((this->rows == rhs.rows) && (this->cols == rhs.cols)) {
        Matrix x(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                x.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
            }
        }
        return x;
    }
    else {
        cout << "Error: adding matrices of different dimensionality" << endl;
    }
    return *this;
}

Matrix & Matrix::operator+=(const Matrix &rhs) {
    if ((this->rows == rhs.rows) && (this->cols == rhs.cols)) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                this->matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
            }
        }
    }
    else {
        cout << "Error: adding matrices of different dimensionality" << endl;
    }
    return *this;
}

//Matrix Subtraction:
Matrix Matrix::operator-(const Matrix &rhs) {
    if ((this->rows == rhs.rows) && (this->cols == rhs.cols)) {
        Matrix x(this->rows, this->cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                x.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
            }
        }
        return x;
    }
    else {
        cout << "Error: subtracting matrices of different dimensionality" << endl;
    }
    return *this;
}

Matrix & Matrix::operator-=(const Matrix &rhs) {
    if ((this->rows == rhs.rows) && (this->cols == rhs.cols)) {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                this->matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
            }
        }
    }
    else {
        cout << "Error: subtracting matrices of different dimensionality" << endl;
    }
    return *this;
}

//Vector Multiplication:
Matrix & Matrix::operator*=(const Matrix &rhs) {
    if (this->cols == rhs.rows) {

        if ((this->rows == 1) && (rhs.cols == 1)) {
            //Dot multiplication
            Matrix x(1,1);
            for (int i = 0; i < this->cols; i++) {
                x.matrix[0][0] += this->matrix[0][i] * rhs.matrix[i][0];
            }
            this->rows = 1;
            this->cols = 1;
            this->setMatrix(x.matrix);
            return *this;
        }
        else {
            //Matrix multiplication
            Matrix x(this->rows, rhs.cols);

            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < rhs.cols; j++) {
                    for (int k = 0; k < this->cols; k++) {
                        x.matrix[i][j]+= this->matrix[i][k] * rhs.matrix[k][j];
                    }
                }
            }
            this->cols = rhs.cols;
            this->setMatrix(x.matrix);
            return *this;
        }

    }
    else {
        cout << "Error: invalid matrix multiplication" << endl;
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix &rhs) {
    if (this->cols == rhs.rows) {

        if ((this->rows == 1) && (rhs.cols == 1)) {
            //Dot multiplication
            Matrix x(1,1);
            for (int i = 0; i < this->cols; i++) {
                x.matrix[0][0] = this->matrix[0][i] * rhs.matrix[i][0];
            }
            return x;
        }
        else {
            //Matrix multiplication
            Matrix x(this->rows, rhs.cols);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < rhs.cols; j++) {
                    for (int k = 0; k < this->cols; k++) {
                        x.matrix[i][j]+= this->matrix[i][k] * rhs.matrix[k][j];
                    }
                }
            }
            return x;
        }

    }
    else {
        cout << "Error: invalid matrix multiplication" << endl;
    }
    return *this;
}

void Matrix::setMatrix(double **m) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->matrix[i][j] = m[i][j];
        }
    }
}

Matrix Matrix::operator^(int pow) {
    if (this->rows == this->cols) {
        if (pow >= 0) {

            Matrix x(this->rows, this->cols);
            x.setMatrix(this->matrix);

            if (pow != 0) {

                for (int i = 1; i < pow; i++) {
                    x *= *this;
                }
            }
            else {
                //Identity transformation
                for (int i = 0; i < this->rows; i++) {
                    for (int j = 0; j < this->cols; j++) {
                        if (i == j) {
                            x.matrix[i][j] = 1;
                        }
                        else {
                            x.matrix[i][j] = 0;
                        }
                    }
                }
            }
            return x;
        }
        else {
            cout << "Error: negative power is not supported" << endl;
        }
    }
    else {
        cout << "Error: non-square matrix provided" << endl;
    }
    return *this;
}

Matrix & Matrix::operator*=(const double &rhs) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->matrix[i][j] *= rhs;
        }
    }
    return *this;
}

Matrix & Matrix::operator^=(int pow) {
    if (this->rows == this->cols) {
        if (pow >= 0) {
            if (pow != 0) {
                //Store Original
                Matrix temp(this->rows, this->cols);
                temp.setMatrix(this->matrix);
                for (int i = 1; i < pow; i++) {
                    *this *= temp;
                }
            }
            else {
                for (int i = 0; i < this->rows; i++) {
                    for (int j = 0; j < this->cols; j++) {
                        if (i == j) {
                            this->matrix[i][j] = 1;
                        }
                        else {
                            this->matrix[i][j] = 0;
                        }
                    }
                }
            }
        }
        else {
            cout << "Error: negative power is not supported" << endl;
        }
    }
    else {
        cout << "Error: non-square matrix provided" << endl;
    }
    return *this;
}

double Matrix::operator~() {
    if (((this->rows == 2) && (this->cols == 2)) || ((this->rows == 3) && (this->cols == 3))) {
        double output = 0;
        if ((this->rows == 2) && (this->cols == 2)) {
            output = (this->matrix[0][0] * this->matrix[1][1]) - (this->matrix[1][0] * this->matrix[0][1]);
        }
        if ((this->rows == 3) && (this->cols == 3)) {
            output = this->matrix[0][0] * ((this->matrix[1][1] * this->matrix[2][2]) - (this->matrix[2][1] * this->matrix[1][2]));

            output -= this->matrix[0][1] * ((this->matrix[1][0] * this->matrix[2][2]) - (this->matrix[2][0] * this->matrix[1][2]));

            output += this->matrix[0][2] * ((this->matrix[1][0] * this->matrix[2][1]) - (this->matrix[2][0] * this->matrix[1][1]));
        }
        denominator = output;
        return output;
    }
    else {
        cout << "Error: invalid matrix dimensions" << endl;
    }
    return 0;
}

double * Matrix::operator|(Matrix &rhs) {
    if (this->rows == this->cols) {

        if (((this->rows == 2) && (this->cols == 2)) || ((this->rows == 3) && (this->cols == 3))) {
            if (rhs.cols == 1) {

                if ((this->rows == 2) && (this->cols == 2)) {
                    //2x2 Cramer's
                    linearDeterminants = new double[2];
                    Matrix x(2,2);
                    x.setMatrix(this->matrix);
                    x.matrix[0][0] = rhs.matrix[0][0];
                    x.matrix[1][0] = rhs.matrix[1][0];
                    linearDeterminants[0] = ~x;
                    x.setMatrix(this->matrix);
                    x.matrix[0][1] = rhs.matrix[0][0];
                    x.matrix[1][1] = rhs.matrix[1][0];
                    linearDeterminants[1] = ~x;
                }

                if ((this->rows == 3) && (this->cols == 3)) {
                    //3x3 Cramer's
                    linearDeterminants = new double[3];
                    Matrix x(3,3);
                    x.setMatrix(this->matrix);
                    x.matrix[0][0] = rhs.matrix[0][0];
                    x.matrix[1][0] = rhs.matrix[1][0];
                    x.matrix[2][0] = rhs.matrix[2][0];
                    linearDeterminants[0] = ~x;
                    x.setMatrix(this->matrix);
                    x.matrix[0][1] = rhs.matrix[0][0];
                    x.matrix[1][1] = rhs.matrix[1][0];
                    x.matrix[2][1] = rhs.matrix[2][0];
                    linearDeterminants[1] = ~x;
                    x.setMatrix(this->matrix);
                    x.matrix[0][2] = rhs.matrix[0][0];
                    x.matrix[1][2] = rhs.matrix[1][0];
                    x.matrix[2][2] = rhs.matrix[2][0];
                    linearDeterminants[2] = ~x;
                }
                //return linearDeterminants;

            }
            else {
                cout << " Error: incorrect number of variables" << endl;
            }
        }
        else {
            cout << "Error: incorrect number of variables" << endl;
        }

    }
    else {
        cout << "Error: non-square matrix provided" << endl;
    }
    return linearDeterminants;
}

Matrix Matrix::operator|=(Matrix &rhs) {
    if (((this->rows == 2) && (this->cols == 2)) || ((this->rows == 3) && (this->cols == 3))) {
        if (rhs.cols == 1) {
            Matrix temp(this->rows, this->cols);
            temp.setMatrix(this->matrix);
            denominator = ~temp;
            if (denominator != 0) {
                //Check if determinants
                if (linearDeterminants == NULL) {
                    linearDeterminants = *this|rhs;
                }
                //Use determinants
                //Check sizes
                if ((this->rows == 2) && (this->cols == 2)) {
                    linearSolutions = new double[2];
                    linearSolutions[0] = linearDeterminants[0] / denominator;
                    linearSolutions[1] = linearDeterminants[1] / denominator;
                    Matrix x(2,1);
                    x.matrix[0][0] = linearSolutions[0];
                    x.matrix[1][0] = linearSolutions[1];
                    return x;
                }

                if ((this->rows == 3) && (this->cols == 3)) {
                    linearSolutions = new double[3];
                    linearSolutions[0] = linearDeterminants[0] / denominator;
                    linearSolutions[1] = linearDeterminants[1] / denominator;
                    linearSolutions[2] = linearDeterminants[2] / denominator;
                    Matrix x(3,1);
                    x.matrix[0][0] = linearSolutions[0];
                    x.matrix[1][0] = linearSolutions[1];
                    x.matrix[2][0] = linearSolutions[2];
                    return x;
                }
            }
            else {
                cout << "Error: division by zero" << endl;
            }
        }
        else {
            cout << "Error: incorrect number of variables" << endl;
        }
    }
    else {
        cout << "Error: incorrect number of variables" << endl;
    }

    return rhs;
}
