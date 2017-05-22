#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Orismos domhs kartas
typedef struct card {
    char color;
    char shape;
    unsigned int num;
    char texture;
} CARD;

// Orismos domhs paikth
typedef struct player {
    char name[18];
    unsigned char score;
    char id;
} PLAYER;

// Arxikopoihsh 81 karton sto cards
void initCards(CARD *cards)
{
    // Orismos metabliton
    char colors[3]          = {'r', 'g', 'b'};
    char shapes[3]          = {'c', 't', 'r'};
    unsigned int nums[3]    = {1, 2, 3};
    char textures[3]        = {'b', 'h', 'e'};

    int i = 0, x, y, z, w, f;

    // Trexe apo 0 eos 80
    while(i < 81)
    {
        // Colors
        for(x=0; x<3; x++)
        {
            // Shapes
            for(y=0; y<3; y++)
            {
                // Nums
                for(z=0; z<3; z++)
                {
                    // Textures
                    for(w=0; w<3; w++)
                    {
                        // Card is complete
                        cards[i].color = colors[x];
                        cards[i].shape = shapes[y];
                        cards[i].num = nums[z];
                        cards[i].texture = textures[w];
                        // Next card
                        i++;
                    }
                }
            }
        }
    }
}

// Elegxos an h karta einai hdh sto board
int isSelected(int cardNum, int cardBoard[3][4])
{
    // Orismos metabliton
    int x, y;

    // Trexe gia 3 grammes kai 4 sthles
    for(x=0; x<3; x++)
    {
        for(y=0; y<4; y++)
        {
            // H karta einai hdh sto board, epestrepse 1
            if(cardBoard[x][y] == cardNum)
            {
                return 1;
            }
        }
    }

    // H karta den einai sto board, epestrepse 0
    return 0;
}

// Arxikopoihsh board
void initCardBoard(int cardBoard[3][4])
{
    // Orismos metabliton
    int x, y, rnd;

    // Mhdenismos arxikon timon
    cardBoard[3][4] = 0;

    // Trexe gia 3 grammes kai 4 sthles
    for(x=0; x<3; x++)
    {
        for(y=0; y<4; y++)
        {
            // Epelexe enan tyxaio arithmo apo 0 eos 81
            // oso o arithmos aytos einai hdh sto board
            do {
                rnd = rand() % 81;
            } while (isSelected(rnd, cardBoard));

            // Bale sth sygekrimenh grammh kai sthlh to
            // noymero ths kartas
            cardBoard[x][y] = rnd;
        }
    }
}

// Emfanisi karton
void displayCards(CARD *cardBoard, int cardsSelected[3][4])
{
    // Orismos metabliton
    int x, y;

    // Trexe gia 3 grammes kai 4 sthles
    for(x=0; x<3; x++)
    {
        for(y=0; y<4; y++)
        {
            // Emfanise ta xarakthristika ths sygkekrimenis kartas
            printf("[%c, %c, %d, %c] \t",
                   cardBoard[cardsSelected[x][y]].color,
                   cardBoard[cardsSelected[x][y]].shape,
                   cardBoard[cardsSelected[x][y]].num,
                   cardBoard[cardsSelected[x][y]].texture);
        }
        printf("\n");
    }
    printf("\n");
}

// Arxikopoihsh domhs paikton
void initPlayers(PLAYER players[3])
{
    strcpy(players[0].name, "Marina Andreou");
    strcpy(players[1].name, "Kostas Grammenos");
    strcpy(players[2].name, "Maria Perdika");
    players[0].score = 0;
    players[1].score = 0;
    players[2].score = 0;
    players[0].id = 'a';
    players[1].id = 'g';
    players[2].id = 'p';

}

// Elegxos an oi kartes apoteloyn SET
int cardSetIsValid(CARD *cardsSelected)
{
    // OYTE ola ta sxhmata idia, OYTE ola ta sxhmata diaforetika
    if(     !(  (cardsSelected[0].shape == cardsSelected[1].shape &&
                cardsSelected[1].shape == cardsSelected[2].shape)

                ||

                (cardsSelected[0].shape != cardsSelected[1].shape &&
                 cardsSelected[1].shape != cardsSelected[2].shape &&
                 cardsSelected[0].shape != cardsSelected[2].shape)
            )
    )
        // Epestrepse 0
        return 0;

    // OYTE ola ta colors idia, OYTE ola ta colors diaforetika
    if(     !(  (cardsSelected[0].color == cardsSelected[1].color &&
                 cardsSelected[1].color == cardsSelected[2].color)

                ||

                (cardsSelected[0].color != cardsSelected[1].color &&
                 cardsSelected[1].color != cardsSelected[2].color &&
                 cardsSelected[0].color != cardsSelected[2].color)
            )
    )
        // Epestrepse 0
        return 0;

    // OYTE ola ta nums idia, OYTE ola ta nuims diaforetika
    if(     !(  (cardsSelected[0].num == cardsSelected[1].num &&
                 cardsSelected[1].num == cardsSelected[2].num)

                ||

                (cardsSelected[0].num != cardsSelected[1].num &&
                 cardsSelected[1].num != cardsSelected[2].num &&
                 cardsSelected[0].num != cardsSelected[2].num)
            )
    )

        // Epestrepse 0
        return 0;

    // OYTE ola ta textures idia, OYTE ola ta textures diaforetika
    if(     !(  (cardsSelected[0].texture == cardsSelected[1].texture &&
                 cardsSelected[1].texture == cardsSelected[2].texture)

                ||

                (cardsSelected[0].texture != cardsSelected[1].texture &&
                 cardsSelected[1].texture != cardsSelected[2].texture &&
                 cardsSelected[0].texture != cardsSelected[2].texture)
    )
            )

        // Epestrepse 0
        return 0;

    // An exeis ftasei os edo, poythena den exei epistrepsei 0
    // Ara einai SET kai epestrepse 1
    return 1;

}

// Elegxos toy SET
int checkSet(unsigned short set[6], int cardsBoard[3][4], CARD *cardsAvailable)
{
    // Orismos metabliton
    CARD cardsSelected[3];

    // Metatroph ton syntetagmenon se pragmatikes kartes
    cardsSelected[0] = cardsAvailable[cardsBoard[set[0]][set[1]]];
    cardsSelected[1] = cardsAvailable[cardsBoard[set[2]][set[3]]];
    cardsSelected[2] = cardsAvailable[cardsBoard[set[4]][set[5]]];

    // Elegxos
    return cardSetIsValid(cardsSelected);

}

// Elegxos an exei kapoios paikths exei score >= 10 kai poios einai aytos
int maxScoreReached(PLAYER players[3])
{
    if(players[0].score >= 10) {
        // 0 = Paikths a
        return 0;
    } else if(players[1].score >= 10) {
        // 1 = Paikths g
        return 1;
    } else if(players[2].score >= 10) {
        // 2 = Paikths p
        return 2;
    } else {
        // -1 = Kaneis
        return -1;
    }
}

// Kyrios programma
int main() {
    // Orismos metabliton
    int cardBoard[3][4] = {};
    CARD cardsAvailable[81];
    PLAYER players[3];
    unsigned short set[6];
    char option;
    int i, currentPlayerId, init = 1;

    // Arxikopoihsh 81 karton
    initCards(cardsAvailable);

    // Arxikopoihsh srand
    srand(time(NULL));

    // Arxikopoihsh paikton
    initPlayers(players);

    // Trexe oso den epilegei kaneis to 0 kai
    // kaneis den exei score >= 10
    do
    {
        // An einai h proth fora h sto teleytaio loop
        // brethike nikiths, bgale 12 nees kartes
        if(init) {
            initCardBoard(cardBoard);
        }

        // Emfanise tis kartes
        displayCards(cardsAvailable, cardBoard);

        // Epilogh paikth h 0 gia exodo
        printf("Epilexte id paikth (a, g, p) h 0 gia exodo kai emfanisi score: ");
        scanf(" %c", &option);

        // H epilogh den einai 0
        if(option != '0')
        {
            switch(option)
            {
                // Paixths a
                case 'a':
                    currentPlayerId = 0;
                    break;

                // Paixths b
                case 'g':
                    currentPlayerId = 1;
                    break;

                // Paixths b
                case 'p':
                    currentPlayerId = 2;
                    break;

                // Anyparktos paixths/epilogh
                default:
                    printf("\nMy egkyrh epilogh h id xrhsth.\n");
                    printf("Ayto shmainei pos oi kartes tha anakateythoyn\n");
                    printf("kai enas neos syndyasmos karton tha emfanistei!\n\n");
                    init = 1;
                    // Prosperase ton ypoloipo brogxo kai
                    // ksekina apo thn arxh
                    continue;
            }

            // Epilogh syntagmenos karton
            printf("\nEpilexte syntetagmenes set 1 0..2 0..3 (px 0 0): ");
            scanf("%hu %hu", &set[0], &set[1]);
            printf("Epilexte syntetagmenes set 2 0..2 0..3 (px 1 0): ");
            scanf("%hu %hu", &set[2], &set[3]);
            printf("Epilexte syntetagmenes set 3 0..2 0..3 (px 2 3): ");
            scanf("%hu %hu", &set[4], &set[5]);

            if(
                    set[0] < 3 && set[2] < 3 && set[4] < 3 &&
                    set[1] < 4 && set[3] < 4 && set[5] < 4) {
                // Elegxos an oi kartes apoteloyn SET
                if (checkSet(set, cardBoard, cardsAvailable)) {
                    // Bale ston paikth +2 pontoys
                    players[currentPlayerId].score += 2;
                    printf("\nSosta, to score sas einai tora %d!\n", players[currentPlayerId].score);
                    printf("\nTha emfanistei tora neos pinakas.\n");
                    // Emfanise neo board
                    init = 1;
                } else {
                    // Lathos SET, afairese 1 ponto apo ton paikth
                    if (players[currentPlayerId].score > 0) {
                        players[currentPlayerId].score -= 1;
                    }
                    printf("\nLathos, to score sas einai tora %d!\n", players[currentPlayerId].score);
                    printf("\n\nTha emfanistei tora o idios pinakas.\n");
                    // Emfanise to idio board
                    init = 0;
                }
            } else {
                printf("\n\nLathos evros syntetagmenon.\n");
                printf("Grammes apo 0 eos 2, sthles apo 0 eos 3 xorismena me keno.\n");
            }
        }

    } while (option != '0' && maxScoreReached(players) == -1);

    // Emfanisi mynhmatos
    if(option == '0') {
        printf("\nEpilexate na termatisete to paixnidi.\n");
    }

    // Enhmerosh apotelesmaton, eite epilexthike to mhden
    // eite kapoios symplhrose 10 pontous
    printf("To paixnidi teleiose.\n\n");
    for(i=0; i<3; i++)
    {
        printf("Paixths [id]: %s [%c] - Score : %hhu\n", players[i].name, players[i].id, players[i].score);
    }

    // An kapoios symplhrose 10 pontous, emfanise ta stoixeia toy
    if(maxScoreReached(players) >= 0) {
        printf("\nO paikths %s einai nikiths me %hhu pontous!\n", players[maxScoreReached(players)].name, players[maxScoreReached(players)].score);
    }

    // Exodos
    return 0;
}