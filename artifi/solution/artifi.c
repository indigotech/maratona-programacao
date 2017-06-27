//
//  main.c
//  C_One
//
//  Created by Taqtile on 6/23/17.
//  Copyright © 2017 Taqtile. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {   
    char input[3];

    scanf("%s", input);
    if (strcmp(input, "no") == 0) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}
