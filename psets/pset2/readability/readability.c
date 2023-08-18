#include<stdio.h>
#include<cs50.h>
#include<string.h>

int count_letters (int n, string s);
int count_words (int n, string s);
int count_sentences (int n, string s);

int main (void) {
    string s = get_string("Text: ");

    int n = strlen(s);
    float letter = count_letters(n,s);
    float word = count_words(n,s);
    float sentence = count_sentences(n,s);
    float L = (letter*100)/word;
    float S = (sentence*100)/word;
    float index = ((0.0588*L) - (0.296*S) - (15.8));
    int grade = index + 0.5;

    if (grade<1) {
        printf("Before Grade 1\n");
    }
    else if ((grade>=1) && (grade<16)) {
        printf("Grade %i\n", grade);
    }
    else if (grade>=16) {
        printf("Grade 16+\n");
    }
}

int count_letters (int n, string s) {

    int k = 0;

    for (int i = 0; i < n; i++) {

        if ((s[i]>=65) && (s[i]<=90)) {
            k++;
        }
        else if((s[i]>=97) && (s[i]<=122)) {
            k++;
        }

    }
    return k;
}

int count_words (int n, string s) {

    int k = 0;

    for (int i = 0; i < n; i++) {

        if (s[i]==32) {
            k++;
        }

    }
    return k+1;
}

int count_sentences (int n, string s) {

    int k = 0;

    for (int i = 0; i < n; i++) {

        if ((s[i]==46) || (s[i]==33) || (s[i]==63)) {
            k++;
        }

    }
    return k;
}