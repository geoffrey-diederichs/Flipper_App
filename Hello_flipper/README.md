# Hello Flipper

Application printing `Hello Flipper`.

## How to use

Example of how to compile the code :

```sh
$ git clone https://github.com/flipperdevices/flipperzero-firmware.git

$ cd flipperzero-firmware

$ cp ~/Documents/Flipper_App/Hello_flipper/ -dR applications_user/

$ ./fbt fap_hello_flipper

$ ./fbt launch APPSRC=Hello_flipper
```

The executable is stored at this path : `flipperzero-firmware/build/f7-firmware-D/.extapps/hello_flipper.fap`.
