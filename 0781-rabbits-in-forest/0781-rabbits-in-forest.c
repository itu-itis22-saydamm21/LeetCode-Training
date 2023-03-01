int numRabbits(int* answers, int answersSize) {
    int counts[1000] = {0}; // Assume no more than 1000 rabbits
    int minCount = 0;
    for (int i = 0; i < answersSize; i++) {
        int ans = answers[i];
        counts[ans]++;
        if (counts[ans] == ans + 1) { // We've seen all rabbits of this color
            minCount += ans + 1;
            counts[ans] = 0; // Reset the count
        }
    }
    // Add up the remaining rabbits that we haven't seen all of their color
    for (int i = 0; i < 1000; i++) {
        if (counts[i] > 0) {
            minCount += i + 1;
        }
    }
    return minCount;
}