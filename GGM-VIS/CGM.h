#ifndef __CGM_H__
#define __CGM_H__

#include "definitions.h"

class CGM
{
	solution v; // матрица численного решения
	solution u; // матрица истинного решения
	solution f; // вектор правой части
	solution r0; // невязка на начальном шаге
	solution rn; // невязка на последнем шаге
	solution difference; // разница истинного и численного решений

	uint n; // число разбиений по x
	uint m; // число разбиений по y
	uint inter; // выбор начального приближения

	std::vector<double> x; // узлы оси x
	std::vector<double> y; // узлы оси y

	double h, k; // шаги по x и y соответственно

	double _a; // элемент матрицы
	double _h; // элемент матрицы
	double _k; // элемент матрицы

	uint n1, n2, m1, m2; // границы в матрице

	uint max_iter; // максимальное число допустимых итераций
	double des_eps; // желаемая точность

	uint iter; // счётчик итераций
	double current_eps; // текущая точность
	double max_true; // разница истинного и численного решений
	uint i_max, j_max; // координаты, где достигается максимум разницы
	double nr0, nrn; // нормы невязок на нулевом шаге и последнем
public:
	CGM(const uint& _n, const uint& _m, const uint& _inter, const uint& _iter, const double& _eps);
	solution mul_scalar(const double& scal, const solution& _sol);
	solution substract(const solution& val1, const solution& val2);
	solution add(const solution& val1, const solution& val2);
	void add_to_solution(const solution& val);
	solution matrix_product88(const solution& out);
	solution give_residual88(const solution& out);
	void solve88();
	solution matrix_product(const solution& out);
	solution give_residual(const solution& out);
	void solve();
	double scalar_product(const solution& val1, const solution& val2);
	double give_max(const solution& out);
	void solver();

	uint giveIter() { return iter; }
	double giveEps() { return current_eps; }
	double giveMaxTrue() { return max_true; }
	double returnX() { return x[i_max]; }
	double returnY() { return y[j_max]; }
	double returnR0() { return nr0; }
	double returnRN() { return nrn; }
	solution returnV() { return v; }
	solution returnU() { return u; }
	solution returnDif() { return difference; }
};

#endif

