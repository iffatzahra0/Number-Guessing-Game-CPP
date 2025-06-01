#include <iostream>
#include <string>

using namespace std;

// Random number generation function
int generateRandomNumber() {
    return rand() % 9000 + 1000;  // Range: 1000 to 9999
}

// Function to separate digits and give feedback
void digit_separator(int rnum, int guess) {
    int d1, d2, d3, d4, g1, g2, g3, g4;
    // Extract digits from random number
    d1 = rnum % 10;
    d2 = (rnum / 10) % 10;
    d3 = (rnum / 100) % 10;
    d4 = (rnum / 1000) % 10;

    // Extract digits from guess
    g1 = guess % 10;
    g2 = (guess / 10) % 10;
    g3 = (guess / 100) % 10;
    g4 = (guess / 1000) % 10;

    int switch1, switch2, switch3, switch4;

    // Feedback for each digit
    if (g1 == d1) {
        switch1 = 1;
    }
    else if (g1 == d2 || g1 == d3 || g1 == d4) {
        switch1 = 2;
    }
    else {
        switch1 = 3;
    }

    if (g2 == d2) {
        switch2 = 1;
    }
    else if (g2 == d1 || g2 == d3 || g2 == d4) {
        switch2 = 2;
    }
    else {
        switch2 = 3;
    }

    if (g3 == d3) {
        switch3 = 1;
    }
    else if (g3 == d1 || g3 == d2 || g3 == d4) {
        switch3 = 2;
    }
    else {
        switch3 = 3;
    }

    if (g4 == d4) {
        switch4 = 1;
    }
    else if (g4 == d1 || g4 == d2 || g4 == d3) {
        switch4 = 2;
    }
    else {
        switch4 = 3;
    }

    // Output guesses results
    switch (switch1) {
    case 1:
        cout << g1 << " is correct at the correct position." << endl;
        break;
    case 2:
        cout << g1 << " is correct at the wrong position. " << endl;
        break;
    case 3:
        cout << g1 << " incorrect digit." << endl;
        break;
    }

    switch (switch2) {
    case 1:
        cout << g2 << " is correct at the correct position." << endl;
        break;
    case 2:
        cout << g2 << " is correct at the wrong position. " << endl;
        break;
    case 3:
        cout << g2 << " incorrect digit." << endl;
        break;
    }

    switch (switch3) {
    case 1:
        cout << g3 << " is correct at the correct position." << endl;
        break;
    case 2:
        cout << g3 << " is correct at the wrong position. " << endl;
        break;
    case 3:
        cout << g3 << " incorrect digit." << endl;
        break;
    }

    switch (switch4) {
    case 1:
        cout << g4 << " is correct at the correct position." << endl;
        break;
    case 2:
        cout << g4 << " is correct at the wrong position. " << endl;
        break;
    case 3:
        cout << g4 << " incorrect digit." << endl;
        break;
    }
}

// Function to print win/lose messages 
void win_lose_msgs(int losses) {
    switch (rand() % 10) {
    case 0:
        cout << (losses ? "\nOops! Try Again." : "\nVictory! You've guessed it right!") << endl;
        break;
    case 1:
        cout << (losses ? "\nBetter luck next time!" : "\nYou are a genius!") << endl;
        break;
    case 2:
        cout << (losses ? "\nOops! The number remains a mystery." : "\nBravo! You cracked the code like a pro!") << endl;
        break;
    case 3:
        cout << (losses ? "\nSo close! Yet so far." : "\nWell done! You're a true code breaker!") << endl;
        break;
    case 4:
        cout << (losses ? "\nGame over! Better luck next time." : "\nAmazing! You nailed it in style!") << endl;
        break;
    case 5:
        cout << (losses ? "\nNo worries, you'll get it next time!" : "\nWoohoo! Code cracked successfully!") << endl;
        break;
    case 6:
        cout << (losses ? "\nSorry! The secret remains safe." : "\nGenius alert! You guessed it!") << endl;
        break;
    case 7:
        cout << (losses ? "\nYou've used all your attempts. Try again?" : "\nYou did it! Code unlocked!") << endl;
        break;
    case 8:
        cout << (losses ? "\nDefeated by digits! Practice makes perfect." : "\nFlawless! You've mastered the game!") << endl;
        break;
    case 9:
        cout << (losses ? "\nTough luck, you almost cracked it!" : "\nThat's a win! Great job!") << endl;
        break;
    }
}
int main() {
    int wins = 0, losses = 0, maxattempts;
    char userinp, play, mode, user_choice;

    do {
        cout << "--> CHOOSE A MODE TO PLAY:\n E. EASY \n M. MEDIUM \n D. DIFFICULT" << endl;
        cin >> mode;
        

        if (mode == 'E') {
            maxattempts = 20;
        }
        else if (mode == 'M') {
            maxattempts = 15;
        }
        else if (mode == 'D') {
            maxattempts = 10;
        }
        else {
            cout << "Invalid mode selected!" << endl;
            return 1;
        }

       
        int rnum = generateRandomNumber();
        int guess, attempts = 0;
        string previousGuesses = "";

        cout << "**************************************** S E C R E T    C O D E   B R E A K E R ****************************************" << endl;
        cout << "\n\t*-* You have max " << maxattempts << " attempts *-*" << endl;

        do {
            cout << "\n---> MAKE A GUESS (4-digit number): ";
            cin >> guess;

            if (guess < 1000 || guess > 9999) {
                cout << "Invalid input. Please enter a 4-digit number." << endl;
                continue;
            }

            digit_separator(rnum, guess);
            attempts++;

            // Ask only after the first guess and half guesses
            if (attempts == 1 ) {
                cout << "\nWould you like to view your previous guesses after each try?\nY. YES\nN. NO" << endl;
                cin >> user_choice;
                
            }

            // Append current guess
            if (attempts == 1) {
                previousGuesses = to_string(guess);// converting to string to display the previous outputs as a string
            }
            else {
                previousGuesses += ", " + to_string(guess);// converting to string to display the previous outputs as a string
            }

            // Show previous guesses if user chose to
            if (user_choice == 'Y') {
                cout << "Previous guesses: " << previousGuesses << endl;
            }

            if (guess == rnum) {
                cout << "\nCongratulations! You've cracked the code in " << attempts << " attempts!" << endl;
                wins++;
                win_lose_msgs(0);
                break;
            }
            else {
                cout << "You have made " << attempts << "/" << maxattempts << " attempts." << endl;
            }

        } while (attempts < maxattempts);

        if (guess != rnum) {
            cout << "\nYou've used all your attempts. Game over!" << endl;
            cout << "\nThe correct code was: " << rnum << endl;
            losses++;
            win_lose_msgs(1);
        }

        cout << "\nWOULD YOU LIKE TO PLAY AGAIN?\n Y. Yes\n N. No" << endl;
        cin >> userinp;
        

    } while (userinp == 'Y');

    cout << "\nThanks for playing!" << endl;
    cout << "Total Wins: " << wins << endl;
    cout << "Total Losses: " << losses << endl;

    return 0;
}
