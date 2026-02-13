# Greedy Knapsack (Fractional Knapsack)

## Introduction

The **Fractional Knapsack Problem** is a classic optimization problem where you are given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity. The goal is to **maximize the total value** you can carry in the knapsack.

Unlike the 0/1 Knapsack (where you must take or leave an entire item), the **fractional variant allows you to take a fraction of an item**. This key difference is what makes the greedy approach work here — and work optimally.

---

## Problem Statement

> Given `n` items, each with a **weight** `w[i]` and a **value** `v[i]`, and a knapsack of capacity `W`, fill the knapsack to **maximize total value**. You may take **fractions** of items.

### Example

| Item | Value | Weight | Value/Weight |
|------|-------|--------|--------------|
| A    | 60    | 10     | 6.0          |
| B    | 100   | 20     | 5.0          |
| C    | 120   | 30     | 4.0          |

**Knapsack Capacity:** `W = 50`

---

## The Greedy Strategy

The greedy approach for Fractional Knapsack is:

1. **Compute the value-to-weight ratio** for each item: `ratio = value / weight`
2. **Sort items in decreasing order** of this ratio
3. **Greedily pick items** — take as much of the highest-ratio item as possible
   - If the full item fits, take it entirely
   - If only a fraction fits, take that fraction and stop

### Why Does Greedy Work?

In the fractional variant, taking items with the **highest value per unit weight first** always leads to the optimal solution. Since we can break items, there is no "wasted capacity" — every unit of weight in the knapsack carries the maximum possible value.

This is fundamentally different from 0/1 Knapsack, where greedy **fails** because you cannot take fractions.

---

## Step-by-Step Walkthrough

Using our example with capacity `W = 50`:

**After sorting by value/weight ratio (descending):**

| Item | Value | Weight | Ratio |
|------|-------|--------|-------|
| A    | 60    | 10     | 6.0   |
| B    | 100   | 20     | 5.0   |
| C    | 120   | 30     | 4.0   |

**Step 1:** Take all of Item A (weight 10, value 60)
- Remaining capacity: `50 - 10 = 40`
- Total value so far: `60`

**Step 2:** Take all of Item B (weight 20, value 100)
- Remaining capacity: `40 - 20 = 20`
- Total value so far: `60 + 100 = 160`

**Step 3:** Item C weighs 30 but only 20 capacity remains. Take `20/30 = 2/3` of Item C.
- Value gained: `120 × (20/30) = 80`
- Remaining capacity: `0`
- Total value: `160 + 80 = 240`

**Answer: Maximum value = 240**

---

## Time and Space Complexity

| Aspect         | Complexity     | Explanation                        |
|----------------|----------------|------------------------------------|
| Time           | **O(n log n)** | Dominated by sorting               |
| Space          | **O(n)**       | To store items and ratios          |
| Greedy Scan    | O(n)           | Single pass after sorting          |

---

## Python Implementation

```python
def fractional_knapsack(values, weights, capacity):
    """
    Solve the Fractional Knapsack problem using a greedy approach.

    Args:
        values:   List of item values
        weights:  List of item weights
        capacity: Maximum knapsack capacity

    Returns:
        Maximum total value achievable
    """
    n = len(values)

    # Create list of (ratio, value, weight) and sort by ratio descending
    items = []
    for i in range(n):
        ratio = values[i] / weights[i]
        items.append((ratio, values[i], weights[i]))

    items.sort(reverse=True, key=lambda x: x[0])

    total_value = 0.0
    remaining = capacity

    for ratio, value, weight in items:
        if remaining <= 0:
            break

        if weight <= remaining:
            # Take the entire item
            total_value += value
            remaining -= weight
        else:
            # Take a fraction of this item
            fraction = remaining / weight
            total_value += value * fraction
            remaining = 0

    return total_value


# --- Example Usage ---
if __name__ == "__main__":
    values  = [60, 100, 120]
    weights = [10, 20, 30]
    capacity = 50

    result = fractional_knapsack(values, weights, capacity)
    print(f"Maximum value in knapsack: {result}")
    # Output: Maximum value in knapsack: 240.0
```

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double value;
    double weight;
    double ratio;
};

// Comparator: sort by value/weight ratio in descending order
bool compare(const Item &a, const Item &b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<double> &values, vector<double> &weights, double capacity) {
    int n = values.size();
    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        items[i].value  = values[i];
        items[i].weight = weights[i];
        items[i].ratio  = values[i] / weights[i];
    }

    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    double remaining  = capacity;

    for (int i = 0; i < n; i++) {
        if (remaining <= 0) break;

        if (items[i].weight <= remaining) {
            // Take the entire item
            totalValue += items[i].value;
            remaining  -= items[i].weight;
        } else {
            // Take a fraction of this item
            double fraction = remaining / items[i].weight;
            totalValue += items[i].value * fraction;
            remaining = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<double> values  = {60, 100, 120};
    vector<double> weights = {10, 20, 30};
    double capacity = 50;

    double result = fractionalKnapsack(values, weights, capacity);
    cout << "Maximum value in knapsack: " << result << endl;
    // Output: Maximum value in knapsack: 240

    return 0;
}
```

---

## Java Implementation

```java
import java.util.Arrays;
import java.util.Comparator;

public class FractionalKnapsack {

    static double fractionalKnapsack(double[] values, double[] weights, double capacity) {
        int n = values.length;

        // Create array of indices sorted by value/weight ratio (descending)
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                double ratioA = values[a] / weights[a];
                double ratioB = values[b] / weights[b];
                return Double.compare(ratioB, ratioA); // Descending
            }
        });

        double totalValue = 0.0;
        double remaining  = capacity;

        for (int idx : indices) {
            if (remaining <= 0) break;

            if (weights[idx] <= remaining) {
                // Take the entire item
                totalValue += values[idx];
                remaining  -= weights[idx];
            } else {
                // Take a fraction of this item
                double fraction = remaining / weights[idx];
                totalValue += values[idx] * fraction;
                remaining = 0;
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        double[] values  = {60, 100, 120};
        double[] weights = {10, 20, 30};
        double capacity = 50;

        double result = fractionalKnapsack(values, weights, capacity);
        System.out.printf("Maximum value in knapsack: %.1f%n", result);
        // Output: Maximum value in knapsack: 240.0
    }
}
```

---

## C Implementation

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    double weight;
    double ratio;
} Item;

// Comparator for qsort: descending order of ratio
int compare(const void *a, const void *b) {
    double ratioA = ((Item *)a)->ratio;
    double ratioB = ((Item *)b)->ratio;
    if (ratioB > ratioA) return 1;
    if (ratioB < ratioA) return -1;
    return 0;
}

double fractionalKnapsack(double values[], double weights[], int n, double capacity) {
    Item *items = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        items[i].value  = values[i];
        items[i].weight = weights[i];
        items[i].ratio  = values[i] / weights[i];
    }

    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    double remaining  = capacity;

    for (int i = 0; i < n; i++) {
        if (remaining <= 0) break;

        if (items[i].weight <= remaining) {
            /* Take the entire item */
            totalValue += items[i].value;
            remaining  -= items[i].weight;
        } else {
            /* Take a fraction of this item */
            double fraction = remaining / items[i].weight;
            totalValue += items[i].value * fraction;
            remaining = 0;
        }
    }

    free(items);
    return totalValue;
}

int main() {
    double values[]  = {60, 100, 120};
    double weights[] = {10, 20, 30};
    int n = 3;
    double capacity = 50;

    double result = fractionalKnapsack(values, weights, n, capacity);
    printf("Maximum value in knapsack: %.1f\n", result);
    /* Output: Maximum value in knapsack: 240.0 */

    return 0;
}
```

---

## Greedy Knapsack vs 0/1 Knapsack

| Feature               | Fractional (Greedy)     | 0/1 (Dynamic Programming) |
|-----------------------|------------------------|---------------------------|
| Can take fractions?   | Yes                    | No                        |
| Approach              | Greedy                 | DP                        |
| Time Complexity       | O(n log n)             | O(n × W)                  |
| Optimality            | Always optimal         | Always optimal             |
| Greedy works?         | **Yes**                | **No**                    |
| Key idea              | Sort by value/weight   | Build subproblem table     |

### Why Greedy Fails for 0/1 Knapsack

Consider: `values = [60, 100, 120]`, `weights = [10, 20, 30]`, `W = 50`

- **Greedy** picks Item A (ratio 6.0), then Item B (ratio 5.0) → weight 30, value 160. Cannot fit Item C. **Total = 160 + (20/30)×120 = 240** ← but this uses a fraction!
- In **0/1 mode**, greedy picks A + B = 160 with weight 30. Then C doesn't fit (needs 30, only 20 left). Total = **160**.
- **DP optimal** picks B + C = **220** with weight 50. Better!

The 0/1 constraint means greedy's "best ratio first" strategy can leave awkward gaps. DP explores all combinations to find the true optimum.

---

## Common Variations

### 1. Minimum Weight for Target Value
> Given items and a target value `V`, find the **minimum total weight** needed to achieve at least value `V`.

Same greedy idea — sort by ratio descending, pick until target value is met.

### 2. Multiple Knapsacks
> Fill `k` knapsacks with different capacities.

Sort items by ratio, fill each knapsack greedily. Note: this variant may not always be optimal with pure greedy.

### 3. Items with Deadlines
> Each item has a deadline — you must decide by a certain point.

Requires careful ordering; sometimes combines greedy with scheduling techniques.

---

## When to Use Greedy Knapsack

Use the greedy approach when:
- Items can be **divided into fractions**
- You need the solution **fast** (O(n log n) vs DP's pseudo-polynomial)
- The problem has **no indivisibility constraint**

Use DP (0/1 Knapsack) when:
- Items must be taken **whole or not at all**
- You need the **exact optimal** for indivisible items

---

## Key Takeaways

1. **Fractional Knapsack** is solved optimally by a greedy algorithm
2. The greedy criterion is **value-to-weight ratio** — always pick the best bang for your buck
3. **Sort by ratio descending**, then greedily fill the knapsack
4. Time complexity is **O(n log n)** due to sorting
5. Greedy **fails** for 0/1 Knapsack — use DP instead
6. The ability to take fractions is what makes greedy work — every unit of capacity carries maximum value
