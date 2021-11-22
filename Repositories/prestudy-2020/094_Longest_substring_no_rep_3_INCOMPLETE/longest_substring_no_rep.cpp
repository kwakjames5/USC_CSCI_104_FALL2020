#include "longest_substring_no_rep.h"

int Solution::lengthOfLongestSubstring(std::string s) 
{
    if (s.size() <= 1)
    {
        return s.size();
    }
        
    int curr_length = 0;
    int max_length = 0;
    std::string check_string = "";
    int flag = 0;
      
    for(int i = 0; i < s.size(); i++)
    {
        if(check_string.empty())
        {
            check_string += s[i];
            curr_length++;
            flag = 0;
            std::cout << check_string << std::endl;
            std::cout << curr_length << std::endl;
        }
        else
        {            
            for(int j = 0; j < check_string.size(); j++)
            {
                if(check_string[j] == s[i])
                {
                    if(curr_length > max_length)
                    {
                        max_length = curr_length;
                        curr_length = 0;
                        check_string.clear();
                        flag = 1;
                        check_string += s[i];
                        curr_length++;
                std::cout << check_string << std::endl;
                std::cout << curr_length << std::endl;
                    }
                }
            }

            if(flag == 0)
            {
                check_string += s[i];
                curr_length++;
                std::cout << check_string << std::endl;
                std::cout << curr_length << std::endl;
            }
            else
            {
                flag = 0;
            }
        }
    }

    std::cout << "EXITTED check_string: " << check_string << std::endl;
    std::cout << "EXITTED curr_length: " << curr_length << std::endl;
       
    if(curr_length > max_length)
    {
        max_length = curr_length;
        check_string.clear();
    }
      
    return max_length;
}

int main()
{
    std::cout << "Enter string" << std::endl;
    std::string input;
    std::cin >> input;

    Solution solution;
    int length = solution.lengthOfLongestSubstring(input);

    std::cout << "Length: " << length << std::endl;

    return 0;
}