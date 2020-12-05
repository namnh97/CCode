// Modular arithmetic
(a + b) % m = (a % m + b % m) % m;
(a - b) % m = (a % m - b % m) % m;
(a * b) % m = (a % m * b % m) % m;

// floating point with c++
double x = 0.3 * 3 + 0.1;
printf("%.20f\n", x); // 0.99999999999999988898


//  comparison function
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
sort(v.begin(), v.end(), comp);
reverse(v.begin(), v.end());
auto a = lower_bound(array, array + n, x);
auto b = upper_bound(array, array + n, x);

// sum formulate 1 + 2 + 3 + .... + n
int sum =  (n * (n + 1)) / 2;
// sum formulate 1^2 + 2^2 + 3^2 + ... + n^2
int sum = (n * (n + 1) * (2n + 1)) / 6;

// To search algorithm
binary_search(a.begin(), a.end(), number);

// sort(first_iterator, last_iterator) – To sort the given vector.
// reverse(first_iterator, last_iterator) – To reverse a vector.
// *max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
// *min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
// accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements
// count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
// find(first_iterator, last_iterator, x) – Points to last address of vector ((name_of_vector).end()) if element is not present in             vector.
// lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which         has a value not less than ‘x’.
// upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last)                  which has a value greater than ‘x’. 
// arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
// arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line. 
// next_permutation(first_iterator, last_iterator) – This modified the vector to its next permutation.
// prev_permutation(first_iterator, last_iterator) – This modified the vector to its previous permutation. 