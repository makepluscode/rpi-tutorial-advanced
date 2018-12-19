# RASPBERRY PI TUTORIAL ADVANCED
This example is about how to install google assistant and magic mirror on raspbian.

## Dependency Versions
1. OS : 2018-11-13-raspbian-stretch-full.img
2. MagicMirror2 : 2.5.0
3. MMM-Hotword : 	1.1.0
4. MMM-AssistantMk2 : 2.1.2

## Install
### STEP1. Rasbian installation
1. Download the latest image from the RazBian website. (2018-11-13-raspbian)
2. Download Rufus to write images to SD card.
3. Run Rufus and select the downloaded image to burn the SD card.

### STEP2. Insert SD card + LCD connection
1. Insert SD card and keyboardㆍmouse dongle into raspberry pi.
2. Connect LCD to raspberry pi on HDMI.

### STEP3. First Boot
1. Connect the USB power cable to the raspberry pi
2. After boot is done, connect to the Internet with WIFI
3. Update packages
```sh
sudo apt-get update
```
4. Install Remote Desktop Server
```sh
sudo apt-get install xrdp
```
5. Check the IP address with ipconfig

### STEP4. Installing a Magic Mirror
1. Remote access to raspberry pi. (ID: pi, password: raspberry)
2. Install the Magic Mirror using a script on the Internet
```sh
sudo apt-get install npm
sudo npm install -g npm@latest
bash -c "$(curl -sL https://raw.githubusercontent.com/MichMich/MagicMirror/master/installers/raspberry.sh)"
```

### STEP5. Installing Magic Mirror Modules
1. Go to modules directory and install the MMM-Hotword
 ```sh
cd ~/MagicMirror/modules/
sudo apt-get install libmagic-dev libatlas-base-dev sox libsox-fmt-all
git clone https://github.com/eouia/MMM-Hotword.git
cd MMM-Hotword
npm install

cd ~/MagicMirror/modules/MMM-Hotword/node_modules/snowboy
npm install --save-dev electron-prebuilt
npm install --save-dev electron-rebuild
npm install nan
./node_modules/.bin/electron-rebuild
```

2. Install MMM-AssistantMk2
 ```sh
cd ~/MagicMirror/modules/
sudo apt-get install mpg321 libasound2-dev
git clone https://github.com/eouia/MMM-AssistantMk2
cd MMM-AssistantMk2
npm install
cd scripts
chmod +x *.sh
cd ~/MagicMirror/modules/MMM-AssistantMk2
npm install --save-dev electron-prebuilt
npm install --save-dev electron-rebuild
./node_modules/.bin/electron-rebuild
 ```

### STEP6. Configure Google Assistant Module
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
```sh
mv ~/Download/cre.... credentials.json
```
8. Run auth_and_test.js to verify the generated client ID
```sh
node auth_and_test.js
```
9. Accept the client verification process and copy and enter your Google account key
10. Move the generated token.json and proceed with the installation of the module (takes about 10 to 20 minutes)
```sh
mv token.json ./profiles/default.json
```

### STEP7. Edit Google assistant module config
1. Open the Magic Mirror configuration file with TextEditor and modify it with the contents of github

```

```

## Install USB Mic. and Speaker
https://github.com/makepluscode/rpi-tips/tree/master/001-bringup-audio-and-mic

```sh
vi ~/.asoundrc
```

```sh
pcm.!default{
  type asym
  playback.pcm{
    type hw
    card 0
  }
  capture.pcm{
    type plug
    slave.pcm "hw:1, 0"
  }
}

ctl.!default{
  type hw
  card 0
}
```

##  Test
Go to the location where the Magic Mirror is and start the application
```
cd ~/MagicMirror
npm start
```

## Video Tutorial 
 [![Watch the video](https://user-images.githubusercontent.com/39910774/47252575-f0c34980-d481-11e8-9c30-5b2543b722e5.png)](https://youtu.be/gNeGzUo-wbo)
 
