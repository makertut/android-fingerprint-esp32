# android-fingerprint-esp32
how to use Fingerprint scanner Android Mobile phone for a door unlock using ESP32 or ESP8266 Wifi or Arduino wifi module.For making this project you need ESP32, Relay module,Solenoid door lock and Android mobile phone

Create Android App <br>
New Projects -> Empty Activity <br>
![maker Tutor](https://1.bp.blogspot.com/-gsUyGJEfXOg/XnCTcwE7QQI/AAAAAAABcdg/efhNZ9ldd2I_qlscIkhKkHQUSt7gv3L6QCNcBGAsYHQ/s400/Screen%2BShot%2B2563-03-17%2Bat%2B16.01.16.png)

Configure Your Project <br>
Minimum SDK : API 28: Android 9.0 ( Pie) <br>

![maker Tutor](https://1.bp.blogspot.com/-UBwCj2UCNlY/XnCTc3oLy6I/AAAAAAABcdk/PYZ5CmJRcHo2dldu8DYqRt8vKVY-JvJcQCNcBGAsYHQ/s400/Screen%2BShot%2B2563-03-17%2Bat%2B16.01.41.png)

Edit AndroidManifest<br>
<uses-permission android:name="android.permission.USE_BIOMETRIC"/>
<uses-permission android:name="android.permission.INTERNET"/>

Edit App : build.gradle <br>

 implementation 'androidx.biometric:biometric:1.0.0-alpha03'
 
 

 
