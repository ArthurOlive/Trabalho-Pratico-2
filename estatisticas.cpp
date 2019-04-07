/*
	Autor: Arthur Vitor Matias de Oliveira.
	Professor: Judson Santos Santiago
	Disciplina: Programação de computadores;
	data: 07/01/19
*/

#include <iostream>
using namespace std;
#include "concurso.h"

int main() {
	int numParticipantes , numQuestoes;//variaveis de controle de loop.
	
	//========================= Mensagem inicial ================================
	funcaoTraco('*', 53);

	cout << "Concurso de programacao\n\n";
	
	cout << "Qual o numero de participantes? ";
	cin >> numParticipantes; //Recebe a quantidade de participantes para inicializar o vetor
	cout << "Qual o numero de questoes? ";
	cin >> numQuestoes;		 //Recebe a quantidade de questoes para inicializar o vetor
	cout << endl;

	funcaoTraco('*', 53);
	//===========================================================================
	
	cin.ignore(); //limpa o buffer do teclado.

	//===================== cria os vetores dinamicos ============================

	 //Inicia um vetor dinamico de um registro, que contem um nome e um ponteiro para as questoes.
	participantes *participante = new participantes[numParticipantes];

	//Numero de questoes vezes o numero de participantes para que se tenha questoes para cada participante.
	questoes *questao = new questoes[(numQuestoes*numParticipantes)];	

	int pontControl = 0; // controle para mudar o participantes dentro do laço for.
	
	for (int i = 0; i < (numQuestoes*numParticipantes); i += numQuestoes) {
		//O ponteiro do registro de participantes sera organizado de acordo com o ponteiro do vetor de questoes.
		(participante + pontControl)->ponteiroQuestao = (questao+i); 
		pontControl++;	//Passa para o proximo participante.
	}

	//===========================================================================

	//============ Leitura dos valores digitados pelo usuario ===================
	for (int vez = 0; vez < numParticipantes;  vez++) {
		//A variavel de controle vez, altera para o proximo participante.

		funcaoTraco('-', 13);
		cout << "Participante: ";
		cin.getline((participante+vez)->nome, 20);//recebe o nome do participante
		funcaoTraco('-', 13);

		char letra = 'A'; //define a letra que irá aparecer na frente da questao

		/*
		 Utilizando do ponteiro o armazenamento sera feito pela referencia do ponteiro, 
		 para assim evitar a utilização direta do vetor questao.
		*/

		for (int i = 0; i < numQuestoes; i++){
			cout << "Questao " << char(letra + i) << endl;
			cout << "\tDificuldade: ";
			cin >> ((participante + vez)->ponteiroQuestao + i)->dificuldade;//recebe o valor da dificuldade pelo o ponteiro contido no vetor de participante
			cout << "\tInicio : ";
			cin >> ((participante + vez)->ponteiroQuestao + i)->inicio;		//recebe o horario inicial pelo o ponteiro contido no vetor de participante
			cout << "\tFim : ";
			cin >> ((participante + vez)->ponteiroQuestao + i)->final;		//recebe o horario final pelo o ponteiro contido no vetor de participante
		}

		cin.ignore(); //para limpar o buffer do teclado.

		funcaoTraco('-', 13);
		cout << endl;
	}
	//===========================================================================

	//======================= Resumo por usuario ================================

	//variaveis usadas
	char letra = 'A';

	funcaoTraco('*', 53);

	funcaoTraco('-', 24);
	cout << "Resumo por participante\n";
	funcaoTraco('-', 24);

	for(int i = 0; i < numParticipantes; i++){
		cout << (participante + i)->nome << endl;
		funcParticipante((participante + i)->ponteiroQuestao, numQuestoes); //Vetor de questoes, quantidade de questoes a ser exibido, NOVO - inicio do processo.
	}
	funcaoTraco('-', 18);

	cout << endl;

	//===========================================================================

	//======================= Resumo por questao ================================

	funcaoTraco('-', 18);
	cout << "Resumo por questao\n";
	funcaoTraco('-', 18);


	for (int i = 0; i < numQuestoes; i++) {
		cout << "Questao " << char(letra + i) << endl; // Exibe a palavra questao e uma letra em ordem alfabetica começando da letra A.
		//Essa função foi atribuida por min, nao tendo a minima relação com o trabalho padrão, foi implementada para diminuir o codigo.
		funcQuestao(participante, i, numQuestoes); //Vetor de questoes, Vetor de participantes, Numero de participantes, inicio do processo ,quantidade de questoes a ser exibido.
	}

	funcaoTraco('-', 18);
	cout << endl;

	//===========================================================================

	//==================== Estatisticas do concurso =============================

	funcaoTraco('-', 12);
	cout << "Estatisticas\n";
	funcaoTraco('-', 12);

	media medU; //Media para conter a media por questoes.
	media medT; //Media total do concuso.
	letra = 'A';

	for (int i = 0; i < numQuestoes; i++) {
		medU = funcaoMediaQuestao(questao, (numQuestoes*numParticipantes), i, numQuestoes); //Vetor de questoes, Tamanho do vetor, inicio do processo, numero de questões.
		
		//Para definir a precisão de duas casas decimais apos o "." .
		cout << fixed;
		cout.precision(2);

		cout << "Questao " << char(letra + i) << ": ";
		cout << "Dificuldade";
		cout << " (" << (medU.dificuldade) << ")" << " - ";
		cout << "Tempo (" << (medU.tempo) << " minutos)\n";

		//Soma as medias da variavel medU e armazena na variavel medT
		medT.dificuldade += medU.dificuldade;
		medT.tempo += medU.tempo;
	}

	//Para definir a precisão de duas casas decimais apos o "." .
	cout << fixed;
	cout.precision(2);

	cout << "Concurso:  ";
	cout << "Dificuldade";
	cout << " (" << (medT.dificuldade / numQuestoes) << ")" << " - "; //dividi pelo numero de questoes para se fazer a media.
	cout << "Tempo (" << (medT.tempo / numQuestoes) << " minutos)\n"; //dividi pelo numero de questoes para se fazer a media.

	cout << endl;
	funcaoTraco('*', 53);

	//===========================================================================

	//deleta a memoria dinâmica.
	delete [] participante;
	delete [] questao;

	system("pause");
	return 0;
}