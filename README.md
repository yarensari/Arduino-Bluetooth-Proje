# ARDUINO BLUETOOTH PROJESİ
Projede DHT11 sıcaklık sensörüyle ortamın sıcaklığı ölçülmüştür ve kullanıcının remote bir şekilde kontrol edebileceği bir alarm sistemi oluşturulmuştur. Arduino ve telefon arasındaki haberleşme HC05 bluetooth
modülüyle sağlanmıştır. Kullanıcının şahsi telefondan 'R' ve 'S' tuşlarıyla alarm sistemini kontrol etmesi sağlanmıştır. 'R' tuşuna basması durumunda alarm devre dışı, 'S' tuşuna basması durumunda ise alarm aktif
konumdadır. 
### Alarmın aktif durumda olması: 
DHT11 sıcaklık sensörüyle ölçülen ortam sıcaklık değerleri LCD ve kullanıcının şahsi telefonunda görüntülenebilmektedir. Ortam sıcaklığının 45 derecenin üstüne çıkması durumunda buzzer ve kırmızı led aktif konuma 
geçmektedir. Bu durum ortam sıcaklığının tekrardan 45 derecenin altına düşmesi veya kullanıcının şahsi telefonundan alarmı kapatmasına kadar devam etmektedir. Ortamın sıcaklığının 45 derecenin altına düşmesi durumunda yeşil led aktif olmaktadır.
### Alarmın pasif durumda olması: 
DHT11 sıcaklık sensörüyle ölçülen ortam sıcaklık değerleri LCD ve kullanıcının şahsi telefonunda görüntülenebilmektedir. Alarmın kapalı olması durumunda ledler ve buzzer pasif durumdadır. Ortam sıcaklığının 45 
dereceyi aşması durumunda ledler ve buzzer aktif duruma geçememektedir.

## Proteus Çizimi
![bluetoothProjesi](https://github.com/user-attachments/assets/308e02f9-b3e4-49e2-b8e5-c71f8e67173f)
