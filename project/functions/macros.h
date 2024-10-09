#ifndef MACROS
#define MACROS
#define LINE_LENGTH 80
#define ROOM_NAME_LEN 50
#define MAX_ROOMS 10
#define CHOSEN_ROOM "Living Room"
#define CSV_FILE "./generated.csv"
//#define DEBUG

// This is something to think about
// IF ROOM_NAME_LEN is changeable, I shouldn't hardcode limits in parse_line
// related to that number
#define STRINGIFY(x) #x
#define TOSTRING (x) STRINGIFY(x)



/* OS detecting stuff for fancy screen clearing.
 * Windows functionality has not been tested though */
#ifdef _WIN32
#define CLEAR_TERMINAL system("cls");
#else
#ifdef __unix
#define CLEAR_TERMINAL system("clear");
#else
#define CLECLEAR_TERMINAL ; // I'm not sure if this is needed
#endif
#endif
#endif
