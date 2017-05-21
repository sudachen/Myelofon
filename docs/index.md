
# Overview
>_Originally **Myelofon** is a fictional device for reading thoughts in the stories of the Soviet Sci-Fi writer Kir Bulychev. First mentioned in the story "Rusty Field Marshal" (1968). The word is a transcription from Russian **миелофон** and probably coming from the Greek as **μυαλοφων** (**μυαλό** "brain or mind" + **φωνή** "voice")_. 

Myelofon is a EEG sensor and set of required software and firmware. The hardware should be cheap and easy to build even in home by any enthusiast. However Myelofon is not a classical EEG device, it is not designed to reading mutichennal EEG. Its responsibility is getting frequency spectrum of the brain activity. Related software/firmware analyzes the brain-waves fraquency spectrum to do useful things. It's pretend to be used for cognitive experiments, brainfitness, psychoterapy, children development, entertaiment, etc. Teoretically for any case requires simplified brain feedback.

Myelofon hardware and software is open and licensed under GPL. It means anyone can build devices and specialized software based on Myelofon design freely.

# Prototype 1
I intend to develop Myelofon as a seria of prototypes. The first one is an analog sensor connecting to uC dev-board (_DK_). The DK like NRF52-DK, STM32F3DISCOVERY or even Arduino Due should do A/D convertaion and process digitalized EEG signals to extract frequency spectrum. Then this spectrum and its dynamics are analyzed on PC or tablet by related software.

Current Schematics and Render. In the [repo](https://github.com/sudachen/Myelofon/proto1) you can find all required files to build one.
<a href="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1.png"><img width="300px" src="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1.png"/></a>
<a href="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1_schem.png"><img width="300px" src="https://github.com/sudachen/Myelofon/raw/master/proto1/pcb/myelofon_p1_schem.png"/></a>
