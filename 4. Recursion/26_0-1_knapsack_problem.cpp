// thief problem or 0-1 Knapsack problem

#include<iostream>
using namespace std;
// Approach -
/*
My approach is to solve this problem by using subset or subsquance method 
I am thinking is that first generate all the subset of of price and then sub the subsets
and then in each subset decreasing value of capacity - weight[i-1] if(weight[i-1]<=capacity)
then call the function for including sum + prince[i-1]
or call the function for excluding sum by not adding price[i-1] and in this call we will not decrease capacity value beacuse we are not adding anything.

and which ever the maximum value we found by including or excluding prince[i-1] 
return that sum value to main() function
*/
int findProfit(int *price, int *weight, int i, int capacity, int sum = 0){
    // base case
    if(i==0 || capacity == 0){  
        return sum;
    }

    int ex , inc;
    ex = inc = 0;
    // include the element
    if(weight[i-1]<=capacity){
        inc = findProfit(price, weight, i-1, capacity-weight[i-1],sum+price[i-1]);
    }
    // exclude the element 
    ex = findProfit(price,weight, i-1, capacity, sum);

    return max(ex, inc);
}
int main() {
    int weight[] = {1,2,3,4};
    int price[] = {40, 20, 30, 100};

    int capacity = 5;

    cout<<findProfit(price,weight, 4, capacity);

    return 0;
}

/*
Output :-
140
*/