
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
__2- Searching:__ Kullanıcının girdiği numara bilgisine göre bağlı listede eleman aranacaktır ve kaç
adımda bulunduğu listelenecektir. Listede olmayan bir eleman arandığında başarısız arama bilgisi
verilecektir.  
Örneğin Ekleme işleminde verilen örneğin son hali için 58 arandığında 3 adımda ulaşıldığı bilgisi
verilecektir.  

__3- Listing:__ Bağlı listedeki elemanlar baştan sona listelenecektir.  

__4- Deletion:__ Kullanıcının girdiği numara bilgisine göre bağlı listeden eleman silinecektir. Silme
sonucunda silinen numara değerinin son hanesi adetine göre liste gerekiyorsa yeniden düzenlenmelidir.
Örneğin Ekleme işleminde verilen örneğin son hali için 471 elemanı silinirse liste sıralaması
değişmeyecektir. Fakat 26 elemanı silinmek istenirse listede en fazla son hanesi 8 ile biten elemanlar
olacağı için listenin son hali şu şekilde olacaktır:  
    [ 58 ][ Ali ][ Demir ] ➜ [ 38 ][ Naci ][ Mutlu ] ➜ [ 16 ][ Fatma ][ Verimli ] ➜ [ 471 ][ Osman ][ Cetin ] ➜ Null  

__5- Exit:__ Bağlı listenin en son haline göre listedeki elemanlar text dosyaya sırayla yazılacaktır.
