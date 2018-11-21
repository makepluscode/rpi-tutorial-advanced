# RASPBERRY PI TUTORIAL ADVANCED
This example is about how to install google assistant and magic mirror on raspbian.

![title](https://user-images.githubusercontent.com/39910774/48819176-e1416400-ed91-11e8-9771-7b9ce78aaf4b.png)

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

### STEP6. Installing Magic Mirror Module
1. Go to modules directory and download the MMM-Hotword module source
 ```
git clone https://github.com/eouia/MMM-Hotword.git
 ```
2. Download the MMM-NotificationTrigger module source
 ```
git clone https://github.com/eouia/MMM-NotificationTrigger
```
3. Download the MMM-AssistantMk2 module source
 ```
git clone https://github.com/eouia/MMM-AssistantMk2
 ```
4. Go to MMM-Hotword and install the module
 ```
npm i
 ```
5. Go to the snowboy directory and install the module
 ```
sudo apt-get --yes install libmagic-dev libatlas-base-dev sox libsox-fmt-all libasound2-dev

npm i --save-dev electron-rebuild
npm install nan
./node_modules/.bin/electron-rebuild
 ```
 
### STEP7. Install Google Assistant Module
1. Open the Google Action Console and create a new project
```
https://console.actions.google.com
```
2. Open the Google Cloud Platform Console and select the generated project
```
https://console.cloud.google.com
```
3. Search for the Google Assistant API and click Enable.
4. Click CONFIGURE ... of Credentials and put the name and e-mail.
5. Generate Other credentials with the OAuth Client ID in Create Credentials
6. Download generated OAuth client ID in json format
7. Move the downloaded OAuth client ID to modules/MMM-AssistantMk2/credentials.json
```
mv ~/Download/cre.... credentials.json
```
8. Run auth_and_test.js to verify the generated client ID
9. Accept the client verification process and copy and enter your Google account key
10. Move the generated token.json and proceed with the installation of the module (takes about 10 to 20 minutes)
```
mv token.json ./profiles/default.json
./node_modules/.bin/electron-rebuild
```

### STEP8. Edit Google assistant module config
1. Open the Magic Mirror configuration file with TextEditor and modify it with the contents of github

```
https://github.com/makepluscode/rpi-tutorial-advanced/blob/master/003-raspbian-magicmirror-google-assistant/config.js.sample.kr
https://github.com/makepluscode/rpi-tutorial-advanced/blob/master/003-raspbian-magicmirror-google-assistant/config.js.sample.en
```

## Install USB Mic. and Speaker
https://github.com/makepluscode/rpi-tips/tree/master/001-bringup-audio-and-mic

##  Test
Go to the location where the Magic Mirror is and start the application
```
cd ~/MagicMirror
npm start
```

## Video Tutorial 
 [![Watch the video](https://user-images.githubusercontent.com/39910774/47252575-f0c34980-d481-11e8-9c30-5b2543b722e5.png)](https://youtu.be/gNeGzUo-wbo)
 
