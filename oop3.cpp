#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class CDoubleVector {
private:
	int size; // Number of elements in the vector
	double* vector; // A pointer to a dynamic array
public:
	// Default constructor
	CDoubleVector() {
		size = 0;
		vector = nullptr;
	}
	// Method to initialize the vector
	void Init(int s) {
		size = s;
		vector = new double[size];
		for (int i = 0; i < size; ++i) {
			vector[i] = 0.0; // Initialization of all elements with zeros
		}
	}
	// Constructor with a parameter to determine the size of the vector
	CDoubleVector(int s) {
		Init(s);
	}
	// Destructor to release memory
	~CDoubleVector() {
		delete[] vector;
	}
	// Method to set the value of a vector element
	void setElement(int index, double value) {
		if (index >= 0 && index < size) {
			vector[index] = value;
		}
		else {
			cout << "Index outside vector!" << endl;
		}
	}
	// Method for obtaining the value of a vector element
	double getElement(int index) const {
		if (index >= 0 && index < size) {
			return vector[index];
		}
		else {
			cout << "Index outside vector!" << endl;
			return 0.0;
		}
	}
	// Method to get the size of the vector
	int getSize() const {
		return size;
	}
	// Method for finding the minimum value
	double getMin() const {
		if (size == 0) return 0.0;
		double min = vector[0];
		for (int i = 1; i < size; ++i) {
			if (vector[i] < min) {
				min = vector[i];
			}
		}
		return min;
	}
	// Method to find the maximum value
	double getMax() const {
		if (size == 0) return 0.0;
		double max = vector[0];
		for (int i = 1; i < size; ++i) {
			if (vector[i] > max) {
				max = vector[i];
			}
		}
		return max;
	}
	// Method to evaluate an expression
	double calculate(double x, double y, double z) const {
		double result = 0.0;
		// First sum: Σ (x^i * y^(10-i)), i from 1 to 10
		for (int i = 1; i <= 10; ++i) {
			result += pow(x, i) * pow(y, 10 - i);
		}
		// Second sum: Σ ((x - y)^i * z^(10-i)), i from 2 to 5
		for (int i = 2; i <= 5; ++i) {
			result += pow(x - y, i) * pow(z, 10 - i);
		}
		return result;
	}
};

int main() {
	// Creation of an object of the CDoubleVector class and its initialization
	CDoubleVector vec(11); // The size of the vector is 11 elements

	// Vector of values
	std::vector<double> values = { 0.3, 0.7, 0.9, 1.3, 1.7, 1.9, 2.3, 2.7, 2.9, 3.3, 3.7 };

	// Setting the values ​​of the elements of the vector
	for (int i = 0; i < vec.getSize(); ++i) {
		vec.setElement(i, values[i]);
	}

	// Output all elements of the vector
	std::cout << "Vector elements:" << std::endl;
	for (int i = 0; i < vec.getSize(); ++i) {
		std::cout << "vec[" << i << "] = " << vec.getElement(i) << std::endl;
	}

	// Testing the getSize() method
	std::cout << "\nVector size: " << vec.getSize() << std::endl;

	// Testing the getMin() and getMax() methods
	std::cout << "Minimum value of the vector: " << vec.getMin() << std::endl;
	std::cout << "Maximum value of vector: " << vec.getMax() << std::endl;

	// Testing the setElement() method - let's change the first element
	vec.setElement(0, 0.1);
	std::cout << "\nAfter changing the first element:" << std::endl;
	std::cout << "vec[0] = " << vec.getElement(0) << std::endl;

	// Testing the getElement() method with an incorrect index
	std::cout << "\nAttempt to get element with incorrect index:" << std::endl;
	vec.getElement(20);

	// Testing the calculate() method
	double x = 1.5, y = 2.0, z = 0.5;
	std::cout << "\nThe result of evaluating the expression (x=" << x << ", y=" << y << ", z=" << z << "):" << std::endl;
	std::cout << std::fixed << std::setprecision(6) << vec.calculate(x, y, z) << std::endl;

	return 0;
}