#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Represents an item in the binary knapsack problem.
 *
 * Each item contains its original index, value, weight, and
 * value-to-weight ratio used by the greedy strategy.
 */
typedef struct
{
    int index;
    int value;
    int weight;
    double ratio; // value/weight
} Item;

/**
 * @brief Compares two items based on their value-to-weight ratio.
 *
 * This function is used by qsort to sort items in decreasing
 * order of benefit-to-cost ratio.
 *
 * @param a Pointer to the first item.
 * @param b Pointer to the second item.
 * @return Negative value if a should come before b,
 *         positive value if b should come before a,
 *         zero if they are equal.
 */
int compareRatio(const void *a, const void *b)
{
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemA->ratio < itemB->ratio)
        return 1;

    if (itemA->ratio > itemB->ratio)
        return -1;

    return 0;
}

/**
 * @brief Solves the binary knapsack problem using a greedy heuristic.
 *
 * The algorithm selects items according to the highest value-to-weight
 * ratio first. Note that this greedy strategy does not always guarantee
 * an optimal solution for the binary knapsack problem.
 *
 * @param items Array of available items.
 * @param n Number of items.
 * @param capacity Maximum weight capacity of the knapsack.
 */
void greedyKnapsack(Item items[], int n, int capacity)
{
    qsort(items, n, sizeof(Item), compareRatio);

    int currentWeight = 0;
    int totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;

            printf("Selected item %d\n", items[i].index);
        }
    }

    printf("Total value: %d\n", totalValue);
    printf("Total weight: %d\n", currentWeight);
}

int main()
{
    int n, capacity;

    scanf("%d", &n);

    Item *items = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].index = i + 1;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    scanf("%d", &capacity);

    greedyKnapsack(items, n, capacity);

    free(items);

    return 0;
}