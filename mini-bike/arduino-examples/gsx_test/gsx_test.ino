
#define TX PA9
#define console Serial
#define cbaud 57600
#define sds Serial1
#define sdsbaud 10400

////////////////////////////////////////////////////// some static options //////////////////////////////////////////////////////

int const debug = 0;
int const timeout = 2000;
int const cyclespeed = 50;
byte const source = 0xF1;
byte const target = 0x12;
byte const header = 0x80;

////////////////////////////////////////////////////// possible protocol values //////////////////////////////////////////////////////

byte const startinit[5] = {
  0x81,
  target,
  source,
  0x81,
  0x05,
};

byte const keepalive[1] = {
  0x01,
};

byte monitorsensordata[7] = {
  header,
  target,
  source,
  0x02,
  0x21,
  0x08,
  0xAE, 
};

////////////////////////////////////////////////////// variables //////////////////////////////////////////////////////

int datalength = 0;
int mode = 0;
int timeold;
int time;


void setup() {
  console.begin(cbaud);
  pinMode(TX, OUTPUT);
}

void loop() {
  fastinit();
  senddata();
  recievedata();
}

// KWP2000 Fast Init
void fastinit(){
  if (!mode) {
    console.println("Starting comunication (fastinit)");
    digitalWrite (TX, HIGH);                                       
    if (debug) console.println("Set K-Line High");
    delay(6000);                                                             
    digitalWrite (TX, LOW);                                                   
    if (debug) console.println("Set K-Line Low");
    delay(25);
    digitalWrite (TX, HIGH);                                                     
    if (debug) console.println("Set K-Line High");
    delay(25);                                                               
    sds.begin(sdsbaud);                                                     
    if (debug) console.println("starting serial comunication");
    mode++;
  }
}

// Send request to the ecu (message)
void senddata() {
  if (mode) {
    if (mode == 1) {
      for (int x = 0; x <= 4; x++) {                            // messagelength=number of parameters stored in array
        sds.write(startinit[x]);
        datalength = 4;
        if (debug) {
          console.print("sending data: ");
          console.println(startinit[x], HEX);
        }
      }
    }
    if (mode == 2) {
      for (int x = 0; x <= 6; x++) {                            // messagelength=number of parameters stored in array
        sds.write(monitorsensordata[x]);
        datalength = 6;
        if (debug) {
          console.print("sending data: ");
          console.println(monitorsensordata[x], HEX);
        }
      }
    }
  }
}

/*

if (mode == 1) {
for (int x = 0; x <= 4; x++) {                            // messagelength=number of parameters stored in array
sds.write(startinit[x]);
if (debug) {
console.print("sending data: ");
console.println(startinit[x], HEX);
}
datalength = 4;
}
}
if (mode == 2) {
for (int x = 0; x <= 6; x++) {                            // messagelength=number of parameters stored in array
sds.write(monitorsensordata[x]);
if (debug) {
console.print("sending data: ");
console.println(monitorsensordata[x], HEX);
}
datalength = 6;
}
}
}
*/
void recievedata() {
  int data = 0;
  int i = 0;
  int incomingdata[] = {
  };
  /*  time = millis();
   console.print("Monitoring speed: ");
   console.print(time-timeold);
   console.println("ms"); */
  if (debug) {
    console.println("waiting for data");
  }
  timeold = millis();
  while (!data) {                          // loop, it needs to be closed later if checksum and everything else is ok
    /*    if (timeout) {
     if ((timeold + timeout) <= time) {        // if time is higher than the time stored last timeout + the needet time it starts from begining
     console.println("Timeout");
     mode = 0;
     sds.end();
     return;     
     }
     } */
    if (sds.available()) {                   // reading data
      byte inByte = sds.read();
      incomingdata[i] = inByte;
      if (debug) {
        console.println(incomingdata[i],HEX);
      }
      byte numparam;
      byte checksum;
      /*      // Check if data was recieved sucessfull
       if (i == messagelength) {
       for (int  x = 0; (incomingdata[x] == message[x]); x++) {
       if (messagelength == x) {
       console.println("Data sent to ECU");
       }
       }
       }
       */
      if (i == datalength + 4) {
        numparam = incomingdata[i];
        if (debug) {
          console.print("Number of Parameters: ");
          console.println(numparam,HEX);
        }
      }
      if (mode == 2) {
        if (i == 20) {
          console.print("Throtle Position: ");
          console.println(incomingdata[i]*125/255);
        }
        if (i == 21) {
          console.print("Intake Air Pressure: ");
          console.println((incomingdata[i]-153)*133/4/255);
        }
        if (i == 22) {
          console.print("Engine Coolant Temp: ");
          console.println(incomingdata[i]*160/255 - 30);
        }
        if (i == 23) {
          console.print("Intake Air Temp: ");
          console.println(incomingdata[i]*160/255 - 30);
        }
        if (i == 28) {
          console.print("Intake Air Pressure2: ");
          console.println((incomingdata[i]-153)*133/4/255);
        }
        if (i == 47) {
          console.print("Second Throtle Valve: ");
          console.println(incomingdata[i]*100/255);
        }
      }
      if (i == datalength+5+numparam) {
        /* for (int x = datalength+1;x<i;x++) {
         checksum += incomingdata[x];
         console.print(checksum,HEX);
         }*/
        if (debug) {
          console.print("Checksum: ");
          console.println(incomingdata[i],HEX);
        }
        mode = 2;
        data++;
        delay (cyclespeed);
        /* if (checksum == incomingdata[i]) {
         data++;
         mode = 2;
         delay (cyclespeed);
         }  */
      }
      i++;
    }
  }
}
