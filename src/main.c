#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 8
#define NUM_FILES 8

#define WHITE 0
#define BLACK 1
#define NO_COLOR 0

#define NO_PIECE 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

typedef struct ChessPiece {
	unsigned int type : 3;
	unsigned int color : 1;
} chess_piece_t;

typedef chess_piece_t chess_board_t[NUM_RANKS][NUM_FILES];

char* chess_piece_type_to_unicode_symbol[7] = { " ", "\u2659", "\u2658","\u2657", "\u2656", "\u2655", "\u2654" };

chess_board_t initial_board = {
	{ { ROOK, WHITE }, { KNIGHT, WHITE }, { BISHOP, WHITE }, { QUEEN, WHITE }, { KING, WHITE }, { BISHOP, WHITE }, { KNIGHT, WHITE }, { ROOK, WHITE } },
	{ { PAWN, WHITE }, { PAWN, WHITE }, { PAWN, WHITE }, { PAWN, WHITE }, { PAWN, WHITE }, { PAWN, WHITE }, { PAWN, WHITE }, { PAWN, WHITE } },
	{ { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR } }, 
	{ { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR } }, 
	{ { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR } }, 
	{ { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR }, { NO_PIECE, NO_COLOR } }, 
	{ { PAWN, BLACK }, { PAWN, BLACK }, { PAWN, BLACK }, { PAWN, BLACK  }, { PAWN, BLACK }, { PAWN, BLACK }, { PAWN, BLACK }, { PAWN, BLACK } },
	{ { ROOK, BLACK }, { KNIGHT, BLACK }, { BISHOP, BLACK }, { QUEEN, BLACK }, { KING, BLACK }, { BISHOP, BLACK }, { KNIGHT, BLACK }, { ROOK, BLACK } }
};

void print_chess_board(chess_board_t* chess_board);

int main() {
	print_chess_board(&initial_board);
}

void print_chess_board(chess_board_t* chess_board) {
	puts("-----------------");
	for (int i = 0; i < NUM_RANKS; i++) {
		printf("|%s|%s|%s|%s|%s|%s|%s|%s|\n",
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][0].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][1].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][2].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][3].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][4].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][5].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][6].type],
				chess_piece_type_to_unicode_symbol[(*chess_board)[i][7].type]
		);
		puts("-----------------");
	}
}

