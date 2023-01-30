
#include <iostream>
#include <time.h>
#include <stdlib.h>

/// The difference between the lower_case and upper_case.
#define case_diff ('a' - 'A')



// TEXT COLORS
#define black_text 30
#define red_text 31
#define green_text 32
#define yellow_text 33
#define blue_text 34
#define purple_text 35
#define cyan_text 36
#define white_text 37




// TEXT STYLE
#define no_effect_style 0
#define bold_style 1
#define underline_style 2
#define negative_1_style 3
#define negative_2_style 5




// BACKGROUND COLOR
#define black_background 40
#define red_background 41
#define green_background 42
#define yellow_background 43
#define blue_background 44
#define purple_background 45
#define cyan_background 46
#define white_background 47


#define BYTE 8


std::string ansi_escape = "\033[";


/// Get the minimum of two different values.
#define min(first, second) (first <= second) ? first : second

/// Get the maximum of two different values.
#define max(first, second) (first >= second) ? first : second

/// Get if the value passed in is between '0' and '9' inclusive.
#define is_num(letter) ((letter >= '0') && (letter <= '9')) ? true : false

/// Determine if the value passed in is a capital letter or not.
#define is_caps(letter) (((char) letter >= (char) 'A') && ((char) letter <= (char) 'Z')) ? true : false

/// Determine if the value passed in is a lower case letter or not.
#define is_lower(letter) (((char) letter >= (char) 'a') && ((char) letter <= (char) 'z')) ? true : false

/// Determine if the value passed in is a letter or not, reguardless of whether or not it's a capital letter or lower case letter.
#define is_letter(letter) ((is_caps(letter)) || (is_lower(letter))) ? true : false






/**
 * @brief  This function raises the base to the exponent function.
 * @note   Be cute.
 * @param  base: The base that is raised to the exponent.
 * @param  exponent: The power that the base is raised to.
 * @retval The base raised to the exponent.
 */
double power(double base, double exponent) {
  if (exponent == 0) {
    return 1;
  }
  return (exponent > 0) ? power(base, exponent - 1) : power(base, exponent + 1);
}


/**
 * @brief  This function converts the character passed in into a capital letter.
 * @note   Relies on predefined macros. Ignores non letters and capital letters.
 * @param  letter: The parameter to be converted into a capital letter. 
 * @retval The capital case version of the letter passed in.
 */
char to_caps(char letter){
  return ((is_letter(letter)) && (is_lower(letter))) ? (char) ((int) letter - (int) case_diff) : letter;
}

/**
 * @brief  This function converts the character passed in into a lower letter.
 * @note   Relies on predefined macros. Ignore non letters and capital letters.
 * @param  letter: The parameter to be converted into a lower letter.
 * @retval The lower case version of the letter passed in
 */
char to_lower(char letter) {
  return ((is_letter(letter)) && (is_caps(letter))) ? (char) ((int) letter + (int) case_diff) : letter;
}

/**
 * @brief  This function checks if the two parameters 'first' and 'second' are the same character.
 * @note   This function can ignore cases if you choose for.
 * @param  first: The first character to be checked.
 * @param  second: The second chracter to be checked.
 * @param  ignore_case: A bool value that specifies if letter cases should be ignored or not.
 * @retval Returns a bool in which true means that the two characters are the same.
 */
bool same_char(char first, char second, bool ignore_case) {

  if ((is_letter(first) && is_letter(second)) && ignore_case) {

    if (((is_caps(first)) && (is_caps(second))) || ((is_lower(first)) && (is_lower(second)))) {

      return ((first) == (second)) ? true : false;
    
    }

    else if ((is_caps(first)) && (is_lower(second))) {

      return ((first) == (to_caps(second))) ? true : false;
    }

    else if ((is_lower(first)) && (is_caps(second))) {

      return (to_caps(first) == (second)) ? true : false;
    }

    return false;

  }

  else {
    
    return ((first) == (second)) ? true : false;

  }

}

/**
 * @brief  Get the length of a string
 * @note   Made to take in char* and std::string
 * @param  the_string: The string to be taken in char* or std::string
 * @retval The length of the string or char* that is passed in.
 */
int string_length(char* the_string) {
  int the_answer = 0;
  while (the_string[the_answer++] != '\0');
  return the_answer;
}

/**
 * @brief  Get the length of a string
 * @note   Made to take in char* and std::string
 * @param  the_string: The string to be taken in char* or std::string
 * @retval The length of the string or char* that is passed in.
 */
int string_length(std::string the_string) {
  int the_answer = 0;
  while (the_string[the_answer++] != '\0');
  return the_answer;
}

/**
 * @brief  Check if 'first' and 'second' strings are the same or not.
 * @note   This function is able to ignore case.
 * @param  first: The first string to be checked.
 * @param  second: The second strings to be checked.
 * @param  ignore_case: A bool value to specify if case should be ignored or not.
 * @retval true if first and second are the same string (reguardless of case if ignore_case)
 * otherwise false.
 */
bool same_string(std::string first, std::string second, bool ignore_case){
  int index;
  int min_len = (int) min(string_length(first), string_length(second));
  for (index = 0; index < min_len; index = index + 1){
    if (!same_char(first[index], second[index], ignore_case)) {
      return false;
    }
  }
  return true;
}


/**
 * @brief  This function delays (equivalent to python's sleep function).
 * @note   Halt program execution for the number of milliseconds passed in.
 * @param  milliseconds: The number of milliseconds to delay program execution for.
 * @retval None
 */
void delay(double milliseconds) {
  clock_t past, present;
  double long pause = milliseconds * (CLOCKS_PER_SEC / 1000);
  past = present = clock();
  while ((present - past) < pause) {
    present = clock();
  }
}


/**
 * @brief  This function returns the text passed in as a colored string.
 * @note   This function matches the background of the terminal at the end of the string.
 * @param  text: The text to be returned as a colored string.
 * @param  text_color: The color the string should be changed to. Ranges between [30 : 37].
 *  * 30 - black
 *  * 31 - red
 *  * 32 - green
 *  * 33 - yellow
 *  * 34 - blue
 *  * 35 - purple
 *  * 36 - cyan
 *  * 37 - white
 * @param  text_style: The effect or style of the text to be printed. Ranges between [0 : 5] excluding 4.
 *  * 0 - no effect
 *  * 1 - bold
 *  * 2 - underlined text
 *  * 3 - negative_1 style
 *  * 5 - negative_2 style
 * @param  background_color: The background color of the text. Ranges between [40 : 47].
 *  * 40 - black
 *  * 41 - red
 *  * 42 - green
 *  * 43 - yellow
 *  * 44 - blue
 *  * 45 - purple
 *  * 46 - cyan
 *  * 47 - white
 * @retval The string with the text color, text_style, and background color specified by the parameters.
 */
std::string colored_string(std::string text, int text_color, int text_style, int background_color) {
  return ansi_escape + std::to_string(text_style) + ";" + std::to_string(text_color) + ";" + std::to_string(background_color) + "m" + text + ansi_escape + "0m";
}



/**
 * @brief  This function takes in a string and creates 'to_add' copies of it.
 * @note   The length of the string does not matter.
 * @param  original_string: The string to create 'to_add' copies of.
 * @param  to_add: The number of times the 'original_string' should be added to the original string.
 * @retval 
 */
std::string expand_string(std::string original_string, int to_add) {
  std::string the_answer = original_string;
  int index;
  for (index = 0; index < to_add; index = index + 1) {
    the_answer = the_answer + original_string;
  }
  return the_answer;
}


/**
 * @brief  This function returns the index of the first encounter of the to_find char passed in.
 * @note   If 'to_find' is not in the 'to_search' string, -1 is returned.
 * @param  to_find: The char to be found.
 * @param  to_search: The string to be searched for the 'to_find' char.
 * @param  match_case: A bool that signifies whether or not the case matters.
 * @retval The first index of the 'to_find' char in 'to_search'.
 */
int get_index(char to_find, std::string to_search, bool match_case) {
  int the_answer;
  for (the_answer = 0; the_answer < to_search.length(); the_answer = the_answer + 1) {
    if (same_char(to_search[the_answer], to_find, !match_case)) {
      return the_answer;
    }
  }
  return -1;
}


/* 
  Implementation of HTTP (Hyper Transmission Text Protocol) methods (https://www.webscrapingapi.com/c-web-scraping)
    * GET
    * HEAD
    * POST
    * PUT
    * DELETE
    * CONNECT
    * OPTIONS
    * TRACE

*/