#include "stdafx.h"
#include "../include/T9Translater.h"

using namespace std;
using std::string;

int main(){
   string input_number;
   int number_of_cases;
   cout << "Enter the number of cases:" << endl;
   cin >> input_number;
   getchar();
   number_of_cases = std::stoi(input_number);
   for(int i = 1; i <= number_of_cases; i++) {
   try {
      string input;
      cout << "Enter text:" << endl;
      getline(cin, input);
      auto elem = T9Translater(input);
      cout << "CASE #"<< i << empty_symbol << elem.get_result() << endl;
   }
   catch (std::invalid_argument const & err)
   {
       std::cerr << "CASE # "<< i << empty_symbol  << string(err.what()) << endl;
   }
   }
   return 0;
}
