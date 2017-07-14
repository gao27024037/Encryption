# Encryption<br />
5种加密算法:Vigenere,DES,RSA,MD5,DSS<br />
Vigenere 密码算法<br />
A、<span style="white-space:pre">	</span>选定一个英文单词，将其中单词对应为1-26的数字数组作为密匙<br />
B、<span style="white-space:pre">	</span>将明文利用ASCII码转换为数字，并将密匙数字与其对应相加，循环，对26取余。<br />
C、<span style="white-space:pre">	</span>将所得数字密文转换为字符，即得密文。<br />
<br />
<br />
&nbsp;DES 对称密码算法&nbsp;<br />
A.<span style="white-space:pre">	</span>输入64位明文数据，并进行初始置换IP；<br />
B.<span style="white-space:pre">	</span>在初始置换IP后，明文数据再被分为左右两部分，每部分32位，以L0，R0表示；<br />
C.<span style="white-space:pre">	</span>在秘钥的控制下，经过16轮运算(f)；<br />
D.<span style="white-space:pre">	</span>16轮后，左、右两部分交换，并连接再一起，再进行逆置换；<br />
E.<span style="white-space:pre">	</span>输出64位密文。<br />
RSA 密码算法<br />
随机选择两个不相等的质数p和q。<br />
计算p和q的乘积n。<br />
计算n的欧拉函数φ(n)。<br />
随机选择一个整数a，条件是1&lt; e &lt; φ(n)，且e与φ(n) 互质。<br />
计算a对于φ(n)的模反元素b。<br />
将n和a封装成公钥，n和b封装成私钥。<br />
MD5 密码算法<br />
A、<span style="white-space:pre">	</span>填充：如果输入信息的长度(bit)对512求余的结果不等于448，就需要填充使得对512求余的结果等于448。填充的方法是填充一个1和n个0。填充完后，信息的长度就为N*512+448(bit)；<br />
B、<span style="white-space:pre">	</span>记录信息长度：用64位来存储填充前信息长度。这64位加在第一步结果的后面，这样信息长度就变为N*512+448+64=(N+1)*512位。<br />
C、<span style="white-space:pre">	</span>装入标准的幻数（四个整数）：标准的幻数（物理顺序）是（A=(01234567)16，B=(89ABCDEF)16，C=(FEDCBA98)16，D=(76543210)16）<br />
四轮循环运算：循环的次数是分组的个数（N+1）&nbsp;<br />
1）将每一512字节细分成16个小组，每个小组64位（8个字节）<br />
2）先认识四个线性函数(&amp;是与,|是或,~是非,^是异或)<br />
&nbsp; F(X,Y,Z)=(X&amp;Y)|((~X)&amp;Z)<br />
&nbsp; G(X,Y,Z)=(X&amp;Z)|(Y&amp;(~Z))<br />
&nbsp; H(X,Y,Z)=X^Y^Z<br />
&nbsp; I(X,Y,Z)=Y^(X|(~Z))<br />
DSS 签名算法<br />
DSS 的签名过程如下：<br />
&nbsp;r=(gkmod p)mod q<br />
&nbsp;s=[k-1(H(M)+xr)] mod q 　<br />
则形成了对信息 M 的数字签名(r,s)，数字签名和信息 M 一同发送给接收方。 接收方接收到信息 M’和数字签名(r’,s’)后，对数字签名的验证过程如下：<br />
&nbsp;w=(s’)-1 mod q&nbsp;<br />
u1=[H(M’)w] mod q,&nbsp;<br />
u2=( r’)wmod q　&nbsp;<br />
v=[(gu1 yu2)mod p] mod q&nbsp;<br />
如果 v= r’,则说明信息确实来自发送方。
