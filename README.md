Main ---> Windows Software
Master ----> Linux Sofware

NetWork Library PNet writen on c++.The program use blocking soctets beetween OS Windows and Linux for passsing network packets type int,std::string and std::vector<uint32_t>/ std::vector<uint16_t> depends of your OS,
aslo, this programm has thow project inside Server and client cluster and you can run any On your OS (MacOS is the exeption), but comming soon.
this is a screens how it works.
Windows:
![image](https://github.com/snipsss/NetWorkLib_PNet/assets/105834928/543cef42-c212-450b-a09a-45c3e781c09c)

LINUX:
![image](https://github.com/snipsss/NetWorkLib_PNet/assets/105834928/36ad6bbd-72ef-41bb-9718-6416033deac7)

HOW TO USE IT!
if you want to set up Server on Linux, go to build/bin/./Server, but keep in mind, you have to change my setting as a port and IpV4 address in Server.cpp or if you use Windows in configPtrFile.h in namespace PNet;
However,you have to make unable port, whatever you want in Devices -> NetWork -> type of your adapter my in my case is NAT network Layer  -> advanced and add in "type of IP" IpV4 and add your port, witch you gonna 
to use.

The second dependence of this programm,you should know what is the Endian in your PC or OS. in my case BigEndianm, Network byteorder will read and compute packets from Priority bit to close bit
![image](https://github.com/snipsss/NetWorkLib_PNet/assets/105834928/2e4ea835-2172-4640-853f-4d79800a704f)


to check you IpV4 on Windows. open command line and write """Ipconfig""" on The button of statement you will see IpV4 stat copy and save this Ip. 

