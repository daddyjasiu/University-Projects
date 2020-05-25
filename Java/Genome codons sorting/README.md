# Sorting codons of a genome between START/ STOP codones.

Program does a couple of things. List of steps below:

1) Search for letters other than `"A"`, `"C"`, `"T"`, `"G"`. If there are any, output _`Wrong character in DNA sequence.`_

2) If the syntax of the genome is **correct**, find START codone (`"ATG"`) and STOP codone (`"TAA", "TGA" or "TAG"`). If there is any other
 START/STOP codone between them, output _`More than one START/STOP codon.`_
 
3) If there is **no** `START/STOP` sequence, output _`Wrong DNA sequence.`_

4) If there is **other amount** of amino acids in `START/STOP` sequence than a **multiple of three** (3, 6, 9...), output _`Wrong DNA sequence.`_

5) If the sequence **and** amount of amino acids is correct - **sort** the codons in the sequence (sorting by `first letters`, then `second`, then `third`).

6) Output **sorted** series of codones (and **only** them, not the rest of the sequence).

Sorting is performed by using **iterative QuickSort with a stack**.

Example input/output below.


### INPUT:
```
ATGAACAAATGA
ATGAAAATGAACTGA
AACTTTAAATGA
ATGWWWTGA
```
### OUTPUT:
```
AAAAAC
More than one START/STOP codon.
Wrong DNA sequence.
Wrong character in DNA sequence.
```
