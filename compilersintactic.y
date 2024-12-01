/** Seccion de definiciones **/
%{
#include <stdio.h>
extern int yylex(void);
extern char *yytext;
extern int yylineno;
void yyerror(char *s);
extern FILE *yyin;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { IN, FL, ST, BO, FN } DataType;

#define MAX_SYMBOLS 500


typedef struct {
    char *name;
    DataType type;  
    union {
        int intValue;
        float floatValue;
        char *stringValue;
        int boolValue;  
        char *fnValue;
    } value;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

void addSymbol(char *name, DataType type) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Error: El símbolo '%s' ya está definido.\nError en la linea: %i \n", name, yylineno);
            return;
        }
    }
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Error: Se ha alcanzado el límite máximo de símbolos.\n");
        return;
    }

    symbolTable[symbolCount].name = strdup(name);
    symbolTable[symbolCount].type = type;

    switch (type) {
        case IN:
            symbolTable[symbolCount].value.intValue = 0;
            break;
        case FL:
            symbolTable[symbolCount].value.floatValue = 0.0f;
            break;
        case ST:
            symbolTable[symbolCount].value.stringValue = strdup("");
            break;
        case BO:
            symbolTable[symbolCount].value.boolValue = 0;
            break;
        case FN:
			symbolTable[symbolCount].value.fnValue = strdup("");
            break;
    }
    symbolCount++;
    
}

void *getSymbolValue(char *name, DataType *type) {
    for (int i = 0; i < symbolCount; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            *type = symbolTable[i].type;
            switch (*type) {
                case IN:
                    return &symbolTable[i].value.intValue;
                case FL:
                    return &symbolTable[i].value.floatValue;
                case ST:
                    return symbolTable[i].value.stringValue;
                case BO:
                    return &symbolTable[i].value.boolValue;
                case FN:
					return symbolTable[i].value.fnValue;
            }
        }
    }
    printf("Error: El símbolo '%s' no está definido en la linea: %i.", name, yylineno);
    yyerror("");
    return NULL;
}

void setIntValue(char *name, int value) {
    DataType type;
    int *valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == IN) {
        *valPtr = value;
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}


void setFloatValue(char *name, float value) {
    DataType type;
    float *valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == FL) {
        *valPtr = value;
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}

void setStringValue(char *name, char *value) {
    DataType type;
    char **valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == ST) {
        *valPtr = strdup(value);
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}

void setFnValue(char *name, char *value) {
    DataType type;
    char **valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == FN) {
        *valPtr = strdup(value);
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s'. En la linea: %i .\n", name, yylineno);
    }
}

void setBooleanValue(char *name, int value) {
    DataType type;
    int *valPtr = getSymbolValue(name, &type);
    if (valPtr != NULL && type == BO) {
        *valPtr = value;
    } else {
        printf("Error: Asignación incorrecta de tipo para '%s' en la linea: %i.\n", name, yylineno);
    }
}

%}

%union {
    int intval;
    float floatval;
    char *strval;
    int boolval;
}

%token <intval> INT  
%token <strval> IFR
%token <strval> STG
%token <floatval> FLT
%left MAS MEN
%left MUL DIV MOD
%token TRUE FALSE VARS VARI VARF VARB CDO CWHILE FWHILE CFOR FFOR CIF FIF CEL FUN RET STH CASE BRK DUT TRY CATCH 
%token ASIG IGU DIF MEQ MAQ MEIQ MAIQ AND NEG OR MOD APT CPT ACH CCH ENDVAR TWP COMA
%type <intval> operation_int_exp operation_int
%type <floatval> operation_float_exp operation_float

/** Seccion de reglas **/
%%

program:				declaration
					|	initialization
					|	asignation
					|	if
					|	while
					|	do-while
					|	for
					|	switch
					|	try-catch
					|	function
					|	program declaration
					|	program initialization
					|	program asignation
					|	program if
					| 	program while
					|	program do-while
					|	program for
					|	program switch
					|	program try-catch
					|	program function
					;
					
value:					STG		
					|	INT
					|	FLT
					;

boolean:				TRUE
					|	FALSE	
					;
								
declaration:			VARS IFR ENDVAR {addSymbol($2, ST);}
					|	VARI IFR ENDVAR {addSymbol($2, IN);}
					|	VARF IFR ENDVAR {addSymbol($2, FL);}
					|	VARB IFR ENDVAR {addSymbol($2, BO);}
					;
		
initialization:			VARS IFR ASIG STG ENDVAR {addSymbol($2, ST); setStringValue($2, $4);}
					|	VARI IFR ASIG INT ENDVAR {addSymbol($2, IN); setIntValue($2,$4);}
					|	VARF IFR ASIG FLT ENDVAR {addSymbol($2, FL); setFloatValue($2, $4);}
					|	VARB IFR ASIG TRUE ENDVAR {addSymbol($2, BO); setIntValue($2,1);}
					|	VARB IFR ASIG FALSE ENDVAR {addSymbol($2, BO); setIntValue($2,0);}
					|	VARI IFR ASIG operation_int ENDVAR {addSymbol($2, IN); setIntValue($2, $4);}
					|	VARF IFR ASIG operation_float ENDVAR {addSymbol($2, FL); setFloatValue($2, $4);}
					;

asignation:				IFR	ASIG STG ENDVAR	{setStringValue($1,$3);}
					|	IFR	ASIG INT ENDVAR {setIntValue($1,$3);}
					|	IFR	ASIG FLT ENDVAR	{setFloatValue($1,$3);}
					|	IFR	ASIG TRUE ENDVAR {setIntValue($1,1);}
					|	IFR	ASIG FALSE ENDVAR {setIntValue($1,0);}
					|	IFR ASIG operation_int ENDVAR {setIntValue($1,$3);}
					|	IFR ASIG operation_float ENDVAR {setFloatValue($1,$3);}
					;

asignation_function:	IFR	ASIG value
					|	IFR	ASIG boolean 
					|	IFR ASIG operation_int_exp
					|	IFR ASIG operation_float_exp
					;
					
operation_int:			operation_int_exp
					|	operation_int operation_int_exp
					|	operation_int MAS INT
					|	operation_int MEN INT
					|	operation_int MUL INT
					|	operation_int DIV INT {
							if ($3 == 0) {
								yyerror("División por cero");
								$$ = 0;
							} else {
								$$ = $1 / $3;
							}}
					;

operation_int_exp:		INT MAS INT	{$$ = $1 + $3;}
					|	INT MEN INT	{$$ = $1 - $3;}
					|	INT MUL INT	{$$ = $1 * $3;}
					|	INT MOD INT	{$$ = $1 % $3;}
					|	INT DIV INT {
							if ($3 == 0) {
								yyerror("División por cero");
								$$ = 0;
							} else {
								$$ = $1 / $3;
							}}
					|	INT INT MAS {$$ = $1 + $2;}
					|	INT INT MEN {$$ = $1 - $2;}
					|	INT INT MUL {$$ = $1 * $2;}
					|	INT INT MOD {$$ = $1 % $2;}
					|	INT INT DIV {
							if ($2 == 0) {
								yyerror("División por cero");
								$$ = 0;
							} else {
								$$ = $1 / $2;
							}
					}
					;
					
operation_float:		operation_float_exp
					|	operation_float operation_float_exp
					|	operation_float MAS FLT
					|	operation_float MEN FLT
					|	operation_float MUL FLT
					|	operation_float DIV FLT {
							if ($3 == 0) {
								yyerror("División por cero");
								$$ = 0;
							} else {
								$$ = $1 / $3;
							}}
					;

operation_float_exp:	FLT MAS FLT	{$$ = $1 + $3;}
					|	FLT MEN FLT	{$$ = $1 - $3;}
					|	FLT MUL FLT	{$$ = $1 * $3;}
					|	FLT DIV FLT	{
							if ($3 == 0) {
								yyerror("División por cero");
								$$ = 0;
							} else {
								$$ = $1 / $3;
							}
					}
					|	FLT MOD FLT	{$$ = (int)$1 % (int)$3;}
					|	FLT FLT MAS {$$ = $1 + $2;}
					|	FLT FLT MEN {$$ = $1 - $2;}
					|	FLT FLT MUL {$$ = $1 * $2;}
					|	FLT FLT MOD {$$ = (int)$1 % (int)$2;}
					|	FLT FLT DIV {
							if ($2 == 0) {
								yyerror("División por cero");
								$$ = 0;
							} else {
								$$ = $1 / $2;
							}
					}
					;
					
condition:				value IGU value
					|	boolean IGU boolean
					|	value DIF value
					|	boolean DIF boolean
					|	value MEQ value
					|	value MAQ value
					|	value MEIQ value
					|	value MAIQ value
					|	IFR IGU value
					|	IFR IGU IFR
					|	IFR MEQ value
					|	IFR MAQ value
					|	IFR MEIQ value
					|	IFR MAIQ value
					|	IFR MEQ IFR
					|	IFR MAQ IFR
					|	IFR MEIQ IFR
					|	IFR MAIQ IFR
					;

conditioncomp:			condition AND condition
					|	condition OR condition
					|	NEG APT condition CPT AND condition
					|	condition AND NEG APT condition CPT 
					|	NEG APT condition CPT OR condition
					|	condition OR NEG APT condition CPT 
					;

ifcondition:			APT condition CPT
					|	APT conditioncomp CPT
					|	APT boolean CPT
					;
					
body:					ACH bodies CCH     
					;

bodies:				    body_stmt bodies
					| 	body_stmt
					;

body_stmt:		      	RET value ENDVAR
					| 	BRK ENDVAR
					| 	if                       
					| 	while 
					| 	do-while                   
					| 	for                      
					| 	switch                   
					| 	try-catch                
					| 	function  
					| 	initialization               
					;
					
elsebody:				ACH RET value ENDVAR CCH
					|	ACH BRK ENDVAR CCH
					;	
					
if:						CIF ifcondition body FIF
					|	CIF ifcondition body FIF CEL elsebody
					;

whilecondition:			APT condition CPT		
					|	APT conditioncomp CPT
					| 	APT boolean CPT
					;

while:					CWHILE whilecondition body FWHILE
					;
					
do-while:				CDO body while
					;

for:					CFOR APT VARI IFR ASIG INT ENDVAR condition ENDVAR for_asignation ENDVAR CPT body FFOR
					|	CFOR APT VARF IFR ASIG FLT ENDVAR condition ENDVAR asignation CPT ACH body CCH FFOR

for_asignation:			IFR MAS MAS
					|	IFR MEN MEN
					;

switch: 				STH APT IFR CPT ACH cases CCH
					;

cases:					case
					| 	cases case
					;

case:					CASE value TWP body BRK ENDVAR
					|   DUT TWP body ENDVAR
					;
try-catch:				TRY body CATCH APT IFR CPT body
					;
					
function:				FUN IFR APT parameters CPT body {addSymbol($2, FN);setFnValue($2, $2);}
					|	FUN IFR APT CPT body {addSymbol($2, FN);setFnValue($2, $2);}
					;
parameters:				IFR
					|	asignation_function
					|	parameters COMA IFR
					|   parameters COMA asignation_function
					;

%%

/** Seccion de codigo de usuario **/


void yyerror(char *s) {
    printf("Error sintáctico: %s en la linea: %i\n", s, yylineno);
}

int main(int argc, char **argv){
	printf("Inicio del programa: \n");
	if(argc > 1){
		yyin = fopen(argv[1], "rt");
	}else{
		yyin = stdin;
	}
	yyparse();
	return 0;
}
