Tek Yönlü Bağlı Liste Uygulaması
İstediğiniz herhangi bir programlama dilinde aşağıda belirtilen işlemleri gerçekleştirecek kodu
yazınız.
1- Ekleme İşlemi: Programınız çalıştığında ilk olarak her bir satırda bir kaydın bulunduğu text dosyadaki
verileri tek yönlü bağlı liste yapısına ekleyecektir. Ekleme işlemi numara bilgisinin son hanesi temel
alınarak yapılacaktır. Listedeki elemanlar numara bilgisinin son hanesi en fazla olan değere göre
azalacak şekilde dinamik bir şekilde listeye eklenmelidir. Ayrıca text dosya haricinde kullanıcı da
menü aracılığıyla kayıt ekleyebilmelidir.
Örneğin text dosya içeriği aşağıdaki gibi olsun
58 Ali Demir
16 Fatma Verimli
26 Ayşe Korkmaz
38 Naci Mutlu
471 Osman Çetin
1. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (8 ile biten 1 adet eleman vardır).
2. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (8 ile biten 1 adet, 6 ile biten 1 adet eleman
vardır).
3. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (6 ile biten 2 eleman, 8 ile biten 1 eleman
vardır).
4. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (6 ile biten 2 eleman, 8 ile biten 2 eleman
vardır)
5. satır okunduğunda bağlı liste aşağıdaki gibi oluşacaktır (6 ile biten 2 eleman, 8 ile biten 2 eleman, 1 ile
biten 1 eleman vardır)
2- Arama İşlemi: Kullanıcının girdiği numara bilgisine göre bağlı listede eleman aranacaktır ve kaç
adımda bulunduğu listelenecektir. Listeden olmayan bir eleman arandığında başarısız arama bilgisi
verilecektir.
Örneğin Ekleme işleminde verilen örneğin son hali için 58 arandığında 3 adımda ulaşıldığı bilgisi
verilecektir.
3- Listeleme İşlemi: Bağlı listedeki elemanlar baştan sona listelenecektir.
4- Silme İşlemi: Kullanıcının girdiği numara bilgisine göre bağlı listeden eleman silinecektir. Silme
sonucunda silinen numara değerinin son hanesi adetine göre liste gerekiyorsa yeniden düzenlenmelidir.
Örneğin Ekleme işleminde verilen örneğin son hali için 471 elemanı silinirse liste sıralaması
değişmeyecektir. Fakat 26 elemanı silinmek istenirse listede en fazla son hanesi 8 ile biten elemanlar
olacağı için listenin son hali şu şekilde olacaktır:
5- Çıkış İşlemi: Bağlı listenin en son haline göre listedeki elemanlar text dosyaya sırayla yazılacaktır.