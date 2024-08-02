# PasswordStrengthTester
A C program to evaluate the strength of a given password based on length, character variety, and similarity to commonly used passwords


## Installation and Usage

1. Clone the repository

`` git clone git@github.com:dariiahacker1/PasswordStrengthTester.git ``

``cd PasswordStrengthTester``

3. Download the rockyou.txt file:

`` mkdir -p resources ``

`` cd resources``

`` wget https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt``

`` cd ..``

5. Compile the program:
   
   `` gcc -o password_tester main.c functions.c -lm ``

7. Run the program:
 
   ``./password_tester``

## Features

`rgb(R,G,B)` Length and Complexity Check: `rgba(248, 71, 9, 0.8)` Ensures the password meets minimum length and includes a mix of uppercase, lowercase, digits, and special characters.

`rgb(R,G,B)` Strength Evaluation: `rgba(248, 71, 9, 0.8)` Calculates the possible combinations and estimated time required to decrypt the password.

`rgb(R,G,B)` Common Password Check: `rgba(248, 71, 9, 0.8)` Compares the password against a list of commonly used passwords.

`rgb(R,G,B)` User Feedback: `rgba(248, 71, 9, 0.8)` Provides feedback on how to improve password strength.

   
