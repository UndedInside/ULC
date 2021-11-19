# ULC
## About:
The Luhn algorithm is a simple formula for calculating a checkbit based on input, to be used to validate if an input has been entered successfully. If the input differs, the checkbit will change.

This is a simple calculator I wrote to calculate and verify an input using the Luhn algorithm

## Usage:
The program can be started by either compiling the source or running the executable. The usage menu is here:
```
Unded's Luhn Calculator
Usage: main [-c calculate | -v verify] [Payload | Payload +  Checksum]

OPTIONS:
  -h          Outputs this list
  -c          Calculates a checkbit
  -v          Validates payload+checkbit
                Returns 1 is valid, 0 if not

EXTRA OPTIONS:
  -l          Outputs payload + checkbit
  -s          Only outputs checkbit (default)
Please note these only apply to the -c flag

USAGE:
  ./ulc -c 7992739871 -l
    RETURNS: 79927398713
  ./ulc -c 7992739871 -s
    RETURNS: 3
  ./ulc -v 79927398713
    RETURNS: 1
  ./ulc -v 79927398719
    RETURNS 0
```
Feel free to contact me @UndedInside for further assistance
