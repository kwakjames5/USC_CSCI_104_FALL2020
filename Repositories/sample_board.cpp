
PlaceResult Board::test_place(const Move& move) const {
	size_t word_len = move.tiles.size();
	
	size_t orig_row = move.row;
	size_t orig_col = move.column;

	Board::Position current_position(orig_row, orig_col);
	
	if (is_in_bounds(current_position) == false) {
		cerr << "Out of Bounds, first letter" << endl;
		PlaceResult wrong_move("Your word is going out of bounds. Please try again.");
		return wrong_move;
	}
	else if (is_in_bounds(current_position.translate(move.direction, word_len)) == false) {
		cerr << "Out of Bounds, last letter" << endl;
		PlaceResult wrong_move("Your word is going out of bounds. Please try again.");
		return wrong_move;
	}

	try {	
		if (is_in_bounds(current_position.translate(move.direction, word_len)) == false) {
			cerr << "Out of Bounds, last letter" << endl;
			throw std::out_of_range("Your word is going out of bounds. Please try again.");
			//PlaceResult wrong_move("Your word is going out of bounds. Please try again.");
			//return wrong_move;
		}
	}
	catch (const std::out_of_range& e) {
		cerr << "Out of Range Error 1: " << e.what() << endl;
		PlaceResult wrong_move("Your word is going out of bounds. Please try again.");
		return wrong_move;
	}
	
	current_position.row = orig_row;
	current_position.column = orig_col;
	
	std::vector<Board::Position> tile_position;

	std::string full_word;

	std::vector<TileKind> full_tilekind;

	bool is_adjacent = false;

	size_t pre_letters = 0;

	current_position = current_position.translate(move.direction, -1); 

	while (at(current_position).has_tile()) {
		pre_letters++;
		current_position = current_position.translate(move.direction, -1);
		is_adjacent = true;
	}

	current_position = current_position.translate(move.direction, 1);

	for (size_t i = 0; i < pre_letters; i++) {
		tile_position.push_back(current_position);
		full_word += at(current_position).get_tile_kind().letter;
		full_tilekind.push_back(at(current_position).get_tile_kind());
		current_position = current_position.translate(move.direction, 1);
	}

	current_position.row = orig_row;
	current_position.column = orig_col;

	bool placed_start = false;
	size_t letters_used = 0;
	for (size_t i = 0; i < word_len && letters_used < move.tiles.size(); i++) {
		try {
			if (at(current_position).has_tile()) {
				if (i == 0) {
					// trying to place first tile & overwrite. not legal
					// handle exception
					PlaceResult wrong_move("Your first tile is trying to overwrite an existing tile. Please try again.");
					return wrong_move;
					//cerr << "this is the first move, and trying to overwrite tile. bad" << endl;
				}
				else {
					cerr << "overwriting letter!" << endl;
					// push the letter overwritten as part of word 
					tile_position.push_back(current_position);
					full_word += at(current_position).get_tile_kind().letter;
					full_tilekind.push_back(at(current_position).get_tile_kind());
					// need to increase so that letters don't get left behind
					word_len++;
					is_adjacent = true;
					cerr << "this is building the middle word: " << full_word << endl;
				}
			}
			else {
				cerr << "not overwriting letter" << endl;
				if (current_position == start) { placed_start = true; }
				tile_position.push_back(current_position);
				full_word += move.tiles[letters_used].letter;
				full_tilekind.push_back(move.tiles[letters_used]);
				letters_used++;
			}
			current_position = current_position.translate(move.direction);
		}
		catch (std::out_of_range& e) {
			cerr << "Out of Range Error 2: " << e.what() << endl;
			PlaceResult wrong_move("Your word is going out of bounds. Please try again.");
			return wrong_move;
		}
	}
	// Case 3: check if first move, must check that one of the tiles placed down is on the starting row/col
	if (this->move_index == 0 && !placed_start) {
		// handle error
		//cerr << "it is the 1st move & one of your tiles is not on the first square. try again" << endl;
		PlaceResult wrong_move("it is the 1st move & one of your tiles is not on the first square. try again");
		return wrong_move;

	}

	while (is_in_bounds(current_position) && at(current_position).has_tile()) {
		tile_position.push_back(current_position);
		full_word += at(current_position).get_tile_kind().letter;
		full_tilekind.push_back(at(current_position).get_tile_kind());
		current_position = current_position.translate(move.direction);
		is_adjacent = true;

		cerr << "this is building post letters: " << full_word << endl;
	}

	PlaceResult additional_words_found = additional_word_finder(move);
	
	if (this->move_index > 0 && !is_adjacent && additional_words_found.words.size() == 0) {
		PlaceResult wrong_move("It is not the start move & no adjacent letters found in any direction. Try again.");
		return wrong_move;
	}
	
	size_t total_points = 0;
	size_t total_word_multiplier = 1;
	for (size_t i = 0; i < tile_position.size(); i++) {
		total_points += (full_tilekind[i].points * at(tile_position[i]).letter_multiplier);
		total_word_multiplier *= (at(tile_position[i]).word_multiplier);
	}

	total_points *= total_word_multiplier;
	
	std::vector<string> all_words_found = additional_words_found.words;
	all_words_found.push_back(full_word);

	total_points += additional_words_found.points;

	PlaceResult final_result(all_words_found, total_points);

	return final_result;
}

PlaceResult Board::additional_word_finder(const Move& move) const{
	cerr << "ENTERING ADDITIONAL WORD FINDER" << endl;
	Direction op_dir;
	if (move.direction == Direction::ACROSS) { op_dir = Direction::DOWN; }
	else if (move.direction == Direction::DOWN) {op_dir = Direction::ACROSS; }

	size_t word_len = move.tiles.size();
	size_t orig_row = move.row;
	size_t orig_col = move.column;

	Board::Position current_position(orig_row, orig_col);

	std::vector<std::string> vec_full_words; 

	size_t total_points = 0;
	size_t total_word_multiplier = 1;
	size_t subtotal_points = 0;
	size_t subtotal_word_multiplier = 1;

	for (size_t i = 0; i < word_len; i++) { // P O K E M O N
		//cerr << "AWF: Looking at original letter: " << move.tiles[i].letter << endl;
		if (in_bounds_and_has_tile(current_position)) {
			//cerr << "There was already a tile. skipping over & not counting" << endl;
			word_len++;
			// advance the letter we're looking at ie. for RED, go from R->E->D
			current_position.row = orig_row;
			current_position.column = orig_col;
			current_position = current_position.translate(move.direction, i+1);
			break;
		}

		// Build a string word to build the entire word (ie. SUN + FLOWER + S)
		std::string full_word;

		// for each letter, search above/before that letter and build the potential word
		size_t pre_letters = 0;
		current_position = current_position.translate(op_dir, -1); // go one above/before
		while (at(current_position).has_tile()) {
			pre_letters++;
			current_position = current_position.translate(op_dir, -1);
		}

		current_position = current_position.translate(op_dir);
		size_t count = 0;

		while (is_in_bounds(current_position) ) {
			// add the letter from the original word if added all pre letters 
			if (!at(current_position).has_tile() && count == pre_letters) { 
				
				full_word += move.tiles[i].letter; // creating the full word
				subtotal_points += (move.tiles[i].points * at(current_position).letter_multiplier);
				subtotal_word_multiplier *= (at(current_position).word_multiplier);
			}
			else if (at(current_position).has_tile()) { 
				full_word += at(current_position).get_tile_kind().letter; // creating the full word
				subtotal_points += at(current_position).get_points();
			}

			current_position = current_position.translate(op_dir);

			count++;
		}

		if (full_word.size() > 1) {
			vec_full_words.push_back(full_word);
			total_points += subtotal_points * subtotal_word_multiplier;
		}
		current_position.row = orig_row;
		current_position.column = orig_col;
		subtotal_points = 0;
		subtotal_word_multiplier = 1;
		current_position = current_position.translate(move.direction, i+1);
	}
	total_points = total_points * total_word_multiplier;
	
	PlaceResult additional_placeresult(vec_full_words, total_points);

	return additional_placeresult;
}


PlaceResult Board::place(const Move& move) {
    // DEBUGGING
    cerr << "IN PLACE FUNCTION" << endl;
    // TODO: Complete implementation here
    PlaceResult result = test_place(move);
    // if (!result.valid) {
    // 	// error. DO THIS. NAH SIKE. 
    //WE are going to check the validity in human player get move
    // }
    // Place on Board if its a valid move
    // reminder: Board is 0 based indexing, move has 1 based indexing
    Position current_position(move.row, move.column);
    //cerr << "Created starting position" << endl;
    // cerr << "starting position: (" << current_position.row << "," << current_position.column << ")" << endl;
    size_t word_len = move.tiles.size();
    //cerr << "word_len: " << word_len << endl;
    
    size_t letters_used = 0;
    //cerr << "entering for loop to place the tiles down" << endl;
    for (size_t i = 0; i < word_len && letters_used < move.tiles.size(); i++) {
    	if (!at(current_position).has_tile()) {
			squares[current_position.row][current_position.column].set_tile_kind(move.tiles[letters_used]);
			squares[current_position.row][current_position.column].letter_multiplier = 1;
			squares[current_position.row][current_position.column].word_multiplier = 1;
			letters_used++;
    	}
    	else { 
    		word_len++; 
    	}
    	current_position = current_position.translate(move.direction, 1);
    }

    move_index++;

    cerr << "EXITING PLACE FUNCTION" << endl;
	
    return result;

}
