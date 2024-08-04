//C++ Program to sort a hand of playing cards in ascending order using the Insertion Sort algorithm.
#include <iostream>
using namespace std;
void printCards(const int cards[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << cards[i] << " ";
    }
    cout << endl;
}
void insertionSort(int cards[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = cards[i];
        int j = i - 1;
        while (j >= 0 && cards[j] > key) {
            cards[j + 1] = cards[j];
            --j;
        }
        cards[j + 1] = key;
    }
}
int main() {
    int cards[] = {7, 3, 9, 2, 5, 1, 4};
    int size = sizeof(cards) / sizeof(cards[0]);

    cout << "Original hand: ";
    printCards(cards, size);

    insertionSort(cards, size);

    cout << "Sorted hand: ";
    printCards(cards, size);

    return 0;
}

