
# <div align="center"><p>Singly Linked List</p> </div>

## Summary
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
This study performs operations such as adding, deleting, listing with a single linked list. It also uses the operations of data read from and data write to file.

## Details
The details of this study are as follows:\
\
__1- Adding:__ When our program runs, it first adds the data in the text file with a record in each line to singly linked list. Addition will be made based on the last digit of the number information. Elements of the list should be dynamic added to the list in such a way that the last digit of the number information decreases from the most value to the least value.

Listedeki elemanlar numara bilgisinin son hanesi en fazla olan değere göre azalacak şekilde dinamik bir şekilde listeye eklenmelidir. 
azalacak şekilde dinamik bir şekilde listeye eklenmelidir. Ayrı ca text dosya haricinde kullanıcı da
menü aracılığıyla kayıt ekleyebilmelidir.
Örneğin text dosya içeriği aşağıdaki gibi olsun:\
58 Ali Demir\
16 Fatma Verimli\
26 Ayşe Korkmaz\
38 Naci Mutlu\
471 Osman Çetin


1. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (8 ile biten 1 adet eleman vardır).  
  
    **[ 58 ][ Ali ][ Demir ]** ➜ Null  
2. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (8 ile biten 1 adet, 6 ile biten 1 adet eleman vardır).  
  
    [ 58 ][ Ali ][ Demir ] ➜ **[ 16 ][ Fatma ][ Verimli ]** ➜ Null  
3. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (6 ile biten 2 eleman, 8 ile biten 1 eleman vardır).  
  
    [ 16 ][ Fatma ][ Verimli ] ➜ **[ 26 ][ Ayse ][ Korkmaz ]** ➜ [ 58 ][ Ali ][ Demir ] ➜ Null  
4. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (6 ile biten 2 eleman, 8 ile biten 2 eleman vardır).  
  
    [ 16 ][ Fatma ][ Verimli ] ➜ [ 26 ][ Ayse ][ Korkmaz ] ➜ [ 58 ][ Ali ][ Demir ] ➜ **[ 38 ][ Naci ][ Mutlu ]** ➜ Null  
5. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (6 ile biten 2 eleman, 8 ile biten 2 eleman, 1 ile biten 1 eleman vardır).  
  
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
