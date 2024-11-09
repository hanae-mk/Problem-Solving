//Teacher's solution I didn't try it//

#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string Text;

    cout << "Please enter text ?" << endl;
    getline(cin, Text);

    return Text;

}

string EncryptText(string Text, short EncryptionKey) //hanae jcpcg
{
    for (int i = 0; i < Text.length() ; i++) 
    {
        Text[i] = char((int)Text[i] + EncryptionKey); 
    }

    return Text;
}

string DecryptText(string Text, short EncryptionKey) //f*l*c
{
    for (int i = 0; i < Text.length() ; i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }

    return Text; 
}

int main()
{
    const short EncryptionKey = 2;

    string Text = ReadText();
    string TextAfterEncryption = EncryptText(Text, EncryptionKey);
    string TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText Before Encryption : " << Text << endl;
    cout << "\nText After Encryption : " << TextAfterEncryption << endl;
    cout << "\nText After Decryption : " << TextAfterDecryption << endl;

    
}