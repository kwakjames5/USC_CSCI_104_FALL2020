#include "board.h"
#include "board_square.h"
#include "exceptions.h"
#include "formatting.h"
#include <iomanip>
#include <fstream>

using namespace std;


bool Board::Position::operator==(const Board::Position& other) const {
    return this->row == other.row && this->column == other.column;
}

bool Board::Position::operator!=(const Board::Position& other) const {
    return this->row != other.row || this->column != other.column;
}

Board::Position Board::Position::translate(Direction direction) const {
    return this->translate(direction, 1);
}

Board::Position Board::Position::translate(Direction direction, ssize_t distance) const {
    if (direction == Direction::DOWN) {
        return Board::Position(this->row + distance, this->column);
    } else {
        return Board::Position(this->row, this->column + distance);
    }
}

Board Board::read(const string& file_path) {
    ifstream file(file_path);
    if (!file) {
        throw FileException("cannot open board file!");
    }

    size_t rows;
    size_t columns;
    size_t starting_row;
    size_t starting_column;
    file >> rows >> columns >> starting_row >> starting_column;
    Board board(rows, columns, starting_row, starting_column);

    // TODO: complete implementation of reading in board from file here.
    // the read function is called in scrabble.cpp as part of the instantiation of Board
    for (size_t i=0; i < rows; i++) {
    	std::string read_row;
    	std::getline(file, read_row);
    	for (size_t j=0; j < columns; j++) {
    		if (read_row[j] == '.') {
    			BoardSquare current_square(1,1);
    			board.squares[i][j] = current_square;
    		}
    		else if (current_square[j] == '2') { 
    			BoardSquare current_square(2,1); 
    			board.squares[i][j] = current_square;
    		}
    		else if (current_square[j] == '3') { 
    			BoardSquare current_square(3,1); 
    			board.squares[i][j] = current_square;
    		}
    		else if (current_square[j] == 'd') { 
    			BoardSquare current_square(1,2); 
    			board.squares[i][j] = current_square;
    		}
    		else if (current_square[j] == 't') { 
    			BoardSquare current_square(1,3); 
    			board.squares[i][j] = current_square;
    		}
    		else {
    			// malformed boardsquare, must handle exception
    		}
    	}
    }
    return board;
}

size_t Board::get_move_index() const {
    return this->move_index;
}

PlaceResult Board::test_place(const Move& move) const {
    // TODO: complete implementation here
	// length of word trying to place down
	size_t word_len = move.tiles.size();
	// first position of the word from move
	// original row and column positions to reference later
	size_t orig_row = move.row - 1;
	size_t orig_col = move.column - 1;

	Board::Position current_position(orig_row, orig_col);

	// Case 1: check if out of bounds
	// need to add helper function for when the bounds are less than 0
	for (size_t i = 0; i < word_len; i++) {
		if (is_in_bounds(current_position)) {
			// iterate to the next position
			current_position.translate(move.direction)
		}
		else {
			// out of bounds... try catch
			// throw error
		}
	}
	
	// Build a Position vector to keep track of all the positions
	std::vector<Board::Position> tile_position;
	// Build a string word to build the entire word (ie. SUN + FLOWER + S) SUNFLOWERS
	std::string full_word;
	// Also build a vector of TileKinds?? This may be helpful
	std::vector<Board::BoardSquare::TileKinds> full_tilekind;
	// need to check if the word we are placing has a letter next to it 
	// if not, it's not a valid move
	bool is_adjacent = false;

	// check letters coming BEFORE the word ie. SUN<-FLOWER
	size_t pre_letters = 0;
	// ie. SUN<-FLOWER, look before F at N, until there is no tile
	current_position.translate(move.direction, -1); // look at N
	while (current_position.row > -1 && current_position.column > -1 && at(current_position).has_tile) {
		pre_letters++;
		current_position.translate(move.direction, -1);
		is_adjacent = true;
	}
	// current_position is at a blank tile. move back to 1st available existing tile. ie. S
	current_position.translate(move.direction, 1);
	// add the tile locations that already existed. ie. SUN
	for (size_t i = 0; i < pre_letters) {
		tile_position.push_back(current_position);
		full_word += at(current_position).get_tile_kind().letter;
		full_tilekind.push_back(at(current_position).get_tile_kind());
		current_position.translate(move.direction);
	}

	// reset curr to the original row & col position
	current_position.row = orig_row;
	current_position.column = orig_col;

	// loop is to try place down the tiles we are actually playing to check validity ie. FLOWER
	// add letters to full_word, and add tilekinds to full_tilekind
	// loop also checks if a word overwrites a tile
	bool is_start = false;
	bool placed_start = false;
	size_t letters_used = 0;
	for (size_t i = 0; i < word_len && letters_used < move.tiles.size(); i++) {
		// if first move, start position should have no tiles & one of the tiles placed should be on start pos
		if (squares[start.row][start.column].empty()) { is_start = true; }
		// check if overwriting a tile -> overwriting a tile, or forming a word?
		if (at(current_position).has_tile()) {
			if (i = 0) {
				// trying to place first tile & overwrite. not legal
				// handle exception
			}
			else {
				// push the letter overwritten as part of word 
				tile_position.push_back(current_position);
				full_word += at(current_position).get_tile_kind().letter;
				full_tilekind.push_back(at(current_position).get_tile_kind());
				// need to increase so that letters don't get left behind
				word_len++;
				is_adjacent = true;
			}
		}
		else {
			// there is no tile at the current position
			if (current_position == start && is_start) { placed_start = true; }
			// not overwriting a tile, just add tiles normally
			tile_position.push_back(current_position);
			full_word += moves.tiles[letters_used].letter;
			// full_tilekind.push_back(at(current_position).get_tile_kind());
			full_tilekind.push_back(move.tiles[letters_used]);
			letters_used++;
		}
		// increment current position to point at next letter
		current_position.translate(move.direction);
	}
	// Case 3: check if first move, must check that one of the tiles placed down is on the starting row/col
	if (is_start && placed_start == false) {
		// handle error
	}
	// the current position should be at the last letter of the move played at this point. could move manually
	// check letters coming AFTER the word ie. SUNFLOWER<-S
	// size_t post_letters = 0;
	current_position.translate(move.direction); // look at ending S
	while (at(current_position).has_tile) {
		tile_position.push_back(current_position);
		full_word += at(current_position).get_tile_kind().letter;
		full_tilekind.push_back(at(current_position).get_tile_kind());
		current_position.translate(move.direction);
		is_adjacent = true;
	}

	// now find the words that may be formed in opposite direction 
	PlaceResult additional_words_found = additional_word_finder(move);

	if (is_start == false && additional_words_found.words.size() == 0) {
		// means that there were NO additional words found in opposite dir
		is_adjacent = false;
		// have to throw some error here
	}
	else {
		is_adjacent = true;
	}

	// ADDING UP PTS FOR move.direction WORD 
	// also, assuming the letters that already existed on board has word & letter multiplier at 1
	size_t total_points = 0;
	size_t total_word_multiplier = 1;
	for (size_t i = 0; i < tile_position.size(); i++) {
		total_points += (full_tilekind[i].points * at(tile_position[i]).letter_multiplier);
		total_word_multiplier *= at(tile_position[i]).word_multiplier;
	}
	
	// push all words found in additional_word_finder
	std::vector<string> all_words_found = additional_words_found.words;
	// push word found in test_place in move.direction
	all_words_found.push_back(full_word);
	total_points += additional_words_found.points;
	PlaceResult final_result(all_words_found, total_points);
	return final_result;
}

PlaceResult Board::additional_word_finder(const Move& move) {
	// For each letter, must look before & after in opposite direction
	Direction op_dir;
	if (move.direction == Direction::ACROSS) { op_dir = Direction::DOWN; }
	else if (move.direction == Direction::DOWN) {op_dir = Direction::ACROSS; }

	size_t word_len = move.tiles.size();
	size_t orig_row = move.row - 1;
	size_t orig_col = move.column - 1;

	Board::Position current_position(orig_row, orig_col);
	// Build a vector of words to check later
	std::vector<std::string> vec_full_words; 
	// TODO: NEED TO DO THE TOTAL POINTS SOMEHOW...
	size_t total_points = 0;
	size_t total_word_multiplier = 1;
	size_t subtotal_points = 0;
	size_t subtotal_word_multiplier = 1;
	for (size_t i = 0; i < word_len; i++) { // P O K E M O N
		// Build a Position vector to keep track of all the positions
		// std::vector<Board::Position> tile_position;
		// Build a string word to build the entire word (ie. SUN + FLOWER + S)
		std::string full_word;

		// for each letter, search above/before that letter and build the potential word
		size_t pre_letters = 0;
		current_position.translate(op_dir, -1); // go one above/before
		while (at(current_position).has_tile()) {
			pre_letters++;
			current_position.translate(op_dir, -1);
		}

		// current_position is at a blank tile. move back to 1st available existing tile.
		current_position.translate(op_dir);
		size_t count = 0;
		// add the tile locations that already existed and keep adding until hit blank space
		// for each letter, search below/after that letter and build the potential word 
		while (is_in_bounds(current_position) && at(current_position).has_tile()) {
			// add the letter from the original word if added all pre letters 
			if (count == pre_letters) { 
				full_word += moves.tiles[i]; // creating the full word
				//total_points += (moves.tiles[i].points * at(current_position).letter_multiplier); // adding the points
				subtotal_points += (moves.tiles[i].points * at(current_position).letter_multiplier);
				//total_word_multiplier *= at(current_position).word_multiplier; // updating word multiplier
				subtotal_word_multiplier *= at(current_position).word_multiplier;
			}
			else { 
				full_word += at(current_position).get_tile_kind().letter; // creating the full word
				// updating the points, no need to update word mult bc tiles that exist on board should be 1
				// total_points += at(current_position).get_points(); 
				subtotal_points += at(current_position).get_points();
			}
			//tile_position.push_back(current_position);
			current_position.translate(op_dir);
			count++;
		}
		// if full_word is not a single letter, push the word & update total pts / mult
		if (full_word.size() > 1) {
			vec_full_words.push_back(full_word);
			total_points += subtotal_points;
			total_word_multiplier *= subtotal_word_multiplier;
		}
		// reset current position to the first letter of original word
		current_position.row = orig_row;
		current_position.column = orig_col;
		subtotal_points = 0;
		subtotal_word_multiplier = 1;
		// advance the letter we're looking at ie. for RED, go from R->E->D
		current_position.translate(move.direction, i+1);
	}
	total_points = total_points * total_word_multiplier;
	// build place result to return
	PlaceResult additional_placeresult(vec_full_words, total_points);
	return additional_placeresult;
}


PlaceResult Board::place(const Move& move) {
    // TODO: Complete implementation here
    PlaceResult result = test_place(move);
    // if (!result.valid) {
    // 	// error. DO THIS. NAH SIKE. 
    //WE are going to check the validity in human player get move
    // }
    // Place on Board if its a valid move
    // reminder: Board is 0 based indexing, move has 1 based indexing
    Position current_position(move.row-1, move.column-1);

    size_t word_len = move.tiles.size();
    size_t letters_used = 0;
    for (int i = 0; i < word_len && letters_used < move.tiles.size(); i++) {
    	if (!at(current_position).has_tile()) {
			squares[current_position.row][current_position.column].set_tile_kind(move.tiles[letters_used]);
			letters_used++;
    	}
    	else { word_len++; }
    	current_position.translate(move.direction);
    }
    // move_index++;

    return result;
}

// The rest of this file is provided for you. No need to make changes.

BoardSquare& Board::at(const Board::Position& position) {
    return this->squares.at(position.row).at(position.column);
}

const BoardSquare& Board::at(const Board::Position& position) const {
    return this->squares.at(position.row).at(position.column);
}

bool Board::is_in_bounds(const Board::Position& position) const {
    return position.row < this->rows && position.column < this->columns;
}

bool Board::in_bounds_and_has_tile(const Position& position) const{
    return is_in_bounds(position) && at(position).has_tile();
}

void Board::print(ostream& out) const {
	// Draw horizontal number labels
	for (size_t i = 0; i < BOARD_TOP_MARGIN - 2; ++i) {
		out << std::endl;
	}
	out << FG_COLOR_LABEL << repeat(SPACE, BOARD_LEFT_MARGIN);
	const size_t right_number_space = (SQUARE_OUTER_WIDTH - 3) / 2;
	const size_t left_number_space = (SQUARE_OUTER_WIDTH - 3) - right_number_space;
	for (size_t column = 0; column < this->columns; ++column) {
		out << repeat(SPACE, left_number_space) << std::setw(2) << column + 1 << repeat(SPACE, right_number_space);
	}
	out << std::endl;

	// Draw top line
	out << repeat(SPACE, BOARD_LEFT_MARGIN);
    print_horizontal(this->columns, L_TOP_LEFT, T_DOWN, L_TOP_RIGHT, out);
    out << endl;

	// Draw inner board
	for (size_t row = 0; row < this->rows; ++row) {
        if (row > 0) {
            out << repeat(SPACE, BOARD_LEFT_MARGIN);
			print_horizontal(this->columns, T_RIGHT, PLUS, T_LEFT, out);
			out << endl;
		}

		// Draw insides of squares
		for (size_t line = 0; line < SQUARE_INNER_HEIGHT; ++line) {
			out << FG_COLOR_LABEL << BG_COLOR_OUTSIDE_BOARD;

			// Output column number of left padding
			if (line == 1) {
				out << repeat(SPACE, BOARD_LEFT_MARGIN - 3);
				out << std::setw(2) << row + 1;
				out << SPACE;
			} else {
				out << repeat(SPACE, BOARD_LEFT_MARGIN);
			}

            // Iterate columns
			for (size_t column = 0; column < this->columns; ++column) {
				out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL;
				const BoardSquare& square = this->squares.at(row).at(column);
				bool is_start = this->start.row == row && this->start.column == column;

				// Figure out background color
				if (square.word_multiplier == 2) {
					out << BG_COLOR_WORD_MULTIPLIER_2X;
				} else if (square.word_multiplier == 3) {
					out << BG_COLOR_WORD_MULTIPLIER_3X;
				} else if (square.letter_multiplier == 2) {
					out << BG_COLOR_LETTER_MULTIPLIER_2X;
				} else if (square.letter_multiplier == 3) {
					out << BG_COLOR_LETTER_MULTIPLIER_3X;
				} else if (is_start) {
					out << BG_COLOR_START_SQUARE;
                }

				// Text
                if (line == 0 && is_start) {
                    out << "  \u2605  ";
                } else if (line == 0 && square.word_multiplier > 1) {
                    out << FG_COLOR_MULTIPLIER << repeat(SPACE, SQUARE_INNER_WIDTH - 2) << 'W' << std::setw(1) << square.word_multiplier;
                } else if (line == 0 && square.letter_multiplier > 1) {
                    out << FG_COLOR_MULTIPLIER << repeat(SPACE, SQUARE_INNER_WIDTH - 2) << 'L' << std::setw(1) << square.letter_multiplier;
				} else if (line == 1 && square.has_tile()) {
                    char l = square.get_tile_kind().letter == TileKind::BLANK_LETTER ? square.get_tile_kind().assigned : ' ';
                    out << repeat(SPACE, 2) << FG_COLOR_LETTER << square.get_tile_kind().letter << l << repeat(SPACE, 1);
				} else if (line == SQUARE_INNER_HEIGHT - 1 && square.has_tile()) {
					out << repeat(SPACE, SQUARE_INNER_WIDTH - 1) << FG_COLOR_SCORE << square.get_points();
				} else {
					out << repeat(SPACE, SQUARE_INNER_WIDTH);
				}
			}

			// Add vertical line
			out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL << BG_COLOR_OUTSIDE_BOARD << std::endl;
		}
	}

	// Draw bottom line
	out << repeat(SPACE, BOARD_LEFT_MARGIN);
	print_horizontal(this->columns, L_BOTTOM_LEFT, T_UP, L_BOTTOM_RIGHT, out);
	out << endl << rang::style::reset << std::endl;
}
