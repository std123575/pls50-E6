#include <stdio.h>

/* Orismos basis os statheras */
int const base = 2;

int main(void)
{
    /* Orismos metabliton */
    int dec, bin;

    /* Emfanisi titlou */
    printf("Metatropi akeraiou se antistrofo dyadiko\n");

    /* Emfanisi keimenoy kai diabasma arithmoy
       mexri na dothei enas thetikos */
    do {
        printf("Doste enan theriko akeraio: ");
        scanf("%d", &dec);

        /* Elegxos an o arithmos einai thetikos, an oxi emfanish mhnymatos */
        if(dec < 0)
        {
            printf("\nEpitrepontai mono **THETIKOI** akeraioi arithmoi\n");
        }

    } while(dec < 0);

    /* Emfanish titlou apotelesmatos */
    printf("\nAnaparasthash toy %d se antistofo dyadiko: ", dec);

    /* Ektelesh praxeon mexri to dec na einai megalytero toy mhden */
    while (dec > 0) {

        /* Dose sthn bin to ypoloipo ths diaireshs toy
           trexontos arithmou me thn base (2) */
        bin = dec % base;

        /* An to ypoloipo einai 0 grapse 1, allios grapse 0 */
        putchar(bin ? '1' : '0');

        /* These os trexon arithmo (dec) to akeraio phliko ths
           diaireshs toy eaytoy tou me thn base (2) */
        dec /=  base;
    }
    printf("\n");

    /* Termatismos programmatos */
    return 1;
}
