# HID_Waehlscheibe
POC: Alte Telefonwaehlscheibe als USB-HID

Die Wählscheibe wird damit zu einem per USB anschliessbaren numerischen Eingabegerät für PC und Co.

KISS (Keep It Simple Stupid) ohne Beachtung von Effizienz und gutem Stil.

Braucht einen Arduino mit 32u4, also z.B. den Leonardo oder einen anderen Controller mit integriertem USB.

Nutzt die Bounce2 Lib für die Entprellung der Kontakte.

Hintergrund:

So eine Wählscheibe hat 2 Kontakte. Einer ist immer dann geschlossen, wenn die Scheibe in der Rückbewegung ist, sich als zurueckdreht. Der andere gibt die Pulse während sich die Scheibe zurueckbewegt. Bei einer 0 gibts bei der Rueckbewegung einen Puls, bei der 0 gibts dann zehn Pulse. 

Man muss also nur erkennen, ob sich die Scheibe dreht, und wenn, dann zaehlt man einfach die Pulse. Das genau macht der Code. Simple stupid.
