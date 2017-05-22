#include <stdio.h>

/* Elegxos an h thesi einai se aristero parathyro */
int isLeftWindow(int maxSeats, int seat)
{
    /* Epistrefei 1 an h thesi einai se tetrada kai to ypoloipo
       ths diareshs me 4 einai 1, h an einai se pentada kai einai
       h proth thesi */
    return (seat <= maxSeats - 5 && seat % 4 == 1) || (seat == maxSeats - 4);
}

/* Elegxos an h thesi einai se deksi parathyro */
int isRightWindow(int maxSeats, int seat)
{
    /* Epistrefei 1 an h thesi einai se tetrada kai to ypoloipo
       ths diareshs me 4 einai 0, h an einai se pentada kai einai
       h pempth thesi */
    return (seat <= maxSeats -5 && !(seat % 4)) || (seat == maxSeats);
}

/* Elegxos an h thesi einai se parathyro */
int isWindow(int maxSeats, int seat)
{
    /* An kapoia apo tis isLeftWindow H isRightWindow
       epistrepsei 1 = h thesi einai se parathyro */
    return isLeftWindow(maxSeats, seat) || isRightWindow(maxSeats, seat);
}

/* Emfanisi menu */
void showMenu(void)
{
    printf("\n");
    printf("1. Emfanisi kenon theseon\n");
    printf("2. Kratisi sygkekrimenis thesis\n");
    printf("3. Evresi kai kratisi proths diathesimis thesis se parathiro\n");
    printf("4. Akirosi kratisis thesis\n");
    printf("5. Anazitisi thesis an einai kratimeni\n");
    printf("6. Lista kratimenon theseon\n");
    printf("7. Emfanisi pinakidas kai diagrammatos theseon\n");
    printf("8. Apothikeysi pinakidas kai diagrammatos sto layout.txt\n");
    printf("------------------------------------------------------------\n");
    printf("0. Eksodos\n");
    printf("\nEpilogi: ");
}

/* Emfanisi kenon theseon */
void showBlanks(int layout[], int maxSeats)
{
    /* Orismos metabliton */
    int i, blanks = 0;

    /* Emfanisi titlou */
    printf("\nDiathesimes theseis\n");
    printf("-------------------\n");

    /* Elegxos gia oles tis theseis */
    for(i = 0; i < maxSeats; i++)
    {
        /* Elegxos an i thesi einai diathesimi */
        if(!layout[i])
        {
            /* Typose ena komma an einai na typosei
               to deytero stoixeio ths grammhs */
            if(blanks % 10)
            {
                printf(", ");
            }

            /* H thesi einai eleytheri, ayksise ton metriti blanks */
            blanks++;

            /* An i thesi einai parathyro balth se aggyles
              allios emfanise th xoris aggyles */
            if(isWindow(maxSeats, i+1))
            {
                printf("[%d]", i+1);
            } else {
                printf("%d", i+1);
            }

            /* Kathe 10 stoixeia, allakse grammh */
            if(!(blanks % 10))
            {
                /* Allakse grammi */
                printf("\n");
            }
        }
    }

    /* H blanks exei parameinei 0=Den brethike kamia kratimeni thesi */
    if(!blanks)
    {
        /* Emfanisi mhnymatos */
        printf("Den yparxei kamia diathesimi thsei!\n");
    } else {
        /* Typose to synolo ton kenon theseon */
        printf("\nSynolo: %d\n", blanks);
    }
}

/* Kratisi thesis */
void reserveSpecific(int layout[], int maxSeats, int seat)
{
    /* An h seat exei thn timh 0, diabase thesi */
    if(!seat)
    {
        printf("\nDoste arithmo thesis: ");
        scanf("%d", &seat);
    }

    /* Elegxos an h thesh einai mesa sto sosto eyros */
    if(seat <= maxSeats)
    {
        /* Elegos an i thesi einai diathesimi */
        if(!layout[seat - 1])
        {
            /* Dose thn timh 1 ston pinaka */
            layout[seat - 1] = 1;

            /* Emfanisi mhnymatos */
            printf("H thesi kratithike\n");

        /* H thesi DEN einai diathesimi */
        } else {

            /* Emfanisi mhnymatos */
            printf("H thesi einai HDH kratimeni, epilexte allh!\n");
        }

    /* O arithmos thesis den einai egkyros (>53) */
    } else {

        /* Emfanisi mhnymatos */
        printf("Prepei na dosete enan egkyro arithmo thesis (Max = %d)\n", maxSeats);
    }
}

/* Kratisi protis diathesimis thesis se parathyro */
void reserveFreeWindow(int layout[], int maxSeats)
{
    /* Orismos metabliton */
    int i;

    /* Elegxos (arxika) olon ton theseon */
    for(i = 0; i < maxSeats; i++)
    {
        /* Elegxos an h thesi ston pinaka exei thn timh
           0 (=diathesimi) KAI einai se parathyro */
        if(!layout[i] && isWindow(maxSeats, i+1))
        {
            /* Emfanisi mhnymatos */
            printf("\nH proti diathesimi thesi se parathyro einai h [%d]\n", i + 1);

            /* Kane thn krathsh kalontas thn reserveSpecific
               kai dinontas sygkekrimeni thesi */
            reserveSpecific(layout, maxSeats, i+1);

            /* Stamata thn ektelesh tou brogxoy, bethike thesi */
            break;
        }
    }

    /* O borgxos teleiose, an to i exei timh megalyterh
       apo tis diathesime theseis = den yparxei thesi se parathyro */
    if(i >= maxSeats)
    {
        /* Emfanisi mhnymatos */
        printf("\nDen yparxei diathesimi thesi se parathyro!\n");
    }
}

/* Akyrosi thesis */
void cancelSpecific(int layout[], int maxSeats)
{
    /* Orismos metabliton */
    int seat;

    /* Diabasma thesis apo to pliktrologio */
    printf("\nDoste arithmo thesis: ");
    scanf("%d", &seat);

    /* Elegxos an h thesh einai mesa sto sosto eyros */
    if(seat <= maxSeats)
    {
        /* Elegos an i thesi einai ontos kratimeni */
        if(layout[seat - 1])
        {
            /* Dose thn timh 0 ston pinaka (eleytheri)*/
            layout[seat - 1] = 0;

            /* Emfanisi mhnymatos */
            printf("H thesi akyrothike\n");

        /* H thesi einai HDH eleytherh */
        } else {

            /* Emfanisi mhnymatos */
            printf("H thesi DEN einai kratimeni, epilexte allh!\n");
        }

    /* O arithmos thesis den einai egkyros (>53) */
    } else {
        /* Emfanisi mhnymatos */
        printf("Prepei na dosete enan egkyro arithmo thesis (Max = %d)\n", maxSeats);
    }
}

/* Emfanisi listas kratimeno theseon */
void showReserved(int layout[], int maxSeats)
{
    /* Orismos metabliton */
    int i, c = 0;

    /* Emfanisi titlou */
    printf("\nKratimenes theseis\n");
    printf("------------------\n");

    /* Elegxos gia oles tis theseis */
    for(i = 0; i < maxSeats; i++)
    {
        /* Elegxos an i thesi einai kratimeni */
        if(layout[i])
        {
            /* H thesi einai kratimeni, ayksise ton metriti c */
            c++;

            /* Emfanisi titloy me aykson arithmo */
            printf("Thesi %d: ", c);

            /* An i thesi einai parathyro balth se aggyles
              allios emfanise th xoris aggyles */
            if(isWindow(maxSeats, i+1))
            {
                printf("[%d]", i+1);
            } else {
                printf("%d", i+1);
            }

            /* Allakse grammi */
            printf("\n");
        }
    }

    /* To c exei parameinei 0=Den brethike kamia kratimeni thesi */
    if(!c)
    {
        /* Emfanisi mhnymatos */
        printf("Den yparxei kamia kratimeni thesi!\n");
    }
}

/* Elegxos an mia sygkekrimeni thesi einai kratimeni */
void checkReservedSpecific(int layout[], int maxSeats)
{
    /* Orismos metabliton */
    int seat;

    /* Diabasma thesis apo to pliktrologio */
    printf("\nDoste arithmo thesis: ");
    scanf("%d", &seat);

    /* Elegxos an i thesi einai egkyri */
    if(seat <= maxSeats)
    {

        /* An i thesi einai kratimeni (timh ston pinaka=1)
           emfanise mynhma, allios shmainei pos den einai
           (timh ston pinaka=0) kai emfanise antistoixo
           mynhma */
        if(layout[seat - 1])
        {
            /* Emfanisi mhnymatos */
            printf("H thesi einai kratimeni\n");
        } else {
            /* Emfanisi mhnymatos */
            printf("H thesi DEN einai kratimeni apo allon\n");
        }

    /* O arithmos thesis den einai egkyros (>53) */
    } else {
        /* Emfanisi mhnymatos */
        printf("Prepei na dosete enan egkyro arithmo thesis (Max = %d)\n", maxSeats);
    }
}

/* Emfanisi pinakidas+planou theseon stin othoni */
void showPlan(int layout[], int maxSeats, char plate[])
{
    /* Orismos metabliton */
    int i, c;

    /* Emfanisi pinakidas */
    printf("\n%s\n", plate);

    /* Brogxos poy eketeleitai toses fores oses kai
       oi seires-1 me bhma 4 */
    for(i = 0; i < (maxSeats - 5); i += 4)
    {
        /* Brogxos poy ekteleitai gia kathe thesei ths seiras */
        for(c = 0; c <= 3; c++)
        {
            /* Edo h i exei kathe fora th thesi ths proths
               thesis ths sygkekrimenhs seiras ston pinaka kai
               to athroisma ths me th c tha mas dosei th thesi
               tis sygkekrimenis thesis ston pinaka. An einai 1
               emfanise *, allios emfanise _ */
            putchar(layout[i+c] ? '*' : '_');

            /* An typosame th deyterh thesi ths seiras, typose ena keno */
            if(c == 1)
            {
                putchar(' ');
            }
        }

        /* Allakse grammi */
        printf("\n");
    }

    /* Antistoixos elegxos, MONO gia teleytaia seira
       epeidh edo oi thesei einai 5 kai oxi 4, kai epipleon den
       xreiazetai keno, me timh ekkinishs ths i th
       thesi toy pinaka poy ksekinane oi teleytaies 5 theseis */
    for(i = maxSeats - 5; i < maxSeats; i++)
    {
        /* Typose * an i thesi einai kratimeni, allios _ */
        putchar(layout[i] ? '*' : '_');
    }

    /* Allakse grammi */
    printf("\n");
}

/* Apothikeysi pinakidas+planou theseon se arxeio */
void writePlanFile(int layout[], int maxSeats, char plate[])
{
    /* Orismos metabliton */
    FILE *plan;
    int i, c;

    /* Anoigma arxeioy layout.txt gia grapsimo */
    plan = fopen("layout.txt", "w");

    /* Grapsimo proths grammhs me tin pinakida */
    fprintf(plan, "%s\n", plate);

    /* Brogxos poy eketeleitai toses fores oses kai
   oi seires-1 me bhma 4 */
    for(i = 0; i < (maxSeats - 5); i += 4)
    {
        /* Brogxos poy ekteleitai gia kathe thesei ths seiras */
        for(c = 0; c <= 3; c++)
        {
            /* Edo h i exei kathe fora th thesi ths proths
               thesis ths sygkekrimenhs seiras ston pinaka kai
               to athroisma ths me th c tha mas dosei th thesi
               tis sygkekrimenis thesis ston pinaka. An einai 1
               grapse sto arxeio *, allios grapse _ */
            putc(layout[i+c] ? '*' : '_', plan);

            /* An grapsame th deyterh thesi ths seiras, grapse ena keno */
            if(c == 1)
            {
                putc(' ', plan);
            }
        }

        /* Grapse ton xarakthra allaghs grammis */
        fprintf(plan, "\n");
    }

    /* Antistoixs elegxos, MONO gia teleytaia seira
      epeidh edo oi thesei einai 5 kai oxi 4, kai epipleon den
      xreiazetai keno, me timh ekkinishs ths i th
      thesi toy pinaka poy ksekinane oi teleytaies 5 theseis */
    for(i = maxSeats - 5; i < maxSeats; i++)
    {
        /* Grapse sto arxeio * an i thesi einai kratimeni, allios _ */
        putc(layout[i] ? '*' : '_', plan);
    }

    /* Grapse ton xarakthra allaghs grammis */
    fprintf(plan, "\n");

    /* Kleise to arxeio */
    fclose(plan);

    /* Emfanise mynhma */
    printf("H pinakida kai to diagramma theseon apothikeytikan sto layout.txt\n");
}

/* Kyrios programma */
int main(void)
{
    /* Orismos metabliton */
    char plate[7], option;
    int maxSeats, layout[53], i;
    FILE *bus;

    /* Anoigma arxeiou */
    bus = fopen("I:\\Personal\\Education\\EAP\\PLS\\PLS50\\GE1\\CLion\\Exercise4\\bus.txt", "r");

    /* Diabasma dedomenon apo arxeio */
    fscanf(bus, "%s %d", plate, &maxSeats);

    /* Kleisimo arxeiou */
    fclose(bus);

    /* An afairesoume 5 theseis apo aytes poy diabasame
       oi ypoloipes kanoyn tetrades? (ypoloipo=0) */
    if((maxSeats - 5) % 4)
    {
        /* Emfanisi mhnymatos */
        printf("Adynatos syndyasmos arithmoy theseon (%d)\n", maxSeats);
        printf("Prepei na isxyei Theseis=4xTheseis + 5 (Theseis >= 0)\n");

    /* Oi theseis kanoun tetrades, alla mhpos einai > 53? */
    } else if(maxSeats > 53) {
        /* Emfanisi mhnymatos */
        printf("Adynato plithos theseon (%d)\n", maxSeats);
        printf("Oi theseis den prepei na einai pano apo 53\n");

    /* O aritmos theseon einai egkyros */
    } else {

        /* Arxikopoihsh pinaka layout me oles
           tis theseis diathesimes */
        for(i = 0; i < maxSeats; i++)
        {
            layout[i] = 0;
        }

        /* Ektelesh brogxou mexri na epilegei to 0=exodos */
        do
        {
            /* Emfanisi menu */
            showMenu();
            /* Diabasma epiloghs */
            scanf(" %c", &option);

            /* Elegxos epiloghs */
            switch (option)
            {
            case '1':
                showBlanks(layout, maxSeats);
                break;
            case '2':
                reserveSpecific(layout, maxSeats, 0);
                break;
            case '3':
                reserveFreeWindow(layout, maxSeats);
                break;
            case '4':
                cancelSpecific(layout, maxSeats);
                break;
            case '5':
                checkReservedSpecific(layout, maxSeats);
                break;
            case '6':
                showReserved(layout, maxSeats);
                break;
            case '7':
                showPlan(layout, maxSeats, plate);
                break;
            case '8':
                writePlanFile(layout, maxSeats, plate);
                break;
            case '0':
                break;

            /* Egkyrh epilogh */
            default:
                /* Emfanisi mhnymatos */
                printf("H epilogh poy dosate den einai egkyrh!\n");
                break;
            }
        } while(option != '0');

        /* Exodos kanonikh */
        return 1;
    }

    /* Exodos logo sfalmatos */
    return 0;
}