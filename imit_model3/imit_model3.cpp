#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<double> rg(0.00001, 1.0);
double randomvalue()
{
    double a = rg(gen);
	if (a < 3.0 / 4.0)
		return 2 * a - 1;
	else return pow(a, 1. / 3.); //возведение в степень 1/3
}
int main()
{
	int n = 100000; 
	double* X = new double[n];


	double sum = 0;
	for (int i = 0; i < n; i++)//генерируем выборку и считаем её сумму
	{
		X[i] = randomvalue();
		sum += X[i];
	}

	double M = sum / n; //считаем выборочное среднее

	std::cout << "Theoretichal mathexpectation: 0\n";
	std::cout << "Selective average: " << M << std::endl;

	sum = 0;

	for (int i = 0; i < n; i++)//считаем выборочную дисперсию
	{
		sum += (X[i] - M) * (X[i] - M);
	}

	double D = sum / (n - 1); 
	std::cout << "Dispersion theoretical: 0.4\n";
	std::cout << "Selective disperison: " << D << std::endl;

	delete[] X;
	return 0;
}

