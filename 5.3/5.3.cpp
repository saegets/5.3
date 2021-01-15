#include <iostream>
#include <cmath>

using namespace std;

double h(const double x);

int main()
{
	double qp, qk, z;
	int n;

	cout << "gp = "; cin >> qp;
	cout << "gk = "; cin >> qk;
	cout << "n = "; cin >> n;
	
	double dq = (qk - qp) / n;
	double q = qp;
	while (q <= qk)
	{
		z = h(q + 1) + h(q * q + 1) + pow(h(q * q), 2);
		cout << q << " " << z << endl;
		q += dq;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1)
		return cos(x + 1) / pow(cos(x + 1), 2);
	
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = x * x / ((2 * i - 2) * (2 * i - 1) * 3 * i);
			a *= R;
			S += a;
		} while (i < 6); 
		S = 1 / cos(x) * S;
		return S;
	}
}