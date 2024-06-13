# esp32-W5500Mini
ESP32 with interface ethernet using module W5500 Mini protocol HIGH SPI

The W5500 chip is a Hardwired TCP/IP embedded Ethernet controller that provides an easier Internet connection to embedded systems. W5500 enables users to have Internet connectivity in their applications just by using the single chip in which TCP/IP stack, 10/100 Ethernet MAC, and PHY are embedded.

WIZnet‘s Hardwired TCP/IP is the market-proven technology supporting TCP, UDP, IPv4, ICMP, ARP, IGMP, and PPPoE protocols. W5500 embeds the 32Kbyte internal memory buffer for the Ethernet packet processing. If you use W5500, you can implement the Ethernet application by adding the simple socket program. It’s a faster and easier way rather than using any other Embedded Ethernet solution. Users can use eight independent hardware sockets simultaneously.

SPI (Serial Peripheral Interface) is provided for easy integration with the external MCU. The W5500’s SPI supports 80 MHz speed. To reduce the system’s power consumption, W5500 provides WOL (Wake on LAN) and power-down mode.

## Features
Supports Hardwired TCP/IP Protocols : TCP, UDP, ICMP, IPv4, ARP, IGMP, PPPoE
Supports 8 independent sockets simultaneously
Supports Power down mode
Supports Wake on LAN over UDP
Supports High Speed Serial Peripheral Interface(SPI MODE 0, 3)
Internal 32Kbytes Memory for TX/RX Buffers
10BaseT/100BaseTX Ethernet PHY embedded
Supports Auto Negotiation (Full and half duplex, 10 and 100-based )
Not supports IP Fragmentation
3.3V operation with 5V I/O signal tolerance
LED outputs (Full/Half duplex, Link, Speed, Active)
48 Pin LQFP Lead-Free Package (7x7mm, 0.5mm pitch)

## Component
- ESP32 Series
- Module Ethernet W5500 Mini
- Cable UTP Cat 5

# Schematic
![esp32_ethernet](https://github.com/eunbiline98/esp32-W5500Mini/assets/50385294/6af9918a-fde7-450f-b49f-fbfebf961290)

# Note Programming tool using platform.io

