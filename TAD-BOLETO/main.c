#include "Data.h"
#include <stdio.h>
#include <stdio.h>
#include "boleto.h"

int main(void) {

	tData* dtCompra;
	int dia=9, mes=9, ano=2022, n=4, i;
	float valor=1000, parcela;
	tBoleto* boleto;
	//Ler(&dia, &mes, &ano, &valor, &n);
	parcela = valor / n;
	dtCompra = dta_cria(dia, mes, ano);
	for (i = 0; i < n; i++) {
		boleto = bol_cria(i + 1, parcela,   dta_intervalo(dtCompra, i * 20));
		bol_exibe(boleto);
		bol_libera(boleto);
		
		printf("\n");
	};
	return 0;
}
