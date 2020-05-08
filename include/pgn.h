#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

#define MOVETEXT_MAX_SIZE 7

#define NUM_CAPTURE_GROUPS 11 // 9 + 1 for full match
#define MOVETEXT_REGEX "^(([KQNBR])?([abcdefgh])?([12345678])?(x)?([abcdefgh][12345678])(=[QNBR])?([+#])?$)|(O-O)(-O)?$"

#define CHECK_SYMBOL '+'
#define CHECKMATE_SYMBOL '#'

typedef struct {
	char piece;
	char orig_file;
	unsigned int orig_row: 4;
	bool capture;
	char dest_file;
	unsigned int dest_row: 4;
	bool promotion;
	char promotion_piece;
	bool check;
	bool checkmate;
	bool kingside_castle;
	bool queenside_castle;
} chess_move_t;

void pgn_init();

int parse_movetext_token(const char* token, chess_move_t* move);

void chess_move_init(chess_move_t* move);

void chess_move_free(chess_move_t* move);
