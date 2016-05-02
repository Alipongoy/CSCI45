/* 
========================================
THINGS THAT STILL HAVE TO BE IMPLEMENTED
========================================
1) PRINT X (DONE)
2) PRINT "STRING" (DONE)
3) INPUT X (IN PROGRESS)
	- cin does not work properly, idk why
4) END (DONE)
5) Error checking for using undefine variables (DONE)
6) Trying to use any other variable is a syntax error. (IN PROGRESS)
7) All variables will be 32-bit integers. (NOT STARTED)
	- Use LDR to move them 32-bit integers
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <unistd.h>
#include <map>
#include <string>
#include "print.c"
using namespace std;

void die(int line_no = 0) {
	cout << "Syntax Error on line " << line_no << endl;
	exit(1);
}

void var_checker(map<string, string> var_map, string var) {
	cout << "var_checker is running.\n";
	if (var_map.count(var) == 0) {
		cout << "Variable " << var << " cannot be found.\n";
		die();
	}
}



int main(int argc, char **argv) {
	//If we pass any parameters, we'll just generate an assembly file 
	//Otherwise we will generate an assembly file, assemble it, and run it
	bool assemble_only = false;
	if (argc > 1) assemble_only = true;
	ofstream outs("main.s"); //This is the assembly file we're creating
	if (!outs) {
		cout << "Error opening file.\n";
		return -1;
	}
	outs << ".global main\nmain:\n"; //Get the file ready to rock
	outs << "\tPUSH {LR}\n\tPUSH {R4-R12}\n\n";

	// JOSH'S CODE
	// This is my map. A map is like an array, but instead of using indexes like var[0] or var[1], you can feed it other data types like strings.
	// E.G. var_map["A"] will return the string R4.
	// This is very similar to hash tables from Ruby.
	// Also I added a string vector to hold the .data stuff for asm
	vector<string> string_vector;
	string_vector.push_back( ".data\n");
	map<string, string> var_map;
	var_map["A"] = "R4";
	var_map["B"] = "R5";
	var_map["C"] = "R6";
	var_map["I"] = "R7";
	var_map["J"] = "R8";
	var_map["X"] = "R9";
	var_map["Y"] = "R10";
	var_map["Z"] = "R11";
	// End of map
	// END OF JOSH'S CODE


	int line_no = 0;

	// JOSH'S CODE
	// This is a range based for loop. It itterates through every element of the var_map. 
	for (auto index: var_map) {
		// index.second will return the value at a certain index in the map.
		// E.G. In first itteration, index.second = "R4". 
		// If we were to use index.first instead, we would get "A" at first itteration.
		outs << "\tMOV " << index.second << ", #0\n";
	}
	// END OF JOSH'S CODE

	while (cin) {
		string s;
		getline(cin,s);
		line_no++;
		if (!cin) break;
		transform(s.begin(), s.end(), s.begin(), ::toupper); //Uppercaseify
		auto it = s.find("QUIT"); //TERMINATE COMPILER
		if (it != string::npos) break;
		stringstream ss(s); //Turn s into a stringstream
		int label;
		ss >> label;
		if (!ss) die(line_no);
		outs << "line_" << label << ":\n"; //Write each line number to the file ("line_20:")
		string command;
		ss >> command;
		if (!ss) die(line_no);

		if (command == "REM") {
			continue;
		}
		else if (command == "GOTO") {
			int target;
			ss >> target;
			if (!ss) die(line_no);
			outs << "\tBAL line_" << target << endl;
			continue;
		}
		else if (command == "EXIT") {
			outs << "\tBAL quit\n";
			continue;
		}

		//YOU: Put all of your code here, interpreting the different commands in BB8
		// This is my implementation of the "PRINT" function
		else if (command == "PRINT") {
			string scommand;
			// scommand is the label or variable we want to print out.
			ss >> scommand;
			// If we want to print text to a screen, this runs.
			if (scommand[0] == '"') {
				string word, push_back_word = "";
				string no_quotes_command = scommand;

				// This continously reads in words until it reads in last quotation mark
				if ((no_quotes_command[no_quotes_command.length() - 1]) != '"') {
					do {
						ss >> word;
						no_quotes_command += " " + word;
					} while ((no_quotes_command[no_quotes_command.length() - 1]) != '"');
				}

				no_quotes_command.erase(0, 1);
				no_quotes_command.erase(no_quotes_command.length() - 1);

				push_back_word = "string_" + to_string(label) + ": .ascii \"" + no_quotes_command + "\"\n\n";
				string_vector.push_back(push_back_word);

				outs << "\tLDR R0, =string_" << label << endl; 

				outs << "\tBL print_string\n"; 
			}
			// If we want to print out a variable to the screen, this runs instead.
			else {
				cout << "Else statement is running.\n";
				// This kills itself if variable does not exist.
				var_checker(var_map, scommand);
				outs << "\tLDR R0, " << var_map[scommand] << endl;
				outs << "\tBL print_number\n";
			}
			continue;
		}


		// My implementation of "LET"
		else if (command == "LET") {
			string var_1, var_2, var_3, my_operator, possible_equals;
			ss >> var_1 >> possible_equals >> var_2 >> my_operator >> var_3;
			var_checker(var_map, var_1);
			// Below code is for debugging purposes
			// cout << var_1 << " " <<  bleh << " " << var_2 << " " << my_operator << " " << var_3 << endl;
			if (my_operator == "+") {
				outs << "\tADD " << var_map[var_1] << ", " << var_map[var_2] << ", " << var_map[var_3] << "\n";				 
			}

			else if (my_operator == "-") {
				outs << "\tSUB " << var_map[var_1] << ", " << var_map[var_2] << ", " << var_map[var_3] << "\n";				 
			}

			else if (my_operator == "*") {
				outs << "\tMUL " << var_map[var_1] << ", " << var_map[var_2] << ", " << var_map[var_3] << "\n";				 
			}

			else if (possible_equals == "=") {
				outs << "\tMOV " << var_map[var_1] << ", " << "#" << var_2  << "\n";				 
			}
			continue;
		}

		// My implementation of IF
		else if (command == "IF") {
			string var_1, expression_holder, var_2, else_statement, line_number_0, line_number_1, irr_statement;
			ss >> var_1 >> expression_holder >> var_2 >> else_statement >> else_statement >> line_number_0 >> else_statement >> irr_statement >> line_number_1;

			if (var_map.count(var_1) == 0) {
				outs << "\tCMP " << "#" << var_1 << ", " << var_map[var_2] << "\n";
			}

			else if (var_map.count(var_2) == 0) {
				outs << "\tCMP " << var_map[var_1] << ", " << "#" << var_2 << "\n";				 
			}

			else if (var_map.count(var_1) == 0 && var_map.count(var_2) == 0) {
				outs << "\tCMP " << "#" << var_1 << ", " << "#" << var_2 <<  " " << "\n";				 
			}

			else {
				outs << "\tCMP " << var_map[var_1] << ", " << var_map[var_2] << "\n";				 
			}

			// ToDo: implement else statements


			if (expression_holder == "==") {
				if (else_statement != "ELSE") {
					outs << "\tBEQ line_" << line_number_0 << endl;
				}

				else {
					outs << "\tBNE line_" << line_number_1 << endl;
				}
			}

			else if (expression_holder == "<=") {
				if (else_statement != "ELSE") {
					outs << "\tBGE line_" << line_number_0 << endl;	
				}

				else {
					outs << "\tBLT line_" << line_number_1 << endl;	
				}
			}

			else if (expression_holder == ">=") {
				if (else_statement != "ELSE") {
					outs << "\tBLE line_" << line_number_0 << endl;	
				}

				else {
					outs << "\tBGT line_" << line_number_1 << endl;	
				}
			}

			else if (expression_holder == "!=") {
				if (else_statement != "ELSE") {
					outs << "\tBNE line_" << line_number_0 << endl;	
				}

				else {
					outs << "\tBEQ line_" << line_number_1 << endl;	
				}
			}

			else if (expression_holder == "<") {
				if (else_statement != "ELSE") {
					outs << "\tBGT line_" << line_number_0 << endl;	
				}

				else {
					outs << "\tBLE line_" << line_number_1 << endl;	
				}
			}

			else if (expression_holder == ">") {
				if (else_statement != "ELSE") {
					outs << "\tBLT line_" << line_number_0 << endl;	
				}

				else {
					outs << "\tBGE line_" << line_number_1 << endl;	
				}
			}

			else {
				cout << "Invaild expression holder.\n";
				die();
			}
			continue;
		}

		// My implementation of INPUT
		else if (command == "INPUT") {
			string user_var;
			int user_num;
			ss >> user_var >> user_num;
			outs << "\tMOV " << var_map[user_var] << ", #" << user_num << endl;
			continue;
		}

		// My implementation of END
		else if (command == "END") {
			outs << "\tBAL quit\n";
			continue;
		}

		// If none of the commands are listed, then it dies :D
		else {
			die();
		}
	}

	//Clean up the file at the bottom
	outs << "\nquit:\n\tMOV R0, #42\n\tPOP {R4-R12}\n\tPOP {PC}\n"; //Finish the code and return
	for (string it: string_vector) {
		outs << it;
	}
	outs.close(); //Close the file

	if (assemble_only) return 0; //When you're debugging you should run bb8 with a parameter

	if (system("g++ main.s")) { //Compile your assembler code and check for errors
		cout << "Assembling failed, which means your compiler screwed up.\n";
		return 1;
	}
	//We've got an a.out now, so let's run it!
	cout << "Compilation successful. Executing program now." << endl;
	execve("a.out",NULL,NULL);
}
