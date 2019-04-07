#pragma once
//================================= Registros ==================================
struct horario {
	int hora = 0;			//valor default
	int minuto = 0;			//valor default
};

struct questoes {
	int dificuldade;
	horario inicio;
	horario final;
};

struct participantes {
	char nome[20];
	questoes * ponteiroQuestao;
};

struct media {
	double dificuldade = 0;	//valor default
	double tempo = 0;		//valor default
};
//===========================================================================

//================================= Fun��es =================================
//prototipos
void funcaoTraco(char, int);
void funcParticipante(questoes*, int);
void funcQuestao(participantes*, int, int); //fun��o implemetada por min para exibir as questoes.
media funcaoMediaQuestao(questoes*, int, int, int);

//processos operator para horario.
istream &operator >> (istream &input, horario &p);	//Defini��o do operador cin
ostream &operator << (ostream &output, horario &p);	//Defini��o do operador cout
int operator-(horario p, horario h);				//Defini��o da opera��o "-"
//===========================================================================

