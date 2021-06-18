@echo on
keytool -genkeypair -keyalg RSA -dname "CN=localhost" -alias server -keystore server.jks -keypass cccccc -storepass cccccc
keytool -exportcert -file server.cer -alias server  -keystore server.jks -storepass cccccc
keytool -importcert -file server.cer -alias server -keystore client_trust.jks -storepass cccccc -keypass cccccc