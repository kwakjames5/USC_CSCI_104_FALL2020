#include <iostream>
#include <string>

using namespace std;

// Implement below
bool are_paren_balanced(const string& expression);

// We have suggested a helper method, but feel free to write whatever you see fit
bool are_paren_balanced(const string& expression, size_t& i, char expected_closing);

// Do not change this method
int main(int argc, char* argv[]) {

    // Check if an expression has been passed to the program
    if (argc != 2) {
        cerr << "error: expected expression to check!" << endl;
        return -1;
    }

    // The second argument is the expression string in the format specified and
    // promised in the assignment page. You do not need to do any error checking
    // except for checking the parentheses.
    string expression(argv[1]);
    if (are_paren_balanced(expression)) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }

    return 0;
}

// Some notes:
// - This method must be implemented recursively.
// - When debugging, make sure to output to cerr rather than cout. This will
//   prevent any leftover debug statements from confusing the automated
//   grading and will make sure output is guaranteed to be written to the
//   terminal in case your program crashes.
bool are_paren_balanced(const string& expression) {
    // TODO: your code here
    if(expression[0] == ']' || expression[0] == ')'
        || expression == "(" || expression == "[")
    {
        return false;
    }

    if(expression.size() == 0 && expression.size() == 1)
	{
		return true;
	}

    // find first instance of a open parentheses
    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '[' || expression[i] == '(')
        {
            first_paren_index = i;
            break;
        }
    }

    std::cerr << "CURR end_char: " << end_char << std::endl;

	int i;
	int curr_paren_count = 0;

    for(i = first_paren_index + 1; i < expression.size(); i++)
    {
    	// if a same type parentheses opens up
    	if(expression[i] == expression[first_paren_index])
    	{
    		curr_paren_count++;
    	}

    	// if at a closing parentheses AKA end_char
    	if(expression[i] == end_char)
    	{
    		// when curr_paren_count is 0, implies that the end_char we are at 
    		// right now is indeed the end_char for the first open paren we started with
    		if(curr_paren_count == 0)
    		{
    			// break out of for loop with int i keeping track of the index of the end_char
    			break;
    		}
    		curr_paren_count--;
    	}
    }

    // no end_char found
    if(i == expression.size())
    {
    	return false;
    }

    int j;
    for(j = i + 1; j < expression.size(); j++)
    {
        std::cerr << expression[j] << std::endl;
        if(expression[j] == '(' || expression[j] == '[')
        {
            break;
        }
    }

    std::cerr << "j: " << j << std::endl;

    // no new paren open
    if(j >= expression.size())
    {
        std::cerr << "SUBSTR WITHIN PAREN and NO NEW PAREN OPEN AFTER END_CHAR: " << expression.substr(first_paren_index + 1, first_paren_index + i - 1) << std::endl;
        return are_paren_balanced(expression.substr(first_paren_index + 1, first_paren_index + i - 1));
    }

    std::cerr << "Next paren index: " << j << " expression[j] = " << expression[j] << std::endl;

    // if end_char was right next to the open paren
    if(i == 1)
    {
        // std::cerr << expression.substr(2, expression.size() - 2) << std::endl;
        // expression.substr(2, expression.size() - 1) is the substring after the immediately closed paren that we just checked AKA "()" or "[]"
    	return are_paren_balanced(expression.substr(first_paren_index + 2, first_paren_index + expression.size() - 2));
    }

    // i is the index of the last closed paren
    std::cerr << "SUBSTR WITHIN PAREN: " << expression.substr(first_paren_index + 1, first_paren_index + i - 1) << std::endl;
    std::cerr << "SUBSTR AFTER END_CHAR: " << expression.substr(j, expression.size() - j) << std::endl;

    // expression.substr(1, i - 1) is the substring within the curr paren
    // expression.substr(j, expression.size() - j) is everything after the end_char of the curr paren
    // if both of these substrings are balanced, that means that the previous iteration is also balanced
    return are_paren_balanced(expression.substr(first_paren_index + 1, first_paren_index + i - 1)) && are_paren_balanced(expression.substr(j, expression.size() - j));
}

// Add any additional function implementations here.
//
// If you want to use the suggested helper method, you'll have to write its
// definition here.
bool are_paren_balanced(const string& expression, size_t& i, char expected_closing)
{
	char end_char;

    if(expected_closing == '[')
    {
        end_char = ']';
    }
    else if (expected_closing == '(')
    {
        end_char = ')';
    }
}