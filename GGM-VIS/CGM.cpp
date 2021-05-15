#include "CGM.h"

double sol(const double& x, const double& y) {
	double value1 = sin(M_PI * x * y) * sin(M_PI * x * y);
	double result = exp(value1);
	return result;
}

double above_x(const double& x, const double& y) {
	double value1 = sin(M_PI * y) * sin(M_PI * y);
	value1 = exp(value1);
	double result = x * value1 + (1 - x);
	return result;
}

double above_y(const double& x, const double& y) {
	double value1 = sin(M_PI * x) * sin(M_PI * x);
	value1 = exp(value1);
	double result = y * value1 + (1 - y);
	return result;
}

double right_part(const double& x, const double& y) {
	double value1 = x * x + y * y;
	double value2 = sin(2 * M_PI * x * y) * sin(2 * M_PI * x * y) + 2 * cos(2 * M_PI * x * y);
	double value3 = sin(M_PI * x * y) * sin(M_PI * x * y);
	value3 = exp(value3);
	double result = M_PI * M_PI * value3 * value2 * value1;
	return result;
}

CGM::CGM(const uint& _n, const uint& _m, const uint& _inter, const uint& _iter, const double& _eps)
	: n(_n), m(_m), inter(_inter), max_iter(_iter), des_eps(_eps), iter(0), current_eps(0.0), max_true(0.0),
	i_max(0), j_max(0), nr0(0.0), nrn(0.0) {
	n1 = n / 4;
	n2 = 3 * n1;
	m1 = m / 4;
	m2 = 3 * m1;

	h = 1.0 / double(n);
	k = 1.0 / double(m);

	_h = 1.0 / (h * h);
	_k = 1.0 / (k * k);
	_a = -2.0 * (_h + _k);

	x.resize(n + 1);
	y.resize(m + 1);
	x[0] = 0;
	y[0] = 0;

	for (uint i = 1; i < n + 1; ++i)
		x[i] = x[i - 1] + h;

	for (uint i = 1; i < m + 1; ++i)
		y[i] = y[i - 1] + k;

	v.resize(m + 1);
	u.resize(m + 1);
	f.resize(m + 1);
	r0.resize(m + 1);
	rn.resize(m + 1);
	difference.resize(m + 1);

	for (uint i = 0; i < m + 1; ++i) {
		v[i].resize(n + 1);
		u[i].resize(n + 1);
		f[i].resize(n + 1);
		r0[i].resize(n + 1);
		rn[i].resize(n + 1);
		difference[i].resize(n + 1);
	}

	for (uint j = 0; j < m + 1; ++j)
		for (uint i = 0; i < n + 1; ++i) {
			if ((i > n1) && (i < n2) && (j > m1) && (j < m2)) {
				u[j][i] = 0;
				v[j][i] = u[j][i];
			}
			else {
				u[j][i] = sol(x[i], y[j]);
				v[j][i] = u[j][i];
			}
		}

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			if (inter == 0) v[j][i] = 0;
			else if (inter == 1) v[j][i] = above_x(x[i], y[j]);
			else v[j][i] = above_y(x[i], y[j]);
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			if (inter == 0) v[j][i] = 0;
			else if (inter == 1) v[j][i] = above_x(x[i], y[j]);
			else v[j][i] = above_y(x[i], y[j]);
		}

		for (uint i = n2 + 1; i < n; ++i) {
			if (inter == 0) v[j][i] = 0;
			else if (inter == 1) v[j][i] = above_x(x[i], y[j]);
			else v[j][i] = above_y(x[i], y[j]);
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			if (inter == 0) v[j][i] = 0;
			else if (inter == 1) v[j][i] = above_x(x[i], y[j]);
			else v[j][i] = above_y(x[i], y[j]);
		}

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i)
			f[j][i] = right_part(x[i], y[j]);

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) 
			f[j][i] = right_part(x[i], y[j]);

		for (uint i = n2 + 1; i < n; ++i)
			f[j][i] = right_part(x[i], y[j]);
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i)
			f[j][i] = right_part(x[i], y[j]);

	for (uint i = 1; i < n; ++i)
	{
		f[1][i] -= _k * v[0][i];
		f[m - 1][i] -= _k * v[m][i];
	}

	for (uint j = 1; j < m; ++j)
	{
		f[j][1] -= _h * v[j][0];
		f[j][n - 1] -= _h * v[j][n];
	}

	for (uint i = n1; i < n2 + 1; ++i)
	{
		f[m1 - 1][i] -= _k * v[m1][i];
		f[m2 + 1][i] -= _k * v[m2][i];
	}

	for (uint j = m1; j < m2 + 1; ++j)
	{
		f[j][n1 - 1] -= _h * v[j][n1];
		f[j][n2 + 1] -= _h * v[j][n2];
	}

	_a = -1 * _a;
	_h = -1 * _h;
	_k = -1 * _k;
	f = mul_scalar(-1, f);
}

solution CGM::mul_scalar(const double& scal, const solution& _sol) {
	solution result;
	result.resize(m + 1);
	for (uint i = 0; i < m + 1; ++i) result[i].resize(n + 1);

	for (uint j = 0; j < m + 1; ++j)
		for (uint i = 0; i < n + 1; ++i)
			result[j][i] = 0;

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] = scal * _sol[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			result[j][i] = scal * _sol[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			result[j][i] = scal * _sol[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] = scal * _sol[j][i];
		}

	return result;
}

solution CGM::substract(const solution& val1, const solution& val2) {
	solution result;
	result.resize(m + 1);
	for (uint i = 0; i < m + 1; ++i) result[i].resize(n + 1);

	for (uint j = 0; j < m + 1; ++j)
		for (uint i = 0; i < n + 1; ++i) 
			result[j][i] = 0;

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] = val1[j][i] - val2[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			result[j][i] = val1[j][i] - val2[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			result[j][i] = val1[j][i] - val2[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] = val1[j][i] - val2[j][i];
		}

	return result;
}

solution CGM::add(const solution& val1, const solution& val2) {
	solution result;
	result.resize(m + 1);
	for (uint i = 0; i < m + 1; ++i) result[i].resize(n + 1);

	for (uint j = 0; j < m + 1; ++j)
		for (uint i = 0; i < n + 1; ++i)
			result[j][i] = 0;

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] = val1[j][i] + val2[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			result[j][i] = val1[j][i] + val2[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			result[j][i] = val1[j][i] + val2[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] = val1[j][i] + val2[j][i];
		}

	return result;
}

void CGM::add_to_solution(const solution& val) {
	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			v[j][i] += val[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			v[j][i] += val[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			v[j][i] += val[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			v[j][i] += val[j][i];
		}
}

double CGM::scalar_product(const solution& val1, const solution& val2) {
	double result = 0.0;

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			result = result + val1[j][i] * val2[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			result = result + val1[j][i] * val2[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			result = result + val1[j][i] * val2[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			result = result + val1[j][i] * val2[j][i];
		}

	return result;
}

solution CGM::matrix_product88(const solution& out) {
	solution result;
	result.resize(m + 1);
	for (uint i = 0; i < m + 1; ++i) result[i].resize(n + 1);

	for (uint j = 0; j < m + 1; ++j)
		for (uint i = 0; i < n + 1; ++i)
			result[j][i] = 0;

	result[1][1] = _a * out[1][1] + _h * out[1][2] + _k * out[2][1];
	result[1][7] = _a * out[1][7] + _h * out[1][6] + _k * out[2][7];
	result[7][1] = _a * out[7][1] + _h * out[7][2] + _k * out[6][1];
	result[7][7] = _a * out[7][7] + _h * out[7][6] + _k * out[6][7];

	for (uint j = 2; j < 7; ++j) {
		result[j][1] = _a * out[j][1] + _k * (out[j - 1][1] + out[j + 1][1]);
		result[j][7] = _a * out[j][7] + _k * (out[j - 1][7] + out[j + 1][7]);
	}

	for (uint i = 2; i < 7; ++i) {
		result[1][i] = _a * out[1][i] + _h * (out[1][i - 1] + out[1][i + 1]);
		result[7][i] = _a * out[7][i] + _h * (out[7][i - 1] + out[7][i + 1]);
	}

	return result;
}

solution CGM::give_residual88(const solution& out) {
	solution result = matrix_product88(out);

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] -= f[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			result[j][i] -= f[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			result[j][i] -= f[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] -= f[j][i];
		}

	return result;
}

void CGM::solve88() {
	solution r = give_residual88(v);
	solution h = mul_scalar(-1, r);
	solution matr_h = matrix_product88(h);
	double alpha = scalar_product(h, h) / scalar_product(matr_h, h);
	solution temp = mul_scalar(alpha, h);
	add_to_solution(temp);
	current_eps = give_max(temp);
	iter = 1;
	double beta = 0.0;

	while ((iter < max_iter) && (current_eps > des_eps)) {
		r = give_residual88(v);
		beta = scalar_product(matr_h, r) / scalar_product(matr_h, h);
		temp = mul_scalar(beta, h);
		h = substract(temp, r);
		matr_h = matrix_product88(h);
		alpha = -scalar_product(r, h) / scalar_product(matr_h, h);
		temp = mul_scalar(alpha, h);
		add_to_solution(temp);
		current_eps = give_max(temp);
		iter += 1;
	}
}

solution CGM::matrix_product(const solution& out) {
	solution result;
	result.resize(m + 1);
	for (uint i = 0; i < m + 1; ++i) result[i].resize(n + 1);

	for (uint j = 0; j < m + 1; ++j)
		for (uint i = 0; i < n + 1; ++i)
			result[j][i] = 0;

	result[1][1] = _a * out[1][1] + _h * out[1][2] + _k * out[2][1];
	for (uint i = 2; i < n - 1; ++i) 
		result[1][i] = _a * out[1][i] + _h * (out[1][i - 1] + out[1][i + 1]) + _k * out[2][i];
	result[1][n - 1] = _a * out[1][n - 1] + _h * out[1][n - 2] + _k * out[2][n - 1];

	for (uint j = 2; j < m1 - 1; ++j) {
		result[j][1] = _a * out[j][1] + _h * out[j][2] + _k * (out[j - 1][1] + out[j + 1][1]);
		for (uint i = 2; i < n - 1; ++i)
			result[j][i] = _a * out[j][i] + _h * (out[j][i - 1] + out[j][i + 1]) + _k * (out[j - 1][i] + out[j + 1][i]);
		result[j][n - 1] = _a * out[j][n - 1] + _h * out[j][n - 2] + _k * (out[j - 1][n - 1] + out[j + 1][n - 1]);
	}
			
	uint l = m1 - 1;
	result[l][1] = _a * out[l][1] + _h * out[l][2] + _k * (out[l - 1][1] + out[l + 1][1]);
	for (uint i = 2; i < n1; ++i)
		result[l][i] = _a * out[l][i] + _h * (out[l][i - 1] + out[l][i + 1]) + _k * (out[l - 1][i] + out[l + 1][i]);
	for (uint i = n1; i < n2 + 1; ++i)
		result[l][i] = _a * out[l][i] + _h * (out[l][i - 1] + out[l][i + 1]) + _k * out[l - 1][i];
	for (uint i = n2 + 1; i < n - 1; ++i)
		result[l][i] = _a * out[l][i] + _h * (out[l][i - 1] + out[l][i + 1]) + _k * (out[l - 1][i] + out[l + 1][i]);
	result[l][n - 1] = _a * out[l][n - 1] + _h * out[l][n - 2] + _k * (out[l - 1][n - 1] + out[l + 1][n - 1]);

	for (uint j = m1; j < m2 + 1; ++j) {
		result[j][1] = _a * out[j][1] + _h * out[j][2] + _k * (out[j - 1][1] + out[j + 1][1]);
		for (uint i = 2; i < n1 - 1; ++i)
			result[j][i] = _a * out[j][i] + _h * (out[j][i - 1] + out[j][i + 1]) + _k * (out[j - 1][i] + out[j + 1][i]);
		result[j][n1 - 1] = _a * out[j][n1 - 1] + _h * out[j][n1 - 2] + _k * (out[j - 1][n1 - 1] + out[j + 1][n1 - 1]);
		result[j][n2 + 1] = _a * out[j][n2 + 1] + _h * out[j][n2 + 2] + _k * (out[j - 1][n2 + 1] + out[j + 1][n2 + 1]);
		for (uint i = n2 + 2; i < n - 1; ++i)
			result[j][i] = _a * out[j][i] + _h * (out[j][i - 1] + out[j][i + 1]) + _k * (out[j - 1][i] + out[j + 1][i]);
		result[j][n - 1] = _a * out[j][n - 1] + _h * out[j][n - 2] + _k * (out[j - 1][n - 1] + out[j + 1][n - 1]);
	}

	l = m2 + 1;
	result[l][1] = _a * out[l][1] + _h * out[l][2] + _k * (out[l - 1][1] + out[l + 1][1]);
	for (uint i = 2; i < n1; ++i)
		result[l][i] = _a * out[l][i] + _h * (out[l][i - 1] + out[l][i + 1]) + _k * (out[l - 1][i] + out[l + 1][i]);
	for (uint i = n1; i < n2 + 1; ++i)
		result[l][i] = _a * out[l][i] + _h * (out[l][i - 1] + out[l][i + 1]) + _k * out[l + 1][i];
	for (uint i = n2 + 1; i < n - 1; ++i)
		result[l][i] = _a * out[l][i] + _h * (out[l][i - 1] + out[l][i + 1]) + _k * (out[l - 1][i] + out[l + 1][i]);
	result[l][n - 1] = _a * out[l][n - 1] + _h * out[l][n - 2] + _k * (out[l - 1][n - 1] + out[l + 1][n - 1]);

	for (uint j = m2 + 2; j < m - 1; ++j) {
		result[j][1] = _a * out[j][1] + _h * out[j][2] + _k * (out[j - 1][1] + out[j + 1][1]);
		for (uint i = 2; i < n - 1; ++i)
			result[j][i] = _a * out[j][i] + _h * (out[j][i - 1] + out[j][i + 1]) + _k * (out[j - 1][i] + out[j + 1][i]);
		result[j][n - 1] = _a * out[j][n - 1] + _h * out[j][n - 2] + _k * (out[j - 1][n - 1] + out[j + 1][n - 1]);
	}

	result[m - 1][1] = _a * out[m - 1][1] + _h * out[m - 1][2] + _k * out[m - 2][1];
	for (uint i = 2; i < n - 1; ++i)
		result[m - 1][i] = _a * out[m - 1][i] + _h * (out[m - 1][i - 1] + out[m - 1][i + 1]) + _k * out[m - 2][i];
	result[m - 1][n - 1] = _a * out[m - 1][n - 1] + _h * out[m - 1][n - 2] + _k * out[m - 2][n - 1];

	return result;
}

solution CGM::give_residual(const solution& out) {
	solution result = matrix_product(out);

	for (uint j = 1; j < m1; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] -= f[j][i];
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = 1; i < n1; ++i) {
			result[j][i] -= f[j][i];
		}

		for (uint i = n2 + 1; i < n; ++i) {
			result[j][i] -= f[j][i];
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = 1; i < n; ++i) {
			result[j][i] -= f[j][i];
		}

	return result;
}

void CGM::solve() {
	solution r = give_residual(v);
	r0 = r;
	solution h = mul_scalar(-1, r);
	solution matr_h = matrix_product(h);
	double alpha = scalar_product(h, h) / scalar_product(matr_h, h);
	solution temp = mul_scalar(alpha, h);
	add_to_solution(temp);
	current_eps = give_max(temp);
	iter = 1;
	double beta = 0.0;

	while ((iter < max_iter) && (current_eps > des_eps)) {
		r = give_residual(v);
		beta = scalar_product(matr_h, r) / scalar_product(matr_h, h);
		temp = mul_scalar(beta, h);
		h = substract(temp, r);
		matr_h = matrix_product(h);
		alpha = -scalar_product(r, h) / scalar_product(matr_h, h);
		temp = mul_scalar(alpha, h);
		add_to_solution(temp);
		current_eps = give_max(temp);
		iter += 1;
	}

	rn = r;
}

double CGM::give_max(const solution& out) {
	double max = 0.0;

	for (uint j = 1; j < m1; ++j)
		for (uint i = n1; i < n; ++i) {
			if (abs(out[j][i]) > max) {
				max = abs(out[j][i]);
				i_max = i;
				j_max = j;
			}
		}

	for (uint j = m1; j < m2 + 1; ++j) {
		for (uint i = n1; i < n1; ++i) {
			if (abs(out[j][i]) > max) {
				max = abs(out[j][i]);
				i_max = i;
				j_max = j;
			}
		}

		for (uint i = n2 + 1; i < n; ++i) {
			if (abs(out[j][i]) > max) {
				max = abs(out[j][i]);
				i_max = i;
				j_max = j;
			}
		}
	}

	for (uint j = m2 + 1; j < m; ++j)
		for (uint i = n1; i < n; ++i) {
			if (abs(out[j][i]) > max) {
				max = abs(out[j][i]);
				i_max = i;
				j_max = j;
			}
		}

	return max;
}

void CGM::solver() {
	iter = 0;
	current_eps = 0.0;
	max_true = 0.0;
	i_max = 0;
	j_max = 0;

	if ((n == 8) && (m == 8)) solve88();
	else solve();

	difference = substract(u, v);
	max_true = give_max(difference);
	nr0 = give_max(r0);
	nrn = give_max(rn);
}