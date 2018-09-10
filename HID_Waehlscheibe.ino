#include <Keyboard.h>
#include <Bounce2.h>

static const byte NSApin = 9;  // NSA switch is low when the dail disk is moved
static const byte NSIpin = 10; // NSI when rotating back, nsi generates the impulses

Bounce waehlpulse = Bounce();
Bounce scheibedreht = Bounce();

void setup()
{
	pinMode(NSApin, INPUT_PULLUP);  // Set the button as an input
	pinMode(NSIpin, INPUT_PULLUP);  // Set the button as an input
  pinMode(LED_BUILTIN,OUTPUT);

  waehlpulse.attach(NSIpin);
  waehlpulse.interval(5); // interval in ms
  scheibedreht.attach(NSApin);
  scheibedreht.interval(5); // interval in ms

  Keyboard.begin();
	
}
unsigned int count=0;

void loop()
{
  waehlpulse.update();
  scheibedreht.update();

  // Wenn sich die Waehlscheibe dreht...
  if(scheibedreht.read() == LOW)
  {
    // ...und wenn ein Impuls anliegt
    if(waehlpulse.fallingEdge()) {
      // ... Impuls zaehlen
      count++;
    }  
  } else { // Wenn sich die Waehlscheibe nicht dreht...
    if(count != 0) { //... und wenn wir vorher etwas gezaehlt haben
      if(count == 10){ //... und wenn der Counter auf 10 steht
  
        Keyboard.write(48); //... schreibe eine 0 auf dem keyboard
      } else { // wenn der Counter nicht 0 aber auch nicht 10 ist
        Keyboard.write(48+count); //... schreibe den Counterwert auf dem Keyboard 
 
      }
      count = 0; // Counter zuruecksetzen
    }
  }
}

