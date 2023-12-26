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

int main() {
    int i;
    int board[120] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
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
    showBoard(board);
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