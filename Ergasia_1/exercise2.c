#include <stdio.h>
#include <math.h> /* Aparaithto gia th stathera M_PI kai th synarthsh sqrt */

/* Emfanish menu */
void showMenu(void)
{
    printf("Ypologismos perimetrou\n");
    printf("Epilexte geometriko sxhma\n");
    printf("-------------------------\n");
    printf("1. Tetragono\n");
    printf("2. Parallhlogrammo\n");
    printf("3. Orthogonio trigono\n");
    printf("4. Kyklos\n");
    printf("-------------------------\n");
    printf("0. Exodos\n");
    printf("\nDoste epilogh: ");
}

/* Perimetros tetragonou: plevra * 4 */
float tetragono(float factor)
{
    return factor * 4;
}

/* Perimetros parallhlogrammou: 2*mhkos + 2*platos */
float parallhlogrammo(float factor1, float factor2)
{
    return 2* (factor1 + factor2);
}

/* Perimetros orthogoniou trigonou:
   Ypoteinousa = sqrt(Katheti1^2 + Katheti2^2)
   Katheti1 + Katheti2 + Ypoteinousa */
float trigono(float factor1, float factor2)
{
    return factor1 + factor2 + sqrt(factor1*factor1 + factor2*factor2);
}

/* Perimetros kykloy: 2 * PI * aktina */
float kyklos(float factor)
{
    return 2 * M_PI * factor;
}

int main(void)
{
    /* Orismos metabliton */
    float factor1, factor2;
    char choice;

    /* Ektelesh oso h epilogh den einai 0 */
    do {
        /* Emfanisi menu me klhsh function kai diabasma epiloghs */
        showMenu();
        scanf(" %c", &choice);

        /* Tetragono */
        if(choice == '1')
        {
            /* Diabasma mhkouys plevras */
            printf("\nDoste mhkos pleyras tetragonou: ");
            scanf("%f", &factor1);

            /* Apotelesma */
            printf("H perimetros tetragonou me diastaseis %.2fx%.2f ", factor1, factor1);
            printf("einai %.2f\n\n", tetragono(factor1)); /* Apotelesma synarthshs */
        }

        /* Parallhlogrammo */
        else if(choice == '2')
        {
            /* Diabasma mhkoys kai platous */
            printf("\nDoste mhkos parallhlogrammou: ");
            scanf("%f", &factor1);
            printf("Doste platos parallhlogrammou: ");
            scanf("%f", &factor2);

            /* Apotelesma */
            printf("H perimetros parallhlogrammou me diataseis %.2fx%.2f ", factor1, factor2);
            printf("einai %.2f\n\n", parallhlogrammo(factor1, factor2)); /* Apotelesma synarthshs */
        }

        /* Orthogonio trigono */
        else if(choice == '3')
        {
            /* Diabasma mhkoys katheton plevron */
            printf("\nDoste mhkos proths kathetis plevras tou orthogoniou trigonou: ");
            scanf("%f", &factor1);
            printf("Doste mhkos deyterhs kathetis plevras tou orthogoniou trigonou: ");
            scanf("%f", &factor2);

            /* Apotelesma */
            printf("H perimetros orthogoniou trigonou me kathetes\n");
            printf("pelvres %.2f kai %.2f ", factor1, factor2);
            printf("einai %.2f\n\n", trigono(factor1, factor2)); /* Apotelesma synarthshs */
        }

        /* Kyklos */
        else if(choice == '4')
        {
            /* Diabasma aktinas */
            printf("\nDoste mhkos aktinas kyklou: ");
            scanf("%f", &factor1);

            /* Apotelesma */
            printf("H perimetros kyklou me aktina %.2f einai ", factor1);
            printf("%.2f\n\n", kyklos(factor1)); /* Apotelesma synarthshs */
        }

        /* Elegxos an dothike lathos epilogi */
        else if(choice != '0')
        {
            /* Emfanisi mynhmatos */
            printf("\nParakalo epilixte mia apo tis diathesimes epiloges, 0 eos 4\n\n");
        }

    /*  Eite yphrxe apotelesma eite dothike lathos epilogi
        epestrepse sthn arxh gia neo ypologismo mexri
        o xristis na patisei mhden */
    } while(choice != '0');

    /* Exodos me 1 (epityxhs) */
    return 1;
}
