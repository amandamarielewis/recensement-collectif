# Atelier Recensement Collectif
Github pour l'atelier de détection collective du festival DIWO à Stereolux à Nantes le 8 septembre 2021.

[Lien vers la présentation technique.](https://docs.google.com/presentation/d/1s3T18qGx1d3UmDFFPPqAXClwZHRb0sIQyXGvgYmdmSk/edit?usp=sharing)

1. [Test pour capteur](https://create.arduino.cc/projecthub/mircemk/arduino-air-quality-monitor-with-dsm501a-sensor-b4f8fc)
2. [Test pour Capteur poussiere DSM501](https://learn.linksprite.com/arduino/shields/use-dust-sensor-dsm501-with-arduino/)


**Matériel**

* Arduino et cordon
* Écran OLED
* Capteur PM2.5
* Planche à pain
* Carte SD + module de lecture de carte SD Arduino
* Fils mâles
* Ordinateur portable
* Convertisseur USB-A vers USB-C (si nécessaire pour les Macbooks plus récents)
* Lecteur de carte SD (si votre ordinateur n'en possède pas)

**Logiciel**

* Arduino IDE [(Téléchargez-le ici)](https://www.arduino.cc/en/software)
* [Driver pour les ordinateurs Windows avec cet Arduino, au cas où il ne serait pas reconnu.](https://sparks.gogo.co.nz/ch340.html)

Librairies Arduino

* Sharp Dust library [(Documentation ici)](https://github.com/luciansabo/GP2YDustSensor)
* MySensors Arduino Library
* U8G2
* U8Glib

## Obtenir des données : Configuration du capteur de poussière

![Image of Dust sensor setup](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/img_dust_only.jpg)

## Visualisation de votre écran : Connexion de l'écran OLED

![Image of Dust sensor and OLED setup](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/ASSL_workshop_dustoled_bb.jpg)

* Le brochage de l'écran OLED est différent de celui du schéma. Les broches 5V et GND sont commutées, assurez-vous donc que la broche VCC est connectée à l'alimentation (+) et que la broche GND est connectée à la terre (-).

```
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_FAST);	// Dev 0, Fast I2C / TWI
```

## La portabilité : sauvegarder vos données sur des cartes SD

![Image of Dust sensor, OLED, SD card setup](https://github.com/amandamarielewis/scarred-landscapes-workshop/blob/main/images/ASSL_workshop_complete_bb.png)

## Questions

Les problèmes courants ou les corrections de bogues seront notés ici.
