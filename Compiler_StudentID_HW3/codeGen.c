#include <stdio.h>
#include "codeGen.h"
#include "string.h"
#define STR_SIZE 200

FILE *file;
void writeAssemblyCode(char str[STR_SIZE])
{
    file = fopen("compiler_hw3.j","a");

    fprintf(file, str);
    fclose(file);
}

char* typeEncode(char* type)
{
    if(strcmp(type, "int") == 0)
    {
        return "I";
    }
    else if(strcmp(type, "float") == 0)
    {
        return "F";
    }
    else if(strcmp(type, "bool") == 0)
    {
        return "Z";
    }
    else if(strcmp(type, "void") == 0)
    {
        return "V";
    }
    else if(strcmp(type, "string") == 0)
    {
        return "S";
    }
    else
    {
        return "WTF";
    }
}

void CGGlobalVar(char* name, char* type, short init, char* val)
{
    char str[STR_SIZE] = {};
    // casting
    char myVal[100] = {};
    strcpy(myVal, val);
    if(strcmp(type, "int")==0)
    {
        char * pch;
        pch = strstr(myVal,".");
        if(pch)
            strncpy (pch,"\0",1);
    }
    else if(strcmp(type, "float")==0)
    {
        char * pch;
        pch = strstr(myVal,".");
        if(!pch)
            strcat(myVal, ".0");
    }
    else if(strcmp(type, "string")==0)
    {
        strcpy(myVal, "\"");
        strcat(myVal, val);
        strcat(myVal, "\"");
    }
    // else
    //     strcat(str, "wtfvalue ");

    strcpy(str, ".field public static ");
    strcat(str, name);
    if(strcmp(type, "int") == 0)
    {
        strcat(str, " I");
    }
    else if(strcmp(type, "float") == 0)
    {
        strcat(str, " F");
    }
    else if(strcmp(type, "bool") == 0)
    {
        strcat(str, " Z");
    }
    else if(strcmp(type, "void") == 0)
    {
        strcat(str, " V");
    }
    else if(strcmp(type, "string") == 0)
    {
        strcat(str, " S");
    }
    else
    {
        strcat(str, " WTF");
    }

    //has init value
    if(init == 1)
    {
        strcat(str, " = ");
        strcat(str, myVal);
    }
    strcat(str, "\n");
    writeAssemblyCode(str);
    printf("%s\n", str);
    return;
}

void CGLocalVar(char* index, char* value, char* type)
{
    char str[STR_SIZE] = {};
    char myVal[100] = {};
    strcpy(myVal, value);
    strcpy(str, "ldc ");
    // cast by fixing value 
    if(strcmp(type, "int")==0)
    {
        char * pch;
        pch = strstr(myVal,".");
        if(pch)
            strncpy (pch,"\0",1);
    }
    else if(strcmp(type, "float")==0)
    {
        char * pch;
        pch = strstr(myVal,".");
        if(!pch)
            strcat(myVal, ".0");
    }
    else if(strcmp(type, "string")==0)
    {
        strcpy(myVal, "\"");
        strcat(myVal, value);
        strcat(myVal, "\"");
    }
    // else
    //     strcat(str, "wtfvalue ");
    strcat(str, myVal);
    strcat(str, "\n");
    if(strcmp(type, "int")==0)
        strcat(str, "istore ");
    else if(strcmp(type, "float")==0)
        strcat(str, "fstore ");
    else
        strcat(str, "istore ");
    strcat(str, index);
    strcat(str, "\n");
    writeAssemblyCode(str);
}

void CGFunction(char* name, char* type)
{
    char str[STR_SIZE] = {};
    if(strcmp(name, "main")==0)
    {
        strcat(str, ".method public static main([Ljava/lang/String;)V\n");
    }
    else
    {
        strcat(str, ".method public static ");
        strcat(str, name);
        strcat(str, "(");
        //strcat(str, params);
        strcat(str, ")");
        if(strcmp(type, "int") == 0)
        {
            strcat(str, " I");
        }
        else if(strcmp(type, "float") == 0)
        {
            strcat(str, " F");
        }
        else if(strcmp(type, "bool") == 0)
        {
            strcat(str, " Z");
        }
        else if(strcmp(type, "void") == 0)
        {
            strcat(str, " V");
        }
        else if(strcmp(type, "string") == 0)
        {
            strcat(str, " S");
        }
        else
        {
            strcat(str, " WTF");
        }
        strcat(str, "\n");
    }
    strcat(str, ".limit stack 50\n.limit locals 50");
    
    strcat(str, "\n");
    writeAssemblyCode(str);
    printf("%s\n", str);
    return;
}

void CGPrint(char* target, char* type)
{
    char str[STR_SIZE] = {};
    strcpy(str, "ldc ");
    if(strcmp(type, "string") == 0)
    {
        strcat(str, "\"");
        strcat(str, target);
        strcat(str, "\"");
    }
    else
        strcat(str, target);
    strcat(str, "\ngetstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(");
    if(strcmp(type, "string") == 0)
        strcat(str, "Ljava/lang/String;");
    else
        strcat(str, typeEncode(type));
    strcat(str, ")V\n");
    writeAssemblyCode(str);
    return;
}

void CGPrintGlobal(char* name, char* type)
{
    char str[STR_SIZE] = {};
    CGLoadGlobal(name, type);
    strcat(str, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(");
    strcat(str, typeEncode(type));
    strcat(str, ")V\n");
    writeAssemblyCode(str);
    return;
}

void CGPrintRegister(char* index, char* type)
{
    char str[STR_SIZE] = {};
    CGLoadRegister(index, type);
    strcat(str, "getstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(");
    strcat(str, typeEncode(type));
    strcat(str, ")V\n");
    writeAssemblyCode(str);
    return;
}

void CGLoadConst(char* targetConstant)
{
    char str[STR_SIZE] = {};
    strcpy(str, "ldc ");
    strcat(str, targetConstant);
    strcat(str, "\n");
    writeAssemblyCode(str);
    return;
}

void CGLoadRegister(char* index, char* type)
{
    char str[STR_SIZE] = {};
    if(strcmp(type, "int")==0)
        strcpy(str, "i");
    else if(strcmp(type, "float")==0)
        strcpy(str, "f");
    else
        strcpy(str, "i");
    strcat(str, "load ");
    strcat(str, index);
    strcat(str, "\n");
    writeAssemblyCode(str);
    return;
}

void CGLoadGlobal(char* name, char* type)
{
    char str[STR_SIZE] = {};
    strcpy(str, "getstatic ");
    strcat(str, "compiler_hw3/");
    strcat(str, name);
    strcat(str, " ");
    strcat(str, typeEncode(type));
    strcat(str, "\n");
    writeAssemblyCode(str);
    return;
}

void CGIncrement()
{
    writeAssemblyCode("ldc 1\niadd\n");
    return;
}

void CGDecrement()
{
    writeAssemblyCode("ldc 1\nisub\n");
    return;
}

void CGArithmetic(char* op, char* varType)
{
    char str[STR_SIZE] = {};
    char myType[10] = {};
    if(strcmp(varType, "int") == 0)
        strcpy(myType, "i");
    else if(strcmp(varType, "float") == 0)
        strcpy(myType, "f");
    
    if(strcmp(op, "+") == 0)
    {
        strcpy(str, myType);
        strcat(str, "add\n");
    }
    else if(strcmp(op, "-") == 0)
    {
        strcpy(str, myType);
        strcat(str, "sub\n");
    }
    else if(strcmp(op, "*") == 0)
    {
        strcpy(str, myType);
        strcat(str, "mul\n");
    }
    else if(strcmp(op, "/") == 0)
    {
        strcpy(str, myType);
        strcat(str, "div\n");
    }
    else if(strcmp(op, "%") == 0)
    {
        strcpy(str, myType);
        strcat(str, "rem\n");
    }
    writeAssemblyCode(str);
    return;
}

void CGCheckSpecialAssignment(char* op, char* varType)
{
    if(strcmp(op, "+=")==0)
        CGArithmetic("+", varType);
    else if(strcmp(op, "-=")==0)
        CGArithmetic("-", varType);
    else if(strcmp(op, "*=")==0)
        CGArithmetic("*", varType);
    else if(strcmp(op, "/=")==0)
        CGArithmetic("/", varType);
    else if(strcmp(op, "%=")==0)
        CGArithmetic("%", varType);
}

void CGSaveToRegister(char* index, char* type)
{
    char str[STR_SIZE] = {};
    if(strcmp(type, "int")==0)
        strcpy(str, "istore ");
    else if(strcmp(type, "float")==0)
        strcpy(str, "fstore ");
    else
        strcpy(str, "istore ");
    strcat(str, index);
    strcat(str, "\n");
    writeAssemblyCode(str);
}

void CGSaveToGlobal(char* name, char* type)
{
    char str[STR_SIZE] = {};
    strcpy(str, "putstatic ");
    strcat(str, "compiler_hw3/");
    strcat(str, name);
    strcat(str, " ");
    strcat(str, typeEncode(type));
    strcat(str, "\n");
    writeAssemblyCode(str);
    return;
}