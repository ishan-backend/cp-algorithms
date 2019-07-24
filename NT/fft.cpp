// Part-1. http://codeforces.com/blog/entry/43499
// Part-2. http://codeforces.com/blog/entry/48798
// https://habr.com/en/post/113642/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
//const long double PI = acos(-1.0);
#define PI 3.14159265358979323846

//Step1 FFT: Time Complexity: nlogn
vector<complex<double>> fft(vector<int> a)
{
	int n = (int)a.size();
	if(n<=1)
		return a;
	//Dividing a into a0 and a1 as even and odd

	vector<complex<double>> a0(n/2), a1(n/2);

	for(int i=0; i<n/2; i++)
	{
		a0[i] = a[2*i];
		a1[i] = a[2*i + 1];
	}

	//Divide Step
	//Recursively calling fft on polynomial of degree 2
	a0 = fft(a0);
	a1 = fft(a0);

	double ang = 2*PI/n;

	//defining w1 and wn
	complex<double> w(1), wn(cos(ang), sin(ang));

	for(int i=0; i<n/2; i++)
	{
		//for powers of k<=n/2
		a[i] = a0[i] + w*a1[i];
		//for powers of k>n/2
		a[i+(n/2)] = a0[i] - w*a1[i];
		//updating value of wk
		w*=wn;
	}
	return a;

}

//Step3 Inverse FFT->given a vector restore itback to point form
vector<complex<double>> inv_fft(vector<complex<double>> y)
{
	int n = y.size();
	if(n>=1)
	{
		return y;
	}
	vector<complex<double>> y0(n/2), y1(n/2);
	for(int i=0; i<n/2; i++)
	{
		y0[i] = y[2*i];
		y1[i] = y[2*i + 1];
	}
	y0 = inv_fft(y0);
	y1 = inv_fft(y1);
	double ang = 2* PI/n * -1;
	complex<double> w(1), wn(cos(ang), sin(ang));
	for(int i=0; i<n/2; i++)
	{
		y[i] = y0[i] + w*y1[i];
		y[i+ n/2] = y0[i] - w*y1[i];
		y[i] /=2;
		y[i + n/2] /= 2;
		w*= wn;
	}

	/* 
		each elemnt of the result is divided by 2
		assume that division by 2 will take place at each level of recursion
		then eventually just turns out that all the elemnts are _____ into n
	*/
	return y;
}

//Step2 Convolution: time complexity O(n) without the time for calculating fft()
void multiply(vector<int> a,vector<int> b)
{
	vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());

	int n=1;
	//resizing n as power of 2
	while(n < max(a.size(), b.size()))
	{
		n<<=1; //right shift or multiply by 2
	}
	//again do right shift so that n is greater than max
	n<<=1;

	//cout<<n<<endl;

	fa.resize(n);
	fb.resize(n);
	//Calling FFT on polynomial A and B
	//fa and fb denotes point form

	fa = fft(fa);
	fb = fft(fb);

	//Convolution Step
	for(int i=0; i<n; i++)
	{
		fa[i] = fa[i] * fb[i];
	}

	//Converting fa from coefficient back to point form
	fa = inv_fft(fa);
	return;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string x, string y;
		vector<int> a, b;
		cin>>x>>y;
		for(int i=0; i<x.length(); i++)
		{
			a.push_back((int)(x[i] - '0'));
		}

		for(int i=0; i<y.length(); i++)
		{
			b.push_back((int)(y[i] - '0'));
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		multiply(a, b);

		//do all extra additions according to problem in multiply function

	}
	return 0;
}
