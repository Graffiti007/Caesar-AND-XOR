#include <iostream> 
#include <cmath> 
#include <clocale>
using namespace std;
struct data_xy
{
	double x, y;
};


class math_expression
{
	data_xy* data;
	double begin = 0;
	double end = 0;
	int size = 0;
public:
	int calculation(double a = 0.0, double b = 0.0, double c = 0.0);
	void PrintResults();
	void DeleteResults();
	friend ostream& operator<<(ostream&, const math_expression& s);
	math_expression operator+=(double a);
	friend math_expression operator+(double a, math_expression b);
	friend math_expression operator+(math_expression a, double b);
	math_expression() :data(0), size(0), begin(0), end(0) {};
	math_expression(const math_expression& s);
	~math_expression();
	math_expression(double a, double b, double c);
};

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Тест 1" << endl;
	math_expression t2(1.0, 10.0, 1.0);
	cout << t2 << endl;
	cout << endl;
	return 0;
}

math_expression::math_expression(double a, double b, double c)
{
	if (size != 0)
	{
		delete[] data;
		size = 0;
	}
	calculation(a, b, c);
}


math_expression::~math_expression()
{
	if (size != 0)
	{
		delete[] data;
		data = 0;
		size = 0;
	}
}

math_expression::math_expression(const math_expression& s)
{
	if (size != 0)
	{
		delete[] data;
		size = 0;
	}
	size = s.size;
	begin = s.begin;
	end = s.end;
	for (int i = 0; i < s.size; i++)
	{
		data[i].x = s.data[i].x;
		data[i].y = s.data[i].y;
	}
}

ostream& operator<<(ostream & f, const math_expression& s)
{
	if (s.size != 0)
	{
		int k = 1;
		for (int i = 0; i < s.size; i++)
		{
			if ((s.data[i].x >= s.begin) && (s.data[i].x <= s.end))
			{
				f << "x" << k << " = " << s.data[i].x << "   " << "y" << k << " = " << s.data[i].y << endl;
				k++;
			}
		}
	}
	else f << "Некорректное значение шага!" << endl;
	return f;
}

istream& operator>> (istream& is, math_expression& s)
{
	double a, b, c;
	is >> a >> b >> c;
	s.calculation(a, b, c);
	return is;
}

math_expression math_expression::operator+=(double a)
{
	begin += a;
	end += a;
	return *this;
}

math_expression operator+(double a, math_expression b)
{
	math_expression r = b;
	return r += a;
}

math_expression operator+(math_expression a, double b)
{
	math_expression r = a;
	return r += b;
}

int math_expression::calculation(double a, double b, double c)
{
	if (c <= 0.0)
	{
		size = 0;
		return size;
	}
	begin = a;
	end = b;
	int j = 0;
	double temp;
	double a2 = a, b2 = b;
	if (a2 < b2)
	{
		while (a2 <= b2)
		{
			a2 = a2 + c;
			j++;
		}
	}
	else
	{
		while (a2 >= b2)
		{
			a2 = a2 - c;
			j++;
		}
	}

	a2 = a;

	data = new data_xy[j];
	int k = 0;
	size = j;

	if (a2 < b2)
	{
		while (a2 <= b2)
		{
			temp = (pow(a2, 4)) - 6 * (pow(a2, 3));
			data[k].x = a2;
			data[k].y = temp;
			a2 = a2 + c;
			k++;
		}
	}
	else
	{
		while (a2 >= b2)
		{
			temp = (pow(a2, 4)) - 6 * (pow(a2, 3));
			data[k].x = a2;
			data[k].y = temp;
			a2 = a2 - c;
			k++;
		}
	}
	return size;
}

void math_expression::DeleteResults()
{
	if (size != 0)
	{
		delete[] data;
		size = 0;
	}
}