# hashtable-in-c



# QUESTION



Write a program to implement a Hash Table data structure to store the product details with product id as key. Your program should contain the following functions.

• HashTable(m): Creates a hash table T of size m.
• Insert(T,k): Inserts an element into hash table T having key value k.
• Search(T,k): Checks whether an element with key ‘k’ is present in hash table T s or not.
• Delete(T,k): Deletes the element with key ‘k’ from hash table.
  Note: Assume that the deletion operation will always be a valid operation. i.e. the element to be deleted is present in the hash table.


Input Format:
• The first line contains a character from { ‘a’, ‘b’}:
  – Character ‘a’ denotes collision resolution by Quadratic Probing with hash function h(k, i) = (h1(k) + c1 i + c2 i^2) mod m
   where h1(k) = k mod m, c1 and c2 are positive auxiliary constants and i ∈ [0, m − 1].
– Character ‘b’ denotes collision resolution by Double Hashing with hash function
h(k, i) = (h1(k) + i ∗ h2(k)) mod m
where h1(k) = k mod m, h2(k) = R − (k mod R) { R = Prime number just smaller than
the size of table } and i ∈ [0, m − 1].
• Second line contains an integer m ∈ [1, 100], denotes the size of the hash table.
• In case of quadratic probing only (option a), next line contains two integers c1 and c2 separated
by space.
• Subsequent lines may contain a character from { ‘i’, ‘s’, ‘d’, ‘p’, ‘t’ } followed by zero or one
integer.
– i x: insert the element with key x into hash table
– s x: search the element with key x in hash table. If the key is present in hash table, then
print 1. Otherwise, print -1.
– d x: delete the element with key x from hash table.
– p: print the hash table in “index (key values)” pattern. If no key values are present in an
index, then print “()” after “index” (Refer sample output for explanation).
– t: terminate the program
Note: Total number of elements n to be inserted into hash table will be lesser than or equal
to size of hash table m i.e., n ≤ m.
Output Format:
• The output (if any) of each command should be printed on a separate line.


Sample Input 1:
a
7
0 1
i 76
i 40
i 48
i 5
s 5
i 55
p
s 62
d 55
t
Sample Output 1:
1
0 (48)
1 ()
2 (5)
3 (55)
4 ()
5 (40)
6 (76)
-1
Sample Input 2:
b
7
i 76
i 93
i 40
i 47
i 10
i 55
p
d 40
s 47
s 76
s 40
t
Sample Output 2:
0 ()
1 (47)
2 (93)
3 (10)
4 (55)
5 (40)
6 (76)
1
1
-1
