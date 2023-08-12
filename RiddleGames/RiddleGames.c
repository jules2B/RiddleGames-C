#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Couleurs ANSI pour le texte
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

int generateRandomNumber(int max)
{
	return rand() % max + 1;
}

void printWelcomeMessage(void)
{
	printf(COLOR_CYAN "Welcome to the Riddles game!\n");
	printf("I'm thinking about a number between 0 and 100\n" COLOR_RESET);
}

int getUserGuess(void)
{
	int guess;
	printf("Enter your answer: ");
	scanf("%d", &guess);
	return guess;
}

void evaluateGuess(int guess, int target)
{
	if (guess < target)
	{
		printf(COLOR_RED "It's too low!\n" COLOR_RESET);
	}
	else if (guess > target)
	{
		printf(COLOR_RED "It's too high!\n" COLOR_RESET);
	}
	else
	{
		printf(COLOR_GREEN "Congratulations, you have found the correct number!\n" COLOR_RESET);
	}
}

int main(void)
{
	int numberToGuess, userGuess, attempts = 0;
	int maxAttempts = 10;

	srand(time(NULL));
	numberToGuess = generateRandomNumber(100);
	printWelcomeMessage();

	while (attempts < maxAttempts)
	{
		userGuess = getUserGuess();
		attempts++;
		evaluateGuess(userGuess, numberToGuess);

		if (userGuess == numberToGuess)
		{
			printf(COLOR_GREEN "You have found the number in %d tries\n" COLOR_RESET, attempts);
			break;
		}
		else if (attempts == maxAttempts)
		{
			printf(COLOR_RED "Too bad! You couldn't guess the number.\n" COLOR_RESET);
			printf(COLOR_GREEN "The number was: %d\n\n" COLOR_RESET, numberToGuess);
		}
	}

	return 0;
}

