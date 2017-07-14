#ifndef RSA_H
#define RSA_H
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class RSA
{
public:
	string plaintext = "";
	string ciphertext = "";
	unsigned __int64 p;			//素数p
	unsigned __int64 q;			//素数q
	unsigned __int64 n;			//n=p*q
	unsigned __int64 b;			//a对于φ(n)的模反元素
	unsigned __int64 a = 65537;
	RSA(int nn, int ab) {
		n = nn;
		b = a = ab;
	}

	string Encrypt(string plaintext) {
		unsigned __int64 num;
		unsigned __int64 N;
		char cnum[7];
		string s;
		for (int i = 0; i < plaintext.size(); i += 2)
		{
			//把2个char用ASCII表转化在一起构成一个6位数字
			num = plaintext[i] * 1000 + plaintext[i + 1];
			N = PowMod(num, a, n);
			sprintf_s(cnum, "%d", N);
			s = cnum;
			while (s.size() < 6)		//若不够6位则在前面补0
			{
				s = "0" + s;
			}
			ciphertext += s;		//把6位数字存入密文
		}
		return ciphertext;
	}

	string Decrypt(string ciphertext) {
		unsigned __int64 num;
		int aa;
		unsigned __int64 N;
		char cnum[7];
		string s ="";
		for (int i = 0; i < ciphertext.size(); i += 6)
		{
			//把秘文中每6位拿出来做解密，得到一个6位数，前3位为一个char，后3位为一个char
			strcpy(cnum, ciphertext.substr(i, 6).c_str());
			sscanf(cnum, "%d", &aa);
			N = aa;
			num = PowMod(N, b, n);
			plaintext += char(num / 1000);
			plaintext += char(num % 1000);
		}
		return plaintext;
	}

	//产生私钥和公钥
	void generateKey() {
		//私钥：(n,a)
		a = 65537;
		srand(time(0));
		p = prime[rand() % 90];
		q = prime[rand() % 90];
		n = p * q;
		b = mod_reverse(a, (p - 1)*(q - 1));
		cout << "公钥:" << "(" << n << "," << a <<")"<< endl;
		cout << "私钥:" << "(" << n << "," << b << ")" << endl;
	}

private:
	//三位素数 从这里面取
	int prime[90] = { 401, 409, 419, 421, 431, 433, 439,
		443, 449, 457, 461, 463, 467, 479, 487, 491, 499,
		503, 509, 521, 523, 541, 547, 557, 563, 569, 571,
		577, 587, 593, 599, 601, 607, 613, 617, 619, 631,
		641, 643, 647, 653, 659, 661, 673, 677, 683, 691,
		701, 709, 719, 727, 733, 739, 743, 751, 757, 761,
		769, 773, 787, 797, 809, 811, 821, 823, 827, 829,
		839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
		911, 919, 929, 937, 941, 947, 953, 967, 971, 977,
		983, 991, 997 };

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
		if(b==0) {
			x=1;y=0;return a;
		}
		long long d=extend_gcd(b,a%b,y,x);
		y-=a/b*x;
		return d;
	}
	//ax = 1(mod n) 求X
	long long mod_reverse(long long a, long long n) {
		long long x, y;
		long long d = extend_gcd(a, n, x, y);
		if (d == 1)
			return (x%n + n) % n;
		else return -1;
	}
};
#endif
