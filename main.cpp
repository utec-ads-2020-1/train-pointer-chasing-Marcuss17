#include <stdio.h>

void chasing(int **A[], int a, int *B[], int b, int C[], int c);

int main() {
        int a = 5, b = 4, c = 3;
        int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
        chasing(A, a, B, b, C, c);
 
        int **ansA[5] = {} ,*ansB[4] = {};
        for (int i = 0; i < a; i++)
                ansA[i] = NULL;
        for (int i = 0; i < b; i++)
                ansB[i] = NULL;
        ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
        /*Check A*/
        for (int i = 0; i < a; i++)
                if (A[i] != ansA[i] )
                        printf("A[%d] wrong answer!\n", i);
 
        /*Check B*/
        for (int i = 0; i < b; i++)
                if (B[i] != ansB[i] )
                        printf("B[%d] wrong answer!\n", i);
        return 0;
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){
    char d, e;
    FILE* filePtr = fopen("test1.txt", "r");
    int lineSize = 30;
    char line[lineSize];
    if(filePtr == NULL){
        printf("No such file.");
    }
    int ok = 1;
    int count = 0;
    bool isIn = false;
    bool start = false;
    int startingPos;
    char alphabet[] = {'A', 'B', 'C', ' '};
    char aChar[5]; 
    char bChar[4];
    char cChar[3];
    for(int i = 0; i < a; i++){
        aChar[i] = i+'0';
    }
    for(int i = 0; i < b; i++){
        bChar[i] = i + '0';
    }
    for(int i = 0; i < c; i++){
        cChar[i] = i + '0';
    }
    int alphabetSize = sizeof(alphabet)/sizeof(alphabet[0]);
    while(fgets(line,lineSize,filePtr) != NULL){
        ok = 1;
        for(int i = 0; i < lineSize; i++){
            if(i == 0){
                for(int j = 0; j < alphabetSize; j++){
                    if(line[i] == alphabet[j]){
                        start = true;
                    }
                }
                if(start){
                    startingPos = i;
                }else{ ok = 0;}
            }
            if(start){
                if(line[startingPos] != 'A' && line[startingPos] != 'B' && line[startingPos] != 'C' && line[startingPos] != ' '){
                    ok = 0;
                }
               switch(line[startingPos]){
                    case 'A':
                        if(line[startingPos+1] != ' '){ ok = 0;};
                        if(line[i] == ' ' && line[i+1] != ' '){
                            isIn = false;
                            for(int k = 0; k < a; k++){
                                if(line[i+1] == aChar[k]){
                                    isIn = true;
                                    break;
                                }
                            }
                            if(isIn){ break;}
                            if(line[i+1] != 'B'){
                                ok = 0;
                            }else{
                                startingPos = i+1;
                            } 
                        }else{continue;}
                        break;
                    case 'B': 
                        if(line[startingPos+1] != ' '){ ok = 0;};
                        if(line[i] == ' ' && line[i+1] != ' '){
                            isIn = false;
                            for(int k = 0; k < b; k++){
                                if(line[i+1] == bChar[k]){
                                    isIn = true;
                                    break;
                                }
                            }
                            if(isIn){ break;}
                            if(line[i+1] != 'C'){
                                ok = 0;
                            }else{
                                startingPos = i+1;
                            } 
                        }else{continue;}
                        break;
                    case 'C':
                        if(line[startingPos+1] != ' '){ ok = 0;};
                        if(line[i] == ' ' && line[i+1] != ' '){
                            isIn = false;
                            for(int k = 0; k < c; k++){
                                if(line[i+1] == cChar[k]){
                                    isIn = true;
                                    break;
                                }
                            }
                            if(isIn) { break;}
                            else{
                                ok = 0;
                            }
                        }
                }
            }
            if((line[i] == ' ' && (line[i+1] == 'A' || line[i+1] == 'B' || line[i+1] =='C')) && !start){
                start = true;
                startingPos = i+1;
            }
            if(line[i] == ' '){continue;}
        }
        count++;
        start = false;
        printf("%d\n",ok);
    }
    fclose(filePtr);
}
