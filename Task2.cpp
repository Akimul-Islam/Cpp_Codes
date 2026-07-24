#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Input Variable Name = ";

    char Var[100];
    cin.getline(Var, 100);

    if(Var[0] == '\0')
    {
        cout << "Invalid: Empty variable name";
        return 0;
    }

    string keyword[] =
    {
        "int","float","double","char","if","else","for","while",
        "do","return","class","void","switch","case","break",
        "continue","long","short","bool","true","false"
    };

    if(!(isalpha(Var[0]) || Var[0]=='_' || Var[0]=='$'))
    {
        if(isdigit(Var[0]))
        {
            cout << "Invalid: the first character cannot be a digit";
        }
        else
        {
            cout << "Invalid: the first character must be a letter, underscore or dollar sign";
        }

        return 0;
    }

    for(int i=1; Var[i]!='\0'; i++)
    {
        if(!(isalnum(Var[i]) || Var[i]=='_'))
        {
            cout << "Invalid: contains invalid character '" << Var[i] << "'";
            return 0;
        }
    }

    for(int i=0; i<21; i++)
    {
        if(keyword[i] == Var)
        {
            cout << "Invalid: reserved keyword";
            return 0;
        }
    }

    cout << "Valid variable name";

    return 0;
}


