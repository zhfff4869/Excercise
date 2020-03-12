#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#define eps 1e-6 
#define PI 3.14159265354
typedef std::complex<double> complex_t;
using namespace std;

//��ת���ӵļ��� 
complex_t W(int k, int n, int N) {
	return complex_t(cos(2 * PI*k*n / N), -sin(2 * PI*k*n / N));
}

//��ʽ�� �� 
complex_t format(complex_t &c) {
	if (fabs(c.real()) < eps) c.real(0);
	if (fabs(c.imag()) < eps) c.imag(0);
	return c;
}

double format(double &c) {
	if (fabs(c) < eps) c = 0;
	return c;
}

//��ɢ���е�DFT����,ֻ���ʵ������ ,��ȫ����DFT�Ĺ�ʽ������,O(n^2)�ĸ��Ӷ�
void DFT(vector<double> &x_n, vector<complex_t> &X_k) {
	X_k.clear();
	int N = x_n.size();
	for (int k = 0; k < N; ++k) {
		complex_t t(0, 0);
		for (int n = 0; n < N; ++n) {
			t += x_n[n] * W(k, n, N);
		}
		X_k.push_back(format(t));
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt == (int)sqrt(N)) {		//print \n every sqrt(N) outputs
			cout << endl;
			cnt = 0;
		}
		++cnt;
		cout << format(X_k[i]) << " ";
	}
	cout << endl;

}

//IDFT�ļ���,ֻ���ʵ������  
void IDFT(vector<complex_t> &X_k, vector<double> &x_n) {
	x_n.clear();
	int N = X_k.size();
	for (int n = 0; n < N; ++n) {
		complex_t t(0, 0);
		for (int k = 0; k < N; ++k) {
			t += X_k[k] * W(k, -n, N);
		}
		x_n.push_back(t.real() / N);//������ֻʣ��ʵ�� 
		//cout<<(t/(double)N)<<endl; 
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt == (int)sqrt(N)) {
			cout << endl;
			cnt = 0;
		}
		++cnt;
		cout << format(x_n[i]) << " ";
	}
	cout << endl;

}

void DFT_test() {
	int N = 64;
	vector<double> x_n(N);
	vector<complex_t> X_k(N);
	for (int i = 0; i < N; ++i) {
		x_n[i] = i;
	}
	DFT(x_n, X_k);
	IDFT(X_k, x_n);
}


//��֤N��2��n����,�򷵻�n
int bitlen(int N) {
	int n = 0;
	while ((N & 1) == 0) {	//��N��ĩλΪ0,��������λ��2��n���ݵ���ʽֻ��Ϊ10000...����n��0
		n++;
		N >>= 1;
	}
	return n;	//Ϊɶ��ֱ���ø�log2()����������Ӧ����Ϊ�˼ӿ���㣬��Ϊ��λ�����ȵ��ú�����ö�
}


int reverse_bit(int n, int len) {//bit��ת 
	int tmp = 0;
	while (len--) {
		tmp += ((n & 1) << len);
		n >>= 1;
	}
	return tmp;

}

//�������� 
void resort(vector<complex_t> &x_n, int N) {
	vector<complex_t> v(x_n);
	int len = bitlen(N);
	for (int i = 0; i < N; ++i) {
		x_n[i] = v[reverse_bit(i, len)];
	}
}


//��2Ƶ���ѡ��,FFT�㷨ʵ��,O(nlogn)�ĸ��Ӷ�
void FFT(vector<complex_t> &x_n) {
	int N = x_n.size();
	int temp=pow(2,ceil(log2(N)));	//�����в���2���ݣ����Զ���0��ȫ
	if (temp > N)
	{
		for (int i = N; i < temp; i++)
			x_n.push_back(0);
		N = temp;
	}
	int r = bitlen(N);

	vector<complex_t> W(N);

	//Ԥ�ȼ�����ת���� 
	for (int i = 0; i < N; ++i) {	//�൱����vector����һ��ӳ��,���溯������,i�����Ա���
		double angle = -i * 2 * PI / N;
		W[i] = complex_t(cos(angle), sin(angle)); //Ԥ�ȼ���Ӧ��Ҳ��Ϊ�˱�����ú������ӿ����
	}


	for (int k = 0; k < r; ++k) {//�������� 
		for (int j = 0; j < (1 << k); ++j) {	//1<<k==2^k,attention:k begin from 0
			int butterfly = 1<<(r - k);		//j��k�����������еĵڼ����棬butter��ÿ�������ĵ���
			int p = j * butterfly;	//p�ǵ�j�����������ĳ�ʼλ�ã�Ҳ�����ϰ벿�ֵĳ�ʼλ��
			int s = p + butterfly / 2;	//s�ǵ�j�������������°벿�ֵĳ�ʼλ��
			for (int i = 0; i < butterfly / 2; ++i) {
				complex_t c = x_n[i + p] + x_n[i + s];	//�µ�ֵ���Ǿɵ�ֵ��������Ҫ��ʱ����
				x_n[i + s] = (x_n[i + p] - x_n[i + s])*W[i*(1 << k)];
				x_n[i + p] = c;
			}
		}
	}

	//�������� 
	resort(x_n, N);
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt == (int)sqrt(N)) {
			cout << endl;
			cnt = 0;
		}
		++cnt;
		cout << format(x_n[i]) << " ";

	}
	cout << endl;
}

//IFFT,��FFT����һ�� 
void IFFT(vector<complex_t> &x_n) {
	int N = x_n.size();
	int r = bitlen(N);

	vector<complex_t> W(N);

	//Ԥ�ȼ�����ת���� 
	for (int i = 0; i < N; ++i) {
		double angle = i * 2 * PI / N;//IFFT����ת������FFT����ת���Ӳ�һ������ 
		W[i] = complex_t(cos(angle), sin(angle));
	}


	for (int k = 0; k < r; ++k) {//�������� 
		for (int j = 0; j < (1 << k); ++j) {
			int butterfly = 1 << (r - k);
			int p = j * butterfly;
			int s = p + butterfly / 2;
			for (int i = 0; i < butterfly / 2; ++i) {
				complex_t c = x_n[i + p] + x_n[i + s];
				x_n[i + s] = (x_n[i + p] - x_n[i + s])*W[i*(1 << k)];
				x_n[i + p] = c;
			}
		}
	}

	//�������� 
	resort(x_n, N);
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt == (int)sqrt(N)) {
			cout << endl;
			cnt = 0;
		}
		++cnt;
		x_n[i] /= N;//IFFT��FFT����һ��ϵ�� 
		cout << format(x_n[i]) << " ";
	}
	cout << endl;
}

void FFT_test() {
	int N = 60;
	vector<complex_t> x_n;
	complex_t c(0, 0);
	for (int i = 1; i <= N; ++i) {
		c.real(i);
		x_n.push_back(c);
	}

	FFT(x_n);
	IFFT(x_n);
}


int main() {
	//DFT_test();
	cout << endl;
	FFT_test();
	system("pause");
	return 0;
}