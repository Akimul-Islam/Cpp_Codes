#include <bits/stdc++.h>
using namespace std;

bool isIdentifier(string value)
{
    if(value.empty())
    {
        return false;
    }
    if(!(isalpha(value[0]) || value[0] == '_' || value[0] == '$'))
    {
        return false;
    }


    for(int i = 1; i < value.length(); i++)
    {
        if(!(isalnum(value[i]) || value[i] == '_' || value[i] == '$'))
        {
            return false;
        }
    }

    string keyword[] =
    {
        "int","float","double","char","if","else","for","while",
        "do","return","class","void","switch","case","break",
        "continue","long","short","bool","true","false"
    };

   
    for(int i = 0; i < 21; i++)
    {
        if(keyword[i] == value)
        {
            return false;
        }
    }

    return true;
}

bool isNumber(string value)
{
    if(value.empty())
    {
        return false;
    }

 
    for(int i = 0; i < value.length(); i++)
    {
        if(!isdigit(value[i]))
        {
            return false;
        }
    }
    
    return true;
}

bool isoperand(string value)
{
    return isIdentifier(value) || isNumber(value);
}

bool hasValidAssignmentSyntax(string tokens[])
{
    if(!isIdentifier(tokens[0]))
    {
        return false;
    }
    if(tokens[1] != "=")
    {
        return false;
    }
    if(!isoperand(tokens[2]))
    {
        return false;
    }
    if(tokens[3] != "+" && tokens[3] != "-" && tokens[3] != "*" && tokens[3] != "/")
    {
        return false;
    }
    if(!isoperand(tokens[4]))
    {
        return false;
    }
    if(tokens[5] != ";")
    {
        return false;
    }
    return true;
}

int main()
{
    cout << "Input an Expression = ";
    char Exp[100];
    cin.getline(Exp, 100);
    string tokens[6];
    int tokenCount = 0;
    char token[100];
    int j;

    for(int i = 0; Exp[i] != '\0'; i++)
    {
        if(Exp[i] == ' ' || Exp[i] == '\t')
        {
            continue;
        }
        else if(isalpha(Exp[i]) || Exp[i] == '_')
        {
            j = 0;
            while(isalpha(Exp[i]) || isdigit(Exp[i]) || Exp[i] == '_')
            {
                token[j] = Exp[i];
                j++;
                i++;
            }
            token[j] = '\0';

            if(tokenCount < 6) 
            {   
                tokens[tokenCount] = token;
                tokenCount++;
                i--;
            }  
        }
        else if(isdigit(Exp[i]))
        {
            j = 0;
            while(isdigit(Exp[i]))
            {
                token[j] = Exp[i];
                j++;
                i++;
            }
            token[j] = '\0';

            if(tokenCount < 6) 
            {   
                tokens[tokenCount] = token;
                tokenCount++;
                i--;
            }  
        }
        else if(Exp[i] == '=' || Exp[i] == '+' || Exp[i] == '-' || Exp[i] == '*' || Exp[i] == '/' || Exp[i] == ';')
        {
            string s(1, Exp[i]);
             
            if(tokenCount < 6) 
            {   
                tokens[tokenCount] = s;
                tokenCount++;
            }  
        }
    }

    if(tokenCount == 6 && hasValidAssignmentSyntax(tokens))
    {
        cout << "Valid assignment syntax" << endl;
    }
    else
    {
        cout << "Invalid assignment syntax"<<endl;
    }

    return 0;
}