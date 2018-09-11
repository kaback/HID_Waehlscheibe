#include <Keyboard.h>
#include <Bounce2.h>

static const byte NSApin = 9;  // NSA, LOW wenn sich die Waehlscheibe dreht
static const byte NSIpin = 10; // NSI, Erzeugt bei der Zuckbewegung der Waehlscheibe die Pulse

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

                                        
  if(scheibedreht.read() == LOW)    // Wenn sich die Waehlscheibe dreht...
  {
                                       
    if(waehlpulse.fallingEdge()) {  //... und wenn ein Impuls anliegt
      count++;                      //... Impuls zaehlen
    }  
  } else {                          // Wenn sich die Waehlscheibe nicht dreht...
    if(count != 0) {                //... und wenn wir vorher etwas gezaehlt haben
      if(count == 10){              //... und wenn der Counter auf 10 steht
        Keyboard.write(48);         //... schreibe eine 0 auf dem keyboard
      } else {                      //... andernfalls, wenn der Counter nicht 0 aber auch nicht 10 ist
        Keyboard.write(48+count);   //... schreibe den Counterwert auf dem Keyboard 
      }
      count = 0;                    // Counter zuruecksetzen
    }
  }
}

