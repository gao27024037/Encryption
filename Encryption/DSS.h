#ifndef DSS_H
#define DSS_H
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
class DSS
{
public:
	unsigned __int64 x;		//私钥
	unsigned __int64 y;		//公钥
	unsigned __int64 r;		//数字签名(r,s)
	unsigned __int64 s;

	DSS() {
	}

	DSS(unsigned __int64 xy, unsigned __int64 rr, unsigned __int64 ss) {
		x = y = xy;
		r = rr;
		s = ss;
	}

	void signature(string message) {
		srand(time(0));
		hash<std::string> h;
		unsigned __int64 k = rand() % q;	//k为随机数  0<k<q
		//unsigned __int64 HM = 1234;
		r = PowMod(g, k, p) % q;
		s = mod_reverse(k, q)*((h(message) + x*r) % q) % q;
	}

	void verify(string message) {
		hash<std::string> h;
		//unsigned __int64 HM = 1234;
		unsigned __int64 w = mod_reverse(s,q);
		unsigned __int64 u1 = h(message) * w % q;
		unsigned __int64 u2 = r * w % q;
		unsigned __int64 v = (PowMod(g, u1, p)*PowMod(y, u2, p) % p) % q;	//用了a*b % n = (a % n)*(b % n) % n
		if (v == r) {
			cout << "ture" << endl;
		}
	}

	//产生私钥x和公钥y
	void generateKey() {
		//0 < x < q;
		srand(time(0));
		x = rand() % q;
		y = PowMod(g, x, p);	//x为75时y为4567
		cout << "私钥:" << x << endl;
		cout << "公钥:" << y << endl;
	}

private:
	unsigned __int64 q = 101;
	unsigned __int64 p = q * 78 + 1;					// p = 7879	
	unsigned __int64 pMinus1Divideq = 78;				// (p - 1) / q
	unsigned __int64 h = 3;
	unsigned __int64 g = PowMod(h, pMinus1Divideq, p);	// g = 170

	//模乘运算，返回值 x=a*b mod n
	inline unsigned __int64 MulMod(unsigned __int64 a, unsigned __int64 b, unsigned __int64 n)
	{
		return a * b % n;
	}

	//模幂运算，返回值 x=base^pow mod n
	unsigned __int64 PowMod(unsigned __int64 &base, unsigned __int64 &pow, unsigned __int64 &n)
	{
		unsigned __int64    a = base, b = pow, c = 1;
		while (b)
		{
			while (!(b & 1))
			{
				b >>= 1;            //a=a * a % n;    //函数看起来可以处理64位的整数，但由于这里a*a在a>=2^32时已经造成了溢出，因此实际处理范围没有64位
				a = MulMod(a, a, n);
			}        b--;        //c=a * c % n;        //这里也会溢出，若把64位整数拆为两个32位整数不知是否可以解决这个问题。
			c = MulMod(a, c, n);
		}    return c;
	}
	//返回d=gcd(a,b);和对应于等式ax+by=d中的x,y
	long long extend_gcd(long long a, long long b, long long &x, long long &y) {
		if (a == 0 && b == 0) return -1;//无最大公约数
		if (b == 0) {
			x = 1; y = 0; return a;
		}
		long long d = extend_gcd(b, a%b, y, x);
		y -= a / b*x;
		return d;
	}

	//ax = 1(mod n) 求X   即: 求 1 / a % n
	long long mod_reverse(long long a, long long n) {
		long long x, y;
		long long d = extend_gcd(a, n, x, y);
		if (d == 1)
			return (x%n + n) % n;
		else return -1;
	}
};
#endif
