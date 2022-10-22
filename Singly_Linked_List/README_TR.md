
# <div align="center"><p>Tek Yönlü Bağlı Liste Uygulaması</p> </div>

## Özet
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Bu uygulama tek yönlü bağlı liste kullanarak ekleme, silme, listeleme gibi işlemleri yapar. Ayrıca dosyadan veri okuma ve dosyaya veri yazma işlemlerini de kullanır.

## Detaylar
Bu uygulamada yapılacak olan şeyler detaylı olarak şu şekildedir:\
\
__1- Ekleme İşlemi:__ Programımız çalıştığında ilk olarak her bir satırda bir kaydın bulunduğu text dosyadaki
verileri tek yönlü bağlı liste yapısına ekleyecektir. Ekleme işlemi numara bilgisinin son hanesi temel
alınarak yapılacaktır. Listedeki elemanlar numara bilgisinin son hanesi en fazla olan değere göre
azalacak şekilde dinamik bir şekilde listeye eklenmelidir. Ayrıca text dosya haricinde kullanıcı da
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
__2- Arama İşlemi:__ Kullanıcının girdiği numara bilgisine göre bağlı listede eleman aranacaktır ve kaç
adımda bulunduğu listelenecektir. Listede olmayan bir eleman arandığında başarısız arama bilgisi
verilecektir.  
Örneğin Ekleme işleminde verilen örneğin son hali için 58 arandığında 3 adımda ulaşıldığı bilgisi
verilecektir.  

__3- Listeleme İşlemi:__ Bağlı listedeki elemanlar baştan sona listelenecektir.  

__4- Silme İşlemi:__ Kullanıcının girdiği numara bilgisine göre bağlı listeden eleman silinecektir. Silme
sonucunda silinen numara değerinin son hanesi adetine göre liste gerekiyorsa yeniden düzenlenmelidir.
Örneğin Ekleme işleminde verilen örneğin son hali için 471 elemanı silinirse liste sıralaması
değişmeyecektir. Fakat 26 elemanı silinmek istenirse listede en fazla son hanesi 8 ile biten elemanlar
olacağı için listenin son hali şu şekilde olacaktır:  
    [ 58 ][ Ali ][ Demir ] ➜ [ 38 ][ Naci ][ Mutlu ] ➜ [ 16 ][ Fatma ][ Verimli ] ➜ [ 471 ][ Osman ][ Cetin ] ➜ Null  

__5- Çıkış İşlemi:__ Bağlı listenin en son haline göre listedeki elemanlar text dosyaya sırayla yazılacaktır.
