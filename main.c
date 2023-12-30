#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char pieceNumberToChar(int piece) {
    char saida;

    saida = '?';
    switch (piece) {
        case 0x00:
            saida = '_';
            break;

        case 0x01:
            saida = 'p';
            break;
        case 0x81:
            saida = 'P';
            break;

        case 0x02:
            saida = 'n';
            break;
        case 0x82:
            saida = 'N';
            break;

        case 0x03:
            saida = 'b';
            break;
        case 0x83:
            saida = 'B';
            break;

        case 0x04:
            saida = 'r';
            break;
        case 0x84:
            saida = 'R';
            break;

        case 0x05:
            saida = 'q';
            break;
        case 0x85:
            saida = 'Q';
            break;

        case 0x06:
            saida = 'k';
            break;
        case 0x86:
            saida = 'K';
            break;


        default:
            saida = '?';
            break;
    }
    return saida;
}



void showBoard(int* board12and10) {
    int i, j;
    for(j = 0; j < 8; j++) {
        for(i = 0; i < 8; i++) {
            printf("%c ", pieceNumberToChar(board12and10[21 + i + (j * 10)]));
        }
        printf("\n");
    }
    return;
}



int *makeBoard(char *fen) {
    int i, j;
    int letra;
    int ptrTabuleiro;
    int *board;
    board = (int *) malloc(sizeof(int) * 120);
    int padrao[120] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                       0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                       0xFF, 0x04, 0x02, 0x03, 0x05, 0x06, 0x03, 0x02, 0x04, 0xFF,
                       0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
                       0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
                       0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
                       0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
                       0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
                       0xFF, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xFF,
                       0xFF, 0x84, 0x82, 0x83, 0x85, 0x86, 0x83, 0x82, 0x84, 0xFF,
                       0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                       0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

    for(i = 0; i < 120; i++) {
        board[i] = padrao[i];
    }
    i = 0;
    ptrTabuleiro = 21;
    while(fen[i] != '\0' && fen[i] != ' ') {
        // printf("fen[i] = %c; i = %i; ptrTabuleiro = %i\n", fen[i], i, ptrTabuleiro);
        // showBoard(board);

        switch (fen[i]) {
            case ' ':
                ptrTabuleiro += 120;
                break;

            case 'p':
                board[ptrTabuleiro] = 0x01;
                break;
            case 'P':
                board[ptrTabuleiro] = 0x81;
                break;

            case 'n':
                board[ptrTabuleiro] = 0x02;
                break;
            case 'N':
                board[ptrTabuleiro] = 0x82;
                break;

            case 'b':
                board[ptrTabuleiro] = 0x03;
                break;
            case 'B':
                board[ptrTabuleiro] = 0x83;
                break;

            case 'r':
                board[ptrTabuleiro] = 0x04;
                break;
            case 'R':
                board[ptrTabuleiro] = 0x84;
                break;

            case 'q':
                board[ptrTabuleiro] = 0x05;
                break;
            case 'Q':
                board[ptrTabuleiro] = 0x85;
                break;

            case 'k':
                board[ptrTabuleiro] = 0x06;
                break;
            case 'K':
                board[ptrTabuleiro] = 0x86;
                break;

            case '1':
                board[ptrTabuleiro] = 0x00;
                break;

            case '2':
                for(j = 0; j < 2; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 1;
                break;

            case '3':
                for(j = 0; j < 3; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 2;
                break;

            case '4':
                for(j = 0; j < 4; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 3;
                break;

            case '5':
                for(j = 0; j < 5; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 4;
                break;

            case '6':
                for(j = 0; j < 6; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 5;
                break;

            case '7':
                for(j = 0; j < 7; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 6;
                break;

            case '8':
                for(j = 0; j < 8; j++) {
                    board[ptrTabuleiro + j] = 0x00;
                }
                ptrTabuleiro += 7;
                break;



            case '/':
                ptrTabuleiro += 1;
                break;

            default:
                break;
        }
        i++;
        ptrTabuleiro++;
        if(ptrTabuleiro > 108) {
            break;
        }
    }
    return board;
}

int main() {
    int i;
    // int *board = makeBoard("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
    int *board = makeBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    // int *board = makeBoard("4r1k1/p4p2/p1n3pp/4p3/1b3P2/1P4P1/P2B2BP/4RK2 w - - 3 29");
    showBoard(board);
    free(board);
    return 0;
}

/*
; *******************************************************
; BOARD	-- Board Array. Used to hold the current position 
; of the board during play. The board itself
; looks like: 
; 	FFFFFFFFFFFFFFFFFFFF 
; 	FFFFFFFFFFFFFFFFFFFF 
; 	FF0402030506030204FF 
; 	FF0101010101010101FF 
; 	FF0000000000000000FF 
; 	FF0000000000000000FF 
; 	FF0000000000000060FF 
; 	FF0000000000000000FF 
; 	FF8181818181818181FF 
; 	FF8482838586838284FF 
; 	FFFFFFFFFFFFFFFFFFFF 
; 	FFFFFFFFFFFFFFFFFFFF 
; The values of FF form the border of the 
; board, and are used to indicate when a piece 
; moves off the board. The individual bits of 
; the other bytes in the board array are as
; follows:
; 	Bit 7 -- Color of the piece
; 	1 -- Black 
; 	0 -- White 
; 	Bit 6 -- Not used 
; 	Bit 5 -- Not used 
; 	Bit 4 --Castle flag for Kings only
; 	Bit 3 -- Piece has moved flag
; 	Bits 2-0 Piece type 
; 		1 -- Pawn 
; 		2 -- Knight
; 		3 -- Bishop 
; 		4 -- Rook 
; 		5 -- Queen 
; 		6 -- King
; 		7 -- Not used
; 		0 -- Empty Square
; *******************************************************
*/


// ♜♞♝♛♚♝♞♜
// ♟♟ ♟♟♟♟♟
// 
//   ♟     
//     ♙   
//      ♘  
// ♙♙♙♙ ♙♙♙
// ♖♘♗♕♔♗ ♖
// rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2 
