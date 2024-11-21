[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/3GzinNZ-)
Assignment 5

Chapter 9

Exercise 1 (15 points)
Write a program that will read in a sentence of up to 100 characters and output the sentence with
spacing corrected and with letters corrected for capitalization. In other words, in the output
sentence, all strings of two or more blanks should be compressed to a single blank. The sentence
should start with an uppercase letter but should contain no other uppercase letters. Do not worry
about capitalizing proper nouns. Assume that the sentence ends with a period and contains no
other periods.


Exercise 2 (15 points)

Write a program that reads in a line of text and replaces all four-letter words with the word
"love". If the four-letter word starts with a capital letter, it should be replaced with "Love". A word
is any string consisting of the letters of the alphabet and delimited at each end by a blank, the
end of the line, or any other character that is not a letter.

Chapter 12

Exercise 3 (15 points)

Write a program that merges the numbers from file1.txt and file2.txt and writes all the numbers
to file3.txt. Assume that each input file contains a list of ints in sorted order from the smallest to
the largest. After the program is run, the output file will contain all the numbers in the two input
files in one longer list in sorted order from smallest to largest. Your program should implement a
function that is called with the two input-file streams and the output-file streams its arguments.
Exercise 4 (15 points)

Write a program that allows the user to type in any one-line question and then answer that
question. The program will not really pay any attention to the question but will simply read the
question line and discard all that it reads. It always gives one of the following answers:

I'm not sure but I think you will find the answer in Chapter 20.

That's a good question.

If I were you, I would not worry about such things.

That question has puzzled philosophers for centuries.

I don't know. I'm just a machine.

Think about it and the answer will come to you.

I used to know the answer to that question, but I've forgotten it.

The answer can be found in a secret place in the woods.

These answers are stored, one per line, in the file answers.txt. Your program should simply read
the next answer from the file and write it out as the answer to the question. Allow the user to
continue asking questions until they choose to exit the program. After your program has read
the entire file, it simply closes the file, reopens the file, and starts down the list of answers again.
