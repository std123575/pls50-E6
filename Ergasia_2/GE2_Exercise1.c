#include <stdio.h>
#include <string.h>

// Orismos megistou arithmou theseon leoforeioy
#define MAXSEATS 53

// Orismos domhs gia stoixeia leoforeioy
typedef struct busdata {
    char plate[8];
    unsigned int seats;
} BUSDATA;

// Orismos domhs gia stoixeia epibati
typedef struct passenger {
    char name[41];
    unsigned short tel[10];
    unsigned int seat;
} PASSENGER;

// Metatatroph pinaka 10 unsigned short se string
void tel2str(char *phone, unsigned short tel[])
{
    // Orismos metabliton
    int i;

    for(i=0; i<10; i++)
    {
        // ASCII(48) = 0
        phone[i] = 48 + tel[i];
    }
    phone[i] = '\0';
}


// Metatroph string 10 xaraktiron se pinaka unsigned short
void str2tel(char *phone, unsigned short tel[])
{
    // Orismos metabliton
    int i;

    for(i=0; i<10; i++)
    {
        // ASCII(48) = 0
        tel[i] = phone[i] - 48;
    }
}

// Mhdenismos pinaka me orismo toy onomatos se \0
void initLayout(PASSENGER layout[])
{
    unsigned int i;

    for(i=0; i<MAXSEATS; i++)
    {
        // Bazoyme seat+1 giati to layout ksekinaei apo 0
        layout[i] = (PASSENGER) { .name[0] = '\0', .seat = i+1};
    }
}

// Anagnosi dedomenon apo to arxeio
BUSDATA getDataFromFile(PASSENGER layout[])
{
    // Orismos metabliton
    int i;
    FILE *bus;
    BUSDATA busdata;
    PASSENGER current;
    char first[41], phone[11];
    unsigned short tel[10];

    // Anoigma arxeioy kai diabasma protis grammis
    // poy periexei pinakida kai theseis
    bus = fopen("bus.txt", "r");
    fscanf(bus, "%s %d", busdata.plate, &busdata.seats);

    // Diabasma deyterhs grammhs (an yparxei) kai apothikeysi dedomenon
    // sto current
    fscanf(bus, "%s %s %d %s", current.name, first, &current.seat, phone);
    // O brogxos ekteleitai oso den exoyme ftasei sto telos toy arxeioy
    while(!feof(bus))
    {
        // Metatroph toy phone[11] poy diabasame apo to arxeio
        // se pinaka unsigned short[10] kai balto sto current.tel
        str2tel(phone, current.tel);

        // H current.name exei hdh to eponymo, prosthese keno kai onoma
        strcat(current.name, " ");
        strcat(current.name, first);

        // H current.seat exei th thesi, ara current.seat-1 einai h thesi ston
        // pinaka layout, poy toy dinoyme timh to periexomeno ths current
        layout[current.seat - 1] = current;

        // Diabasma epomenhs grammhs, oste an exei erthei to EOF na bgei
        fscanf(bus, "%s %s %d %s", current.name, first, &current.seat, phone);
    }

    // Kleisimo arxeioy
    fclose(bus);

    // H layout einai pass by reference ara exei ta sosta dedomena
    // Epestrepse thn busdata poy exei pinakida kai theseis
    return busdata;
}

// Emfanisi menu
void showMenu(void)
{
    printf("\n");
    printf("1. Emfanisi kenon theseon\n");
    printf("2. Kratisi sygkekrimenis thesis\n");
    printf("3. Anazitisi thesis an einai kratimeni me onoma/thlefono\n");
    printf("4. Akirosi kratisis thesis\n");
    printf("5. Lista kratimenon theseon\n");
    printf("------------------------------------------------------------\n");
    printf("0. Eksodos\n");
    printf("\nEpilogi: ");
}

// Emfanisi kenon theseon
void showBlanks(PASSENGER layout[], unsigned int maxSeats)
{
    // Orismos metabliton
    int i, blanks = 0;

    // Emfanisi titlou
    printf("\nDiathesimes theseis\n");
    printf("-------------------\n");

    // Elegxos gia oles tis theseis
    for(i = 0; i < maxSeats; i++)
    {
        // Elegxos an i thesi einai diathesimi
        if(layout[i].name[0] == '\0')
        {
            // Typose ena komma an einai na typosei
            // to deytero stoixeio ths grammhs
            if(blanks % 10)
            {
                printf(", ");
            }

            // H thesi einai eleytheri, ayksise ton metriti blanks
            blanks++;

            // Arithmos thesis
            printf("%d", layout[i].seat);

            // Kathe 10 stoixeia, allakse grammh
            if(!(blanks % 10))
            {
                printf("\n");
            }
        }
    }

    // H blanks exei parameinei 0=Den brethike kamia kratimeni thesi
    if(!blanks)
    {
        // Emfanisi mhnymatos
        printf("Den yparxei kamia diathesimi thsei!\n");
    } else {
        // Typose to synolo ton kenon theseon
        printf("\nSynolo: %d\n", blanks);
    }
}

// Kratisi thesis
void reserveSpecific(PASSENGER *seat)
{
    // Orismos metabliton
    char first[41], tel[11];

    // Elegos an i thesi einai diathesimi
    if(seat->name[0] == '\0')
    {
        // Bale to eponymo sthn seat->name
        printf("Doste eponymo epibath: ");
        scanf("%s", seat->name);

        // Diabase to onoma
        printf("Doste onoma epibath: ");
        scanf("%s", first);

        // Bale ena keno sthn seat->name kai meta to onoma
        strcat(seat->name, " ");
        strcat(seat->name, first);

        // Diabasma thlefonoy se morfh char[11]
        printf("Doste thlefono epibath: ");
        scanf("%s", tel);

        // Kane to to thlefono pinaka unsigned short[10]
        // kai balto sthn seat->tel
        str2tel(tel, seat->tel);

        // Emfanisi mhnymatos
        printf("H thesi kratithike\n");

    } else { // H thesi DEN einai diathesimi seat->name != '\0'
        printf("H thesi einai HDH kratimeni, epilexte allh!\n");
    }
}

// Elegxos an mia thesi einai kratimeni
void checkReserved(PASSENGER layout[], unsigned int maxSeats)
{
    char option, first[41], fullname[41], phone[11], curPhone[11];
    unsigned int i, found = 0;

    // Emfanisi epilogon
    printf("\n[1] Anazthsh me onopateponymo\n");
    printf("[2] Anazhthsh me thlefono\n");
    printf("Epilogh: ");

    // Brogxos oso h epilogh den einai 1 h 2
    do {
        scanf(" %c", &option);
        switch(option)
        {
            // Anazhthsh me onomateponymo, diabasma metabliton
            case '1':
                printf("Doste eponymo: ");
                scanf("%s", fullname);
                printf("Doste onoma: ");
                scanf("%s", first);
                strcat(fullname, " ");
                strcat(fullname, first);
                break;

                // Anazhthsh me thlefono, diabasma metabliton
            case '2':
                printf("Doste thlefono: ");
                scanf("%s", phone);
                break;

                // Akyrh epilogh
            default:
                printf("Akyrh epilogh, epilexte 1 h 2!\n");
                break;
        }
    } while(option != '1' && option != '2');

    // Anazhthsh se oles tis theseis
    for(i=0; i<maxSeats; i++)
    {
        // Metatroph toy thelfonoy apo unsigned short[10] se char[11]
        tel2str(curPhone, layout[i].tel);

        // Elegxos an epilogh=onomateponymo kai yparxei taythsh h
        // an epilogh=thlefono kai yparxei taythsh
        // KAI den prokeitai gia mh krathmenh thesh (layout[i].name != '\0')
        if(
                (
                        (option == '1' && strcmp(layout[i].name, fullname) == 0) ||
                        (option == '2' && strcmp(curPhone,  phone) == 0)
                ) &&
                layout[i].name != '\0'
                )
        {
            // Brethike eggrafh, emfanise stoixeia
            printf("H kratisi brethike -> Thesi: %d, Onomateponymo: %s, Thlefono: %s\n", layout[i].seat, layout[i].name, curPhone);
            found = 1;

            // Edo tha mporoyse na mpei ena break; kai na bgoyme apo ton brogxo
            // alla tha xasoyme theseis se periptosh synonymias h idioy thlefonoy
            // break;
        }
    }

    // Den brethike eggrafh
    if(!found)
    {
        printf("Den brethike thesi me ayta ta stoixeia!\n");
    }

}

// Akyrosi thesis
void cancelSpecific(PASSENGER *seat)
{
    // Elegxos an i thesi einai ontos kratimeni
    if(seat->name[0] != '\0')
    {
        // Dose thn timh \0 ston pinaka (eleytheri)
        seat->name[0] = '\0';

        // Emfanisi mhnymatos
        printf("H thesi akyrothike\n");

    } else { // H thesi einai HDH eleytherh

        // Emfanisi mhnymatos
        printf("H thesi DEN einai kratimeni, epilexte allh!\n");
    }
}

// Emfanisi listas kratimeno theseon
void showReserved(PASSENGER layout[], unsigned int maxSeats)
{
    // Orismos metabliton
    int i, c = 0;
    char phone[11];

    // Emfanisi titlou
    printf("\nKratimenes theseis\n");
    printf("------------------\n");

    // Elegxos gia oles tis theseis
    for(i = 0; i < maxSeats; i++)
    {
        // Elegxos an i thesi einai kratimeni
        if(layout[i].name[0] != '\0')
        {
            // H thesi einai kratimeni, ayksise ton metriti c
            c++;

            // Metatroph toy thelfonoy apo unsigned short[10] se char[11]
            tel2str(phone, layout[i].tel);

            // Emfanisi stoixeion me aykson arithmo
            printf("Thesi %d: [Arithmos: %d] %s - Thl: %s\n", c, layout[i].seat, layout[i].name, phone);
        }
    }

    // To c exei parameinei 0=Den brethike kamia kratimeni thesi
    if(!c)
    {
        // Emfanisi mhnymatos
        printf("Den yparxei kamia kratimeni thesi!\n");
    }
}

// Eggrafh ton neon stoixeion sto arxeio
void commitLayout(PASSENGER layout[], BUSDATA busdata)
{
    // Orismos metabliton
    FILE *bus;
    unsigned int i;
    char phone[11];

    // Anoigma arxeioy gia grapsimo
    bus = fopen("bus.txt", "w");

    // Grapsimo proths grammhs me tin pinakida
    fprintf(bus, "%s %d\n", busdata.plate, busdata.seats);

    // Brogxos gia oles tis theseis
    for(i=0; i<busdata.seats; i++)
    {
        // Grapse sto arxeio mono tis kratimenes theseis
        if(layout[i].name[0] != '\0')
        {
            // Metatroph toy thelfonoy apo unsigned short[10] se char[11]
            tel2str(phone, layout[i].tel);

            // Grapsimo sto arxeio
            fprintf(bus, "%s %d %s\n", layout[i].name, layout[i].seat, phone);
        }
    }

    // Kleisimo arxeioy
    fclose(bus);

    // Emfanisi mynhmatos
    printf("To arxeio bus.txt enimorothike!");
}

// Kyrios programma
int main()
{
    // Orismos metablhton
    PASSENGER layout[MAXSEATS];
    BUSDATA busdata;
    char option;
    unsigned int seat;

    // Mhdenismos stoixeion pinaka
    initLayout(layout);

    // Diabasma stoixeion apo to arxeio
    busdata = getDataFromFile(layout);

    // Ektelesh brogxou mexri na epilegei to 0=exodos
    do
    {
        // Emfanisi menu
        showMenu();

        // Diabasma epiloghs
        scanf(" %c", &option);

        // Elegxos epiloghs
        switch (option)
        {
            // Emfanisi kenon theseon
            case '1':
                showBlanks(layout, busdata.seats);
                break;

            // Kratisi sygekrimenis thesis
            case '2':
                printf("\nDoste arithmo thesis: ");
                scanf("%d", &seat);

                // Elegxos an h thesi einai entos orion
                if(seat <= busdata.seats)
                {
                    // Kratisi tis thesis
                    reserveSpecific(&layout[seat - 1]);
                } else { // Thesi ektos orion
                    printf("Prepei na dosete enan egkyro arithmo thesis (Max = %d)\n", busdata.seats);
                }
                break;

            // Elegxos kratisis me onomateponymo/thlefono
            case '3':
                checkReserved(layout, busdata.seats);
                break;

            // Akyrosi thesis
            case '4':
                printf("\nDoste arithmo thesis: ");
                scanf("%d", &seat);

                // Elegxos an h thesi einai entos orion
                if(seat <= busdata.seats)
                {
                    // Akyrosi thesis
                    cancelSpecific(&layout[seat - 1]);
                } else { // Thesi ektos orion
                    printf("Prepei na dosete enan egkyro arithmo thesis (Max = %d)\n", busdata.seats);
                }
                break;

            // Emfanisi kratimenon theseon
            case '5':
                showReserved(layout, busdata.seats);
                break;

            // Exodos, apothikeyse to layout kai to busdata sto arxeio
            case '0':
                commitLayout(layout, busdata);
                break;

            // Akyrh epilogh
            default:
                printf("H epilogh poy dosate den einai egkyrh!\n");
                break;
        }
    } while(option != '0');

    // Exodos kanonikh
    return 0;
}