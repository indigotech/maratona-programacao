#include <stdio.h>
#define DISTANCE_TO_INTERNATIONAL_WATERS 12

int main()
{
    int distanceBetween, speedAna, speedCevice;
    
    while(scanf("%d %d %d", &distanceBetween, &speedCevice, &speedAna) != EOF) {
        if (willAnaReachCevice(distanceBetween, speedAna, speedCevice )) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}

int willAnaReachCevice(int distanceBetween, int speedAna, int speedCevice) {
    // A ideia é utilizar o teorema de pitagoras para determinar a distancia que a Ana deve percorrer
    // e a partir disso, ver a diferença dos tempos.
    // Para não lidarmos com float, rearranjamos a equação para comparar ints.
    return 
        powerOf2(DISTANCE_TO_INTERNATIONAL_WATERS) * powerOf2(speedAna)  >= pitagoras(distanceBetween, DISTANCE_TO_INTERNATIONAL_WATERS) * powerOf2(speedCevice);
}
// Returns hipotenusa^2
int pitagoras(int catet1, int catet2) {
    return powerOf2(catet1) + powerOf2(catet2);
}

int powerOf2(int x) {
    return x * x;
}
