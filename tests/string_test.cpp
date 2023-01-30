#include "../include/headers.h"
#include "vector"

std::string PASS = colored_string("PASSED", black_text, bold_style, green_background), FAIL = colored_string("FAILED", black_text, bold_style, red_background);
// arguments.push_back("--checkcase");
const double DELAY_EXTRA_SHORT = 325 / 2;
const double DELAY_SHORT = 325;
const double DELAY_MEDIUM = 500;
const double DELAY_LONG = 750;

// keep track of all the arguments that can be used.
const int TEST_COUNT = 8;
char* arguments[] = {"--checkcase", "--checkletter", "--casedetection", "--lettertester", "--tocaps", "--tolower", "--samechar", "--samestring"};


void check_case_diff();

void letter_tester(char letter);

void test_case_detection();

void is_letter_tester();

void test_to_caps();

void test_to_lower();

void test_same_char();

void test_same_string(std::string first, std::string second);

int args_size(int len, char** args);

int index_shifter(int current, std::string to_find, char** to_search, int length);

void execute_args(int len, char** args);

using namespace std;

int main(int len, char** args) {
    execute_args(len, args);
    // cout << ((same_string("Oh the mouth of the river", "Oh the mouth of the river", true)) ? colored_string("same_string() success!", black_text, bold_style, green_background) : colored_string("same_string() failure!", black_text, bold_style, red_background)) << endl;
    return 0;
}



void check_case_diff() {
    std::cout << "Executing -cd :\t\t";
    if ((int) case_diff == ((int) 'a' - (int) 'A')) {
        std::cout << colored_string("Valid case difference", black_text, bold_style, green_background) << endl;
    }
    else {
        std::cout << colored_string("Invalid case difference", black_text, bold_style, red_background) << endl;
    }
}

void letter_tester(char letter) {
    cout << ((((is_letter(letter) == ((('A' >= letter) && ('Z' <= letter)) || (('a' >= letter) && ('z' <= letter))))) ) ? PASS + ": " + letter + " correctly read." : FAIL + " not correctly read.") << endl;
}

void test_case_detection(){
    char index;
    cout << colored_string("test_case_detection()", black_text, bold_style, yellow_background) << endl;
    cout << "\n\n";
    cout << "is_caps(char):" << endl;
    for (index = 'A'; index <= 'Z'; index = index + 1) {
        cout << "\t" + ((is_caps(index)) ? PASS + ": is_caps(" + (char) index + ") returned expected: true." : FAIL + ": is_caps(" + to_string(index) + ") did not return expected: false") << endl;
        delay(DELAY_LONG);
    }
    cout << "\n\n";
    cout << "is_lower(char):" << endl;
    for (index = 'a'; index <= 'z'; index = index + 1) {
        cout << "\t" + ((is_lower(index)) ? PASS + ": is_lower(" + (char) index + ") returned expected: true." : FAIL + ": is_lower(" + to_string(index) + ") did not return expected: false") << endl;
        delay(DELAY_LONG);
    }
}

void is_letter_tester() {
    char index;
    cout << colored_string("is_letter_tester()", black_text, bold_style, yellow_background) << endl;
    cout << "\n\n";
    cout << "is_letter(char):" << endl;
    for (index = 'A'; index <= 'z'; index = index + 1) {

        if (is_letter(index)) {
            cout << "\t" + ((is_letter(index) && (((index >= 'A') && (index <= 'Z')) || ((index >= 'a') && (index <= 'z')))) ? PASS + ": is_letter(" + (char) index + ") returned expected: " + ((is_letter(index)) ? "true" : "false") + "." : FAIL + ": is_letter(" + to_string(index) + ") did not return expected: " + ((is_letter(index)) ? "true" : "false") + ".") << endl;
        }
        else {
            cout << "\t" + (!(((is_letter(index)) && (((index >= 'A') && (index <= 'Z')) || ((index >= 'a') && (index <= 'z'))))) ? PASS + ": is_letter(" + (char) index + ") returned expected: " + ((is_letter(index)) ? "true" : "false") + "." : FAIL + ": is_letter(" + to_string(index) + ") did not return expected: " + ((is_letter(index)) ? "true" : "false") + ".") << endl;
        }
        delay(DELAY_SHORT);
    }
}

void test_to_caps() {
    char index;
    cout << colored_string("test_to_caps()", black_text, bold_style, yellow_background) << endl;
    for (index = 'A'; index <= 'z'; index = index + 1) {
        if (index > 'Z' && index < 'a'){
            cout << "\t" + ((to_caps((char) index) == (char) index) ? PASS + ": to_caps(" + (char) index + ") returned expected: " : FAIL + ": to_caps(" + (char) index + ") did not return expected: ") + to_caps(index) + "." << endl;
        }
        else {
            cout << "\t" + (((to_caps((char) index) >= 'A') && (to_caps((char) index) <= 'Z')) ? PASS + ": to_caps(" + (char) index + ") returned expected: " : FAIL + ": to_caps(" + (char) index + ") did not return expected: ") + to_caps(index) + "." << endl;
        }
        delay(DELAY_SHORT);
    }
}

void test_to_lower() {
    char index;
    cout << colored_string("test_to_lower()", black_text, bold_style, yellow_background) << endl;
    for (index = 'A'; index <= 'z'; index = index + 1) {
        if (index > 'Z' && index < 'a'){
            cout << "\t" + ((to_lower((char) index) == (char) index) ? PASS + ": to_lower(" + (char) index + ") returned expected: " : FAIL + ": to_lower(" + (char) index + ") did not return expected: ") + to_lower(index) + "." << endl;
        }
        else {
            cout << "\t" + (((to_lower((char) index) >= 'a') && (to_lower((char) index) <= 'z')) ? PASS + ": to_lower(" + (char) index + ") returned expected: " : FAIL + ": to_lower(" + (char) index + ") did not return expected: ") + to_lower(index) + "." << endl;
        }
        delay(DELAY_SHORT);
    }
}

void test_same_char() {
    int capital;
    int lower;
    cout << "Testing same_char(char, char, true | false)" << endl;
    capital = (int) 'A';
    lower = (int) 'a';
    while (capital <= (int) '~') {
        
        cout << "\tsame_char(" << (char) capital << ", " << (char) lower << ", false) -> " << ((same_char((char) capital, (char) lower, false)) ? "true" : "false") << (((same_char(capital, lower, false)) == (capital == lower)) ? " (expected): " + PASS : " (not expected)" + FAIL) << endl;
        cout << "\tsame_char(" << (char) capital << ", " << (char) lower << ", true) -> " << ((same_char((char) capital, (char) lower, true)) ? "true" : "false") << (((same_char(capital, lower, true)) == (to_caps(capital) == to_caps(lower))) ? " (expected): " + PASS : " (not expected)" + FAIL) << endl;
        capital = capital + 1;
        lower = (lower == (int) ('~' + 1)) ? (int) 'A' : lower + 1;
        delay(DELAY_SHORT);
    }

    cout << "\n\nTesting same_char(char, char, true | false)" << endl;
    capital = (int) 'A';
    lower = (int) 'A';
    while (capital <= (int) '~') {
        
        cout << "\tsame_char(" << (char) capital << ", " << (char) lower << ", false) -> " << ((same_char((char) capital, (char) lower, false)) ? "true" : "false") << (((same_char(capital, lower, false)) == (capital == lower)) ? " (expected): " + PASS : " (not expected)" + FAIL) << endl;
        cout << "\tsame_char(" << (char) capital << ", " << (char) lower << ", true) -> " << ((same_char((char) capital, (char) lower, true)) ? "true" : "false") << (((same_char(capital, lower, true)) == (to_caps(capital) == to_caps(lower))) ? " (expected): " + PASS : " (not expected)" + FAIL) << endl;
        capital = capital + 1;
        lower = lower + 1;
        delay(DELAY_SHORT);
    }

}

void test_same_string(std::string first, std::string second) {
    // string first, second;
    if ((first.length() == 0) && (second.length() == 0)) {
        cout << "Enter two words to compare: ";
        cin >> first >> second;
    }
    bool this_test = (first.length() == second.length()) ? true : false;
    
    if (this_test) {

        int f_index, s_index;
        f_index = s_index = 0;
        bool this_test = true;
        while ((f_index < first.length()) && (second.length())){
            this_test = same_char((char) first[f_index], second[s_index], false);
            if (!this_test) {
                break;
            }
            f_index = f_index + 1;
            s_index = s_index + 1;
        }
        cout << "\tsame_string(" << first << ", " << second << ", false) -> " << ((same_string(first, second, false)) ? "true: " : "false: ") << ((same_string(first, second, false) == this_test) ? PASS  : FAIL) << endl;

        // cout << "Testing same_string(" << first << ", " << second << ", true)" << endl;
        f_index = s_index = 0;
        this_test = true;
        while ((f_index < first.length()) && (s_index < second.length())) {
            this_test = same_char((char) first[f_index], (char) second[s_index], true);
            if (!this_test) {
                break;
            }
            f_index = f_index + 1;
            s_index = s_index + 1;
        }
        cout << "\tsame_string(" << first << ", " << second << ", true) -> " << ((same_string(first, second, true)) ? "true: " : "false: ") << ((same_string(first, second, true) == this_test) ? PASS  : FAIL) << endl;

    }

    else {
        cout << "\tsame_char(" << first << ", " << second << ", false) -> " << ((same_string(first, second, false)) ? "true: " : "false: ") << ((same_string(first, second, false) == this_test) ? PASS  : FAIL) << endl;
        cout << "\tsame_char(" << first << ", " << second << ", true) -> " << ((same_string(first, second, true)) ? "true: " : "false: ") << ((same_string(first, second, true) == this_test) ? PASS  : FAIL) << endl;
    }

}

int index_shifter(int current, string to_find, char** to_search, int length) {
    int the_answer;

    for (the_answer = current; the_answer < length; the_answer = the_answer + 1){
        if (same_char((char) to_find[0], (char) to_search[the_answer][0], true)){
            return the_answer;
        }
    }
    return length + 1;
}

int args_size(int len, char** args) {
    int the_answer, index;
    the_answer = 0;
    for (index = 0; index < len; index = index + 1) {
        the_answer = the_answer + string_length(args[index]);
    }
    return the_answer * BYTE;
}

void execute_args(int len, char** args) {

    int index, all_index;
    all_index = -1;
    for (index = 1; index < len; index = index_shifter(index, "-", args, len)){
        
        // Works
        if ((same_string("--checkcase", args[index], true)) || same_string("-cc", args[index], true)) {

            check_case_diff();
            // cout << "Done!" << endl;

        }

        // Works
        else if (same_string("--checkletter", args[index], true) || same_string("-cl", args[index], true)) {

            if (((index + 1 < len) && (args[index + 1][0] == 0)) || (index + 1 >= len)) {

                cout << FAIL << args[index] << " needs an argument" << endl;

            }

            else {

                letter_tester(args[index + 1][0]);

            }

        }

        // Works
        else if (same_string("--casedetection", args[index], true) || same_string("-cd", args[index], true)) {

            test_case_detection();

        }

        // Works
        else if (same_string("--lettertester", args[index], true) || same_string("-lt", args[index], true)) {

            is_letter_tester();

        }

        // Works
        else if (same_string("--tocaps", args[index], true) || same_string("-tc", args[index], true)) {

            test_to_caps();

        }

        // Works
        else if (same_string("--tolower", args[index], true) || same_string("-tl", args[index], true)) {

            test_to_lower();

        }

        // Works
        else if (same_string("--samechar", args[index], true) || same_string("-sc", args[index], true)) {

            test_same_char();

        }

        // Works
        else if (same_string("--samestring", args[index], true) || same_string("-ss", args[index], true)) {

            if ((index + 2 < len) && ((!same_char(args[index + 1][0], '-', false)) && (!same_char(args[index + 2][0], '-', false)))) {
                test_same_string(args[index + 1], args[index + 2]);
            }

            else {
                test_same_string("", "");
            }

        }

        // Works
        else if (same_string("--all", args[index], true) || same_string("-a", args[index], true)) {
            execute_args(TEST_COUNT, (char**) arguments);
        }

        else {
            cout << colored_string("Unrecognized command:", black_text, bold_style, purple_background) + " " + colored_string(args[index], black_text, bold_style, yellow_background) << endl;
        }
        index = index + 1;
    }

    if (all_index > 0) {
        free(args[all_index]);
    }


}