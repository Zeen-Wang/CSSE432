/* File: paint.c 
   Author: Zeen Wang
   
*/
#define CAN_COVERAGE 200

#include <stdio.h>
#include <math.h>

/*Optional functions, uncomment the next two lines
 * if you want to create these functions after main: */
// float readDimension(const char* name);
float calcArea(float width, float height, float depth);

int main(int argc, char *argv[]){
    // your code here
    float width, height, depth, area;
    printf("width> ");
    scanf("%f", &width);
    printf("height> ");
    scanf("%f", &height);
    printf("depth> ");
    scanf("%f", &depth);
    
    area = calcArea(width, height, depth);
    printf("Total Area: %.3f\n", area);
    printf("Number of cans required: %d\n", (int)ceil(area/200));
}

// float readDimension(const char* name){
    
// }

float calcArea(float width, float height, float depth){
    return 2 * width * height + 2 * width * depth + 2 * height * depth;
}