#include <stdio.h>
#include <string.h>

#define INCREASING 1
#define DECREASING 0


void convert(char original[], char converted[], int numRows);

int main(){
    char initial[] ="AB";
    char converted[strlen(initial)];

    convert(initial, converted, 1);

    printf("%s\n", converted);
}

void convert(char original[], char converted[], int numRows){
    char temp;
    int currentIndex = 0;
    char arr[numRows][100];
    int arrLength[numRows];
    int state = INCREASING;

    int i = 0;

    if(numRows == 1) {
        for(int start = 0; original[start] != '\0'; start++){
            converted[start] = original[start];
        }
        return;
    }

    for(int s = 0; s<numRows; s++){
        arrLength[s] = 0;
    }

    while(original[i] != '\0'){
        int currentLength = arrLength[currentIndex];
        arr[currentIndex][currentLength] = original[i];
        arrLength[currentIndex]++;

        if(state == INCREASING){
            if(currentIndex >= numRows-1){
                currentIndex--;
                state = DECREASING;
            }else{
                currentIndex++;
            }
        }else{
            if(currentIndex <= 0){
                currentIndex++;
                state = INCREASING;
            }else{
                currentIndex--;
            }
        }
        i++;
    }

    currentIndex = 0;
    i=0;
    for(int j = 0; original[j] != '\0'; j++){
        if(arrLength[currentIndex] == i){
            currentIndex++;
            i=0;
            j--;
            continue;
        }
        printf("%c", arr[currentIndex][i]);
        converted[j] = arr[currentIndex][i];
        i++;
    }

    printf("\n");
    return;
}
