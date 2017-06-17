#include <string>
#include <iostream>
#include <vector>
#include "Vigenere.h"
#include "DES.h"
#include "RSA.h"
#include "MD5.h"
#include "DSS.h"
using namespace std;
int main()
{
	string plaintext = "hello nsfjnoiwjwljelk";
	string ciphertext = "";
	string keyword = "123456";  
	DSS dss;
	dss.generateKey();
	dss.signature(plaintext);
	dss.verify(plaintext);
	
	//cout << "密文是：" << endl;
	//cout << d.ciphertext << endl;
	//d.Decrypt(d.ciphertext);
	//cout << "明文是：" << endl;
	//cout << d.plaintext << endl;
	system("pause");
	return 0;
}



