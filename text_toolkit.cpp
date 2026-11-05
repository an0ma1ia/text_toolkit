#include <iostream>
#include <cstring>

using namespace std;

char text[256]; //initial text
int option;
char cop[256], cop2[256], reversed[256], string1[256], positive[256], string2[256]; //used for options 3, 5, 6, 7, 8
char *negative[] = {"no", "No", "NO", "nO"};
int cnt1, cnt2, nr_words;
char *poz;
bool ok = false;
char punctuation[10] = {'.', ',', '!', '?', ';', ':'}; //used for option 4
char divider[5] = {',', '.'}; //used for option 5


void option1 (char text[256], int nr_words){
    cout << "The number of characters is " << strlen(text) << " and the number of words is.";
    for (int i = 0; i < strlen(text); i ++)
        if (text[i] == ' ') nr_words ++;
    cout << nr_words + 1 << "." << "\n";
}

void option2(char text [256], int cnt1, int cnt2){
    for (int i = 0; i < strlen(text); i ++){
        if (isalpha(text[i])) cnt1 ++;
        if (isdigit(text[i])) cnt2 ++;
    }
    cout << "There are" << " " << cnt1 << " " << "letters and " << " " << cnt2 << " " << "numbers." << "\n";
}

void option3(char cop[256]){
    for (int i = 0; i < strlen(text); i ++){
            cop[i] = text[i];
            if (isupper(cop[i])) ok = true;
               cop[i] = tolower(cop[i]);
        }
            if (ok) cout << cop << "\n";
            else cout << "There are no capital letters in the text.\n";
    ok = false;
}

void option4(char text[256]){
    for (int i = 0; i < strlen(text); i ++)
        if (strchr(punctuation, text[i])) ok = true, cout << text[i] << " ";
    if (!ok) cout << "There are no punctuation marks in the text.";
    cout << "\n";
}

void option5(char cop2[256]){
    strcpy(cop2, text);
    char* a = strtok(cop2, divider);
        while (a){
            cout << a << "\n";
            a = strtok(NULL, divider);
        }
}

void option6(char reversed[256]){
    strcpy (reversed, text);
    for (int i = 0; i < strlen(reversed)/2; i ++){
            int aux = reversed[i];
            reversed[i] = reversed[strlen(reversed) - i - 1];
            reversed[strlen(reversed) - i - 1] = aux;
        }
    cout << reversed << "\n";
}

void option7(char text[256], char string1[256]){
    cout << "Insert a string:\n\n";
    cin.ignore();
    cin.getline(string1, 256);
    cout << "\n";
    if (strlen(string1) + strlen(text) + 1 < 256) strncat(string1, " ", 1);
    strncat(string1, text, 255 - strlen(string1));
    cout << string1 << "\n";
}

void option8(char pozitiv[256]){
    strcpy(pozitiv, text);
    for (int i = 0; i < 4; i ++){
        poz = strstr(positive, negative[i]);
        while (poz != NULL){
            ok = true;
            strcpy(poz, poz + 3);
            poz = strstr(positive, negative[i]);
        }
    }
    if (ok) cout << positive << "\n";
        else cout << "The word 'no' doesn't exist in the text.\n";
    ok = false;
}

void option9(char text[256], char string2[256]){
    cout << "Insert a string:\n\n";
    cin.ignore();
    cin.getline(string2, 256);
    cout << "\n";
    if (strcmp(text, string2) < 0) cout << "The first sring is lexicographically smaller.\n";
    else if (strcmp(text, string2) > 0) cout << "The second sring is lexicographically smaller.\n";
        else if (strcmp(text, string2) == 0) cout << "The srings are lexicographically equal.\n";
}

int main(){

    cout << "Insert text:\n\n";
    cin.getline(text, 256);

    while (true){
        cout << "\n";
        cout << "Choose an option:\n";
        cout << "1. Number of characters and number of words\n";
        cout << "2. Number of letters and number of numbers\n";
        cout << "3. Convert capital letters into small ones\n";
        cout << "4. Display all punctuation marks\n";
        cout << "5. Extract from text words separated by {',','.'}\n";
        cout << "6. Reverse text\n";
        cout << "7. Concatenate the text to another given one\n";
        cout << "8. Eliminate the word no from text, if it exists\n";
        cout << "9. Lexicographically compare the string to another given one\n";
        cout << "10. Exit\n\n";

        cin >> option;

        if(option == 1) option1(text, nr_words);

        if(option == 2) option2(text, cnt1, cnt2);

        if(option == 3) option3(cop);

        if(option == 4) option4(text);

        if(option == 5) option5(cop2);

        if(option == 6) option6(reversed);
          
        if(option == 7) option7(text, string1);

        if(option == 8) option8(positive);

        if(option == 9) option9(text, string2);

        if(option == 10){
            cout << "The end.\n";
            break;
        }
    }
    return 0;
}
