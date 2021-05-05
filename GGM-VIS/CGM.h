#ifndef __CGM_H__
#define __CGM_H__

#include "definitions.h"

class CGM
{
	solution v; // ������� ���������� �������
	solution u; // ������� ��������� �������
	solution f; // ������ ������ �����
	solution r0; // ������� �� ��������� ����
	solution rn; // ������� �� ��������� ����
	solution difference; // ������� ��������� � ���������� �������

	uint n; // ����� ��������� �� x
	uint m; // ����� ��������� �� y
	uint inter; // ����� ���������� �����������

	std::vector<double> x; // ���� ��� x
	std::vector<double> y; // ���� ��� y

	double h, k; // ���� �� x � y ��������������

	double _a; // ������� �������
	double _h; // ������� �������
	double _k; // ������� �������

	uint n1, n2, m1, m2; // ������� � �������

	uint max_iter; // ������������ ����� ���������� ��������
	double des_eps; // �������� ��������

	uint iter; // ������� ��������
	double current_eps; // ������� ��������
	double max_true; // ������� ��������� � ���������� �������
	uint i_max, j_max; // ����������, ��� ����������� �������� �������
	double nr0, nrn; // ����� ������� �� ������� ���� � ���������
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

