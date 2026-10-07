#include <stdio.h>

#define MAX 100

/* Parallel arrays replace the struct */
int no[MAX];
float value[MAX];
float weight[MAX];
float ratio[MAX];
float selected[MAX];

int n = 0;
float capacity = 0;

/* Function to calculate Value/Weight ratio */
void calculateRatio()
{
    int i;
    for(i = 0; i < n; i++)
    {
        ratio[i] = value[i] / weight[i];
    }
    printf("\nValue/Weight ratio calculated successfully.\n");
}

/* Function to display package details */
void displayPackages()
{
    int i;
    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }

    printf("\nPackage\tValue\tWeight\tRatio\n");

for(i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", no[i], value[i], weight[i], ratio[i]);
    }
    printf("Vehicle Capacity = %.2f\n", capacity);
}

/* Function to sort packages in decreasing ratio using Bubble Sort */
void sortPackages()
{
    int i, j;
    
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                /* Swap ratios */
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;
                
                /* Swap values */

float tempValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempValue;
                
                /* Swap weights */
                float tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;
                
                /* Swap package numbers */
                int tempNo = no[j];
                no[j] = no[j + 1];
                no[j + 1] = tempNo;
                
                /* Swap selected fractions */
                float tempSelected = selected[j];
                selected[j] = selected[j + 1];
                selected[j + 1] = tempSelected;
            }
        }
    }

printf("\nPackages sorted by decreasing Value/Weight ratio.\n");
}

/* Function to find maximum value */
void findMaximum()
{
    int i;
    float remaining = capacity;
    float maxValue = 0;

    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }

    /* Reset selected quantity */
    for(i = 0; i < n; i++)
    {
        selected[i] = 0;
    }

  /* Greedy selection */
    for(i = 0; i < n; i++)
    {
        if(remaining <= 0)
            break;

        if(weight[i] <= remaining)
        {
            /* Take complete package */
            selected[i] = 1;
            remaining = remaining - weight[i];
            maxValue = maxValue + value[i];
        }
        else
        {
            /* Take fraction of package */
            selected[i] = remaining / weight[i];
            maxValue = maxValue + value[i] * selected[i];
            remaining = 0;
        }
    }

printf("\nMaximum Value = %.2f\n", maxValue);
    printf("Total Weight Used = %.2f\n", capacity - remaining);
}

/* Function to display selected packages */
void displaySelected()
{
    int i;
    int found = 0;

    if(n == 0)
    {
        printf("\nPlease enter package details first.\n");
        return;
    }

    printf("\nSelected Packages:\n");
    printf("Package\tFraction Taken\n");

    for(i = 0; i < n; i++)
    {
        if(selected[i] > 0)
        {
            printf("%d\t%.2f\n", no[i], selected[i]);
            found = 1;
        }
    }

    if(found == 0)
        printf("No packages selected.\n");
}

int main()
{
    int choice;
    int i;

    do
    {
        printf("\n========== FRACTIONAL KNAPSACK ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter number of packages: ");
                scanf("%d", &n);

                printf("Enter vehicle capacity: ");
                scanf("%f", &capacity);

                for(i = 0; i < n; i++)
                {
                    no[i] = i + 1;

                    printf("\nPackage %d Value: ", i + 1);
                    scanf("%f", &value[i]);

                    printf("Package %d Weight: ", i + 1);
                    scanf("%f", &weight[i]);

                    ratio[i] = 0;
                    selected[i] = 0;
                }
                printf("\nPackage details entered successfully.\n");
                break;

            case 2:
                displayPackages();
                break;
            case 3:
                calculateRatio();
                break;
            case 4:
                sortPackages();
                break;
            case 5:
                calculateRatio();
                sortPackages();
                findMaximum();
                break;
            case 6:
                displaySelected();
                break;
            case 7:
                printf("\nProgram terminated.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while(choice != 7);

    return 0;
}
