# Why we need array?
 - If we have store the 1000 books information, so in that case as a human  we cann't be create 1000 variables with differents names and whenever we use any variable
    then it's hard remember 1000 variable names that's why we use Array to store multiple items in a linear memory location.
    
Array is a 'Linear Data Structure' which can used to store multiple items of same data type.
And it provide the indexing by using we can access the item which we want in just constant time  O(1).

<img src="data:image/png;base64,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">