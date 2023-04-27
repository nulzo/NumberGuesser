#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

using std::cout;
using std::cin;
using std::vector;
using std::string;

const int count = 3;

int find(vector<int>& arr, int num, int count) {
    for(int i=0; i<count; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

int generate(vector<int>& generated, int count){
    int randomNumber;
    int size = 0;
    while(size < count){
        srand(time(NULL));
        randomNumber = (rand() % 10) + 1;
        if (find(generated, randomNumber, count) == -1){
            generated[size] = randomNumber;
            size++;
        }
    }
    return 0;
}

int getUserInput(vector<int>& input, int count){
    int userChoice;
    int size=0;
    while(size < count){
        cout << "Enter user input: ";
        cin >> userChoice;
        while(userChoice > 9 || userChoice < 1){
            cout << "Enter a value between [1-9]: ";
            cin >> userChoice;
        }
        if (find(input, userChoice, count) == -1){
            input[size] = userChoice;
            size++;
        }
        else cout << "Must enter non-duplicate value.\n";
    }
    return 0;
}

int findBalls(vector<int>& generated, vector<int>& input){
    int balls = 0;
    int currentGen = 0;
    int idx = -1;
    for(int i=0; i<count; i++){
        currentGen = generated[i];
        idx = find(input, currentGen, count);
        if(idx != -1 && idx != i){
            balls++;
        }
    }
    return balls;
}

int findStrikes(vector<int>& generated, vector<int>& input){
    int strikes = 0;
    int currentGen = 0;
    int idx = -1;
    for(int i=0; i<count; i++){
        currentGen = generated[i];
        idx = find(input, currentGen, count);
        if(idx == i){
            strikes++;
        }
    }
    return strikes;
}

int main(){
    int balls;
    int strikes;
    string choice;
    vector<int> g(count, 0);
    generate(g, count);

    while(true){
        vector<int> userInput(count, 0);
        getUserInput(userInput, count);

        balls = findBalls(g, userInput);
        strikes = findStrikes(g, userInput);

        if(strikes > 0) cout << strikes << " strikes ";
        if(balls > 0) cout << balls << " balls ";
        if(balls == 0 && strikes == 0) cout << "Out";
        cout << std::endl;

        if(strikes == count){
            cout << "\nGood Job! Do you want to play again (y/n)?: ";
            cin >> choice;
            while(choice != "y" && choice != "n"){
                cout << "Invalid input!\n";
                cout << "Good Job! Do you want to play again (y/n)?: ";
                cin >> choice;
            }
            if(choice == "n") break;
            else{
                srand(time(NULL));
                vector<int> g(count, 0);
                generate(g, count);
            }
        }
    }
    return 0;
}