// Calculates the check bit of a number using Luhn's algorithm
// Or verifies if a number is valid
#include <iostream>
#include <cstring>
using namespace std;

int calcCheckBit(long long toValidate);
int isValid(long long toValidate);

void headerOut();
void helpOut();

int main(int argc, char* argv[]) {
  if (argc == 1){
    // Display help if no args passed
    headerOut();
  } else {
    // Check if all args present
    // Avoids segfault when passing null to calcCheckBit
    if (argc > 2){
      if (strcmp(argv[1], "-c") == 0){
        // Calculate check bit
        long long pass = strtol(argv[2], nullptr,0);
        // Checks if extra flag is present
        // Defaults to 'no'
        if (argc == 4){
          if (strcmp(argv[3], "-l") == 0){
            cout << pass;
          }
        }
        cout << calcCheckBit(pass) << "\n";
      }
      // Checks if input is valid
      else if (strcmp(argv[1], "-v") == 0){
        long long pass = strtol(argv[2], nullptr,0);
        cout << isValid(pass) << "\n";
      }
    } else {
      if (strcmp(argv[1], "-h") == 0){
        // Extended help
        headerOut();
        helpOut();
      } else {
        cout << "MISSING ARGUMENT\n\n";
        headerOut();
      }
    }
  }
}

int calcCheckBit(long long toValidate){
  // Variable init
  int sumTotal = 0;
  // Starting validation

  // flipper alternates digits while being read
  int flipper = 1; 
  while (toValidate > 0){
    // One digit at a time, LIFO
    int currentDigit = toValidate % 10;
    // Multiply every other digit by 2
    if (flipper % 2 != 0){
      currentDigit *= 2;
      // Add the digits of any multiplication over 10
      if (currentDigit >= 10){
        sumTotal += currentDigit % 10 + 1;
      } else {
        sumTotal += currentDigit;
      }
    } else {
      sumTotal += currentDigit;
    }
    // Increment counts
    toValidate /= 10;
    flipper++;
  }

  // Calculates checkbit using the sum created previously
  int checkBit = 10 - sumTotal % 10;
  return checkBit;
}

int isValid(long long toValidate){
  // Strips checkbit, recalculates checkbit, adds it back on
  // If newly calculated is the same as the old, return 1
  long long payload = toValidate /10;
  long long clone = payload*10 + calcCheckBit(payload);

  if (clone == toValidate){
    return 1;
  } else {
    return 0;
  }
}

void headerOut(){
  // Basic help header
  cout << "Unded's Luhn Calculator\n";
  cout << "Usage: main [-c calculate | -v verify] [Payload | Payload +  Checksum]\n";
}

void helpOut(){
  // Extended help header
  cout << "\n";
  cout << "OPTIONS:\n";
  cout << "  -h          Outputs this list\n";
  cout << "  -c          Calculates a checkbit\n";
  cout << "  -v          Validates payload+checkbit\n";
  cout << "                Returns 1 is valid, 0 if not\n\n";
  cout << "EXTRA OPTIONS:\n";
  cout << "  -l          Outputs payload + checkbit\n";
  cout << "  -s          Only outputs checkbit (default)\n";
  cout << "Please note these only apply to the -c flag\n\n";
  cout << "USAGE:\n";
  cout << "  ./ulc -c 7992739871 -l\n";
  cout << "    RETURNS: 79927398713\n";
  cout << "  ./ulc -c 7992739871 -s\n";
  cout << "    RETURNS: 3\n";
  cout << "  ./ulc -v 79927398713\n";
  cout << "    RETURNS: 1\n";
  cout << "  ./ulc -v 79927398719\n";
  cout << "    RETURNS 0\n";
}
