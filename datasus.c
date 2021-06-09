#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

#define database "PA"
#define year "10"

int main() {
    char *states[] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};
    char *months[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    
    char ad[80] = "ftp://ftp.datasus.gov.br/dissemin/publicos/SIASUS/200801_/Dados/";
    int i, j;

    #pragma omp parallel for private(i,j)
    for (i=0; i<=26; i++) {
        for (j=0; j<=11; j++) {
            char url[120] = "";
            strcpy(url, ad);
            strcat(url, database);
            strcat(url, states[i]);
            strcat(url, year);
            strcat(url, months[j]);
            strcat(url, ".dbc");
            // printf("%s\n", url);
            char cmd[140];
            strcpy (cmd, "wget ");
            strcat (cmd, url);
            system (cmd);
        }
    }
}
