# Speller
## Introduction
Solving the problem [speller](https://cs50.harvard.edu/x/2020/psets/5/speller/), the Problem Set 5 of [Harvard CS50x 2020](https://cs50.harvard.edu/x/2020/).
For this problem, given 1) a text file with all english words and 2) a text file the program should write a file with all the misspellings in the text, considering a misspelling as a word or expression that is not in the input 1.

## Overview

To solve this problem in C, I used a [Trie](https://en.wikipedia.org/wiki/Trie) to store the words from the dictionary, since it's Big O notation is O(1) for this case;

Each node of the trie represent a character. In each trie, an unsigned int represents if the word exists or not

At the end of the search, the trie is released with a recursive function
