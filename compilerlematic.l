/** Seccion de definiciones **/
%{
#include "compilersintactic.tab.h"
extern int yylineno;
%}

/** Seccion de reglas **/
identificador 	[a-z][a-zA-Z0-9]{0,10}
entero        	-?[0-9]{0,10}  
float 			-?[0-9]+\.[0-9]+
string      	\'[^\']*\' 

%%
"labuena"   		{return TRUE;}
"lamala"    		{return FALSE;}
"start"      		{return VARS; }
"startI"			{return VARI;}
"startF"			{return VARF;}
"startB"			{return VARB;}
"dele"				{return CDO;}
"vamo"				{return CWHILE;}
"aTerminar"  		{return FWHILE;}
"paLante"			{return CFOR;}
"aTerminal"  		{return FFOR;}
"vamoSi"			{return CIF;}
"aTerminarpues" 	{return FIF;}
"siNoVamos" 		{return CEL;}
"hagalePues" 		{return FUN;}
"tome"				{return RET;}
"trueque"			{return STH;}
"incidente"			{return CASE;}
"rompido"			{return BRK;}
"efecto"			{return DUT;}
"pruebe"			{return TRY;}
"pille"				{return CATCH;}
{identificador}   	{yylval.strval = strdup(yytext); return IFR; }
{entero}      		{yylval.intval = atoi(yytext);return INT;}
{float}				{yylval.floatval = atof(yytext);return FLT;}
{string}			{yylval.strval = strdup(yytext);return STG; }
=					{return ASIG; }
== 					{return IGU;}
"!="				{return DIF;}
"<"					{return MEQ;}
">"					{return MAQ;}
"<="				{return MEIQ;}
">="				{return MAIQ;}
\&\&				{return AND;}
\!					{return NEG;}
\|\|				{return OR;}
\+					{return MAS;}
\~					{return MEN;}
\*					{return MUL;}
\/					{return DIV;}
\%					{return MOD;}
\(					{return APT;}
\)					{return CPT;}
\{					{return ACH;}
\}					{return CCH;}
\:					{return TWP;}
\,					{return COMA;}
\$  				{return ENDVAR; }
[\n]				{yylineno++;}
[ \t]       		{/* Ignorar espacios */}
.             		{printf("Error lexico token desconocido: ' %s ' en la linea: %i\n", yytext, yylineno);}
%%
/** Seccion de codigo de usuario **/
int yywrap (){
	return 1;
}
