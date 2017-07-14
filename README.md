# Encryption
5种加密算法:Vigenere,DES,RSA,MD5,DSS
<h2>
	<a name="_Toc485547453">Vigenere </a>密码算法
</h2>
<p align="left">
	A、&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;选定一个英文单词，将其中单词对应为1-26的数字数组作为密匙
</p>
<p align="left">
	B、&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;将明文利用ASCII码转换为数字，并将密匙数字与其对应相加，循环，对26取余。
</p>
<p align="left">
	C、&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;将所得数字密文转换为字符，即得密文。
</p>
<p align="left">
	&nbsp;
</p>
<h2>
	&nbsp;<a name="_Toc485547454">DES </a>对称密码算法 
</h2>
<p>
	<span style="color:#555555;">A.&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color:#555555;">输入</span><span style="color:#555555;">64</span><span style="color:#555555;">位明文数据，并进行初始置换</span><span style="color:#555555;">IP</span><span style="color:#555555;">；</span>
</p>
<p>
	<span style="color:#555555;">B.&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color:#555555;">在初始置换</span><span style="color:#555555;">IP</span><span style="color:#555555;">后，明文数据再被分为左右两部分，每部分</span><span style="color:#555555;">32</span><span style="color:#555555;">位，以</span><span style="color:#555555;">L0</span><span style="color:#555555;">，</span><span style="color:#555555;">R0</span><span style="color:#555555;">表示；</span>
</p>
<p>
	<span style="color:#555555;">C.&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color:#555555;">在秘钥的控制下，经过</span><span style="color:#555555;">16</span><span style="color:#555555;">轮运算</span><span style="color:#555555;">(f)</span><span style="color:#555555;">；</span>
</p>
<p>
	<span style="color:#555555;">D.&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color:#555555;">16</span><span style="color:#555555;">轮后，左、右两部分交换，并连接再一起，再进行逆置换；</span>
</p>
<p>
	<span style="color:#555555;">E.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style="color:#555555;">输出</span><span style="color:#555555;">64</span><span style="color:#555555;">位密文。</span>
</p>
<h2>
	<a name="_Toc485547455">RSA </a>密码算法
</h2>
<p>
	<strong><span style="color:#111111;">随机选择两个不相等的质数</span><span style="color:#111111;">p</span><span style="color:#111111;">和</span><span style="color:#111111;">q</span><span style="color:#111111;">。</span></strong>
</p>
<p>
	<strong><span style="color:#111111;">计算</span><span style="color:#111111;">p</span><span style="color:#111111;">和</span><span style="color:#111111;">q</span><span style="color:#111111;">的乘积</span><span style="color:#111111;">n</span><span style="color:#111111;">。</span></strong>
</p>
<p>
	<strong><span style="color:#111111;">计算</span><span style="color:#111111;">n</span><span style="color:#111111;">的欧拉函数</span><span style="color:#111111;">φ(n)</span><span style="color:#111111;">。</span></strong>
</p>
<p>
	<strong><span style="color:#111111;">随机选择一个整数</span><span style="color:#111111;">a</span><span style="color:#111111;">，条件是</span><span style="color:#111111;">1&lt; e &lt; φ(n)</span><span style="color:#111111;">，且</span><span style="color:#111111;">e</span><span style="color:#111111;">与</span><span style="color:#111111;">φ(n) </span><span style="color:#111111;">互质。</span></strong>
</p>
<p>
	<strong><span style="color:#111111;">计算</span><span style="color:#111111;">a</span><span style="color:#111111;">对于</span><span style="color:#111111;">φ(n)</span><span style="color:#111111;">的模反元素</span><span style="color:#111111;">b</span><span style="color:#111111;">。</span></strong>
</p>
<p>
	<strong><span style="color:#111111;">将</span><span style="color:#111111;">n</span><span style="color:#111111;">和</span><span style="color:#111111;">a</span><span style="color:#111111;">封装成公钥，</span><span style="color:#111111;">n</span><span style="color:#111111;">和</span><span style="color:#111111;">b</span><span style="color:#111111;">封装成私钥。</span></strong>
</p>
<h2>
	<a name="_Toc485547456">MD5 </a>密码算法
</h2>
<p align="left">
	A、<span style="color:#333333;">填充：如果输入信息的长度</span><span style="color:#333333;">(bit)</span><span style="color:#333333;">对</span><span style="color:#333333;">512</span><span style="color:#333333;">求余的结果不等于</span><span style="color:#333333;">448</span><span style="color:#333333;">，就需要填充使得对</span><span style="color:#333333;">512</span><span style="color:#333333;">求余的结果等于</span><span style="color:#333333;">448</span><span style="color:#333333;">。填充的方法是填充一个</span><span style="color:#333333;">1</span><span style="color:#333333;">和</span><span style="color:#333333;">n</span><span style="color:#333333;">个</span><span style="color:#333333;">0</span><span style="color:#333333;">。填充完后，信息的长度就为</span><span style="color:#333333;">N*512+448(bit)</span><span style="color:#333333;">；</span>
</p>
<p align="left">
	B、 <span style="color:#333333;">记录信息长度：用</span><span style="color:#333333;">64</span><span style="color:#333333;">位来存储填充前信息长度。这</span><span style="color:#333333;">64</span><span style="color:#333333;">位加在第一步结果的后面，这样信息长度就变为</span><span style="color:#333333;">N*512+448+64=(N+1)*512</span><span style="color:#333333;">位。</span>
</p>
<p align="left">
	C、<span style="color:#333333;">装入标准的幻数（四个整数）：标准的幻数（物理顺序）是（</span><span style="color:#333333;">A=(01234567)<sub>16</sub></span><span style="color:#333333;">，</span><span style="color:#333333;">B=(89ABCDEF)<sub>16</sub></span><span style="color:#333333;">，</span><span style="color:#333333;">C=(FEDCBA98)<sub>16</sub></span><span style="color:#333333;">，</span><span style="color:#333333;">D=(76543210)<sub>16</sub></span><span style="color:#333333;">）</span>
</p>
<p align="left">
	<span style="color:#333333;">四轮循环运算：循环的次数是分组的个数（</span><span style="color:#333333;">N+1</span><span style="color:#333333;">）</span><span style="color:#333333;">&nbsp;<br />
	1</span><span style="color:#333333;">）将每一</span><span style="color:#333333;">512</span><span style="color:#333333;">字节细分成</span><span style="color:#333333;">16</span><span style="color:#333333;">个小组，每个小组</span><span style="color:#333333;">64</span><span style="color:#333333;">位（</span><span style="color:#333333;">8</span><span style="color:#333333;">个字节）</span><span style="color:#333333;"><br />
	2</span><span style="color:#333333;">）先认识四个线性函数</span><span style="color:#333333;">(&amp;</span><span style="color:#333333;">是与</span><span style="color:#333333;">,|</span><span style="color:#333333;">是或</span><span style="color:#333333;">,~</span><span style="color:#333333;">是非</span><span style="color:#333333;">,^</span><span style="color:#333333;">是异或</span><span style="color:#333333;">)</span>
</p>
<p align="left">
	&nbsp;&nbsp;F(X,Y,Z)=(X&amp;Y)|((~X)&amp;Z)<br />
	&nbsp;&nbsp;G(X,Y,Z)=(X&amp;Z)|(Y&amp;(~Z))<br />
	&nbsp;&nbsp;H(X,Y,Z)=X^Y^Z<br />
	&nbsp;&nbsp;I(X,Y,Z)=Y^(X|(~Z))
</p>
<h2>
	<a name="_Toc485547457">DSS </a>签名算法
</h2>
<p align="left">
	<span style="color:#333333;">DSS </span><span style="color:#333333;">的签名过程如下：</span>
</p>
<p align="left">
	<span style="color:#333333;">&nbsp;r=(gkmod p)mod q</span>
</p>
<p align="left">
	<span style="color:#333333;">&nbsp;s=[k-1(H(M)+xr)] mod q </span>
</p>
<p align="left">
	<span style="color:#333333;">则形成了对信息</span><span style="color:#333333;"> M </span><span style="color:#333333;">的数字签名</span><span style="color:#333333;">(r,s)</span><span style="color:#333333;">，数字签名和信息</span><span style="color:#333333;"> M </span><span style="color:#333333;">一同发送给接收方。</span><span style="color:#333333;">接收方接收到信息</span><span style="color:#333333;"> M’</span><span style="color:#333333;">和数字签名</span><span style="color:#333333;">(r’,s’)</span><span style="color:#333333;">后，对数字签名的验证过程如下：</span>
</p>
<p align="left">
	<span style="color:#333333;">&nbsp;w=(s’)<sup>-1</sup> mod q </span>
</p>
<p align="left">
	<span style="color:#333333;">u1=[H(M’)w] mod q, </span>
</p>
<p align="left">
	<span style="color:#333333;">u2=( r’)<sup>w</sup>mod q</span>
</p>
<p align="left">
	<span style="color:#333333;">v=[(g<sup>u1</sup> y<sup>u2</sup>)mod p]mod q </span>
</p>
<p align="left">
	<span style="color:#333333;">如果</span><span style="color:#333333;"> v= r’,</span><span style="color:#333333;">则说明信息确实来自发送方。</span>
</p>
