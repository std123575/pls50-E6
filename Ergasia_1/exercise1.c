#include <stdio.h>

int main(void)
{
    /* Orismos metabliton */
    float num1, num2, result;
    char praxi;

    /* Emfanisi minimatos me odigies */
    printf("Doste praxi sti morfi: arithmos praxi arithmos\n");
    printf("Doste + gia prosthesi, - gia afairesh, * gia pollaplasiasmo, / gia diairesh.\n");
    printf("Px. 123.45 * 2.3\n");

    /* Diabasma arithmon kai praxis apo to pliktrologio */
    scanf("%f %c %f", &num1, &praxi, &num2);

    /* Elegxos an zitite diairesh me to mhden */
    if(praxi == '/' && num2 == 0)
    {
        printf("Den mporei na ginei diairesh me to mhden.\n");

        /* Exodos me 0 (sfalma) */
        return 0;
    }

    /* Elegxos symbolou praxis */
    switch(praxi)
    {
        /* Prosthesi */
        case '+':
            result = num1 + num2;
            break;

        /* Afairesi */
        case '-':
            result = num1 - num2;
            break;

        /* Pollaplasiasmos */
        case '*':
            result = num1 * num2;
            break;

        /* Diairesh */
        case '/':
            result = num1 / num2;
            break;

        /* Agnosto symbolo praxis */
        default:
            /* Emfanisi minimatos */
            printf("Lathos symbolo praxis, doste + gia prosthesi, - gia afairesh, \n");
            printf("* gia pollaplasiasmo, / gia diairesh.\n");

            /* Exodos me 0 (sfalma)*/
            return 0;
    }

    /* Emfanisi apotelesmatos me 2 dekadika psifia */
    printf("Apotelesma: %.2f\n", result);

    /* Exodos me 1 (epitixys) */
    return 1;
}
