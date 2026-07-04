<img src="https://static.vecteezy.com/system/resources/thumbnails/069/676/900/small/yellow-warning-triangle-sign-with-exclamation-mark-isolated-on-transparent-background-png.png" />

# SAFETY WARNING [Read This First]
## ⚠️ Safety

OpenGVS applies a small electrical current across the mastoid processes (behind the ears) to stimulate the vestibular system. Please read this before building or using it.

**Do not use this device if you:**
- Have a pacemaker, cochlear implant, or any other implanted electronic medical device
- Have epilepsy or a history of seizures
- Have any diagnosed neurological or inner-ear condition (e.g. vestibular disorders, Ménière's disease)
- Have skin damage, cuts, or irritation at the electrode contact points

**Before first use:**
- Verify the actual output current with a multimeter — don't rely on the calculated value alone. Confirm it stays within the intended limit under real load before it ever touches skin.
- Double-check polarity and connections. A miswired H-bridge or a failed current-limiting stage could send more current than intended.
- Test on a dummy load (e.g. a resistor matching skin resistance) before testing on a person.

- Start at the lowest possible setting and increase gradually. Stop immediately if you feel pain, a burning sensation, nausea, headache, or anything beyond mild tingling/pulling.

**General:**
This is an experimental DIY project, not a medical device. It hasn't been tested or certified for safety by any regulatory body. Build and use it entirely at your own risk. If you have any doubts about your health or the device's safety, consult a doctor before use, and don't use it on other people without their informed consent.

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

So thats all...............



