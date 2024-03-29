void writeAssemblyCode(char str[100]);
char* typeEncode(char* type);
void CGPop();
void CGGlobalVar(char* name, char* type, short init, char* val);
void CGLocalVar(char* index, char* value, char* type);
void CGFunction(char* name, char* type, char* params);
void CGCallFunction(char* name, char* type, char* params);
void CGPrint(char* target, char* type);
void CGPrintGlobal(char* name, char* type);
void CGPrintRegister(char* index, char* type);
void CGLoadConst(char* targetConstant);
void CGLoadConstAsFloat(char* targetConstant);
void CGLoadRegister(char* index, char* type);
void CGLoadGlobal(char* name, char* type);
void CGIncrement();
void CGDecrement();
void CGArithmetic(char* op, char* varType);
int CGCheckSpecialAssignment(char* op, char* varType); //1:= 2: special +=, -=, etc.
void CGSaveToRegister(char* index, char* type);
void CGSaveToGlobal(char* name, char* type);
void CGWhileHead(int count);
void CGWhileLoop(char* op, char* type, int count);
void CGWhileEnd(int count);
