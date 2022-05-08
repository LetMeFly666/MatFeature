/*
 * @Author: LetMeFly
 * @Date: 2022-05-08 13:42:41
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-05-08 13:42:41
 */
#ifndef FFT_H
#define FFT_H

#include <cmath>
#include <vector>


#define pi 3.1415926
using namespace std;

struct My_Complex {
	double real;
	double imag; //a:real b:Imagine
};


class My_FFT {

public:
	My_FFT();
	~My_FFT();

	
	vector<My_Complex> FFT(vector<double>& res);
	//返回对应频率和幅值
	vector<pair<double, double>> abs_FFT();

	//复数求和
	My_Complex comp_plus(My_Complex u, My_Complex v);

	//复数相乘
	My_Complex comp_times(My_Complex u, My_Complex v);
	//复数相减
	My_Complex comp_minus(My_Complex u, My_Complex v);
	//序数重排
	void rev();
	My_Complex Wn(double A, double B);
	void fft1(int l, int r, int len);
public:
	int N;						//Num of Sample Nodes
	double fs=512;					//Sample frequency
	vector<My_Complex> x, u, W;
	double f0;
};

My_FFT::My_FFT() {

}
My_FFT::~My_FFT() {

}


vector<My_Complex> My_FFT::FFT(vector<double>& res) {

	this->N = int(res.size());
	this->fs = fs;
	this->f0 = fs / N;

	My_Complex temp;

	for (int i = 0; i < N; i++) {

		u.push_back(temp);
		temp.real = res[i];
		temp.imag = 0;
		
		x.push_back(temp);
		
		W.push_back(Wn(N, i));//e^-j((2*pi*i)/N)
	}

	this->rev(); //reverse the original order 
	this->fft1(0, N - 1, N);


	return x;
}

vector<pair<double, double>> My_FFT::abs_FFT() {

	vector<pair<double, double>> ret;

	for (int i = 0; i < N ; i++) {
		double u, f;
		u = sqrt(x[i].real * x[i].real + x[i].imag * x[i].imag)*2/N;
		f = double(i) * f0;
		ret.push_back({ f ,u });
	}

	return ret;
}




//复数求和
My_Complex My_FFT::comp_plus(My_Complex u, My_Complex v) {
	My_Complex e;
	e.real = u.real + v.real;
	e.imag = u.imag + v.imag;
	return e;
}

//复数相乘
My_Complex My_FFT::comp_times(My_Complex u, My_Complex v) {
	My_Complex e;
	e.real = u.real * v.real - u.imag * v.imag;
	e.imag = u.real * v.imag + u.imag * v.real;
	return e;
}

//复数相减
My_Complex My_FFT::comp_minus(My_Complex u, My_Complex v) {
	My_Complex e;
	e.real = u.real - v.real; e.imag = u.imag - v.imag;
	return e;
}


//序数重排
void My_FFT::rev() { //reverse the sequence in bit order.  
	int len = log2(N);
	int idd, ret, bit;
	for (int i = 0; i < N; i++) {
		idd = i; ret = 0;
		for (int j = 0; j < len; j++) {
			ret = ret << 1;
			bit = idd & 1;
			idd = idd >> 1;
			ret = bit | ret;
		}
		u[i] = x[ret];
	}
	for (int i = 0; i < N; i++)
		x[i] = u[i];
}

My_Complex My_FFT::Wn(double A, double B) {
	My_Complex u;
	u.real = cos((2 * pi / A) * B); 
	u.imag = -sin((2 * pi / A) * B);
	return u;
}

void My_FFT::fft1(int l, int r, int len) {
	My_Complex tmp;
	int n = len / 2;
	if (len < 2) return; //Level 1 

	fft1(l, l + n - 1, n); //even seg process 
	fft1(l + n, r, n);	//odd seg process

	for (int i = l; i <= r; i++) {
		if (i < l + n) {
			u[i] = comp_plus(x[i], comp_times(W[(i - l) * (N / len)], x[i + n]));
		}
		else {
			x[i] = comp_minus(x[i - n], comp_times(x[i], W[(i - n - l) * (N / len)]));
			x[i - n] = u[i - n];
		}
	}
	return;
}

#endif