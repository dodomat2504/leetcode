#include <iostream>
#include <vector>


/**
 * Rotiert die Elemente einer n*n Matrix um 90° im Uhrzeigersinn
*/
static void rotate(std::vector<std::vector<int>>& matrix) {

    // Anzahl Reihen/Spalten
    const int N = matrix.size();
    
    /*
     *  z und s werden so gewählt, dass jeder Ring, der rotiert werden muss, nur einmal rotiert wird
     *  Ring bedeutet hier: Alle vier Zahlen, die in jeder Rotation miteinander die Plätze tauschen
     */

    for (int z = 0; z < (N / 2); z++) {
        for (int s = z; s < (N - 1 - z); s++) {
            const int temp = matrix[z][s];

            /*
             *  Formeln für das vorherige X und Y:
             *  X(i-1) = Y(i)
             *  Y(i-1) = N - 1 - X(i)
             */

            int x = s, y = z;
            int prevX = y;
            int prevY = N - 1 - x;

            // Rotation eines Rings, bis man das Startelement kopieren würde, welches aber bereits überschrieben wurde
            while (prevX != s || prevY != z) {
                matrix[y][x] = matrix[prevY][prevX];
                
                x = prevX;
                y = prevY;
                prevX = y;
                prevY = N - 1 - x;
            }

            matrix[y][x] = temp;
        }
    }
}

int main() {

    std::vector<std::vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    std::cout << "Output before:" << std::endl;
    for (const std::vector<int> reihe : matrix) {
        for (const int val : reihe)
            std::cout << " " << val << ",";
        std::cout << std::endl;
    }
    
    rotate(matrix);

    std::cout << "Output after:" << std::endl;
    for (const std::vector<int> reihe : matrix) {
        for (const int val : reihe)
            std::cout << " " << val << ",";
        std::cout << std::endl;
    }
    
    return 0;
}
