/*
 * PGN - Portable Game Notation
 *
 * Not clear whether this is going to be a complete implementation of the PGN
 * specification (https://www.thechessdrum.net/PGN_Reference.txt), but we'll see
 */
#include "../include/pgn.h"

static regex_t movetext_regex_compiled;
regmatch_t movetext_regex_matches[NUM_CAPTURE_GROUPS];


void pgn_init() {
	regcomp(&movetext_regex_compiled, MOVETEXT_REGEX, REG_EXTENDED|REG_NEWLINE);
}

int parse_movetext_token(const char* token, chess_move_t* move) {
	if (regexec(&movetext_regex_compiled, token, NUM_CAPTURE_GROUPS, movetext_regex_matches, 0) == REG_NOMATCH) {
		return 1;
	}

	chess_move_init(move);

	int i = 0;

	// first capture group is full match, so can skip
	// second capture group is just used for grouping (non-grouping capture groups
	// are not available in the c regex std lib)

	if (movetext_regex_matches[2].rm_so != -1) {
		move->piece = token[i++];
	}

	if (movetext_regex_matches[3].rm_so != -1) {
		move->orig_file = token[i++];
	}

	if (movetext_regex_matches[4].rm_so != -1) {
		// gets int value of single char
		move->orig_row = token[i++] - '0';
	}

	if (movetext_regex_matches[5].rm_so != -1) {
		move->capture = true;
		i++;
	}

	if (movetext_regex_matches[6].rm_so != -1) {
		move->dest_file = token[i++];
		// gets int value of single char
		move->dest_row = token[i++] - '0';
	}

	if (movetext_regex_matches[7].rm_so != -1) {
		move->promotion = true;
		i++;
		move->promotion_piece = token[i++];
	}

	if (movetext_regex_matches[8].rm_so != -1) {
		if (token[i++] == CHECK_SYMBOL) {
			move->check = true;
		} else {
			move->checkmate = true;
		}
	}

	// 10th capture group (index 9) will match on both kingside and queenside
	// castling, so first check if queenside matches, and if not, then check
	// kingside
	if (movetext_regex_matches[10].rm_so != -1) {
		move->queenside_castle = true;
	} else if (movetext_regex_matches[9].rm_so != -1) {
		move->kingside_castle = true;
	}

	return 0;
}

void chess_move_init(chess_move_t* move) {
	move->piece = '\0';
	move->orig_file = '\0';
	move->orig_row = 0;
	move->capture = false;
	move->dest_file = '\0';
	move->dest_row = 0;
	move->promotion = false;
	move->promotion_piece = '\0';
	move->check = false;
	move->checkmate = false;
	move->kingside_castle = false;
	move->queenside_castle = false;
}
