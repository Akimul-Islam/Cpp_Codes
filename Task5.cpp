#include <bits/stdc++.h>
using namespace std;

bool isIdentifier(string value)//This functions checks if the variable declared was a valid variable
{
    if(value.empty())
    {
        return false;
    }

    if(!(isalpha(value[0]) || value[0] == '_'))
    {
        return false;
    }

    for(int i = 1; i < value.length(); i++)
    {
        if(!(isalnum(value[i]) || value[i] == '_'))
        {
            return false;
        }
    }

    string keyword[] = //these are some reserved key words of c++ the function uses them to identify if the
                       //user has inputed a reserved word as variable
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

bool isNumber(string value)//This function checks weather the input is a number or not
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

bool isOperand(string value) // This function checks if the input has a operand
{
    return isIdentifier(value)||isNumber(value);
}

bool hasValidAssignmentSyntax(string tokens[])// This function checks if the input was given according to the
                                              //instructions and if any syntex was misplaced for example = is not
                                              //at the start of the equation.
{
    if(!isIdentifier(tokens[0]))//checks if the element in the token index 0 a valid variable name by calling
                                //the function isIdentifier()
    {
        cout << "Syntax Error: invalid identifier" << endl;
        return false;
    }

    if(tokens[1] != "=")//Checks if = is placed where it should be.
    {
        cout << "Syntax Error: expected '='" << endl;
        return false;
    }

    if(!isOperand(tokens[2]))//Checks if (+,-,*,%) is placed where it should be.
    {
        cout << "Syntax Error: expected first operand" << endl;
        return false;
    }

    if(tokens[3] != "+" &&
       tokens[3] != "-" &&
       tokens[3] != "*" &&
       tokens[3] != "/")
    {
        cout << "Syntax Error: expected operator" << endl;
        return false;
    }

    if(!isOperand(tokens[4]))//Checks if the second oparand(+,-,*,%) is placed where it should be.
    {
        cout << "Syntax Error: expected second operand" << endl;
        return false;
    }

    if(tokens[5] != ";")//checks if there is a ; in the end of a valid input
    {
        cout << "Syntax Error: missing semicolon" << endl;
        return false;
    }

    return true;
}

string findResultType(string type1, string type2)// Identifies the data type of the input after '=' and returns it
                                                 //if there is a non-compatible variable type then returns error
{
    if(type1 == "bool" || type2 == "bool")
    {
        return "Error";
    }
    else if(type1 == "float" || type2 == "float")
    {
        return "float";
    }
    else
    {
        return "int";
    }
}

bool checkAssignment(string variableType, string resultType)//checks if the varableType and resultType is
                                                            //compatible or not
{
    if(resultType == "Error")
    {
        return false;
    }

    if(resultType == "float" && variableType == "int")
    {
        return false;
    }

    return true;
}

int main()
{
    map<string, string> symbolTable;//Creates a Dictionary which stores the data type of the predetermined variables

    symbolTable["count"] = "int";
    symbolTable["price"] = "float";
    symbolTable["total"] = "float";
    symbolTable["active"] = "bool";

    cout << "Input Statement = ";//this is where the statement in inputed

    char Exp[100];
    cin.getline(Exp, 100);

    string tokens[6];
    int tokenCount = 0;

    char token[100];
    int j;




    for(int i = 0; Exp[i] != '\0'; i++)//this code is to tokenize the input
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
            }

            i--;
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
            }

            i--;
        }

        else if(Exp[i] == '=' ||
                Exp[i] == '+' ||
                Exp[i] == '-' ||
                Exp[i] == '*' ||
                Exp[i] == '/' ||
                Exp[i] == ';')
        {
            string s(1, Exp[i]);

            if(tokenCount < 6)
            {
                tokens[tokenCount] = s;
                tokenCount++;
            }
        }

        else
        {
            cout << "Lexical Error: invalid character '" << Exp[i] << "'" << endl;
            return 0;
        }
    }




    for(int i = 0; i < tokenCount; i++)// this code is for checking if the inputed variable is ligitimate
    {
        if(isalpha(tokens[i][0]) || tokens[i][0] == '_')
        {
            if(!isIdentifier(tokens[i]))
            {
                cout << "Identifier Error: invalid identifier "
                     << tokens[i] << endl;
                return 0;
            }
        }
    }


    if(tokenCount != 6) //if there is less then 6 tokens then prints an error massage
    {
        cout << "Syntax Error: invalid statement format" << endl;
        return 0;
    }

    if(!hasValidAssignmentSyntax(tokens))
    {
        return 0;
    }

    string leftVar = tokens[0];
    string operand1 = tokens[2];
    string op = tokens[3];
    string operand2 = tokens[4];

    if(symbolTable.find(leftVar) == symbolTable.end())//if the inputed.........
    {
        cout << "Semantic Error: undeclared identifier "
             << leftVar << endl;
        return 0;
    }

    string typeLeft = symbolTable[leftVar];
    string typeOp1 = "";
    string typeOp2 = "";

    if(symbolTable.find(operand1) != symbolTable.end())
    {
        typeOp1 = symbolTable[operand1];
    }
    else if(isNumber(operand1))
    {
        typeOp1 = "int";
    }
    else
    {
        cout << "Semantic Error: undeclared identifier "
             << operand1 << endl;
        return 0;
    }

    if(symbolTable.find(operand2) != symbolTable.end())
    {
        typeOp2 = symbolTable[operand2];
    }
    else if(isNumber(operand2))
    {
        typeOp2 = "int";
    }
    else
    {
        cout << "Semantic Error: undeclared identifier "
             << operand2 << endl;
        return 0;
    }

    if(typeOp1 == "bool" || typeOp2 == "bool")
    {
        cout << "Semantic Error: bool cannot be used with '"
             << op << "'" << endl;
        return 0;
    }

    string expressionType = findResultType(typeOp1, typeOp2);

    if(!checkAssignment(typeLeft, expressionType))
    {
        cout << "Semantic Error: cannot assign float result to int"
             << endl;
        return 0;
    }

    cout << "Accepted" << endl;
    cout << "Expression type is " << expressionType << endl;

    return 0;
}
