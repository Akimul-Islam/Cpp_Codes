#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Input an Expression = ";

    char Exp[100];
    cin.getline(Exp,100);

    char token[100];
    int j;

    for(int i=0; Exp[i]!='\0'; i++)
    {
        if(Exp[i]==' ' || Exp[i]=='\t')
        {
            continue;
        }
        else if(isalpha(Exp[i]) || Exp[i]=='_')
        {
            j=0;

            while(isalpha(Exp[i]) || isdigit(Exp[i]) || Exp[i]=='_')
            {
                token[j]=Exp[i];
                j++;
                i++;
            }

            token[j]='\0';

            cout << "<Identifier, " << token << ">" << endl;

            i--;
        }
        else if(isdigit(Exp[i]))
        {
            j=0;

            while(isdigit(Exp[i]))
            {
                token[j]=Exp[i];
                j++;
                i++;
            }

            token[j]='\0';

            cout << "<Integer, " << token << ">" << endl;

            i--;
        }
        else if(Exp[i]=='=')
        {
            cout << "<Assignment Operator, =>" << endl;
        }
        else if(Exp[i]=='+' || Exp[i]=='-' || Exp[i]=='*' || Exp[i]=='/')
        {
            cout << "<Arithmetic Operator, " << Exp[i] << ">" << endl;
        }
        else if(Exp[i]=='(' || Exp[i]==')')
        {
            cout << "<Parenthesis, " << Exp[i] << ">" << endl;
        }
        else if(Exp[i]==';')
        {
            cout << "<Semicolon, ;>" << endl;
        }
        else
        {
            cout << "<Lexical Error, " << Exp[i] << ">" << endl;
        }
    }

    return 0;
}

