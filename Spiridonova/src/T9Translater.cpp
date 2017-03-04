#include "../include/T9Translater.h"


std::string T9Translater::spell(const std::string&  initial_str){
    if (initial_str.size() < 1)
       throw::invalid_argument("Empty input!\n");
    char key_number;
    string result = "";
    uint repeat_count;
    for (size_t i = 0 ;  i <= initial_str.size() - 1; i++) {
        if (((initial_str[i] < 'a') or (initial_str[i] > 'z'))and (initial_str[i] != ' ')){
            throw::invalid_argument("You can use only Latin letters in lower case!\n");}

        if (initial_str[i]== empty_symbol){
            key_number = '0';
            repeat_count = 1;
        }
        else {
            for(char j = '2'; j <= '9'; j++){


                if (initial_mapping.at(j).find(initial_str[i]) != std::string::npos){
                    repeat_count = initial_mapping.at(j).find(initial_str[i]);
                    key_number = j;
                    repeat_count++;
                    break;
                }
            }

        }
        if (result[result.size() - 1] == key_number)
            result += empty_symbol;
        result += string(repeat_count, key_number);


      };
    return result;
}

