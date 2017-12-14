#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

string g_message = "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\n"
	"Xof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe\n"
	"ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg\n"
	"fnxfexdqn oqp ge ofe.\n"
	"Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\n"
	"Xof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf\n"
	"qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef\n"
	"fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro\n"
	"gxofe. - Mgon Rdepdrw.\n"
	"(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n"
	"(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";

string g_freqLang = "TEOAISRHNUCMDLGWFPYKJBVQX";

int 	indexFinder(char c)
{
    if (c <= 'z' && c >= 'a')
	return (c - 'a');
    if (c <= 'Z' && c >= 'A')
	return (c -'A');
    return (-1);
}

map<char, char> createDecrypter(vector<int> alpha, string freqLang)
{
    map<char, char> decrypter;
    int max;
    int index;

    for (int i = 0; i < freqLang.size(); i++)
    {
	max = -1;
	int index = -1;
	for(int j =0; j < 26; j++)
	{
	    if (alpha[j] >= max)
	    {
		max = alpha[j];
		index = j;
	    }
	}
	if (index != -1)
	{
	    decrypter[index + 'a'] = freqLang[i];
	    alpha[index] = 0;
	}
    }
    return (decrypter);
}

void	decryptMessage(string message, string freqLang)
{
    map<char, char> decrypter;
    vector<int> alpha (26, 0);
    for (int i = 0; i < message.size(); i++)
    {
	if (indexFinder(message[i]) != -1)
	    alpha[indexFinder(message[i])]++;
    }
    decrypter = createDecrypter(alpha, freqLang);
    for (int i = 0; i < message.size(); i++)
    {
	if(indexFinder(message[i]) != -1)
	{
	    if(message[i] <= 'Z')
		cout << decrypter[indexFinder(message[i]) + 'a'];
	    else
		cout << static_cast<char>(decrypter[indexFinder(message[i]) + 'a'] + ('a' - 'A'));
	}
	else
	    cout << message[i];
    }
    cout << endl;
}

int main(void)
{
    cout << g_message << endl;
    cout << "\nDecrypted message is : \n";
    decryptMessage(g_message, g_freqLang);
    return (0);
}
