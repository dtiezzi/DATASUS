#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

#define database "PA"
#define year "10" // define the year you want to download

int main() {
    char *states[] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "
RS", "RO", "RR", "SC", "SE", "SP", "TO"};
    char *sp_state[] = {"SP"};
    char *months[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    char *sp_months[] = {"01a","01b","01c","02a","02b","02c","03a","03b","03c","04a","04b","04c","05a","05b","05c","06a","06b","06c","07a","07b
","07c","08a","08b","08c","09a","09b","09c","10a","10b","10c","11a","11b","11c","12a","12b","12c"};

    char ad[80] = "ftp://ftp.datasus.gov.br/dissemin/publicos/SIASUS/200801_/Dados/";
    int i, j;
    int y = atoi(year);

    #pragma omp parallel for private(j)
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
            //printf("%s\n", cmd);
            system (cmd);
        }
    }

	if (y >= 13) {
        for (j=0; j<=35; j++) {
            char url[120] = "";
            strcpy(url, ad);
            strcat(url, database);
            strcat(url, sp_state[0]);
            strcat(url, year);
            strcat(url, sp_months[j]);
            strcat(url, ".dbc");
            // printf("%s\n", url);
            char cmd[140];
            strcpy (cmd, "wget ");
            strcat (cmd, url);
            //printf("%s\n", cmd);
            system (cmd);
        }
    }
}

