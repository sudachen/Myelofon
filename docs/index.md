
# Overview
>_Originally **Myelofon** is a fictional device for reading thoughts from the stories of the Soviet Sci-Fi writer Kir Bulychev. First mentioned in the story "Rusty Field Marshal" (1968). The word is a transcription from Russian **миелофон** and is probably coming from the Greek as **μυαλοφων** (**μυαλό** "brain or mind" + **φωνή** "voice")_. 

Myelofon is an EEG sensor and a set of required software and firmware. The sensor hardware is cheap and easy to build by any enthusiast. However Myelofon is not a classical EEG device, it is not designed to reading mutichannel EEG. Its responsibility is getting frequency spectrum of the brain activity. Related software/firmware analyzes the brain-waves frequency spectrum to do useful things. It pretends to be used for cognitive experiments, brainfitness, psychotherapy, children development, entertaiment, etc. Theoretically, it can be used for any case requiring simplified brain feedback.

Myelofon hardware and software is open and licensed under GPL. It means anyone can build devices and specialized software based on Myelofon design freely.

# Prototype 1
I intend to develop Myelofon as a series of prototypes. The first one is an analog sensor connecting to uC dev-board (_DK_). The DK like NRF52-DK, STM32F3DISCOVERY, or even Arduino Due performs A/D convertion and processes digitalized EEG signals to extract frequency spectrum. Then this spectrum and its dynamics are analyzed on PC or tablet by related software.

Here are current schematics and PCB render. In the [repo](https://github.com/sudachen/Myelofon/tree/master/proto1) you can find all required files to build one.

<a href="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1_schem.png"><img width="700px" src="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1_schem.png"/></a>
<!--a href="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1.png"><img width="200px" src="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1.png"/></a-->

The device looks like simple EEG headset with connected NRF52-DK board.

<img width="680px" src="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1_dev.jpg"/>


# Prototype 2
On the way.
