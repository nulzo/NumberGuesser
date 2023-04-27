#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int find(int* arr, int num, int count);
int findBalls(int* generated, int* input);
int findStrikes(int* generated, int* input);
int generate(int* generated, int count);
int getInput(int* input, int count);

const int count = 3;

int find(int* arr, int num, int count){
    for(int i=0; i<count; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

int findBalls(int* generate, int* input){
    int index;
    int num;
    int balls = 0;
    for(int i=0; i<count; i++){
        num = generate[i];
        index = find(input, num, count);
        if(index != -1 && index != i){
            balls++;
        }
    }
    return balls;
}

int findStrikes(int* generate, int* input){
    int index;
    int num;
    int strikes = 0;
    for(int i=0; i<count; i++){
        num = generate[i];
        index = find(input, num, count);
        if(index == i){
            strikes++;
        }
    }
    return strikes;
}

int generate(int* generated, int count){
    int randomNumber;
    int index;
    int added = 0;
    while(added < count){
        srand(time(NULL));
        randomNumber = (rand() % 9) + 1;
        index = find(generated, randomNumber, count);
        if(index == -1){
            generated[added] = randomNumber;
            added++;
        }
    }
    return 0;
}

int getInput(int* input, int count){
    int userInput;
    int index;
    int added = 0;
    while(added < count){
        printf("Enter a value between (1-9): ");
        scanf("%d", &userInput);
        fflush(stdin);
        while(userInput > 9 || userInput < 1){
            printf("Invalid input. Must be between (1-9): \n");
            scanf("%d", &userInput);
            fflush(stdin);
        }
        index = find(input, userInput, count);
        if(index == -1){
            input[added] = userInput;
            added++;
        }
        else{
            printf("Must enter non-duplicate value.\n");
        }
    }
    return 0;
}

void clearBuffer(void){    
  while ( getchar() != '\n' );
}

void print(int* generate, int* input){
    for(int i=0; i<count; i++){
        printf("Generated: %d  --  Input: %d\n", generate[i], input[i]);
    }
}


int main(void){
    int generated[3] = {0};
    int balls;
    int strikes;
    char choice;
    int deez;
    generate(generated, count);
    while(1){
        int input[3] = {0};
        getInput(input, count);
        balls = findBalls(generated, input);
        strikes = findStrikes(generated, input);
        print(generated, input);
        (strikes > 0 ? (strikes==1) ? printf("%d strike ", strikes) : printf("%d strikes ", strikes) : printf(""));
        (balls > 0 ? (balls==1) ? printf("%d ball ", balls) : printf("%d balls ", balls) : printf(""));
        if(balls == 0 & strikes == 0) printf("Out");
        printf("\n");
        if(strikes == count){
            printf("Good Job! Do you want to play again (y/n)?: ");
            clearBuffer();
            choice = getchar();
            while(choice != 'y' && choice != 'n'){
                printf("Invalid Input!\n");
                printf("Good Job! Do you want to play again (y/n)?: ");
                choice = getchar();
                clearBuffer();
            }
            if(choice == 'n') break;
            generate(generated, count);
        }
    }
    return 0;
}