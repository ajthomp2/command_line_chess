#include <stdio.h>
#include <stdlib.h>
#include "../include/pgn.h"

#define NUM_RANKS 8
#define NUM_FILES 8

#define NO_PIECE 0
#define WHITE_PAWN 1
#define WHITE_KNIGHT 2
#define WHITE_BISHOP 3
#define WHITE_ROOK 4
#define WHITE_QUEEN 5
#define WHITE_KING 6
#define BLACK_PAWN 7
#define BLACK_KNIGHT 8
#define BLACK_BISHOP 9
#define BLACK_ROOK 10
#define BLACK_QUEEN 11
#define BLACK_KING 12

typedef unsigned char chess_board_t[NUM_RANKS][NUM_FILES];

char* chess_piece_type_to_unicode_symbol[13] = { " ", "\u2659", "\u2658","\u2657", "\u2656", "\u2655", "\u2654", "\u265F", "\u265E", "\u265D", "\u265C", "\u265B", "\u265A" };

chess_board_t initial_board = {
	{ WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK },
	{ WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN },
	{ NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE }, 
	{ NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE }, 
	{ NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE }, 
	{ NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE, NO_PIECE }, 
	{ BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN },
	{ BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK },
};

void copy(chess_board_t* src, chess_board_t* dest);
void print_chess_board(chess_board_t* chess_board);
/* int make_move(char input[MAX_INPUT_SIZE], chess_board_t* chess_board); */

int main() {

	pgn_init();

	puts("Alex's Chess Engine Version 0.0.1");
	puts("Press Ctrl-c to exit");

	// 2 extra chars from '\n'
	int input_max_size = MOVETEXT_MAX_SIZE + 2;
	char input[input_max_size];
	chess_move_t move;

	while(1) {
		fputs("> ", stdout);
		fgets(input, input_max_size, stdin);

		if (parse_movetext_token(input, &move) == 1) {
			puts("Unable to parse move\n");
		} else {
			printf("Piece: %c\n", move.piece);
			printf("Original File: %c\n", move.orig_file);
			printf("Original Row: %d\n", move.orig_row);
			printf("Capture: %s\n", move.capture ? "true" : "false");
			printf("Destination File: %c\n", move.dest_file);
			printf("Destination Row: %d\n", move.dest_row);
			printf("Promotion: %s\n", move.promotion ? "true" : "false");
			printf("Promotion Piece: %c\n", move.promotion_piece);
			printf("Check: %s\n", move.check ? "true" : "false");
			printf("Checkmate: %s\n", move.checkmate ? "true" : "false");
			printf("Kingside Castle: %s\n", move.kingside_castle ? "true" : "false");
			printf("Queenside Castle: %s\n", move.queenside_castle ? "true" : "false");
		}
	}

	return 0;

	/* chess_board_t* chess_board = (chess_board_t*) malloc(sizeof(chess_board_t)); */
	/* copy(&initial_board, chess_board); */

	/* print_chess_board(chess_board); */
}

void copy(chess_board_t* src, chess_board_t* dest) {
	for (int i = 0; i < NUM_RANKS; i++) {
		for (int j = 0; j < NUM_FILES; j++) {
			(*dest)[i][j] = (*src)[i][j];
		}
	}
}

/* int make_move(char input[MAX_INPUT_SIZE], chess_board_t* chess_board) { */

/* } */

void print_chess_board(chess_board_t* chess_board) {
	puts("-----------------");
	for (int i = 0; i < NUM_RANKS; i++) {
		for (int j = 0; j < NUM_FILES; j++) {
			printf("|%s", chess_piece_type_to_unicode_symbol[(*chess_board)[i][j]]);
		}
		puts("|");
		puts("-----------------");
	}
}

