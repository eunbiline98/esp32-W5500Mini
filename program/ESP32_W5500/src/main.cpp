#include <Arduino.h>
#include <EthernetSPI2.h>
#include <EthernetUdp.h>

//=========Pinout I/O===========
#define led_eth 2

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {0x02, 0xAB, 0xCD, 0xEF, 0x00, 0x01};
IPAddress ip(xxx, xxx, xxx, xxx);
IPAddress dns(xxx, xxx, xxx, xxx);
IPAddress gateway(xxx, xxx, xxx, xxx);
IPAddress subnet(xxx, xxx, xxx, xxx);

boolean runEvery(unsigned long interval)
{
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    return true;
  }
  return false;
}

void setup_eth()
{
  Ethernet.init(15);
  Ethernet.begin(mac, ip, dns, gateway, subnet); // For setup IP Static
  // Ethernet.begin(mac); // for setup IP DHCP

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware)
  {
    Serial.println("Ethernet shield was not found. Sorry, can't run without hardware. :(");
    while (true)
    {
      Serial.print(".");
      digitalWrite(led_eth, HIGH);
      delay(100);
      digitalWrite(led_eth, LOW);
      delay(100);
    }
  }
  while (Ethernet.linkStatus() == LinkOFF)
  {
    Serial.println("Ethernet cable is NOT connected.");
    digitalWrite(led_eth, HIGH);
    delay(250);
    digitalWrite(led_eth, LOW);
    delay(250);
  }

  Serial.println("Ethernet cable is now connected.");
  digitalWrite(led_eth, HIGH);
  delay(500);
  // print ip address
  Serial.print("Local IP : ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet Mask : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Gateway IP : ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS Server : ");
  Serial.println(Ethernet.dnsServerIP());
}

void setup()
{
  Serial.begin(115200);
  pinMode(led_eth, OUTPUT);
  delay(1000);
  setup_eth();
}

void loop()
{
  if (runEvery(5000)) // check interval 5 second
  {
    if (Ethernet.linkStatus() == LinkOFF)
    {
      Serial.println("");
      Serial.println("Message -> Ethernet cable is NOT connected.");
    }
    else
    {
      Serial.println("");
      Serial.println("Message -> Ok..!!!");
      Serial.println("==================");
      digitalWrite(led_eth, HIGH);
      delay(500);
    }
  }
  digitalWrite(led_eth, LOW);
}