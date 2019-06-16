#include <stdio.h>
#include "codeGen.h"
#include "string.h"

FILE *file;
void writeAssemblyCode(char str[100])
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
    char str[100] = {};
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
        strcat(str, val);
    }
    strcat(str, "\n");
    writeAssemblyCode(str);
    printf("%s\n", str);
    return;
}

void CGLocalVar(char* index, char* value)
{
    char str[100] = {};
    strcpy(str, "ldc ");
    strcat(str, value);
    strcat(str, "\nistore ");
    strcat(str, index);
    strcat(str, "\n");
    writeAssemblyCode(str);
}

void CGFunction(char* name, char* type)
{
    char str[100] = {};
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
    char str[100] = {};
    strcpy(str, "ldc ");
    strcat(str, target);
    strcat(str, "\ngetstatic java/lang/System/out Ljava/io/PrintStream;\nswap\ninvokevirtual java/io/PrintStream/println(");
    strcat(str, typeEncode(type));
    strcat(str, ")V\n");
    writeAssemblyCode(str);
    return;
}