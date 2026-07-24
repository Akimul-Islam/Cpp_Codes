#include <bits/stdc++.h>
using namespace std;

string findResultType(string type1, string type2)
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

bool checkAssignment(string variableType, string resultType)
{
    if(resultType == "Error")
    {
        return false;
    }
    else if(resultType == "float" && variableType == "int")
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    map<string, string> symbolTable;
    symbolTable["count"] = "int";
    symbolTable["price"] = "float";
    symbolTable["total"] = "float";
    symbolTable["active"] = "bool";

    cout << "Input Expression (count=int; price= float; total=float; active=bool) = ";
    string leftVar, eqSign, operand1, op, operand2, semicolon;
    cin >> leftVar >> eqSign >> operand1 >> op >> operand2 >> semicolon;

    if(symbolTable.find(leftVar) == symbolTable.end())
    {
        cout << "Semantic error: undeclared identifier " << leftVar << endl;
        return 0;
    }

    string typeLeft = symbolTable[leftVar];
    string typeOp1 = "";
    string typeOp2 = "";

    if(symbolTable.find(operand1) != symbolTable.end())
    {
        typeOp1 = symbolTable[operand1];
    }
    else if(isdigit(operand1[0]))
    {
        typeOp1 = "int";
    }
    else
    {
        cout << "Semantic error: undeclared identifier " << operand1 << endl;
        return 0;
    }

    if(symbolTable.find(operand2) != symbolTable.end())
    {
        typeOp2 = symbolTable[operand2];
    }
    else if(isdigit(operand2[0]))
    {
        typeOp2 = "int";
    }
    else
    {
        cout << "Semantic error: undeclared identifier " << operand2 << endl;
        return 0;
    }

    if(typeOp1 == "bool" || typeOp2 == "bool")
    {
        cout << "Semantic error: bool cannot be used with '" << op << "'" << endl;
        return 0;
    }

    string expressionType = findResultType(typeOp1, typeOp2);

    if(!checkAssignment(typeLeft, expressionType))
    {
        cout << "Semantic error: cannot assign float result to int" << endl;
    }
    else
    {
        cout << "Semantically valid; expression type is " << expressionType << endl;
    }

    return 0;
}