
# <div align="center"><p>Singly Linked List</p> </div>

## Summary
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
This study performs operations such as adding, deleting, listing with a single linked list. It also uses the operations of data read from and data write to file.

## Details
The details of this study are as follows:\
\
__1- Adding:__ When our program runs, it first adds the data in the text file with a record in each line to singly linked list. Addition will be made based on the last digit of the number information. Elements of the list should be dynamic added to the list in such a way that the last digit of the number information decreases from the most number to the least number. Also without text file, user can add record via the menu. For example, the text file content is as follows:  
58 Ali Demir\
16 Fatma Verimli\
26 Ayşe Korkmaz\
38 Naci Mutlu\
471 Osman Çetin


1. When the 1st line is read, the linked list will be as follows (There is 1 element that ending with 8):
  
    **[ 58 ][ Ali ][ Demir ]** ➜ Null  
2. When the 2nd line is read, the linked list will be as follows (There is 1 element ending with 8 and 1 element ending with 6):  
  
    [ 58 ][ Ali ][ Demir ] ➜ **[ 16 ][ Fatma ][ Verimli ]** ➜ Null  
3. When the 3rd line is read, the linked list will be as follows (There are 2 elements ending with 6 and 1 element ending with 8):  
  
    [ 16 ][ Fatma ][ Verimli ] ➜ **[ 26 ][ Ayse ][ Korkmaz ]** ➜ [ 58 ][ Ali ][ Demir ] ➜ Null  
4. When the 4th line is read, the linked list will be as follows (There are 2 elements ending with 6 and 2 elements ending with 8): 
  
    [ 16 ][ Fatma ][ Verimli ] ➜ [ 26 ][ Ayse ][ Korkmaz ] ➜ [ 58 ][ Ali ][ Demir ] ➜ **[ 38 ][ Naci ][ Mutlu ]** ➜ Null  
5. When the 5th line is read, the linked list will be as follows (There are 2 elements ending with 6, 2 elements ending with 8 and 1 element ending with 1):  
  
    [ 16 ][ Fatma ][ Verimli ] ➜ [ 26 ][ Ayse ][ Korkmaz ] ➜ [ 58 ][ Ali ][ Demir ] ➜ [ 38 ][ Naci ][ Mutlu ] ➜ **[ 471 ][ Osman ][ Cetin ]** ➜ Null  
  
  \
__2- Searching:__ According to the number information entered by the user, the element will be searched in the linked list and the number of steps will be listed. Failed search information will be given when an element not in the list is searched.  
For example, when 58 is searched in the Add process, it will be informed that it has been reached in 3 steps.  
  
__3- Listing:__ Elements in the linked list will be listed from beginning to end.  
  
__4- Deletion:__ The element will be deleted from the linked list according to the number information entered by the user. If necessary, the list should be rearranged according to the number of last digits of the deleted number value as a result of deletion. For example, if the 471 element is deleted for the final version of the sample given in the Add operation, the list order will not change. However, if 26 is desired to be deleted, the final state of the list will be as follows, as there will be elements whose last digit ends with 8 at most:  
  \
    [ 58 ][ Ali ][ Demir ] ➜ [ 38 ][ Naci ][ Mutlu ] ➜ [ 16 ][ Fatma ][ Verimli ] ➜ [ 471 ][ Osman ][ Cetin ] ➜ Null  
  \
__5- Exit:__ According to the latest version of the linked list, the elements in the list will be written to the text file in order.
