/*	Definition section */
%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "codeGen.h"
extern int yylineno;
extern int yylex();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
extern int errorStatus;
extern bool isFunction;
extern bool isArg;
extern bool forwardDeclarationLine;
extern char errID[256];
extern bool dumpTheTableRightHereAccordingToTheHomeworkRequirement;
extern int tableScope;

////For jasmin code gen
FILE* file;

//DS for table
typedef struct element{
	char Name[256];
	char Kind[10]; // 3 kinds
	char Type[10];
	int Scope;
	int index;
	char Attribute[1000]; //func input
	bool isForwardFunction;
	struct element* next;
} tableElement;

tableElement *scope[30];

/* Symbol table function - you can add new function if needed. */
int lookup_symbol(int tar_scope, char tar_name[256]);
void create_symbol();
int insert_symbol(int tar_scope, char name[256], char type[10], char kind[10], bool forward);
void set_dump_symbol(int tar_scope);
void dump_symbol(int tar_scope, bool print);
void yyerror(char *s);
void ysemError(short type);

void Dbug(char *s);

/* Global variables coming in hot */
int fuckin_flag1 = 0;
int cur_scope = 0;
char last_queried_data_type[10] = {};
char lookup_var_name[256] = {};
char lookup_var_type[10] = {};
int lookup_var_scope; /*0:global, else:local*/
char lookup_var_index[10] = {};
char assign_var_name[256] = {};
char assign_var_type[10] = {};
char assign_var_index[10] = {};
int assign_var_scope; /*0:global, else:local*/

%}

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    double f_val;
    char string[1000];
    _Bool bool_val;
}

/* Token without return */
%token PRINT 
%token IF ELSE FOR WHILE
%token ID SEMICOLON
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB LSB RSB COMMA
%token VOID INT FLOAT STRING BOOL
%token RET

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STR_CONST
%token <bool_val> TRUE
%token <bool_val> FALSE

/* Nonterminal with return, which need to sepcify type */
%type <string> type
%type <string> ID_expr
%type <string> constants
%type <string> primary_expression
%type <string> print_tar
%type <string> lp_arithmetic_operator
%type <string> hp_arithmetic_operator
%type <string> assignment_operator

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : program statement
	|
;

statement
    : declaration
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | print_func
	| RET SEMICOLON
	| RET assignment_expression SEMICOLON
;

declaration
    : type ID_expr ASGN primary_expression SEMICOLON 	{ /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/int i = insert_symbol(cur_scope, $2, $1, "variable", false); if(cur_scope==0) CGGlobalVar($2, $1, 1, $4); else { char str[12]; sprintf(str, "%d", i);CGLocalVar(str, $4, $1); } }
    | type ID_expr SEMICOLON							{ /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/int i = insert_symbol(cur_scope, $2, $1, "variable", false); if(cur_scope==0) CGGlobalVar($2, $1, 0, ""); else { char str[12]; sprintf(str, "%d", i);CGLocalVar(str, "0", $1); } }
	| type ID_expr ASGN arithmetic_expression SEMICOLON { /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/int i = insert_symbol(cur_scope, $2, $1, "variable", false); if(cur_scope==0) CGGlobalVar($2, $1, 0, "No globals here"); else { char str[12]; sprintf(str, "%d", i);CGSaveToRegister(str, $1); } }
	| type ID_expr LB function_item_list RB SEMICOLON	{ /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/insert_symbol(cur_scope, $2, $1, "function", true); isFunction = true; forwardDeclarationLine = true;}
	| type ID_expr LB function_item_list RB				{ /*[SCOPE] cur_scope, [NAME] $2 [Type] $1*/insert_symbol(cur_scope, $2, $1, "function", false); isFunction = true; CGFunction($2, $1);}
;

function_item_list
	: function_item_list COMMA function_item
	| function_item
;

function_item
	: type ID_expr { /*printf("[SCOPE] %d, [NAME] %s [Type] %s\n", cur_scope+1, $2, $1);*/insert_symbol(cur_scope + 1, $2, $1, "parameter", false); }
	|
;

/* actions can be taken when meet the token or rule */
type
    : INT 	 	{ strcpy($$, "int"); }
    | FLOAT		{ strcpy($$, "float"); }
    | BOOL		{ strcpy($$, "bool"); }
    | STRING	{ strcpy($$, "string"); }
    | VOID		{ strcpy($$, "void"); }
;

compound_statement
	: LCB RCB 
	| LCB {cur_scope++;} a_random_nonterminal RCB {cur_scope--; set_dump_symbol(cur_scope+1); if(cur_scope==0) writeAssemblyCode("return\n.end method\n");}
;

a_random_nonterminal
	: another_random_nonterminal_what_is_going_on_out_here
	| a_random_nonterminal another_random_nonterminal_what_is_going_on_out_here
;

another_random_nonterminal_what_is_going_on_out_here
	: declaration
	| statement
;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
;

expression
	: assignment_expression
	| expression COMMA assignment_expression
;

assignment_expression
	: unary_expression { assign_var_scope = lookup_var_scope; strcpy(assign_var_index, lookup_var_index); strcpy(assign_var_type, lookup_var_type); strcpy(assign_var_name, lookup_var_name); } assignment_operator assignment_expression { CGCheckSpecialAssignment($3, assign_var_type); if(assign_var_scope == 0) CGSaveToGlobal(assign_var_name, assign_var_type); else CGSaveToRegister(assign_var_index, assign_var_type); }
    | logical_expression
;

unary_expression
	: postfix_expression
	| INC unary_expression					{ CGIncrement(); if(lookup_var_scope == 0) {CGSaveToGlobal(lookup_var_name, lookup_var_type); CGLoadGlobal(lookup_var_name, lookup_var_type);} else {CGSaveToRegister(lookup_var_index, lookup_var_type); CGLoadRegister(lookup_var_index, lookup_var_type); } }
	| DEC unary_expression					{ CGDecrement(); if(lookup_var_scope == 0) {CGSaveToGlobal(lookup_var_name, lookup_var_type); CGLoadGlobal(lookup_var_name, lookup_var_type);} else {CGSaveToRegister(lookup_var_index, lookup_var_type); CGLoadRegister(lookup_var_index, lookup_var_type); } }
	| unary_operator cast_expression

postfix_expression
	: primary_expression					{ if(strcmp($1, "ID")==0) 
												{ 
													if(lookup_var_scope==0) 
														CGLoadGlobal(lookup_var_name, lookup_var_type);
													else
														CGLoadRegister(lookup_var_index, lookup_var_type);
												} 
											  else if(strcmp($1, "")!=0) 
											  	CGLoadConst($1); 
											}
	| postfix_expression LB RB				{ isFunction = true; }
	| postfix_expression LB arguments RB	{ isFunction = true; }
	| postfix_expression INC				{ CGIncrement(); if(lookup_var_scope == 0) {CGSaveToGlobal(lookup_var_name, lookup_var_type); CGLoadGlobal(lookup_var_name, lookup_var_type);} else {CGSaveToRegister(lookup_var_index, lookup_var_type);  CGLoadRegister(lookup_var_index, lookup_var_type); } CGDecrement(); }
	| postfix_expression DEC				{ CGDecrement(); if(lookup_var_scope == 0) {CGSaveToGlobal(lookup_var_name, lookup_var_type); CGLoadGlobal(lookup_var_name, lookup_var_type);} else {CGSaveToRegister(lookup_var_index, lookup_var_type);  CGLoadRegister(lookup_var_index, lookup_var_type); } CGIncrement(); }
;

primary_expression
	: ID_expr { strcpy($$, "ID"); if(lookup_symbol(cur_scope, $1)==0){ errorStatus = 2; strcpy(errID, $1); } }
	| constants { strcpy($$, $1); }
	| LB expression RB { strcpy($$, ""); }
;

constants
	: I_CONST {strcpy($$, yytext); strcpy(last_queried_data_type, "int");}
    | F_CONST {strcpy($$, yytext); strcpy(last_queried_data_type, "float");}
    | STR_CONST {strcpy($$, yytext); strcpy(last_queried_data_type, "string");}
	| TRUE {strcpy($$, yytext); strcpy(last_queried_data_type, "bool");}
    | FALSE {strcpy($$, yytext); strcpy(last_queried_data_type, "bool");}
;

arguments
	: assignment_expression					{ isArg = true; }
	| arguments COMMA assignment_expression	{ isArg = true; }
;

unary_operator
	: ADD
	| SUB
	| NOT
;

cast_expression
	: unary_expression
	| LB type RB cast_expression
;

assignment_operator
	: ASGN		{ strcpy($$, yytext); }
	| MULASGN	{ strcpy($$, yytext); }
	| DIVASGN	{ strcpy($$, yytext); }
	| MODASGN	{ strcpy($$, yytext); }
	| ADDASGN	{ strcpy($$, yytext); }
	| SUBASGN	{ strcpy($$, yytext); }
;

logical_expression
	: logical_expression OR relational_expression
	| logical_expression AND relational_expression
	| relational_expression
;

relational_expression
	: relational_expression relational_operator arithmetic_expression
	| arithmetic_expression
;

arithmetic_expression
	: arithmetic_expression lp_arithmetic_operator high_precedence_arithmetic_expression		{ CGArithmetic($2, "int"); }
	| high_precedence_arithmetic_expression
;

high_precedence_arithmetic_expression
	: high_precedence_arithmetic_expression hp_arithmetic_operator unary_expression 			{ CGArithmetic($2, "int"); }
	| unary_expression
;

relational_operator
	: MT
	| LT
	| MTE
	| LTE
	| EQ
	| NE
;

lp_arithmetic_operator
	: ADD { strcpy($$, yytext); }
	| SUB { strcpy($$, yytext); }
;

hp_arithmetic_operator
	: MUL { strcpy($$, yytext); }
	| DIV { strcpy($$, yytext); }
	| MOD { strcpy($$, yytext); }
;

selection_statement
    : IF LB expression RB statement ELSE statement
	| IF LB expression RB statement
;

iteration_statement
    : WHILE LB expression RB statement
	| FOR LB expression_statement expression_statement RB statement
	| FOR LB expression_statement expression_statement expression RB statement
	| FOR LB declaration expression_statement RB statement
	| FOR LB declaration expression_statement expression RB statement
;

print_func
    : PRINT LB print_tar RB
;

print_tar 
    : ID_expr { 
				if(lookup_symbol(cur_scope, $1)==0)
				{ 
					errorStatus = 2;  strcpy(errID, $1);
				} 
				strcpy($$, $1); 
				if(lookup_var_scope==0) 
					CGPrintGlobal(lookup_var_name, lookup_var_type); 
				else 
				{ 
					CGPrintRegister(lookup_var_index, lookup_var_type);
				}
			}
    | constants { strcpy($$, $1); CGPrint($1, last_queried_data_type);}
;

ID_expr
	: ID { strcpy($$, yytext); }
;

%%

/* C code section */
int main(int argc, char** argv)
{
    yylineno = 0;
	file = fopen("compiler_hw3.j","w");

    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n");
	fclose(file);

	create_symbol();
    yyparse();
	dump_symbol(0, true);
	if(fuckin_flag1!=1)
		printf("\nTotal lines: %d \n",yylineno);

	// fprintf(file, "\treturn\n"
    //               ".end method\n");

    return 0;
}

void yyerror(char *s)
{
	printf("%d: %s\n", yylineno + 1, buf);
	if(errorStatus==1)
    {
        errorStatus = 0;
        if(isFunction)
        {
            ysemError(2);
        }
        else
        {
            ysemError(3);
        }
    }
    else if(errorStatus==2)
    {
        errorStatus = 0;
        if(isFunction)
        {
			ysemError(2);
        }
            else
                ysemError(1);
    }
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s\n", yylineno + 1, buf);
    printf("| %s", s);
    printf("\n|-----------------------------------------------|\n\n");
	fuckin_flag1 = 1;
}

void Dbug(char *s)
{
    printf("%s\n", s);
}

void create_symbol() 
{
	//initialize symbol table
	int i;
	for(i=0;i<30;++i)
	{
		scope[i] = NULL;
	}
}

//Ret value: 
//-2 :forward function
//-1 :Error
//int: index that inserted
int insert_symbol(int tar_scope, char name[256], char type[10], char kind[10], bool forward)
{
	//create new element
	tableElement* newElement = malloc(sizeof(tableElement));
	strcpy(newElement->Name, name);
	strcpy(newElement->Type, type);
	strcpy(newElement->Kind, kind);
	newElement->index = 0;
	newElement->isForwardFunction = forward;
	if(strcmp(kind, "function") != 0)
		strcpy(newElement->Attribute, "");
	else
	{
		tableElement* iter = scope[tar_scope+1];
		if(iter)
		{
			strcpy(newElement->Attribute, iter->Type);
			while(iter->next)
			{
				iter = iter->next;
				strcat(newElement->Attribute, ",");
				strcat(newElement->Attribute, iter->Type);
			}
		}
	}

	int tmp = lookup_symbol(tar_scope, name);
	if(tmp == 1)
	{
		errorStatus = 1;
		strcpy(errID, name);
		return -1;
	}
	else if(tmp == 2)
	{
		//forward function
		return -2;
	}


	if(scope[tar_scope] == NULL)
	{
		// Empty, insert new
		scope[tar_scope] = newElement;
		newElement->next = NULL;
		newElement->index = 0;
		return 0;
	}
	else
	{
		// Not empty, insert new to tail
		int index = 0;
		tableElement* iter = scope[tar_scope];
		while(iter->next)
		{
			index++;
			iter = iter->next;
		}
		iter->next = newElement;
		newElement->next = NULL;
		index++;
		newElement->index = index;
		return index;
	}
}

// Return 2 = found forwarded function, 1 = found, 0 = not found
int lookup_symbol(int tar_scope, char tar_name[256]) 
{
	tableElement* iter = scope[tar_scope];
	int cur_scope = tar_scope;
	while(cur_scope>=0)
	{
		while(iter)
		{
			if(strcmp(tar_name, iter->Name) == 0)
			{
				strcpy(last_queried_data_type, iter->Type);
				strcpy(lookup_var_name, iter->Name);
				strcpy(lookup_var_type, iter->Type);
				lookup_var_scope = cur_scope;
				sprintf(lookup_var_index, "%d", iter->index);
				if(iter->isForwardFunction)
				{
					iter->isForwardFunction = false;
					return 2;
				}
				return 1;
			}
			iter = iter->next;
		}
		cur_scope--;
		iter = scope[cur_scope];
	}
	return 0;
}

void set_dump_symbol(int tar_scope) {
	dumpTheTableRightHereAccordingToTheHomeworkRequirement = true;
	tableScope = tar_scope;
}

void dump_symbol(int tar_scope, bool print)
{
	if(scope[tar_scope] == NULL)
	{
		return;
	}
	if(!print)
	{
		scope[tar_scope] = NULL;
		return;
	}
	int ctr = 0;
	tableElement *cur = scope[tar_scope];
	printf("\nIndex     Name      Kind        Type      Scope     Attribute \n");
	while(cur)
	{
    	printf("\n%-10d%-10s%-12s%-10s%-10d%-10s", ctr, cur->Name, cur->Kind, cur->Type, tar_scope, cur->Attribute);
		cur = cur->next;
		ctr++;
	}
	printf("\n\n");
	scope[tar_scope] = NULL;
}

void ysemError(short type)
{
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d: %s", yylineno+1, buf);
    if(type==1)
        printf("\n| %s %s", "Undeclared variable", errID);
    else if(type==2)
        printf("\n| %s %s", "Undeclared function", errID);
    else if(type==3)
        printf("\n| %s %s", "Redeclared variable", errID);
    else if(type==4)
        printf("\n| %s %s", "Redeclared function", errID);
    printf("\n|-----------------------------------------------|\n\n");
}