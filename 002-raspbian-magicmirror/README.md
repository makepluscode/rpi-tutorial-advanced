# RASPBERRY PI TUTORIAL ADVANCED
This example is about how to install magic mirror on raspbian.

![title](https://user-images.githubusercontent.com/39910774/48461226-0b38da80-e816-11e8-93f2-e4e35e8268d7.png)

## Install
### STEP1. Rasbian installation
1. Download the latest image from the RazBian website
2. Download Rufus to write images to SD card
3. Run Rufus and select the downloaded image to burn the SD card

### STEP2. Insert SD card + LCD connection
1. Insert SD card and keyboardㆍmouse dongle into raspberry pi.
2. Connect LCD and connector to raspberry pi

### STEP3. First Boot
1. Connect the USB power cable to the raspberry pi
2. After boot is done, connect to the Internet with WIFI
3. Update packages
```
sudo apt-get update
```
4. Install Remote Desktop Server
```
sudo apt-get install xrdp
```
5. Check the IP address with ipconfig

### STEP4. LCD HDMI setting
1. Remote access to raspberry pi. (ID: pi, password raspberry)
2. Install vim for easy editing
3. Open Raspberry pi settings file
```
$  vim /boot/config.txt
```
4. Edit hdmi settings for 800x480, 5 inch LCD
 ```
hdmi_group=2
hdmi_mode=1
hdmi_mode=87
hdmi_cvt= 800 480 60 6 0 0 0
```
5. Save your settings and reboot
6. Make sure the raspberry pi is in full view.

### STEP5. Installing a Magic Mirror
1. Remote access to raspberry pi. (ID: pi, password raspberry)
2. Install the Magic Mirror using a script on the Internet
```
bash -c "$(curl -sL https://raw.githubusercontent.com/MichMich/MagicMirror/master/installers/raspberry.sh)"
```

##  Test
Go to the location where the Magic Mirror is and start the application
```
cd ~/MagicMirror
npm start
```

## Video Tutorial 
 [![Watch the video](https://user-images.githubusercontent.com/39910774/47252575-f0c34980-d481-11e8-9c30-5b2543b722e5.png)](https://youtu.be/Vx4s-l8IGY8)
