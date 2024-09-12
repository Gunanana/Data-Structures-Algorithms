/*
TIP 1

If you're following a guide and get stuck on this problem, make sure you have done the pre-reqs.

1) Understand recursion. Don't just skip to this, otherwise understanding the call stack will be difficult. Do basic recursion problems!

2) Draw out the state diagram. In this problem, you have two decisions you can make. Pick the number at the current index, or skip that number. There are plenty of videos on visualization for these sorts of problems, follow along. Struggle here, and be rewarded it for it later.

3) Come back to these sorts of problems, repeat step 2 and solve it again. Consistency is key.

4) Don't just blindly copy down to solution involving the for loop. Begin with understanding the solution that purely involves the two function calls.

5) Once you've truly understood this problem, move on to Combination Sum and other backtracking problems that involve pick or skip.

6) If you've made it here, you can now understand how things work when the for loop is involved. You will need to use this concept, and an immediate application from here is Letter Combinations of a Phone Number.

7) Build yourself up with more and more backtracking problems.

8) To start with DP, understand how to brute-force, then top-down memo, then bottom up. There's a great guide here



TIP 2

The subsets problem has two backtracking solutions, one in which we loop over all the elements in the rest of the array and add an element recur and remove the element. And one in which we have two recursive calls for each element, one in which the present element is added and one in which the present element is skipped.

These can be explained as follows.

IN THE FIRST WAY, we use the mathematical logic "create every subset which contains this element for every element". Starting from a blank array, we first want to create every subset which contains nums[0]. So, we add nums[0] to a blank array.

Thinking mathematically again, all the subsets that contain nums[0] are all the subsets of the array excluding nums[0] to which nums[0] is added. Since the recursive function returns all the subsets beginning from the next index, it is time for a recursive call where the present element is included. After this call, all the subsets containing this element have been added and so it may be removed.

The reason for the loop to go over every element is that the subsets excluding the current element are always given by all the subsets that can be formed by including each one of the following elements as the beginning of the rest of the subset.


IN THE SECOND WAY we use the combinatorial logic of every element can either "be present or not be present" in a subset. We make a recursive call where the element is not present and then one where it is present. There is no need for loops and when the present index reaches the end of the array it means another subset is completed and can be added to the result.

The second way is more straightforward since that is how most people view the construction of a subset, however the first way is more suited to a variety of approaches. For example in Subsets II, for both the approaches the only difference from Subsets is an if statement, however it is much easier to write this statement in the first case than in the second.

For Subsets II, repetitions are not allowed. So by sorting the array before performing either method, we ensure that we can easily check for the last inserted element.

In the first method if i > idx && A[idx-1] == A[idx] where idx is the beginning index for the iteration it suggests a duplicate element. However once we have a single copy inserted then the recursive calls will make sure that any copies are places always at i == idx and hence recursive calls will only add the duplicate values, never replace them.

In the second method, the recursive call to the non-appended array should be made only either the current array is empty or if the last element in the current array is not equal to the present element. Again, the appended call is always made since the subset with different number of duplicates is counted but one with replaced duplicates is not.
*/
