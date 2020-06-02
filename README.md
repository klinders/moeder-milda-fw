# Moeder Milda Firmware.
This firmware is written for the "Moeder milda" main module. Moeder Milda is part of the Milda Marine product line. 

## Used platforms
The project is build upon Mbed-OS and uses PlatformIO for compilation and debugging. VS Code is recommended in combination with the PIO plugin.
To flash the firmware using USB (DFU) install dfu-util

```bash
sudo apt update
sudo apt install dfu-util
```

For flashing and debugging with the ST-Link tool install st-util. For installation instructions please refer to the [ST-Link Repository](https://github.com/stlink-org/stlink).

## License
[MIT](https://choosealicense.com/licenses/mit/)