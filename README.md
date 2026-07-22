<img src="https://static.vecteezy.com/system/resources/thumbnails/069/676/900/small/yellow-warning-triangle-sign-with-exclamation-mark-isolated-on-transparent-background-png.png" />

# SAFETY WARNING [Read This First]
## ⚠️ Safety

OpenGVS applies a small amount of current across the mastoid (behind the ears) to stimulate the vestibular system. You are requied to read this before continuing:

**Dont Use OPENGVS or Similar Device if You::**
- Have a pacemaker, cochlear implant, or any other implanted electronic medical device
- Have epilepsy or a history of seizures
- Have any diagnosed neurological or inner-ear condition (e.g. vestibular disorders, Ménière's disease)


**Before first use:**
- Verify the output current with a multimeter — don't rely on the calculated value alone. Check if it stays within the limit before using it on skin.
- Double Check for the connections.. Any faulty connection in any of the circuit can result in flow of more current than safe.
- Test on a dummy load (for eg. a Resistor of 10k OHM)


**General:**
This is a open source Project and is not cerfitied as a medical device.. Use it with caution and at you own risk.
If you are unclear whether to use this or not, consult a doctor first..

ALSO dont use it near stairs, machineries, water or anyplace where falling can cause major injuries..






# What is a GVS ?

Simply speaking, GVS is a device which can ***HACK*** your balance. (i.e. your bodies tendency to shift either left or right to keep itself upright)

It does this by applying a **very little** current through a specific part of your head that contains the organs which sense the orientation of the body (i.e. vestibular system)


# How OPENGVS Works !

To control the balance of body we need to send **very little** current through our mastoids (i.e. the bony part right behind the ears)
This makes the current to interfere with the vestibular system and then *hack* our balance..

****BUT**** we dont want to send a lot of current through our head and fry our brain.
So the current must be limited to a **MAX OF 4mA**.

This is done through using a "current sense feedback loop". [More on this later]

I also wanted the current to be able to flow both from left to right and from right to left.
So i used a H bridge, to do so..

Thw complete thing is powered through a single 18650 cell of 3.7v

To make it wireless i decided to add a ESP32C3-Mini.

When the right firmware is uploaded in the ESP32, it starts a WiFi and theen connected to the Wifi, we meet with a webpage from where we can control wheter we want the current to flow from right to left or from left to right. (in other words i can control wheter the user moves left or right through the web page)

# The Assembly Instructions

### First of all solder the H bridge on a perf Board [or you can use a breadboard or get a PCB-- I will use a perfboard]

<img width="512" height="328" alt="Screenshot 2026-07-01 182518" src="https://github.com/user-attachments/assets/f4f90d56-1325-4eff-ba6b-8c483e149b35" />

This is the Schematic for the H bridge.
The H bridge is pretty simple. 

The pins A, B will be connected to GPIO pins 7 & 8 of Esp32.
Pulling these pins High of Low decides the direction of the current..
The GND is connected to OFCOURSE the GND.

HOLD THE CCV pins for now..


#### Second- Solder the Current Limiting Circuit As per the Schematic.
<img width="409" height="302" alt="Screenshot 2026-07-01 185214" src="https://github.com/user-attachments/assets/964c6a3b-d1e4-4853-b8be-b7e0c4d541a1" />
The circuit of the bottom left of the image..

This circuits works as follow-

The transistor Q7 starts to conduct current to the pin CCV, but when a certain threshold current goes through the 220ohm resistor to Q7, the resistor creates a potential difference across it.
This potential difference is falt directly across the Base and emitter pin of the Q9.
This makes the Q9 to conduct and thus it drian all the curent to gnd..
Hence the current is limited to a certain limit through the resistor.

In this case its 3.2mA MAX.

#### Third- Add the ESP32 and battery and Volage Converters.
<img width="476" height="330" alt="Screenshot 2026-07-03 100449" src="https://github.com/user-attachments/assets/b72c0626-e187-41f5-971e-daf13bdd65e8" />

this is the final connection..

You can alter this last step according to your need.
the multiple mounting holes in the schematic are for only the purpose of converting 3.7v into 3.3v, nd 12v for the esp32 and H bridge to work.


# BOM

# Bill of Materials (BOM)

## 🔌 Boards & Prototyping
| Component | Short Name | Qty | Unit Price (INR) | Subtotal (INR) | Source | Link |
|---|---|---|---|---|---|---|
| VeroBoard (6x4 Inch) | Perfboard 6x4" | 1 | 40.00 | 40.00 | Robocraze | https://robocraze.com/products/veroboard6x4?_pos=2&_sid=71be420dd&_ss=r |
| ESP32-C3 Mini Development Board - Unsoldered | ESP32-C3 Dev Board | 1 | 234.00 | 234.00 | Robocraze | https://robocraze.com/products/esp32-c3-mini-development-board-unsoldered?variant=48465411506400 |

## 🔋 Power & Charging
| Component | Short Name | Qty | Unit Price (INR) | Subtotal (INR) | Source | Link |
|---|---|---|---|---|---|---|
| TP4056 1A Li-ion Charging Module (Type-C, w/ protection) | TP4056 Li-ion Charger | 1 | 16.00 | 16.00 | Makerbazar | https://makerbazar.in/products/tp4056-1a-li-ion-lithium-battery-charging-module?variant=45459125567728 |
| 18650 SMD/SMT Battery Holder Case (Single) | 18650 Battery Holder | 1 | 39.00 | 39.00 | Makerbazar | https://makerbazar.in/products/18650-battery-holder-single-battery.js?variant=44006735 |
| Samsung SDI INR18650 Li-Ion Rechargeable Cell, 3000mAh | 18650 Li-ion Cell (3000mAh) | 1 | 249.00 | 249.00 | Makerbazar | https://makerbazar.in/products/samsung-sdi-inr18650-li-ion-rechargeable-cells?variant=48251034140912 |

## ⚡ DC-DC Converters
| Component | Short Name | Qty | Unit Price (INR) | Subtotal (INR) | Source | Link |
|---|---|---|---|---|---|---|
| DC-DC 1.8V-5V to 3.3V Booster/Buck Module | 3.3V DC-DC Converter | 1 | 52.00 | 52.00 | Robu.in | https://robu.in/product/dc-dc-1-8v-5v-to-3-3v-boost-and-buck-power-module/ |
| 3.7V to 12V Mini DC-DC Boost Step-Up Converter (5V/8V/9V/12V out) | 3.7V-12V DC-DC Boost Converter | 1 | 18.00 | 18.00 | Robu.in | https://robu.in/product/3-7v-to-12v-mini-dc-dc-boost-step-up-converter-board-module-5v-8v-9v-12v-output/ |

## 🔺 Transistors & MOSFETs
| Component | Short Name | Qty | Unit Price (INR) | Subtotal (INR) | Source | Link |
|---|---|---|---|---|---|---|
| IRLZ44N MOSFET, DIP-3 | IRLZ44N MOSFET (N-Ch) | 2 | 39.00 | 78.00 | Robu.in | https://robu.in/product/irlz44n/ |
| SPP18P06PHXKSA1 Infineon Power MOSFET, P-Ch, 60V, 18.7A, TO-220 | SPP18P06 MOSFET (P-Ch) | 2 | 180.00 | 360.00 | Robu.in | https://robu.in/product/spp18p06phxksa1-infineon-power-mosfet-p-channel/ |
| 2N3904 NPN Transistor, TO-92, onsemi | 2N3904 NPN Transistor | 2 | 18.00 | 36.00 | Robu.in | https://robu.in/product/2n3904ta-onsemi-40v-625mw-400-1ma1-0v-200ma-npn-to-92-3l-bipolar-bjt-rohs/ |
| 2N3906 PNP Transistor, TO-92, JCET | 2N3906 PNP Transistor | 2 | 5.00 | 10.00 | Robu.in | https://robu.in/product/2n3906-ta-jcet-40v-625mw-10010ma1v-200ma-pnp-to-92-bipolar-bjt-rohs/ |

## 🧩 Passive Components (Local)
| Component | Short Name | Qty | Unit Price (INR) | Subtotal (INR) | Source | Link |
|---|---|---|---|---|---|---|
| Electrode | Electrode | 2 | 15.00 | 30.00 | Local Market | N/A - local purchase |
| Resistor 220 Ohm | 220R Resistor | 1 | 10.00 | 10.00 | Local Market | N/A - local purchase |
| Resistor 10K Ohm | 10K Resistor | 5 | 10.00 | 50.00 | Local Market | N/A - local purchase |

---
**Grand Total:** ₹1,222.00
So thats all...............



