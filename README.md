# MegaDeck
> Custom StreamDeck-like clone using Arduino Pro Micro and RobotDyn keypad

Configurable keypad that allows to assign custom macros to specified keys, like:

* Type a text
* Media control (playback, volume)
* Press a sequence of keys (like ALT+SHIFT to change keyboard layout)
* etc

Works on any OS without any drivers.

## Requirements

**Hardware**

* [Arduino Pro Micro](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all)
* [RobotDyn Keypad 4x4](https://aliexpress.ru/item/32635207928.html?spm=a2g0s.9042311.0.0.18fd33ed5mrU54)

**Software**

In order to compile the firmware, you need **Visual Studio Code** with *PlatformIO* extension installed.

## Development

### Assembly

**Pins**

This project heavily relies on interrupt feature, so I recommend to check supported interrupt pin on your board
before project assembly.

Default keypad output pin is 8, which is defined by `KBD_PIN` constant in `main.cpp`.

**Layout**
In this project, I used 8x8 keypad grid.
Keypad button values are defined at [`/include/keypad.h`](/include/keypad.h).

Button values may vary and depend on your board or keypad type.

### Customization

In order to define custom macros, just modify switch statement in [`main.cpp`](src/main.cpp) and build the project.

See [NicoHood's HID library](https://github.com/NicoHood/HID/wiki) docs for more information.

**Example**

```cpp
 switch (keyNumber) {
      case MDKEY_1:
        Keyboard.add(KEY_LEFT_SHIFT);
        Keyboard.add(KEY_LEFT_ALT);
        Keyboard.send();
        Keyboard.releaseAll();
        break;
      case MDKEY_2:
        Keyboard.println("Hello World!");
        break;
      case MDKEY_3:
        Consumer.write(MEDIA_PLAY_PAUSE);
        break;
    }
```

### Debugging & Troubleshooting

This firmware includes a special **Recovery Mode**.

If you faced some issue with your board (USB decriptior issue, board not flashable),
try to start the board in *Recovery mode*.

In this mode, HID (keyboard) and interrupts functionality which may cause any issues - will be disabled, so you can reflash 
any other sketch to revive your board.

#### How to enter Recovery mode

* Disconnect your Arduino from PC
* Connect pin 2 to ground (GRD)
* Connect back a board.

If you did everything right, you will see next message in serial console:

```
============= ! RECOVERY MODE ! =============
Use this mode to reflash the board in case:  

* Board does not respond to commands.        
* Board's USB device descriptor errors.

Good luck :)
```

Now, start Arduino IDE and flash any other sketch to replace the MegaDeck firmware.
