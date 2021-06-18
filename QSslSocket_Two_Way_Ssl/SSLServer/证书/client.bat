@echo on
keytool -genkeypair -keyalg RSA -dname "CN=localhost" -alias client -keystore client.jks -keypass cccccc -storepass cccccc
keytool -exportcert -file client.cer -alias client -keystore client.jks -storepass cccccc
keytool -importcert -file client.cer -alias client -keystore server_trust.jks -storepass cccccc -keypass cccccc