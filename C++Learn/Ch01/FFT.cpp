// FFT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include <complex>
#include <cstring> 
#include <cstdio> 
#include <cstdlib>
#include <cmath>
#include<windows.h>
using namespace std;

void fft(complex<double>* TD, complex<double>* FD, int m)//m为log2N，即迭代次数
{
	int	n;				        // 
	int	i, j, k;				// 循环变量
	int	bfsize, p;              //？
	double angle;				// 角度	
	complex<double>* W, * X1, * X2, * X;
	double PI = 3.14159265358979323846;
	n = 1 << m;				// 计算付立叶变换点数
	//将二进制数左移m位，右边补零； n=2^m

	// 分配运算所需存储器
	W = new complex<double>[n / 2];
	X1 = new complex<double>[n];
	X2 = new complex<double>[n];

	// 计算加权系数
	for (i = 0; i < n / 2; i++)
	{
		angle = -i * PI * 2 / n;
		W[i] = complex<double>(cos(angle), sin(angle));
	}

	// 将时域点写入X1
	memcpy(X1, TD, sizeof(complex<double>) * n);

	// 采用蝶形算法进行快速付立叶变换
	for (k = 0; k < m; k++)//k为蝶形运算的级数
	{
		for (j = 0; j < 1 << k; j++)	//k级蝶形运算2^k个叉的第j个,注意这个叉是个总体形状
		{								// ///\\\交叉起来的感觉,只是到最后才会变成X
			bfsize = 1 << (m - k);//蝶形运算的叉包含的点数,就等于2^m/2^k,2^m是总的点数
			for (i = 0; i < bfsize / 2; i++)	//bfsize/2即是大叉包含的小叉的个数
			{
				p = j * bfsize;		//叉[j]的起始位置
				X2[i + p] = X1[i + p] + X1[i + p + bfsize / 2];
				X2[i + p + bfsize / 2] = (X1[i + p] - X1[i + p + bfsize / 2])
					* W[i * (1 << k)];
			}
		}
		X = X1;
		X1 = X2;	//X作为临时变量似乎多余
		X2 = X;
	}
	// 重新排序
	for (j = 0; j < n; j++)
	{
		p = 0;
		for (i = 0; i < m; i++)
		{
			if (j & (1 << i))
			{
				p += 1 << (m - i - 1);
			}
		}
		FD[j] = X1[p];
	}

	delete W;
	delete X1;
	delete X2;
};
void ifft(complex<double>* TD, complex<double>* FD, int m)//m为log2N，即迭代次数
{
	int	N = 1 << m;			   //将二进制数左移m位，右边补零； N=2^m
	int	i, j, k;				// 循环变量
	int	bfsize, p;              //？
	double angle;				// 角度	
	complex<double>* W, * X1, * X2, * X;
	double PI = 3.14159265358979323846;
	double n = N;

	// 分配运算所需存储器
	W = new complex<double>[N / 2];
	X1 = new complex<double>[N];
	X2 = new complex<double>[N];

	// 计算加权系数
	for (i = 0; i < N / 2; i++)
	{
		angle = i * PI * 2 / N;
		W[i] = complex<double>(cos(angle), sin(angle));
	}

	// 将时域点写入X1
	memcpy(X1, TD, sizeof(complex<double>) * N);

	// 采用蝶形算法进行快速付立叶变换
	for (k = 0; k < m; k++)//k为蝶形运算的级数
	{
		for (j = 0; j < 1 << k; j++)
		{
			bfsize = 1 << (m - k);//做蝶形运算两点间距离
			for (i = 0; i < bfsize / 2; i++)
			{
				p = j * bfsize;
				X2[i + p] = X1[i + p] + X1[i + p + bfsize / 2];
				X2[i + p + bfsize / 2] = (X1[i + p] - X1[i + p + bfsize / 2])
					* W[i * (1 << k)];
			}
		}
		X = X1;
		X1 = X2;
		X2 = X;
	}
	// 重新排序
	for (j = 0; j < N; j++)
	{
		p = 0;
		for (i = 0; i < m; i++)
		{
			if (j & (1 << i))
			{
				p += 1 << (m - i - 1);
			}
		}
		FD[j] = X1[p]/n;
	}

	delete W;
	delete X1;
	delete X2;
};
int mi(int n)            //求大于等于n的最小整数次幂
{
	//int t = 1, i = 0;
	//while (t < n)
	//{
	//	t = t * 2;
	//	i++;
	//}
	int i = ceil(log2(n));
	return i;
};
void zero(complex<double>* a, complex<double>* b,int s,int N)    //对序列a的第s个元素后补零
{
	for (int j = 0;j < N;j++)
	{
		if (j < s)
		{
			b[j] = a[j];
		}
		else
			b[j] = 0;
	}
}
void conv(complex<double>* a, complex<double>* b, int NA, int NB)  //卷积
{
	int NC = NA + NB - 1;	//卷积后的总长度
	complex<double>* c = new complex<double>[NC];
	//memset(c, 0, sizeof(int) * NC);
	for (int n = 0;n < NC;n++)
	{
		for (int k = 0;k < NA;k++)
		{
			int bindex = n - k;
			if (bindex >= 0 && bindex < NB)	//去掉b[bindex]==0的情况，加快计算
			{
				c[n] += a[k] * b[bindex];
			}
		}
	}
	for (int n = 0;n < NC;n++) 
	{
		cout << c[n] << " ";
	}
		
};

int main()
{
	//输入序列长度
	int sx,sh;
	cout << "size of x(n):";
	cin >> sx;
	cout << "size of h(n):";
	cin >> sh;
	//输入序列
	complex<double>* p = new complex<double>[sx];      //指针p 指向输入序列的x(0) 
	complex<double>* q = new complex<double>[sh];      //指针q 指向输入序列的h(0)
	cout << "please input x(n):\n";
	for (int i = 0; i < sx; i++)
	{
		cin >> p[i];
	}
	cout << "please input h(n):\n";
	for (int i = 0; i < sh; i++)
	{
		cin >> q[i];
	}

	int n = sx + sh - 1;
	int m = mi(n);        //m是两个输入序列做FFT的点数
	int N = 1 << m;       //N=2^m

	//计算卷积
	cout << "The convolution of x(n) and h(n):\n";
	LARGE_INTEGER frequency, st1, fn1,st2,fn2;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&st1);           //开始计时,精度<1us
	//double st1= GetTickCount64();     最小精度是15ms，太大了
	conv(p, q, sx, sh);
	//double fn1 = GetTickCount64();
	QueryPerformanceCounter(&fn1);        //结束计时
	cout << "\n";

	//序列补零
	QueryPerformanceCounter(&st2);
	complex<double>* x = new complex<double>[N];    //xn序列补零后
	complex<double>* h = new complex<double>[N];    //hn序列补零后
	zero(p, x, sx, N);
	zero(q, h, sh, N);
	free(p);
	free(q);

	//计算补零后两输入序列的FFT
	complex<double>* xf = new complex<double>[N];      //指针pf 指向输入序列xn的FFT 
	complex<double>* hf = new complex<double>[N];      //指针qf 指向输入序列hn的FFT
	fft(x, xf, m);
	fft(h, hf, m);
	free(x);
	free(h);

	//两FFT序列相乘
	complex<double>* c = new complex<double>[N];
	for (int i = 0; i < N; i++)
	{
		c[i] = xf[i] * hf[i];
	}

	complex<double>* y = new complex<double>[N];      //结果y
	ifft(c, y, m);
	QueryPerformanceCounter(&fn2);
	free(c);
	cout << "The IFFT[X(k)*H(k)]:\n";
	for (int i = 0; i < N; i++) {
		cout << y[i] << " ";
	}

	//输出运行时间
	//cout << "\n卷积运行时间: " << fn1 - st1 << "ms";
	cout <<"\n卷积运行时间: " << (double)(fn1.QuadPart - st1.QuadPart) / frequency.QuadPart << "\n";
	cout << "利用FFT计算卷积的运行时间：" << (double)(fn2.QuadPart - st2.QuadPart) / frequency.QuadPart << endl;


	//int m;           //m为满足：2^m<=s的最大数；
	//int ss = s;     //ss是原始输入序列长度，s作为补零后长度
	////以下 判断s是否为2的整数次幂（t=0表示是，t=1表示不是） & 如果s是2的整数次幂，求次数m
	//int t; 
	//if (s == 1)
	//{
	//	m = 0; t = 0;
	//}
	//else
	//{
	//	int j = 1;
	//	while (s / 2 != 1)
	//	{
	//		if (s % 2 != 0)
	//		{
	//			break;
	//		}
	//		else
	//			s = s / 2; j++;
	//	}
	//	if (s % 2 == 0)
	//	{
	//		t = 0; m = j;
	//	}
	//	else
	//		t = 1;
	//}

	////如果s不是2的整数次幂，求m
	//if(t==1)
	//{
	//	int j = 1;
	//	s = ss;
	//	while (s / 2 != 1)
	//	{
	//		s = s / 2;j++;
	//	}
	//	m = j;
	//}
 //   cout << t <<" "<<m;

	//对序列末尾补零,求傅里叶变换
	//if(t != 0)  //s不是2的整数次幂
	//{
	//	int q = 1;
	//	for (int j = 0;j < m;j++)
	//	{
	//		q = 2 * q;
	//	}
	//	s = 2 * q;
		//complex<double>* b = new complex<double>[s];    //指针b 补零后序列
		//for (int j = 0;j < s;j++)
		//{
		//	if (j < ss)
		//	{
		//		b[j] = x[j];
		//	}
		//	else
		//		b[j] = 0;
		//}
	//	x = b;
	//	complex<double>* y = new complex<double>[s];   //傅里叶变换后序列
	//	fft(x, y, m+1);
	//	//输出序列
	//	for (int i = 0; i < s; i++) {
	//		cout << y[i] << " ";
	//	}
	//}
	//else
	//{
	//	complex<double>* y = new complex<double>[ss];   //傅里叶变换后序列
	//	fft(x, y, m);
	//	//输出序列
	//	for (int i = 0; i < ss; i++) {
	//		cout << y[i] << " ";
	//	}
	//}
	//

	
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
