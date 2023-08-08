#include <stdio.h>
#include <math.h>

#define K 3

typedef struct {
    double x;
    double y;
    char label;
} Point;

double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

char predictClass(Point dataset[], Point query) {
    double distances[K];
    char labels[K];

    for (int i = 0; i < K; i++) {
        distances[i] = calculateDistance(dataset[i], query);
        labels[i] = dataset[i].label;
    }

    for (int i = K; i < sizeof(dataset) / sizeof(dataset[0]); i++) {
        double distance = calculateDistance(dataset[i], query);

        int maxIndex = 0;
        for (int j = 1; j < K; j++) {
            if (distances[j] > distances[maxIndex]) {
                maxIndex = j;
            }
        }

        if (distance < distances[maxIndex]) {
            distances[maxIndex] = distance;
            labels[maxIndex] = dataset[i].label;
        }
    }

    int countA = 0, countB = 0;
    for (int i = 0; i < K; i++) {
        if (labels[i] == 'A') {
            countA++;
        } else {
            countB++;
        }
    }

    return (countA > countB) ? 'A' : 'B';
}

int main() {
    Point dataset[] = {
        {1.0, 2.0, 'A'},
        {2.0, 3.0, 'A'},
        {3.0, 4.0, 'B'},
        {4.0, 5.0, 'B'}
    };

    Point query = {2.5, 3.5, '?'};

    char predictedClass = predictClass(dataset, query);

    printf("The query point belongs to the class: %c\n", predictedClass);

    return 0;
}
