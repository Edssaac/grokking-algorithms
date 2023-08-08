#include <stdio.h>

int binary_search(int[], int);
int recursive_binary_search(int[], int, int, int);

int main() {
    int sorted_list[] = {0, 5, 7, 24, 45, 59, 82};
    
    printf("%d\n", binary_search(sorted_list, 7));
    printf("%d\n", binary_search(sorted_list, 59));
    printf("%d\n", binary_search(sorted_list, 99));
    
    puts("-------\n");

    int low = 0;
    int high = sizeof(&sorted_list) - 1;
    
    printf("%d\n", recursive_binary_search(sorted_list, 7, low, high));
    printf("%d\n", recursive_binary_search(sorted_list, 59, low, high));
    printf("%d\n", recursive_binary_search(sorted_list, 99, low, high));
    
    return 0;
}

int binary_search(int list[], int item) {
    int low = 0;
    int high = sizeof(&list) - 1;
    int mid, guess;
    
    while (low <= high) {
        mid = (low + high) / 2;
        guess = list[mid];
        
        if (guess == item) {
            return mid;
        }
       
        if (guess > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return -1;
}

int recursive_binary_search(int list[], int item, int low, int high) {
    if (low <= high) {
        int mid = (low + high) / 2;
        int guess = list[mid];
        
        if (guess == item) {
            return mid;
        }
        
        if (guess > item) {
            return recursive_binary_search(list, item, low, (mid-1));
        }
            
        return recursive_binary_search(list, item, (mid+1), high);
    }

    return -1;
}