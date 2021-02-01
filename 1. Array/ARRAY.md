# Why we need array?
 - If we have store the 1000 books information, so in that case as a human  we cann't be create 1000 variables with differents names and whenever we use any variable
    then it's hard remember 1000 variable names that's why we use Array to store multiple items in a linear memory location.
    
Array is a `Linear Data Structure` which can used to store multiple items of same data type.
And it provide the indexing by using we can access the item which we want in just constant time  O(1).


<img src="https://github.com/manishhedau/Data-Structure-Algorithm/blob/main/1.%20Array/Array_1.png" width="600px" height="auto">

<img src="https://github.com/manishhedau/Data-Structure-Algorithm/blob/main/1.%20Array/Array_2.png" width="600px" height="auto">

<img src="https://github.com/manishhedau/Data-Structure-Algorithm/blob/main/1.%20Array/Array_3.jpg" width="600px" height="auto">


- First Index  address  - `Base Address`

## How to create an array?
```cpp
// Creating an array with size 10 And every index contain garbage values
    int Arr[10];
    
 ```

## Initializing the all index with Zero's

```cpp
  int Arr[10] = {0};
```
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|---|---|---|---|---|
 0    1    2   3   4   5   6   7    8   9
## Initializing the some index value while creating

```cpp
  int Arr[10] = {1,2,3};
```
| 1 | 2 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|---|---|---|---|---|
 0    1    2   3   4   5   6   7    8   9



