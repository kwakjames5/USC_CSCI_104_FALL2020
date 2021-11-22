#include <sstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "place_result.h"
#include "move.h"
#include "exceptions.h"
#include "human_player.h"
#include "tile_kind.h"
#include "formatting.h"
#include "rang.h"

using namespace std;


// This method is fully implemented.
inline string& to_upper(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

Move HumanPlayer::get_move(const Board& board, const Dictionary& dictionary) const {
	// TODO: begin your implementation here.
    cout << "Your Hand: " << endl;
    print_hand(std::cout);
    std::cout << "Your move, " << get_name() << ": ";
    string move_string;
    std::getline(std::cin, move_string);

    // parse the input
    Move parsed_move = parse_move(move_string);

    // validity checks here or in game_loop
    // validity checks: check if word is valid according to the dictionary
    if (parsed_move.kind == MoveKind::EXCHANGE) {
        // need to check the player has the right tiles need to do with helper function
        // need to replace their TileKind vector with new TileKinds...I think
        if (!all_tiles_avail(move.tiles)) {
            cout << "You don't have all the tiles you're trying to exchange. Try again." << endl;
            return get_move(board, dictionary);
        }
    }
    else if (parsed_move.kind == MoveKind::PLACE) {
        // need to call has_all_tiles here

        PlaceResult test_placeresult = board.test_place(parsed_move);

        bool all_words_valid = true;
        // check if the words are valid in PlaceResult's vector of words
        for (size_t i = 0; i < test_placeresult.words.size() < i++) {
            all_words_valid = dictionary.is_word(test_placeresult.words[i]);
            if (!all_words_valid) { break; }
        }
        if (all_words_valid && test_placeresult.valid) { 
            PlaceResult real_placeresult = board.place(parsed_move);
        }
        else {
            // this is probably where the try catch block goes
            cout << test_placeresult.error << endl;
            cout << "All of your words were not valid. Please try again." << endl;
            return get_move(board, dictionary);
        }
        // update points
        this->points += real_placeresult.points;
        // remove the tiles we just used
        this->remove_tiles(parsed_move.tiles);
       
    }
    return parsed_move;
}

vector<TileKind> HumanPlayer::parse_tiles(string& letters) const{
    // TODO: begin implementation here.
    // parse_tiles checks if the player has the right tiles
    std::vector<TileKind> tiles_vector;
    for (int i = 0; i < letters.size(); i++) {
        
        TileKind found_tile = this->tiles.lookup_tile(letters[i]);
        if (found_tile) {
            if (found_tile.letter == TileKind::BLANK_LETTER) {
                found_tile.assigned = letters[i+1];
                found_tile.points = 0;
            }

            tiles_vector.push_back(found_tile);
        }
        else {
            // didn't find tile...
        }
        
    }
    return tiles_vector;
}

Move HumanPlayer::parse_move(string& move_string) const {
	// TODO: begin implementation here.
    std::stringstream ss(move_string);

    std::string eval;
    ss >> eval;
    if (eval == "PASS") {
        // if user say pass, just construct default Move
        // this should be the correct syntax to call Move()
        Move parsed_move();
        return parsed_move;
    }
    else if (eval == "EXCHANGE") {
        std::string exchange_tiles;
        // this should extract the string of tiles to exchange
        ss >> exchange_tiles;
        // send the string of tiles to parse_tiles to turn them into TileKinds
        std::vector<TileKind> exchange_tiles_vector = parse_tiles(exchange_tiles);
        Move parsed_move(exchange_tiles_vector);
        return parsed_move;
    }
    else if (eval == "PLACE") {
        std::string direction;
        ss >> direction;
        // note about row & col: not changing it to be 0 based indexing here
        // will change it later? if not...I could do it here
        PLACE | 3 3 CAKE
        size_t row;
        size_t col;
        std::string place_tiles;
        
        if (direction == "|") {
            ss >> row >> col >> place_tiles;
            std::vector<TileKind> place_tiles_vector = parse_tiles(place_tiles);
            Move parsed_move(place_tiles_vector, row, col, Direction::DOWN);
            return parsed_move;
        }
        else if (direction == "-") {
            ss >> row >> col >> place_tiles;
            std::vector<TileKind> place_tiles_vector = parse_tiles(place_tiles);
            Move parsed_move(place_tiles_vector, row, col, Direction::ACROSS);
            return parsed_move;
        }
        else {
           // handle error that this is a wrong move, ? ask palyer to enter move again?
        } 
    }
    
}


// This function is fully implemented.
void HumanPlayer::print_hand(ostream& out) const {
	const size_t tile_count = tiles.count_tiles();
	const size_t empty_tile_count = this->get_hand_size() - tile_count;
	const size_t empty_tile_width = empty_tile_count * (SQUARE_OUTER_WIDTH - 1);

	for(size_t i = 0; i < HAND_TOP_MARGIN - 2; ++i) {
		out << endl;
	}

	out << repeat(SPACE, HAND_LEFT_MARGIN) << FG_COLOR_HEADING << "Your Hand: " << endl << endl;

    // Draw top line
    out << repeat(SPACE, HAND_LEFT_MARGIN) << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE;
    print_horizontal(tile_count, L_TOP_LEFT, T_DOWN, L_TOP_RIGHT, out);
    out << repeat(SPACE, empty_tile_width) << BG_COLOR_OUTSIDE_BOARD << endl;

    // Draw middle 3 lines
    for (size_t line = 0; line < SQUARE_INNER_HEIGHT; ++line) {
        out << FG_COLOR_LABEL << BG_COLOR_OUTSIDE_BOARD << repeat(SPACE, HAND_LEFT_MARGIN);
        for (auto it = tiles.cbegin(); it != tiles.cend(); ++it) {
            out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL << BG_COLOR_PLAYER_HAND;

            // Print letter
            if (line == 1) {
                out << repeat(SPACE, 2) << FG_COLOR_LETTER << (char)toupper(it->letter) << repeat(SPACE, 2);

            // Print score in bottom right
            } else if (line == SQUARE_INNER_HEIGHT - 1) {
                out << FG_COLOR_SCORE << repeat(SPACE, SQUARE_INNER_WIDTH - 2) << setw(2) << it->points;

            } else {
                out << repeat(SPACE, SQUARE_INNER_WIDTH);
            }
        }
        if (tiles.count_tiles() > 0) {
            out << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE << I_VERTICAL;
            out << repeat(SPACE, empty_tile_width) << BG_COLOR_OUTSIDE_BOARD << endl;
        }
    }

    // Draw bottom line
    out << repeat(SPACE, HAND_LEFT_MARGIN) << FG_COLOR_LINE << BG_COLOR_NORMAL_SQUARE;
    print_horizontal(tile_count, L_BOTTOM_LEFT, T_UP, L_BOTTOM_RIGHT, out);
    out << repeat(SPACE, empty_tile_width) << rang::style::reset << endl;
}
