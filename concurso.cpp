#include <iostream>
using namespace std;

#include <iomanip> //para usar o setfill() e setw()
#include "concurso.h"

void funcaoTraco(char alpha, int quant) {
	//laço for repete o numero de vezes o caractere passado
	for (int i = 0; i < quant; i++) {
		cout << alpha;
	}
	cout << endl; // pula a linha final
}

void funcParticipante(questoes* questao, int quant) {
	/*
		Esta função é responsavel por gerar a seguinte saida:
		Nome:
			Questao (dificuldade) inicio as final (tempo em min)
	*/
	char letra = 'A'; //letra que irá aparecer referente a questao.
	int lt = 0;	//variavel que irá fazer a letra alterar de acordo com quantas vezes o loop foi realizado 

	for (int i = 0; i < quant; i++) {
		cout << "\t"; cout << char(letra + lt++); //soma do int char com a quantidade de vezes que o loop repetiu 
		cout << " (" << (questao + i)->dificuldade << ") ";; //mostra a dificuldade
		cout << (questao + i)->inicio << " as " << (questao + i)->final;//mostra o horario inicial e depois o horario final
		cout << " (" <<  (questao + i)->final - (questao + i)->inicio << "min)";//exibe a diferença do horario final menos o inicial
		cout << endl;
	}
}

void funcQuestao( participantes* participante, int quant, int numQuestoes) {
	/*
	Esta função é responsavel por gerar a seguinte saida:
	Questao:
		Nome (dificuldade) inicio as final (tempo em min)
	*/
	for (int i = 0; i < (numQuestoes); i++) {
		cout << "\t" << (participante + i)->nome;//mostra o nome do usuario
		cout << " (" << ((participante + i)->ponteiroQuestao  + quant)->dificuldade << ") "; //mostra a dificuldade
		cout << ((participante + i)->ponteiroQuestao + quant)->inicio << " as " 
			<< ((participante + i)->ponteiroQuestao + quant)->final;//mostra o horario inicial e depois o horario final
		cout << " (" << ((participante + i)->ponteiroQuestao + quant)->final 
			- ((participante + i)->ponteiroQuestao + quant)->inicio  << "min)";//exibe a diferença do horario final menos o inicial
		cout << endl;
	}
}

media funcaoMediaQuestao(questoes* questao, int tamVet, int IndicElement, int tamPasso) {
	media result;
	for (int i = IndicElement; i < tamVet; i += tamPasso) {
		result.dificuldade += (questao + i)->dificuldade; //soma a dificuldade da questão
		result.tempo += (questao + i)->final - (questao + i)->inicio; //soma os tempos da questão
	}
	result.dificuldade /= tamPasso;
	result.tempo /= tamPasso;

	return result;
}

//Operador >> definido para o tipo horario
istream &operator >> (istream &input, horario &p) {
	char let;
	input >> p.hora >> let >> p.minuto; //Ler HH : MM ler um inteiro hora, um char : e um inteiro hora
	return input;
}

//Operador << definido para o tipo horario
ostream &operator << (ostream &output, horario &p) {
	//O uso de setw e setfill foi para resolver o problema da simplificação do cout, exemplo, o horario passado no cin 6:05 iria aparecer 6:5.
	//Agora com o setw e setfill é garantido a forma HH:MM pois é colocado o '0' antes dos numeros caso eles nao ocupem 2 espaços. 
	output << setfill('0') << setw(2);
	output << p.hora; //mostra a hora com duas casas decimais, caso nao possua as duas casas a casa da esquerda é ocupada por um 0
	output << ":"; //mostra os dois pontos centrais
	output << setfill('0') << setw(2);
	output << p.minuto;//mostra os minutos com duas casas decimais, caso nao possua as duas casas a casa da esquerda é ocupada por um 0
	output  <<  setfill(' ') << setw(0);
	return output;
}

int operator-(horario p, horario h) {
	//faz a subtração de horarios, retornando em minutos.
	return (p.hora - h.hora) * 60 + (p.minuto - h.minuto); 
}