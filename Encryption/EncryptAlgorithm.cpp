#include <string>
#include <iostream>
#include <vector>
#include <fstream> 
#include "Vigenere.h"
#include "DES.h"
#include "RSA.h"
#include "MD5.h"
#include "DSS.h"
using namespace std;
void printHead();
void dss();
void vigenere();
void md5();
void rsa();
void des();
string getText(string filename);
void writeCiphertext(string ciphertext, string fileName);
int main()
{
	printHead();
	int a;
	while (cin>>a)
	{
		switch (a)
		{
		case 1:vigenere(); break;
		case 2:des(); break;
		case 3:rsa(); break;
		case 4:md5(); break;
		case 5:dss(); break;
		default: 
			break;
		}
		if (a==6)
		{
			cout << "谢谢使用" << endl;
			break;
		}
		system("pause");
		system("cls");
		printHead();
	}
	system("pause");
	return 0;
}

void printHead() {
	cout << "---------------------------------------" << endl;
	cout << "-            1.Vigenere加密算法       -" << endl;
	cout << "-            2.DES加密算法            -" << endl;
	cout << "-            3.RSA加密算法            -" << endl;
	cout << "-            4.MD5加密算法            -" << endl;
	cout << "-            5.DSS签名算法            -" << endl;
	cout << "-            6.退出                   -" << endl;
	cout << "---------------------------------------" << endl;
	cout << "明文内容为："+ getText("plaintext.txt") +"\n" << endl;
	cout << "选择：";
}

void dss() {
	cout << "\n***  DSS加密算法  ***" << endl;
	cout << "随机生产公钥私钥对:" << endl;
	DSS d(1,"1");
	d.generateKey();
	d.signature(getText("plaintext.txt"));
	cout << "公钥签名后签名为(r,s)：" << "(" << d.r << "," << d.s << ")" << endl;
	writeCiphertext(d.sig, "ciphertext.dss");
	cout << "签名验证：" << endl;
	d.verify(getText("plaintext.txt"));
	cout << "签名已写入 ciphertext.dss 文件" << endl;
}

void vigenere() {
	string keyword;
	cout << "\n***  Vigenere加密算法  ***" << endl;
	cout << "输入密钥(一个英文单词):" << endl;
	cin >> keyword;
	Vigenere v(keyword);
	v.Encrypt(getText("plaintext.txt"));
	cout << "加密后密文为：" << v.ciphertext << endl;
	writeCiphertext(v.ciphertext, "ciphertext.vig");
	v.Decrypt(getText("ciphertext.vig"));
	cout << "解密后明文为：" << v.plaintext << endl;
	cout << "密文已写入 ciphertext.vig 文件" << endl;
}

void md5() {
	string keyword;
	cout << "\n***  MD5加密算法  ***" << endl;
	MD5 m;
	m.Encrypt(getText("plaintext.txt"));
	cout << "加密后密文为：" << m.ciphertext << endl;
	writeCiphertext(m.ciphertext, "ciphertext.md5");
	cout << "密文已写入 ciphertext.md5 文件" << endl;
}

void rsa() {
	string keyword;
	cout << "\n***  RSA加密算法  ***" << endl;
	cout << "随机生产公钥私钥对:" << endl;
	RSA r(1,1);
	r.generateKey();
	r.Encrypt(getText("plaintext.txt"));
	cout << "公钥加密后密文为：" << r.ciphertext << endl;
	writeCiphertext(r.ciphertext, "ciphertext.rsa");
	r.Decrypt(getText("ciphertext.rsa"));
	cout << "私钥解密后明文为：" << r.plaintext << endl;
	cout << "密文已写入 ciphertext.rsa 文件" << endl;
	
}

void des() {
	string keyword;
	cout << "\n***  DES加密算法  ***" << endl;
	cout << "输入密钥:" << endl;
	cin >> keyword;
	DES d(keyword);
	d.Encrypt(getText("plaintext.txt"));
	cout << "加密后密文为：" << d.ciphertext << endl;
	writeCiphertext(d.ciphertext, "ciphertext.des");
	d.Decrypt(getText("ciphertext.des"));
	cout << "解密后明文为：" << d.plaintext << endl;
	cout << "密文已写入 ciphertext.des 文件" << endl;
}

//读入文本
string getText(string filename) {
	ifstream infile(filename);
	string plaintext;
	getline(infile, plaintext);
	infile.close();
	return plaintext;
}

//创建并写入文本
void writeCiphertext(string ciphertext, string fileName) {
	ofstream outfile(fileName, ofstream::out);
	outfile << ciphertext;
	outfile.close();
}





