
# Get time

To get time from GSM provider with +CCLK command you have to:
1. Unregister device from the network:
   ```
   AT+COPS=2
   OK
   ```
2. Set 1 as value for +CLTS
   ```
   AT+CLTS=1
   OK
   ```
3. Register again in the network (now there would be additional information about time and timezone):
   ```
   AT+COPS=0

   +CTZV: +4,0
   *PSUTTZ: 2017,1,22,21,7,29,"+4",0
   DST: 0
   OK
   ```
4. SIM will update its time automatically.
   ```
   AT+CCLK?

   +CCLK: "17/01/22,22:07:47+04"
   OK
   ```
