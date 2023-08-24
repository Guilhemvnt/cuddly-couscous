# cuddly-couscous

Discover Wireshark sofware for Network Traffic Analysis :
  wget -O file.zip 'https://academy.hackthebox.com/storage/resources/pcap_files.zip' && mkdir tempdir && unzip file.zip -d tempdir && mkdir -p pcaps && mv tempdir/Intermediate_Network_Traffic_Analysis/* pcaps/ && rm -r tempdir file.zip
  I notice right away that an excessive amount of deauthentication frames were sent to one of our client devices.
  Adresse MAC = F8:14:FE:4D:E6:F1

For Filtering Deauthentication Frames in WireShark :

  (wlan.bssid == F8:14:FE:4D:E6:F1) and (wlan.fc.type == 0) && (wlan.fc.type_subtype == 12)
    
  (wlan.bssid == F8:14:FE:4D:E6:F1) --> the attacker on the wlan device

  (wlan.fc.type == 0) && (wlan.fc.type_subtype == 12) -> 0 to 12 is a default code use by "aireplay-ng" and "mdk4" , which are common attack tools for Deauthentication
  This code is found on the reason code of the request
