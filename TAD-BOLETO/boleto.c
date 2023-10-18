#include "boleto.h"
#include "Data.h"

/* TAD: Boleto (n�, valor, data de Vencimento) */

//--------------
// Implementa��o
//--------------

struct boleto {
	int num;
	float valor;
	tData* dtVenc;
};
	

/* Fun��es exportadas */
/* Fun��o cria - Aloca e retorna um boleto*/
	tBoleto* bol_cria(int n, float valor, tData* dtVenc) {
		tBoleto* b = (tBoleto*)malloc(sizeof(struct boleto));
		b->num= n;
		b->valor = valor;
		b->dtVenc = dtVenc;	
		return b;
	}

/* Fun��o libera � Libera  mem�ria de um Boleto criado */
	void bol_libera(tBoleto* p) {
		free(p);
	}

/* Fun��o acessa - Retorna os valores de um Boleto */
	void bol_acessa(tBoleto* p, int* n, float* val, tData* dtVenc) {
		*n = p->num;
		*val = p->valor;
		dtVenc = p->dtVenc;
		return;

	}

/* Fun��o atribui - Atribui novos valores ao Boleto */
	void bol_atribui(tBoleto* b, int n, float val, tData* dtVenc) {
		b->num = n;
		b->valor = val;
		b->dtVenc = dtVenc;
		return ;
}


/* Fun��o Exibe � Mostra os dados do Boleto na tela */
	void bol_exibe(tBoleto* p) {
		printf("Num: %03d Valor R$%.2f Data de Vencimento: %s", p->num, p->valor, dta_getData(p->dtVenc));
		return;
	}

/* Fun��o getBoleto - Retorna uma string com os valores do boleto */
	char* bol_getBoleto(tBoleto* p) {
		char* b;
		b = (char*)malloc(sizeof(*p)+21);
		sprintf(b, "%03d - R$%.2f - %s", p->num, p->valor, dta_getData(p->dtVenc));
		return b;
	}